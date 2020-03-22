#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    pair<int, int> start, end;
    vector<pair<int, int> > coord;
    for(int t=1;t<=T;++t){
        int N;
        cin >> N;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        coord.clear();
        for(int i=1, t1, t2;i<=N;++i){
            cin >> t1 >> t2;
            coord.push_back(make_pair(t1, t2));
        }
        int min_dist = 0x7fffffff, dist;
        vector<int> order;
        for(int i=0;i<N;++i){order.push_back(i); }
        do {
            // min_dist check
            dist = 0;
            dist += abs(coord[order[0]].first - start.first) + abs(coord[order[0]].second - start.second);
            dist += abs(end.first - coord[order[N-1]].first) + abs(end.second - coord[order[N-1]].second);
            for(int i=0;i<N-1;++i){
                dist += abs(coord[order[i+1]].first - coord[order[i]].first) + abs(coord[order[i+1]].second - coord[order[i]].second);
            }

            min_dist = dist < min_dist? dist: min_dist;
        } while(next_permutation(order.begin(), order.end()));
        
        cout << '#' << t << ' ' << min_dist << '\n';
    }
    return 0;
}