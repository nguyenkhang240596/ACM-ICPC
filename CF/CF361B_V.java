import java.util.Scanner;

/**
 * Created by vothvu on 21/06/2017.
 */
public class Main {
    public static void main(String[] args) {
        int n, k;
        long m = 10000000000;
        System.out.println(m);
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        k = in.nextInt();
        if(n != k) {
            for (int i = 2; i <= n - k; ++i) System.out.print(i + " ");
            System.out.print(1 + " ");
            for (int i = n - k + 1; i <= n; ++i) System.out.print(i + " ");
        } else {
            System.out.print(-1);
        }
    }
}
