#include <iostream>
#include <string>
using namespace std;

class info{
    public:
    string code;
    char color;
    int time;
    info(string code, char color, int time){this->code=code; this->color=color;this->time=time;}
};

int main() {
    // 여기에 코드를 작성해주세요.
    string code;
    char color;
    int time;
    cin>>code>>color>>time;
    info inf(code,color,time);
    cout<<"code : "<<inf.code<<endl;
    cout<<"color : "<<inf.color<<endl;
    cout<<"second : "<<inf.time;
    return 0;
}