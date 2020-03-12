// Queue
#include <iostream>
#include <string>
using namespace std;

class que_inst { // queue instance
private:
    int value;
    que_inst* next_node;
public:
    // setting
    void set_next_node(que_inst *next){
        this->next_node = next;
    }
    void set_dat(int dat){
        this->value = dat;
    }
    
    // getting
    que_inst* get_next_node(){
        return next_node;
    }
    int get_dat(){
        return value;
    }

    // generator (initial setting)
    que_inst(int dat, que_inst* prev){
        if(prev != nullptr){
            prev->set_next_node(this);
        }
        set_dat(dat);
        this->set_next_node(nullptr);
    }
};

class que { // queue control
private:
    que_inst *head;
    que_inst *rear, *front;
    int size;
public:
    que(){
        size = 0;
        head = new que_inst(-1, nullptr);
        rear = front = head;
    }
    void push(int param){
        que_inst *tmp;
        if(is_empty()){        
            tmp = new que_inst(param, front);
        }
        else{
            tmp = new que_inst(param, rear);
        }
        rear = tmp;
        size ++;
    }
    int pop(){
        if(is_empty()){
            return -1;
        }
        else{
            que_inst *tmp2;
            if(front != head){
                tmp2 = front;
            }

            front = front->get_next_node();
            head->set_next_node(front);
            
            size --;
            
            if(front != head){
                delete[] tmp2;
            }
            return front->get_dat();
        }
    }
    int get_size(){
        return size;
    }
    int is_empty(){
        return (rear == front)? 1: 0;
    }
    int get_front(){
        if(this->is_empty()){
            return -1;
        }
        else {
            return front->get_next_node()->get_dat();
        }
    }
    int get_back(){
        if(this->is_empty()){
            return -1;
        }
        else {
            return rear->get_dat();
        }
    }
};

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    string cmd;
    int param;

    que myque;
    cin >> n;
    for(;n>0;--n){
        cin >> cmd;
        if(cmd == "push"){
            cin >> param;
            myque.push(param);
        }
        else if(cmd == "pop"){
            cout << myque.pop() << '\n';
        }
        else if(cmd == "size"){
            cout << myque.get_size() << '\n';
        }
        else if(cmd == "empty"){
            cout << myque.is_empty() << '\n';
        }
        else if(cmd == "front"){
            cout << myque.get_front() << '\n';
        }
        else if(cmd == "back"){
            cout << myque.get_back() << '\n';
        }
        else{ // error
        }
    }
    return 0;
}