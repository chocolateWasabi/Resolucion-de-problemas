// page replacement algorithm과 유사
#include <iostream>
using namespace std;

int n, r, student[101][2];
int album[21][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r;
    for(int i=0, stu;i<r;++i) {
        cin >> stu;
        student[stu][0] ++;

        // checking process

    }

    return 0;
}