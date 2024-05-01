#include <iostream>
using namespace std;

int mul(int n)
{
    if(n<10) return n*n;
    return mul(n/10)+(n%10)*(n%10);
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<mul(n);
    
    return 0;
}