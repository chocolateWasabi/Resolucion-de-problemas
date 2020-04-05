// DEQUE (Double Ended Queue) ADT - BOJ 10866
#include <iostream>
#include <string>
using namespace std;

class deque_inst {
private:
    deque_inst *prev, *next;
    int value;
public:
    void set_prev(deque_inst *prev){
        this->prev = prev;
    }
    void set_next(deque_inst *next){
        this->next = next;
    }
    void set_value(int value){
        this->value = value;
    }
    deque_inst* get_prev(){
        return prev;
    }
    deque_inst* get_next(){
        return next;
    }
    int get_value(){
        return value;
    }
};

class my_deque {
private:
    deque_inst *head, *tail;
    int size;
public:
    void push_back(int n){
        deque_inst *node = new deque_inst;
        node->set_value(n);
        node->set_next(tail);
        tail->get_prev()->set_next(node);
        node->set_prev(tail->get_prev());
        tail->set_prev(node);
        size ++;
    }
    void push_front(int n){
        deque_inst *node = new deque_inst;
        node->set_value(n);
        node->set_next(head->get_next());
        head->get_next()->set_prev(node);
        head->set_next(node);
        node->set_prev(head);
        size ++;
    }
    int get_front(){
        if(size)
            return head->get_next()->get_value();
        else return -1;
    }
    int get_back(){
        if(size)
            return tail->get_prev()->get_value();
        else return -1;
    }
    void pop_front(){
        if(size){
            deque_inst *node;
            node = head->get_next();
            node->get_next()->set_prev(head);
            head->set_next(node->get_next());
            delete node;
            size --;
        }
    }
    void pop_back(){
        if(size){
            deque_inst *node;
            node = tail->get_prev();
            node->get_prev()->set_next(tail);
            tail->set_prev(node->get_prev());
            delete node;
            size --;
        }
    }
    int get_size(){
        return size;
    }
    int empty(){
        return size? 0: 1;
    }

    my_deque(){
        size = 0;
        head = new deque_inst;
        tail = new deque_inst;
        head->set_next(tail);
        head->set_prev(nullptr);
        tail->set_next(nullptr);
        tail->set_prev(head);
    }
    ~my_deque(){
        while(size){
            pop_front();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string cmd;
    int value;
    my_deque *deq = new my_deque;
    for(;N>0;--N){
        cin >> cmd;
        // c++ 에서는 string switch 사용 불가

        if(cmd == "push_front"){
            cin >> value;
            deq->push_front(value);
        }
        else if(cmd == "push_back"){
            cin >> value;
            deq->push_back(value);
        }
        else if(cmd == "pop_front"){
            cout << deq->get_front() << '\n';
            deq->pop_front();
        }
        else if(cmd == "pop_back"){
            cout << deq->get_back() << '\n';
            deq->pop_back();
        }
        else if(cmd == "size"){
            cout << deq->get_size() << '\n';
        }
        else if(cmd == "empty"){
            cout << deq->empty() << '\n';
        }
        else if(cmd == "front"){
            cout << deq->get_front() << '\n';
        }
        else if(cmd == "back"){
            cout << deq->get_back() << '\n';
        }
        else { // error
        }
    }
    delete deq;
    return 0;
}