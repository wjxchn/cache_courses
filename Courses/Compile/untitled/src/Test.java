public class Test {
    public static void main(String[] args){
        byte[] out_byte ="\\\n".toString().getBytes();
        for(byte item:out_byte){
            System.out.printf("%02x",item);
        }

    }
}
