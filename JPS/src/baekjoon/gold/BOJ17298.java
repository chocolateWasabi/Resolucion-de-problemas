package baekjoon.gold;

import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ17298 {
    private static Stack<ArrayList<Integer>> mainStack = new Stack<>();

    private static void pushPush(int a, int b) {
        mainStack.push(new ArrayList<Integer>(){{
            add(a);
            add(b);
        }});
    }

    private static ArrayList<Integer> getTop() {
        return mainStack.get(mainStack.size() - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.valueOf(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[][] data = new int[N][2];
        br.close();

        for(int i=0;i<N;i++) {
            data[i][0] = Integer.valueOf(st.nextToken());
            if(mainStack.empty()) {
                pushPush(data[i][0], i);
            } else {
                ArrayList<Integer> top = getTop();
                while(top.get(0) < data[i][0]) {
                    data[top.get(1)][1] = data[i][0];
                    mainStack.pop();

                    if(!mainStack.empty()) {
                        top = getTop();
                    } else {
                        break;
                    }
                }
                pushPush(data[i][0], i);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;i++) {
            if(data[i][1] == 0) {
                sb.append("-1 ");
            } else {
                sb.append(data[i][1] + " ");
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(sb.toString());
        bw.close();
    }
}
