import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner read = new Scanner(System.in);
        BigInteger ind = read.nextBigInteger();
        int k=read.nextInt();
        int i;
        del: for(i=1;i<=k;i++){
            String fir=ind.toString();
            String mid=fir.substring(0,(fir.length()/2));
            StringBuffer turn = new StringBuffer(mid);
            turn=turn.reverse();
            String fin=turn.toString();
            String sed=fir.substring(fir.length()-(fir.length()/2),fir.length());
            if(sed.equals(fin)){
                break del;
            }
            else{
                BigInteger ind2=reverse(ind);
                ind=ind.add(ind2);
            }
        }
        System.out.println(ind);
        System.out.println(i-1);
    }
    public static BigInteger reverse(BigInteger i ){
        BigInteger s ,j =BigInteger.valueOf(0),temp;
        s= i;
        while(s!=BigInteger.valueOf(0)){
        temp=s.remainder(BigInteger.valueOf(10));
        j = (j.multiply(BigInteger.valueOf(10))).add(temp);
        s=s.divide(BigInteger.valueOf(10));
        }
        return j;
    }
       
}
