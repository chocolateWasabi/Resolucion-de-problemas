package baekjoon.gold;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

// BOJ ID 3190 (Uncompleted)
public class Main {
    static int N, K, L;
    static Map<Integer, String> dirChangeInfo;
    static int[][] dummy;

    static void readDummyInfo() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.valueOf(br.readLine());
        dummy = new int[N+1][N+1];

        K = Integer.valueOf(br.readLine());
        for(int i=0;i<K;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int line, column;
            line = Integer.valueOf(st.nextToken());
            column = Integer.valueOf(st.nextToken());
            dummy[line][column] = 5;
        }

        L = Integer.valueOf(br.readLine());
        dirChangeInfo = new HashMap<Integer, String>();
        for(int i=0;i<L;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            dirChangeInfo.put(Integer.valueOf(st.nextToken()), st.nextToken());
        }

        br.close();
    }

    public static void main(String[] args) throws IOException {

        readDummyInfo();

        /*
         *  Task: Implement a snake game within 100x100 square !
         */

    }
}
