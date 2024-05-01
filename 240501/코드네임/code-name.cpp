#include <iostream>
using namespace std;

class person{
    public:
    char codename;
    int score;
};

int main() {
    // 여기에 코드를 작성해주세요.
    person p[5];
    int min=100;
    int idx=0;

    for(int i=0;i<5;i++)
    {
        char codename=' ';
        int score=0;
        cin>>codename>>score;
        p[i].codename=codename;
        p[i].score=score;
        if(min>score) {
            min=score;
            idx=i;
        }
    }
    cout<<p[idx].codename<<' '<<p[idx].score;
    return 0;
}