import java.util.Scanner;

public class Q1App {
    public static void main(String[] args) {
        Q1 q1 = new Q1();
        q1.func();
    }
}

class Q1 {
    public Q1(){};
    public void func() {
        Scanner sc = new Scanner(System.in);
        try {
            char c = sc.next().charAt(0);
            switch(c){
                case('a'):
                    System.out.println("Action movie fan");
                    break;
                case('c'):
                    System.out.println("Comedy movie fan");
                    break;
                case('d'):
                    System.out.println("Drama movie fan");
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        } finally {
            if(sc!=null)
                sc.close();
        }
    }
}