import java.io.*;
import java.net.Socket;

/**
 * Created by EladKeyshawn on 12/12/2016.
 */
public class Client {

    private Socket sock;
    private String serverIp;
    private int serverPort;
    private String clientId;

    public Client (String ip, int port, String id) {
        serverIp = ip;
        serverPort = port;
        clientId = id;
    }

    public static void main (String[] args) {
        String clientId = args[0];
        try {

            Socket sock = new Socket("127.0.0.1", 5656);
            System.out.println("Connected successfully to server: " + sock.getInetAddress());

            OutputStream outputStream = sock.getOutputStream();
            DataOutputStream dataToServer = new DataOutputStream(outputStream);

            InputStream inputStream = sock.getInputStream();
            DataInputStream dataFromServer = new DataInputStream(inputStream);

            int msg_index = 0;
            while (msg_index < 100) {

                Thread.sleep(2000);
                dataToServer.writeUTF("msg: " + msg_index + "from client: " + clientId);

                System.out.println("Received from server: " + dataFromServer.readUTF());
                msg_index++;
            }


            sock.close();


        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

}
