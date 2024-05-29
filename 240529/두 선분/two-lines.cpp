#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x4>>x4;
    if(x1<=x3)
    {
        if(x3<=x2)
        {
            cout<<"intersecting";
        }
        else
        {
            cout<<"nonintersecting";
        }
    }
    else if(x1>x3)
    {
        if(x1<=x4)
        {
            cout<<"intersecting";
        }
        else
        {
            cout<<"nonintersecting";
        }
    }
    return 0;
}