#include <iostream>
using namespace std;

int num(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    return n+num(n-2);
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<num(n);
    return 0;
}