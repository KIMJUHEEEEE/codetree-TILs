#include <iostream>
#include <string>
using namespace std;

class code{
public:
string cd;
char point;
int time;
code(string cd, char point, int time){this->cd=cd; this->point=point; this->time=time;}
};

int main() {
    // 여기에 코드를 작성해주세요.
    string cdd="";
    char point=' ';
    int time=0;
    cin>>cdd>>point>>time;
    code cd(cdd,point,time);
    cout<<"secret code : "<<cd.cd<<endl;
    cout<<"meeting point : "<<cd.point<<endl;
    cout<<"time : "<<cd.time;

    return 0;
}