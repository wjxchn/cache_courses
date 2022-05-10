import java.io.*;

public class program2 {
    static char[] signal = {'#','+','*','(',')','i'};
    static int[][] priority = {{1,2,1,1,2,1},{1,2,1,1,2,1},{1,2,1,1,2,1},{1,2,1,1,2,1},{1,2,1,1,2,1},{1,2,1,1,2,1}};
    static String inputstring = "";
    static String hasread = "#";
    static String[] grammar = {"N+N","N*N","(N)","N","i"};

    public static void main(String[] args) throws IOException {
        File filename = new File(args[0]);
        InputStreamReader reader = new InputStreamReader(new FileInputStream(filename));
        BufferedReader br = new BufferedReader(reader);

        char str = (char)br.read();
        while(str!='\r'&&str!='\n'){
            System.out.print(str);
            inputstring = inputstring + str;
            str = (char)br.read();
        }
    }
}
