// 심심해서 직접 짜 보는 트리
// 이런거 코딩하면 뭔가 기분이 좋아짐
// 괜히 내가 코딩 잘 하는거 같잖아 ?!
#include <iostream>
using namespace std;

const int alphabetSize = int('Z'-'A')+1;

class tree_inst {
private:
    tree_inst *l_child, *r_child;
    char value;
public:
    tree_inst* getLeftChild() {
        return l_child;
    }
    tree_inst* getRightChild() {
        return r_child;
    }
    char getValue() {
        return value;
    }
    void setLeftChild(tree_inst* leftNode) {
        l_child = leftNode;
    }
    void setRightChild(tree_inst* rightNode) {
        r_child = rightNode;
    }
    void setValue(char value) {
        this->value = value;
    }
};

class tree {
private:
    tree_inst* root;
    int size;
    tree_inst* findPosition(char value);
    tree_inst* alphabetTree[alphabetSize];
    void setIndex(tree_inst *treeNode);
    void traverseProcess(tree_inst *node, int type);
public:
    void preOrderTraversal() {
        if(root != nullptr) {
            traverseProcess(root, 1);
            cout << '\n';
        } else {
            cout << "No root";
            exit(1);
        }
    }
    void inOrderTraversal() {
        if(root != nullptr) {
            traverseProcess(root, 2);
            cout << '\n';
        } else {
            cout << "No root";
            exit(1);
        }
    }
    void postOrderTraversal() {
        if(root != nullptr) {
            traverseProcess(root, 3);
            cout << '\n';
        } else {
            cout << "No root";
            exit(1);
        }
    }
    void addNode(char myself, char left, char right);
    tree() {
        root = nullptr;
        size = 0;
        for(int i=0;i<alphabetSize;++i) {
            alphabetTree[i] = nullptr;
        }
    }
};

void tree::traverseProcess(tree_inst *node, int type) {
    tree_inst *l_child, *r_child;
    l_child = node->getLeftChild();
    r_child = node->getRightChild();
    if(type == 1) { // preorder
        cout << node->getValue();
    }
    if(l_child != nullptr) { // traverse left
        traverseProcess(node->getLeftChild(), type);
    }
    if(type == 2) { // inorder
        cout << node->getValue();
    }
    if(r_child != nullptr) { // traverse right
        traverseProcess(node->getRightChild(), type);
    }
    if(type == 3) { // postorder
        cout << node->getValue();
    }
}

tree_inst* tree::findPosition(char value) {
    return alphabetTree[int(value-'A')];
}

void tree::setIndex(tree_inst *treePosition) {
    alphabetTree[int(treePosition->getValue()-'A')] = treePosition;
}

void tree::addNode(char value, char left, char right) {
    ++ size;
    tree_inst *position = findPosition(value);

    if(position == nullptr) {
        root = new tree_inst;
        root->setValue(value);
        position = root;
        setIndex(root);
    }

    if(left == '.') {
        position->setLeftChild(nullptr);
    } else {
        tree_inst *l_child = findPosition(left);
        if(l_child == nullptr) {
            l_child = new tree_inst;
            l_child->setValue(left);
            l_child->setLeftChild(nullptr); // no problem
            l_child->setRightChild(nullptr); // no problem
            position->setLeftChild(l_child);
            setIndex(l_child);
        }
        position->setLeftChild(l_child);
    }

    if(right == '.') {
        position->setRightChild(nullptr);
    } else {
        tree_inst *r_child = findPosition(right);
        if(r_child == nullptr) {
            r_child = new tree_inst;
            r_child->setValue(right);
            r_child->setLeftChild(nullptr); // no problem
            r_child->setRightChild(nullptr); // no problem
            setIndex(r_child);
        }
        position->setRightChild(r_child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char parent, left, child;
    tree alphabet;
    for(;n>0;--n) {
        cin >> parent >> left >> child;
        alphabet.addNode(parent, left, child);
    }

    int test = 3;

    alphabet.preOrderTraversal();
    alphabet.inOrderTraversal();
    alphabet.postOrderTraversal();
    return 0;
}