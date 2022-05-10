import java.io.*;

public class program {
    static char[] signal = {'#','+','*','i','(',')'};
    static int[][] priority = {{0,-1,-1,-1,-1,-1},{1,1,-1,-1,-1,1},{1,1,1,-1,-1,1},{1,1,1,-2,-2,1},{-2,-1,-1,-1,-1,0},{1,1,1,-2,-2,1}};
    static String inputstring = "";
    static String hasread = "#";
    static String[] grammar = {"N+N","N*N","(N)","N","i"};
    static int lastparse = 0;

    public static boolean isinsignal(char a){
        int i = 0;
        for(;i<6;i++){
            if(a==signal[i]){
                break;
            }
        }
        if(i==6){
            return false;
        }
        else{
            return true;
        }
    }

    public static String resolution_function(){
        int i = 1;
        for(;i<hasread.length();i++){
            int j=0;
            for(;j<5;j++){
                if(hasread.substring(i).equals(grammar[j])&&!hasread.equals(hasread.substring(0,i)+"N")){
                    break;
                }
            }
            if(j!=5){
                break;
            }
        }
        if(i!=hasread.length()){
            hasread = hasread.substring(0,i)+"N";
            //System.out.println(hasread);
            return "R";
        }
        else{
            return "RE";
        }
    }

    public static int cmp(char a,char b){
        int i = 0;
        for(;i<6;i++){
            if(a==signal[i]){
                break;
            }
        }
        if(i==6){
            return -3;
        }
        int j = 0;
        for(;j<6;j++){
            if(b==signal[j]){
                break;
            }
        }
        if(j==6){
            return -3;
        }
        return priority[i][j];
    }

    public static void main(String[] args) throws IOException {
        File filename = new File(args[0]);
        InputStreamReader reader = new InputStreamReader(new FileInputStream(filename));
        BufferedReader br = new BufferedReader(reader);

        int str;
        while((str = br.read())!=-1){
            if((char)str!='\r'&&(char)str!='\n'){
                inputstring = inputstring + (char)str;
            }
        }

        inputstring = "#"+inputstring+"#";
        int i=1;
        while(i!=inputstring.length()){
            int j = hasread.length()-1;
            for(;j>0;j--){
                if(isinsignal(hasread.charAt(j))){
                    break;
                }
            }
            if(cmp(hasread.charAt(j),inputstring.charAt(i))==1){
                if(resolution_function().equals("RE")){
                    System.out.println("RE");
                    break;
                }
                else{
                    System.out.println("R");
                }
            }
            else if(cmp(hasread.charAt(j),inputstring.charAt(i))==-1||cmp(hasread.charAt(j),inputstring.charAt(i))==0){
                if(inputstring.charAt(i)!='#'){
                    System.out.println("I"+inputstring.charAt(i));
                }
                hasread = hasread + inputstring.charAt(i);
                i++;
            }
            else{
                System.out.println("E");
                break;
            }
            // System.out.println(hasread);
        }
    }
}
