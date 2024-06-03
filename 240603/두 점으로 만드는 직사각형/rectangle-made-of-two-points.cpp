#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x1,x2,y1,y2,a1,a2,b1,b2;
    cin>>x1>>y1>>x2>>y2;
    cin>>a1>>b1>>a2>>b2;
    int minx1=min(x1,a1);
    int miny1=min(y1,b1);
    int maxx1=max(x2,a2);
    int maxy1=max(y2,b2);
    cout<<(maxx1-minx1)*(maxy1-miny1);
    return 0;
}