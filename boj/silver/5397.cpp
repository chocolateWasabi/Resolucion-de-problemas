// boj id 5397
// password decode using doubly linked list
#include <iostream>
#include <string>
using namespace std;

class DLL { // Doubly Linked List
public:
    DLL *left, *right;
    char c;
    DLL() {
        this->left = this->right = nullptr;
        this->c = '.';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string pw;

    cin >> n;
    for(;n;--n) {
        cin >> pw;
        DLL *dec_h = new DLL;
        DLL *dec_t = new DLL;
        dec_h->right = dec_t;
        dec_t->left = dec_h;

        DLL *cursor = dec_h;
        for(const auto& i: pw) {
            if(i == '<') {
                if(cursor->left != nullptr) {
                    cursor = cursor->left;
                }
            } else if(i == '>') {
                if(cursor->right != dec_t) {
                    cursor = cursor->right;
                }
            } else if(i == '-') {
                if(cursor != dec_h && cursor != dec_t) {
                    DLL *tmp = cursor;
                    
                    cursor->left->right = cursor->right;
                    cursor->right->left = cursor->left;
                    cursor = cursor->left;

                    delete tmp;
                }
            } else {
                DLL *new_c = new DLL;
                new_c->c = i;
                new_c->left = cursor;
                new_c->right = cursor->right;
                cursor->right->left = new_c;
                cursor->right = new_c;
                cursor = cursor->right;
            }
        }

        for(DLL *it = dec_h->right; it != dec_t; it = it->right) {
            cout << it->c;
        }
        cout << '\n';

        delete dec_h, dec_t;
    }
    return 0;
}