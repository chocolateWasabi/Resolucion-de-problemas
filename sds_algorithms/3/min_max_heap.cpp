#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap = true;

void pushToHeap(vector<int>& heap, int dat, int &actualSize) {
    heap[++actualSize] = dat;
    int idx = actualSize;
    while(idx > 1) {
        if(!isMinHeap? (heap[idx/2] < heap[idx]): (heap[idx/2] > heap[idx])) {
            // 어차피 제일 마지막 칸에 넣는 거니까 *2+1 같은 경우 생각할 필요 없음. /2 시 자동으로 .5는 날라감
            heap[idx/2] ^= heap[idx];
            heap[idx] ^= heap[idx/2];
            heap[idx/2] ^= heap[idx];
            idx /= 2;
        } else {
            break;
        }
    }
}

int popFromHeap(vector<int>& heap, int &actualSize) {
    // vector라서 넘어가는 index에 대한 처리 필요
    int top = heap[1];
    heap[1] = heap[actualSize];
    heap[actualSize] = !isMinHeap? 0: 0x7fffffff;
    actualSize--;
    // heap.pop_back();

    int idx = 1;
    while(idx <= (actualSize / 2)) { // 인덱스 조건 어떻게 하는게 좋을까? - max heap의 경우 더 큰 자식 노드와 교환, min heap의 경우 그 반대.
        // 
        // skewed tree가 되지 않기 위해, 무작정 한 쪽으로 보내는 것이 아니라 좌/우 자식 노드 중 어디와 교환할지 비교해서 미리 결정해야함
        // 위 내용 xxx ... skewed보다 더 중요한 heap의 특성이 있다. (아래 설명)
        //
        // max heap의 경우, 무조건 자식 노드 둘 중 큰 쪽이랑 교환을 해야 함.
        // 왜냐하면, 그렇지 않다면 작은 쪽이랑 교환을 하는 경우 작은 노드가 큰 우측 노드보다 상위 노드가 되는 모순이 발생

        int tmp;
        if(!isMinHeap? (heap[idx] < heap[idx*2]): (heap[idx] > heap[idx*2])) {
            if(!isMinHeap? (heap[idx*2] < heap[idx*2 + 1]): (heap[idx*2] > heap[idx*2 + 1])) { // 우측으로
                tmp = heap[idx];
                heap[idx] = heap[idx*2 + 1];
                heap[idx*2 + 1] = tmp;
                idx = idx * 2 + 1;
            } else { // 좌측으로
                tmp = heap[idx];
                heap[idx] = heap[idx*2];
                heap[idx*2] = tmp;
                idx = idx * 2;
            }
        } else {
            if(!isMinHeap? (heap[idx] < heap[idx*2 + 1]): (heap[idx] > heap[idx*2 + 1])) { // 우측으로
                tmp = heap[idx];
                heap[idx] = heap[idx*2 + 1];
                heap[idx*2 + 1] = tmp;
                idx = idx * 2 + 1;
            } else { // 현재가 큰 값 - 종료
                break;
            }
        }
    }
    return top;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //const int maxima = 123456;
    vector<int> heap;
    //heap.reserve(maxima);
    //heap.push_back(0); // index를 0번부터 시작

    int n;
    cin >> n;
    heap.resize(n + 1, !isMinHeap? 0: 0x7fffffff);
    // 이렇게가 아니라, 조금 더 넉넉히 할당해야 한다. => 원래는 그 level까지 다 할당해 주는게 좋은데,
    // 여기 문제에서는 n값이 원소의 값이 아니므로 그냥 할당ㄱ
    // min heap의 경우, 0과 비교해서 교환해버리는 아이러니가 있기 때문에, 빈 index는 무한대로 설정
    // 또는 위에서 교환 시마다 actualSize 넘어가는지 확인하면 되기는 한데, 그냥 간단히 이렇게 sentinel을 설정해버리자.

    int actualSize = 0;
    for(int i=0, dat;i<n;++i) {
        cin >> dat;
        if(dat) {
            pushToHeap(heap, dat, actualSize);
            /*cout << actualSize << ": ";
            for(auto i:heap) {
                cout << i << ' ';
            }
            cout << '\n';*/
        } else {
            if(actualSize) {
                cout << popFromHeap(heap, actualSize) << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}