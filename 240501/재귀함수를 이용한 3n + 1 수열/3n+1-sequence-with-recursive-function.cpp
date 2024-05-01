#include <iostream>
using namespace std;

int f(int n,int cnt){
    if(n==1) return cnt;
    if(n%2==0) n/=2;
    else {
        n=n*3+1;
    }
    return f(n,cnt+1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<f(n,0);
    return 0;
}