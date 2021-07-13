package baekjoon.silver;

import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ1476 {
    public static final int MAX_E = 15;
    public static final int MAX_S = 28;
    public static final int MAX_M = 19;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        sc.close();

        int E, S, M;
        E = Integer.valueOf(st.nextToken());
        S = Integer.valueOf(st.nextToken());
        M = Integer.valueOf(st.nextToken());

        int e, s, m;
        e = s = m = 1;

        int year = 1;
        while(true) {
            if(e == E && s == S && m == M) {
                System.out.println(year);
                break;
            } else if(e == MAX_E && s == MAX_S && m == MAX_M) {
                System.out.println("LIMIT");
                break;
            }

            e = e == MAX_E? 1: e + 1;
            s = s == MAX_S? 1: s + 1;
            m = m == MAX_M? 1: m + 1;
            year ++;
        }
    }
}
