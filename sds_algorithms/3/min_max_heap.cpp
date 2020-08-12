#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap = false;

void pushToHeap(vector<int>& heap, int dat) {
    heap.push_back(dat);
    int idx = heap.size() - 1;
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

int popFromHeap(vector<int>& heap) {
    // vector라서 넘어가는 index에 대한 처리 필요
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int maxima = 123456;
    vector<int> heap;
    heap.reserve(maxima);
    heap.push_back(0); // index를 0번부터 시작

    int n;
    cin >> n;
    for(int i=0, dat;i<n;++i) {
        cin >> dat;
        if(dat) {
            pushToHeap(heap, dat);
        } else {
            cout << popFromHeap(heap);
        }
    }

    return 0;
}