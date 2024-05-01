#include <iostream>
#include <string>
using namespace std;

class product{
    public:
    string name;
    int code;
    product(string name, int code){this->name=name; this->code=code;}
};

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    int code;
    cin>>str>>code;
    product pd1("codetree",50);
    product pd2(str,code);
    cout<<"product "<<pd1.code<<" is "<<pd1.name<<endl;
    cout<<"product "<<pd2.code<<" is "<<pd2.name<<endl;
    return 0;
}