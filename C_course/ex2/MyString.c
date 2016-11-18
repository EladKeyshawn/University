#define NULL 0


int str_len(char str[]) {
    int len = 0;
    const char* r1 = str;
    while (*r1 != '\0' ) {
        len++;
        r1++;
    }
    return len;
}



// returns 1 if s2 before s1 in dict
int str_cmp(char s1[], char s2[])
{
    int i = 0;
    while ( s1[i] != '\0' )
    {
        if( s2[i] == '\0' ) { return 1; }
        else if( s1[i] < s2[i] ) { return -1; }
        else if( s1[i] > s2[i] ) { return 1; }
        i++;
    }
    return 0;
}

int isDelim(char c, const char* delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}


int word_len_by_delim(char *s) {
    int word_len = 0;
    while (*s != '\0') {
        if (*s == ';') {
            break;
        }
        word_len++;
    }
    
    return word_len;
}

void str_cpy (char* t, char* str) {
    int i;
    for (i=0; i < 20; i++) {
        if(*str != '\0') {
            t[i] = *str;
        }
        str++;
    }
}


void sortDelim(char str[], const char* delim) {
    char *r = str;
    int words_count = 1;
    // replace delimiter with ';'
    while (*r != '\0') {
        if (isDelim(*r, delim) > 0) {
            *r = ';';
            words_count++;
        }
    }
    r = str;
    char* orig_dup = strdup(str);
    char *p = strtok (str, ";");
    char *words_sep[6];
    int i =0;
    while (p != NULL)
    {
        words_sep[i++] = p;
        p = strtok (NULL, ";");
    }
    
    
    char t[20];
    int j;

    for (i = 1; i < 6; i++) {
        for (j = 1; j < 6; j++) {
            if (str_cmp(words_sep[j - 1], words_sep[j]) > 0) {
                str_cpy(t, words_sep[j - 1]);
                str_cpy(words_sep[j - 1], words_sep[j]);
                str_cpy(words_sep[j], t);
            }
        }
    }
    
    int index;
    for (index = 0; index < 6; index++) {
        char *wrd_runner = words_sep[index];
        while (*r != '\0' && *wrd_runner != '\0') {
            *r = *wrd_runner;
            r++;
            wrd_runner++;
        }
        
        *r = ';';
    }
            
}



int extendedSubStr(int isCyclic, int step, const char* str1, const char* str2) {
    int len1 = str_len(str1);
    
    if (*str1 == '\0' || *str2 == '\0') {
        return -1;
    }
    int i,j,temp;

    for(i=0;str1[i]!='\0' ;i++)
    {
        j=0;
        if(str1[i]==str2[j])
        {
            temp=i+1;
            while(str1[i]==str2[j] && str2[j] != '\0')
            {
                if (i + step > len1-1 && isCyclic == 1 ) {
                    i = step-(len1-i);
                } else {
                    i += step;
                }
                
                j++;
                
            }
            if(str2[j] == '\0') {
                return temp-1;
            } else {
                i=temp;
                temp=0;
            }
        }
    }

    return -1;
}
