// SWEA 1248 공통조상 문제 (D5)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int vertex[10010]; // tree에서의 정점의 위치
int pre_tree[10010][2]; // 서브 트리가 먼저 입력되는 경우를 대비한 전처리
int tree[100000]; 
// 크기가 최대 2^10000 (skewed tree 인 경우...)
// 결국 배열로 해결 불가.

void make_tree(int node, int pos){
    tree[pos] = node;
    vertex[node] = pos;

    if(pre_tree[node][0]){
        make_tree(pre_tree[node][0], 2 * pos);
    }
    if(pre_tree[node][1]){
        make_tree(pre_tree[node][1], 2 * pos + 1);
    }
}

void get_size(int node_pos, int& size){
    if(tree[2*node_pos]){
        size ++;        
        get_size(2*node_pos, size);
    }
    if(tree[2*node_pos+1]){
        size ++;
        get_size(2*node_pos+1, size);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int v, e, t1, t2;
    vector<int> ancestor;
    bool find_flag;
    int where_common, size;
    for(int t=1;t<=T;++t){
        cin >> v >> e >> t1 >> t2;
        
        // 초기화
        memset(vertex, 0, sizeof(vertex));
        memset(pre_tree, 0, sizeof(pre_tree));
        memset(tree, 0, sizeof(tree));
        ancestor.clear();
        
        // 간선 정보 build up (무조건 루트는 1)
        for(int i=1, parent, child;i<=e;++i){
            cin >> parent >> child;
            if(!pre_tree[parent][0]){
                pre_tree[parent][0] = child;
            }
            else {
                pre_tree[parent][1] = child;
            }
        }

        // 트리 생성
        make_tree(1, 1);
        
        // 검사: tree에서 t1, t2의 위치 = vertex[t1], vertex[t2]
        find_flag = false;
        where_common = 1;
        for(int i=vertex[t1]/2;i>=1;i/=2){
            ancestor.push_back(tree[i]);
        }
        for(int i=vertex[t2]/2;i>=1 && !find_flag;i/=2){
            for(auto j:ancestor){
                if(j == tree[i]){
                    find_flag = true;
                    where_common = tree[i];
                    break;
                }
            }
        }

        // 서브 트리의 크기 구하기
        size = 1;
        get_size(vertex[where_common], size);

        cout << '#' << t << ' ' << where_common << ' ' << size << '\n';
    }
    return 0;
}