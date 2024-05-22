#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x,y;
    cin>>x>>y;
    int ans=0;
    for(int i=x;i<=y;i++)
    {
        int arr[11]={0,};
        int tmp=i;
        int size=0;
        while(tmp>0)
        {
            size++;
            arr[tmp%10]++;
            tmp/=10;
        }
        int cnt=0;
        bool a=0;
        bool b=0;
        for(int j=0;j<11;j++)
        {
            if(arr[j]!=0)
            {
                if(arr[j]==1){
                    if(a==0)
                    {
                        a=1;
                        cnt++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(arr[j]>1)
                {
                    if(b==0)
                    {
                        b=1;
                        cnt+=arr[j];
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(cnt==size&&a==1&&b==1) ans++;
    }
    cout<<ans;
    return 0;
}