// page replacement algorithm과 유사
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ipair;

int n, r;
vector<int> student;
vector<ipair> album; // (학생 번호, 앨범에 들어간 순서)
int albumCount;

bool inAlbum(int stu) {
    for(auto i:album) {
        if(i.first == stu) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r;
    student.resize(101);
    album.resize(n);
    for(auto &i:student) {
        i = 0;
    }
    albumCount = 0;
    for(auto &i:album) {
        i.first = -1;
        i.second = -1;
    }

    for(int i=0, stu;i<r;++i) {
        cin >> stu;
        student[stu] ++;

        if(!inAlbum(stu)) {
            // checking process
            if(albumCount < n) {
                album[albumCount].first = stu;
                album[albumCount].second = albumCount;
            } else {
                sort(album.begin(), album.end(), [](const ipair& left, const ipair& right) {
                    if(student[left.first] == student[right.first]) {
                        return left.second < right.second;
                    } else {
                        return student[left.first] < student[right.first];
                    }
                });
                student[album[0].first] = 0;
                album[0].first = stu;
                album[0].second = albumCount;
            }

            albumCount ++;
        }
    }

    sort(album.begin(), album.end());
    for(vector<ipair>::iterator i = album.begin(); i != album.end(); ++i) {
        if((*i).first == -1) {
            cout << 0;
        } else {
            cout << (*i).first;
        }
        cout << ' ';
    }

    return 0;
}