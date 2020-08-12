#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap = false;

void pushToHeap(vector<int>& heap, int dat, int &actualSize) {
    heap[++actualSize] = dat;
    int idx = actualSize;
    while(idx > 1) {
        if(!isMinHeap? (heap[idx/2] > heap[idx]): (heap[idx/2] < heap[idx])) {
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
    heap[1] = heap[actualSize--];
    // heap.pop_back();

    int idx = 1;
    while(idx <= (actualSize / 2)) { // 인덱스 조건 어떻게 하는게 좋을까?
        // skewed tree가 되지 않기 위해, 무작정 한 쪽으로 보내는 것이 아니라 좌/우 자식 노드 중 어디와 교환할지 비교해서 미리 결정해야함
    }
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
    heap.resize(n + 1);
    heap[0] = 0;

    int actualSize = 0;
    for(int i=0, dat;i<n;++i) {
        cin >> dat;
        if(dat) {
            pushToHeap(heap, dat, actualSize);
        } else {
            cout << popFromHeap(heap, actualSize);
        }
    }

    return 0;
}