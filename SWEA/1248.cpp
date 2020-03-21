// SWEA 1248 공통조상 문제 (D5)
#include <iostream>
//#include <fstream>
#include <vector>
using namespace std;

class tree_node {
private:
    tree_node *parent, *l_child, *r_child;
    int value;
public:
    tree_node* get_parent(){
        return parent;
    }
    tree_node* get_l_child(){
        return l_child;
    }
    tree_node* get_r_child(){
        return r_child;
    }
    tree_node(int value){
        this->value = value;
    }
    void set_parent(tree_node* parent){
        this->parent = parent;
    }
    void set_l_child(tree_node* l_child){
        this->l_child = l_child;
    }
    void set_r_child(tree_node* r_child){
        this->r_child = r_child;
    }
    int get_value(){
        return value;
    }
};
//ifstream fin;

class common_ancestor {
private:
    tree_node* vertex[10010]; // 각 정점의 메모리 위치 정보
    tree_node* root;
    int v, e, t1, t2;
    int subtree_size;
    int trial;
    void make_tree(int parent, int child);
    void traverse_tree(tree_node* node);
    void get_subtree_size(tree_node* node);
    void ca_main();
public:
    common_ancestor(int trial){
        this->trial = trial;    
        root = new tree_node(1);
        root->set_parent(root);
        root->set_l_child(nullptr);
        root->set_r_child(nullptr);
        vertex[1] = root;
        subtree_size = 0;
        ca_main();
    }
    ~common_ancestor(){ // 트리 정보 모두 삭제
        for(int i=1;i<=v;++i){
            delete vertex[i];
        }
    }
};

void common_ancestor::make_tree(int parent, int child){
    if(vertex[parent] == nullptr){
        tree_node* tmp = new tree_node(parent);
        tmp->set_parent(nullptr);

        if(vertex[child] == nullptr){ // P(X) C(X)
            tree_node* tmp2 = new tree_node(child);
            tmp2->set_parent(tmp);
            tmp2->set_l_child(nullptr);
            tmp2->set_r_child(nullptr);

            tmp->set_l_child(tmp2);
            vertex[child] = tmp2;
        }
        else { // P(X) C(O)
            tmp->set_l_child(vertex[child]);
            vertex[child]->set_parent(tmp);
        }

        // 공통 작업
        tmp->set_r_child(nullptr);
        vertex[parent] = tmp;
    }
    else {
        if(vertex[child] == nullptr){ // P(O) C(X)
            tree_node* tmp2 = new tree_node(child);
            tmp2->set_parent(vertex[parent]);
            tmp2->set_l_child(nullptr);
            tmp2->set_r_child(nullptr);
            vertex[child] = tmp2;

            // 부모와 연결
            if(vertex[parent]->get_l_child() == nullptr){
                vertex[parent]->set_l_child(tmp2);
            }
            else {
                vertex[parent]->set_r_child(tmp2);
            }
        }
        else { // P(O) C(O) : 둘 다 존재하는데 아직 연결이 안 된 경우, C subtree를 P에 연결하는 작업.
            if(vertex[parent]->get_l_child() == nullptr){
                vertex[parent]->set_l_child(vertex[child]);
            }
            else {
                vertex[parent]->set_r_child(vertex[child]);
            }
            vertex[child]->set_parent(vertex[parent]);
        }
    }
}

void common_ancestor::traverse_tree(tree_node* node){
    // 메모리 접근에 주의해서 출력
    cout << "node:" << node->get_value();
    if(node->get_l_child() != nullptr){
        cout << " l_child:" << node->get_l_child()->get_value();
    }
    else {
        cout << " l_child:nullptr";
    }
    if(node->get_r_child() != nullptr){
        cout << " r_child:" << node->get_r_child()->get_value();
    }
    else {
        cout << " r_child:nullptr" ;
    }
    if(node->get_parent() != nullptr){
        cout << " parent:" << node->get_parent()->get_value();
    }
    else {
        cout << " parent:nullptr";
    }
    cout << '\n';

    // 순회
    if(node->get_l_child() != nullptr){
        traverse_tree(node->get_l_child());
    }
    if(node->get_r_child() != nullptr){
        traverse_tree(node->get_r_child());
    }
}

void common_ancestor::get_subtree_size(tree_node* node){
    subtree_size ++;
    if(node->get_l_child() != nullptr){
        get_subtree_size(node->get_l_child());
    }
    if(node->get_r_child() != nullptr){
        get_subtree_size(node->get_r_child());
    }
}

void common_ancestor::ca_main(){
    cin >> v >> e >> t1 >> t2;
    //fin >> v >> e >> t1 >> t2;
    for(int i=2;i<=v;++i){
        vertex[i] = nullptr;
    }
    for(int i=1, parent, child;i<=e;++i){

        cin >> parent >> child;
        //fin >> parent >> child;
        make_tree(parent, child);
    }
    // traverse_tree(root);
    vector<int> ancestors;
    for(auto i=vertex[t1]->get_parent();i->get_value() != 1;i=i->get_parent()){
        ancestors.push_back(i->get_value());
    }
    // ancestors.push_back(1);
    bool find_flag = false;
    int where_common = 1;
    for(auto i=vertex[t2]->get_parent();i->get_value() != 1 && !find_flag;i=i->get_parent()){
        for(auto j:ancestors){
            if(j == i->get_value()){
                find_flag = true;
                where_common = j;
                break;
            }
        }
    }

    // get size of subtree
    get_subtree_size(vertex[where_common]);
    cout << '#' << trial << ' ' << where_common << ' ' << subtree_size << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifstream fin;
    //fin.open("C:/inputt.txt");
    int T;
    cin >> T;
    //if(fin.is_open()){
        //fin >> T;
        for(int t=1;t<=T;++t){
            common_ancestor *get_common = new common_ancestor(t);
            delete get_common;
        }
        //fin.close();

        // cout << "opened";

        // delete[] 는 배열 없앨 때
        // delete 는 그냥 원소 하나 없앨 때. delete 써야할 때 delete[] 쓰면 런타임 에러 발생.
    /*}
    else {
        cout << "file error\n";
    }*/
    return 0;
}