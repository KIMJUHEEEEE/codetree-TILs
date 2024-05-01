#include <iostream>
using namespace std;

void star(int n)
{
    if(n==0) return;
    star(n-1);
    for(int i=0;i<n;i++)
    {
        cout<<"*";
    }
    cout<<endl;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    star(n);
    return 0;
}