#include <iostream>
using namespace std;

void n1(int n)
{
    if(n==0) return;
    n1(n-1);
    cout<<n<<" ";
}
void n2(int n)
{
    if(n==0) return;
    cout<<n<<" ";
    n2(n-1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    n1(n);
    cout<<endl;
    n2(n);
    return 0;
}