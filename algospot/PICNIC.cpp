#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int matrix[11][11];
int occupied[11];

int wheretogo(){
    for(int i=0;i<n;++i){
        if(occupied[i] == 0){
            return i;
        }
    }
}

void match(int current_node, int matched, int& count){
    if(matched == n){
        count ++;
        return;
    }

    for(int i=0;i<n;++i){
        if(matrix[current_node][i] == 1 && occupied[i] == 0){
            occupied[current_node] = occupied[i] = 1;
            match(wheretogo(), matched + 2, count);
            occupied[current_node] = occupied[i] = 0;
        }
    }
}

int main(){
    int C;
    cin >> C;

    for(int c=1;c<=C;++c){
        cin >> n >> m;
        memset(matrix, 0, sizeof(matrix));
        memset(occupied, 0, sizeof(occupied));
        int u, v;
        for(int i=0;i<m;++i){
            cin >> u >> v;
            matrix[u][v] = matrix[v][u] = 1;
            /*matrix[u][0] ++;
            matrix[v][0] ++; // degree in 0th index */
        }
        /*
        int max_degree_i = 0;
        for(int i=1;i<=n;++i){
            if(matrix[i][0] > matrix[max_degree_i][0]){
                max_degree_i = i;
            }
        }*/
        int count = 0;
        match(0, 0, count);
        cout << count << '\n';
    }
    return 0;
}