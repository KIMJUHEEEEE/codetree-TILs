#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(abs(a-i)<=2||abs(b-j)<=2||abs(c-k)<=2)
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}