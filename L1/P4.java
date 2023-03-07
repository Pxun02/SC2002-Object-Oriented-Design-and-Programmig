import java.util.Scanner;

public class P4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            int n = sc.nextInt();
            func(n);
        } finally {
            if(sc!=null)
                sc.close();
        }
    }

    public static void func(int n) {
        String str = "";
        for(int i=0;i<n;i++){
            if(i%2==0)
                str = "AA" + str;
            if(i%2==1)
                str = "BB" + str;
            System.out.println(str);
        }
    }
}