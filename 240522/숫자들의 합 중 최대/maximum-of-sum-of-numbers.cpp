#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x,y;
    cin>>x>>y;
    int max=0;
    for(int i=x;i<=y;i++)
    {
        int tmp=i;
        int sum=0;
        while(tmp>0)
        {
            sum+=tmp%10;
            tmp/=10;
        }
        if(max<sum) max=sum;
    }
    cout<<max;
    return 0;
}