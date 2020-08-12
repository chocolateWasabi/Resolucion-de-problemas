// 강사님 강의 듣고 Java -> C++ 로 직역한 Indexed Tree 코드
// 조금 더 이해가 되면 나만의 방식으로 다시 작성해볼 것
// (기억이 가물해질 토요일 쯤)
#include <iostream>
#include <vector>
#include <cmath>

// indexed tree 작성하는 데 평균 1시간 정도... 생각하고 연습하면 된다고 한다.
class IndexedTree {
private:
    std::vector<int> tree, nums;
    int leafSize, depth;
public:
    int getLeafSize() {
        return leafSize;
    }
    IndexedTree(std::vector<int>& nums) {
        this->nums = nums;
        depth = 0;
        while(int(pow(2.0, double(depth))) < nums.size() - 1) {
        // 실제로 사용하는 게 첫 번째 index(0번지) 부터이기 때문에 ! 1빼줌
            ++ depth;
        }
        leafSize = int(pow(2.0, double(depth)));
        tree.resize(int(pow(2.0, double(depth+1))));
    }

    int makeTree(int node, int left, int right) {
        // 1. leaf에 도달하게 되면 하는 일
        if(left == right) {
            if(left <= nums.size()) {
                return tree[node] = nums[left];
            } else {
                return tree[node] = 0;
            }
        }

        // 2. 그러지 않은 경우
        int mid = (left + right) / 2;
        tree[node] = makeTree(node * 2, left, mid);
        tree[node] += makeTree(node * 2 + 1, mid + 1, right);
        return tree[node];
    }

    int query() {
        return 0;
    }

    void printTree() {
        std::cout << "Tree: ";
        for(auto i:tree) {
            std::cout << i << ' ';
        } std::cout << std::endl;
        std::cout << "Nums: ";
        for(auto i:nums) {
            std::cout << i << ' ';
        } std::cout << std::endl;
        std::cout << "leafSize: " << leafSize << std::endl << \
                "depth: " << depth << std::endl;
    }
};

int main() {
    std::vector<int> inputs{0, 3, 2, 4, 5, 1, 6, 2, 7};

    IndexedTree it(inputs);
    it.printTree();
    it.makeTree(1, 1, it.getLeafSize());
    it.printTree();

    return 0;
}