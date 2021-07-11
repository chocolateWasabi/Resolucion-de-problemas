package baekjoon.silver;

import java.io.*;
import java.util.*;

public class BOJ18870 {

    public static void main(String[] args) throws IOException {
        int N;
        int[][] originData, sortedData;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.valueOf(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br.close();

        originData = new int[N][2];
        sortedData = new int[N][2];

        for(int i=0;i<N;i++) {
            sortedData[i][0] = originData[i][0] = Integer.valueOf(st.nextToken());
            sortedData[i][1] = originData[i][1] = i;
        }
        //System.arraycopy(originData, 0, sortedData, 0, N);

        Arrays.sort(sortedData, (x, y) -> {
            return x[0] != y[0]? Integer.compare(x[0], y[0]): Integer.compare(x[1], y[1]);
        });

        int prev = -1000000001, prevIndex = -1;
        for(int i=0;i<N;i++) {
            //System.out.printf("%d: %d\n", sortedData[i][0], sortedData[i][1]);

            if(sortedData[i][0] != prev) {
                prev = sortedData[i][0];
                prevIndex ++;
            }
            originData[sortedData[i][1]][1] = prevIndex;
        }

        StringBuilder result = new StringBuilder();

        for(int i=0;i<N;i++) {
            result.append(originData[i][1]);
            if(i != N-1) {
                result.append(" ");
            }
        }

        bw.write(result.toString());
        //bw.flush();
        bw.close();
    }
}