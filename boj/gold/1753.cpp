// basic dijkstra algorithm
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int v, e;
int stp;

class Edge {
public:
    Edge *next_one;
    int from, to, weight;
    bool checked;
    Edge() {
        next_one = nullptr;
        from = to = weight = 0;
        checked = false;
    }
};
Edge *graph[20001];

typedef pair<int, int> ipair;
auto cmp = [](const ipair& left, const ipair& right) {
    return left.second > right.second;
};
priority_queue<ipair, vector<ipair>, decltype(cmp)> dijk(cmp);
int cost[20001];
const int inf = 0x7fffffff;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    cin >> stp;
    for(int i=1;i<=v;++i) {
        graph[i] = new Edge;
        cost[i] = inf;
    }
    for(int i=0;i<e;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge *new_edge = new Edge;
        new_edge->from = u;
        new_edge->to = v;
        new_edge->weight = w;
        new_edge->next_one = graph[u]->next_one;
        graph[u]->next_one = new_edge;
    }

    dijk.push({stp, 0});
    while(!dijk.empty()) {
        ipair now = dijk.top();
        dijk.pop();
        if(cost[now.first] <= now.second) { // 같은 경우에도 pass
            continue;
        }
        cost[now.first] = now.second;

        // idea: 모든 edge를 다 보는 경우(=worst case)
        for(Edge *it=graph[now.first]->next_one;it != nullptr;it = it->next_one) {
            if(!(it->checked)) {
                dijk.push({it->to, it->weight + now.second});
                it->checked = true;
            }
        }
    }

    for(int i=1;i<=v;++i) {
        if(cost[i] != inf) {
            cout << cost[i] << '\n';
        } else {
            cout << "INF\n";
        }
    }

    return 0;
}