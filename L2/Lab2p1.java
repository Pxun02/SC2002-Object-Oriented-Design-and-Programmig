import java.util.Scanner;
public class Lab2p1 {
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following methods:");
            System.out.println("1: miltiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            choice = sc.nextInt();
            switch (choice) {
                case 1: mulTest();
                    break;
                case 2: 
                    System.out.printf("m = ");
                    int m = sc.nextInt();
                    System.out.printf("n = ");
                    int n = sc.nextInt();
                    System.out.format("%d/%d=%d%n", m, n, divide(m,n));
                    break;
                case 3:
                    System.out.printf("m = ");
                    int m3 = sc.nextInt();
                    System.out.printf("n = ");
                    int n3 = sc.nextInt();
                    System.out.format("%d%c%d=%d%n", m3, '%', n3, modulus(m3,n3));
                    break;
                case 4:
                    System.out.printf("n: ");
                    int m4 = sc.nextInt();
                    if(m4<0){
                        System.out.format("n: %d - Error input!!%n", m4);
                        break;
                    }
                    System.out.format("n: %d - count =  %d%n", m4, countDigits(m4));
                    break;
                case 5:
                    System.out.printf("n: ");
                    int n5 = sc.nextInt();
                    System.out.printf("digit: ");
                    int digit = sc.nextInt();
                    System.out.format("%nposition = %d%n", position(n5, digit));
                    break;
                case 6:
                    System.out.printf("n: ");
                    long n6 = sc.nextLong();
                    if(n6 < 0){
                        System.out.println("oddDigits = Error input!!");
                        break;
                    }
                    System.out.format("oddDigits = %d%n", extractOddDigits(n6));
                    break; 
                case 7: System.out.println("Program terminating ….");
            }
        } while(choice < 7);
    }
    public static void mulTest() {
        int correct =  0;
        int no_of_ans = 5;
        for(int i=0;i<5;i++){
            Scanner sc1 = new Scanner(System.in);
            int r1 = (int)Math.floor(Math.random()*9+1);
            int r2 = (int)Math.floor(Math.random()*9+1);
            System.out.format("How much is %d times %d? ", r1, r2);
            int ans = sc1.nextInt();
            if(ans == r1*r2)    correct++;
        }
        System.out.format("%d answers of %d are correct.%n", correct, no_of_ans);
    }
    public static int divide(int m, int n) {
        int count = 0;
        while(m>=n) {
            m -= n;
            count++;
        };
        return count;
    }
    public static int modulus(int m, int n){
        while(m>=n) {
            m -= n;
        };
        return m;
    }
    public static int countDigits(int n) {
        int count = 0;
        for(int i=n;i>0;i/=10){
            count++;
        }
        return count;
    }
    public static int position(int n, int digit){
        int  count = 0;
        for(int i=n;i>0;i/=10){
            count++;
            if(i%10 == digit)
                return count;
        }
        return -1;
    }
    public static long extractOddDigits(long n){
        long dig = 1;
        long tmp = 0;
        long dam;
        for (long i=n;i>0;i/=10){
            dam = i % 10;
            if(dam%2==1){
                tmp += dam * dig;
                dig *= 10;
            }
        }
        if(tmp==0)  return -1;
        return tmp;
    }
}