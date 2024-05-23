#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c;
    cin>>a>>b>>c;

    int max=0;
    for(int i=0;i<1000;i++)
    {
        int sum=a*i;
        if(sum>c) break;
        for(int j=0;j<1000;j++)
        {
            sum+=b*j;
            if(sum>c) break;
            if(sum<=c&&max<sum)
            {
                max=sum;
            }
        }
    }
    cout<<max;
    return 0;
}