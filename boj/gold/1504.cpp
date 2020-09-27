// dijkstra 응용
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

class Edge {
public:
    Edge *next_one;
    int from, to, weight;
    Edge() {
        next_one = nullptr;
        from = to = weight = 0;
    }
    Edge(int a, int b, int c, Edge *next_one) {
        from = a, to = b, weight = c;
        this->next_one = next_one;
    }
};
typedef pair<int, int> ipair;
auto cmp = [](const ipair& left, const ipair& right) {
    return left.second > right.second;
};
priority_queue<ipair, vector<ipair>, decltype(cmp)> dijk(cmp);
const int max_v = 800;
const int inf = 0x7fffffff;
int cost[max_v + 1];
int v, e;
Edge *graph[max_v + 1];


void initialize() {
    for(int i=1;i<=v;++i) {
        cost[i] = inf;
    }
    while(!dijk.empty()) {
        dijk.pop();
    }
}

int wayFind(int s, int e) {
    initialize();

    dijk.push({s, 0});
    while(!dijk.empty()) {
        ipair now = dijk.top();
        dijk.pop();
        if(cost[now.first] <= now.second) {
            continue;
        }
        cost[now.first] = now.second;

        for(Edge *it=graph[now.first]->next_one;it != nullptr;it = it->next_one) {
            if(now.second + it->weight < cost[it->to]) {
                dijk.push({it->to, now.second + it->weight});
            }
        }
    }
    if(cost[e] != inf) {
        return cost[e];
    } else {
        return -1;
    }
}

int my_min(int a, int b) {
    return a < b? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for(int i=1;i<=v;++i) {
        graph[i] = new Edge;
    }
    for(int i=0;i<e;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge *new_edge1 = new Edge(a, b, c, graph[a]->next_one);
        graph[a]->next_one = new_edge1;
        Edge *new_edge2 = new Edge(b, a, c, graph[b]->next_one);
        graph[b]->next_one = new_edge2;
    }
    int v1, v2;
    cin >> v1 >> v2;
    // 1 -> N을 v1, v2 거치면서 최단 경로를 만족하는 것은,
    // 1->v1, v1->v2, v2->N 혹은 1->v2, v2->v1->, v1->N을 거치면서 최단 경로를 만족해야 하는 것과 동일함
    // 엄밀한 증명은 패스
    int p1_1, p1_2, p1_3;
    int p2_1, p2_2, p2_3;
    bool p1_valid, p2_valid;
    p1_valid = p2_valid = false;
    p1_1 = wayFind(1, v1);
    p1_2 = wayFind(v1, v2);
    p1_3 = wayFind(v2, v);
    if(p1_1 != -1 && p1_2 != -1 && p1_3 != -1) {
        p1_valid = true;
    }
    p2_1 = wayFind(1, v2);
    p2_2 = wayFind(v2, v1);
    p2_3 = wayFind(v1, v);
    if(p2_1 != -1 && p2_2 != -1 && p2_3 != -1) {
        p2_valid = true;
    }
    if(!p1_valid && !p2_valid) {
        cout << -1;
    } else if(!p1_valid && p2_valid) {
        cout << p2_1 + p2_2 + p2_3;
    } else if(p1_valid && !p2_valid) {
        cout << p1_1 + p1_2 + p1_3;
    } else {
        cout << my_min(p1_1 + p1_2 + p1_3, p2_1 + p2_2 + p2_3);
    }

    return 0;
}