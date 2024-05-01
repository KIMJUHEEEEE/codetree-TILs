#include <iostream>
#include <string>
using namespace std;

class info{
    public:
    string id;
    int level;
    info(){this->id="codetree"; this->level=10;}
    info(string id, int level){this->id=id; this->level=level;}

};

int main() {
    // 여기에 코드를 작성해주세요.
    info user1;
    string id;
    int level;
    cin>>id>>level;
    info user2(id, level);
    cout<<"user "<<user1.id<<" lv "<<user1.level<<endl;
    cout<<"user "<<user2.id<<" lv "<<user2.level<<endl;
    return 0;
}