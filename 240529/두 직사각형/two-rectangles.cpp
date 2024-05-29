#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x1,y1,x2,y2;
    int a1,b1,a2,b2;
    cin>>x1>>y1>>x2>>y2;
    cin>>a1>>b1>>a2>>b2;
    if(a1<=x2&&a1>=x1)
    {
        if((b1<=y2&&b1>=y1)||(b2>=y1&&b2<=y2)||(b1<=y1&&b2>=y2)||y1<=b1&&y2>=b2) cout<<"overlapping";
        else cout<<"nonoverlapping";
    }
    else if(a2<=x2&&a2>=x1)
    {
        if((b1<=y2&&b1>=y1)||(b2>=y1&&b2<=y2)||(b1<=y1&&b2>=y2)||(y1<=b1&&y2>=b2)) cout<<"overlapping";
        else cout<<"nonoverlapping";
    }
    else cout<<"nonoverlapping";
    return 0;
}