import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Created by EladKeyshawn on 12/12/2016.
 */
public class MultiServer implements Runnable {
    private final ServerSocket serverSocket;
    private final ExecutorService pool;

    public MultiServer(String ipToBind, int port, int poolSize)
            throws IOException {
        serverSocket = new ServerSocket(port, 5, InetAddress.getByName(ipToBind));
        System.out.println("server: " + serverSocket.getInetAddress() + ", Listening on port " + serverSocket.getLocalPort());
        pool = Executors.newFixedThreadPool(poolSize);
    }

    public void run() { // run the service
        try {
            while (true) {
                pool.execute(new Handler(serverSocket.accept()));
            }
        } catch (IOException ex) {
            pool.shutdown();
        }
    }
}

class Handler implements Runnable {
    private final Socket socket;
    Handler(Socket socket) { this.socket = socket; }
    public void run() {
        try {
            while (true) {
                InputStream inputStream;
                if ((inputStream = socket.getInputStream()) != null) {
                    DataInputStream dataFromClient = new DataInputStream(inputStream);
                    System.out.println("Got from client: " + dataFromClient.readUTF());

                    OutputStream outputStream = socket.getOutputStream();
                    DataOutputStream dataToClient = new DataOutputStream(outputStream);
                    dataToClient.writeUTF("Hey client!");
                }

            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        finally {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }




    }
}

