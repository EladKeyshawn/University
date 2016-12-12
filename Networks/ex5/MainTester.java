import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by EladKeyshawn on 12/12/2016.
 */
public class MainTester {



    public static void main (String[] args) {
        final int PORT = 5656;
        final String serverIp = "127.0.0.1";
        try {
            MultiServer server = new MultiServer(serverIp,PORT, 5);
            server.run();
        } catch (IOException e) {
            e.printStackTrace();
        }

        

    }
}
