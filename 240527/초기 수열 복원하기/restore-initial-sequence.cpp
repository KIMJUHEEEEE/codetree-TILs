#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    int sum[1000]={0,};
    for(int i=0;i<n-1;i++)
    {
        cin>>sum[i];
    }
   
    for(int a=1;a<=n;a++)
    {
        int tmp[1001]={0,};
        int tmpa=a;
        int cnt=0;
        bool ck[1001]={0,};
        for(int i=0;i<n;i++)
        {
            tmp[i]=tmpa;
            ck[tmpa]=1;
            tmpa=sum[i]-tmp[i];
            if(tmp[i]==tmpa||tmpa==0||ck[tmpa]==1) break;
            cnt++;
        }
        if(cnt==n)
        {
            for(int i=0;i<n;i++)
            {
                cout<<tmp[i]<<' ';
            }
            break;
        }
    }
    return 0;
}