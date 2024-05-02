#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c;
    cin>>a>>b>>c;
    int sum=0;
    sum+=(a-11)*24*60;
    sum+=(b-11)*60;
    sum+=(c-11);
    if(sum<0) sum=-1;
    cout<<sum;
    return 0;
}