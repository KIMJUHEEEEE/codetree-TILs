#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int time=0;
    time+=(c-a)*60;
    time+=(d-b);
    cout<<time;
    return 0;
}