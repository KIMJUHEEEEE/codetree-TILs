#include <iostream>
using namespace std;

int main() {
    int arr[20][20]={0,};
    // 여기에 코드를 작성해주세요.
    int ans=0;
    int x=0;
    int y=0;
    for(int i=1;i<20;i++)
{
    for(int j=1;j<20;j++)
    {
        cin>>arr[i][j];
    }
}
bool ck=0;
for(int i=1;i<20;i++)
{
    for(int j=1;j<20;j++)
    {
        if(arr[i][j]==1)
        {
            int cnt1=0;
            int cnt2=0;
            int cnt3=0;
            int cnt4=0;
            for(int k=0;k<5;k++)
            {
                if(arr[i][j+k]==1&&j+k<20)
                {
                    cnt1++;
                }
                if(arr[i+k][j]==1&&i+k<20)
                {
                    cnt2++;
                }
                if(arr[i+k][j+k]==1&&i+k<20&&j+k<20)
                {
                    cnt3++;
                }
                if(arr[i+k][j-k]==1&&i+k<20&&j-k>=0)
                {
                    cnt4++;
                }
            }
            if(cnt1==5) {
                ans=1;
                x=i;
                y=j+2;
                ck=1;
                break;
            }
            else if(cnt2==5) {
                ans=1;
                x=i+2;
                y=j;
                ck=1;
                break;
            }
            else if(cnt3==5)
            {
                ans=1;
                x=i+2;
                y=j+2;
                ck=1;
                break;
            }
            else if(cnt4==5)
            {
                ans=1;
                x=i+2;
                y=i-2;
                ck=1;
                break;
            }
        }
        else if(arr[i][j]==2)
        {
            int cnt1=0;
            int cnt2=0;
            int cnt3=0;
            int cnt4=0;
            for(int k=0;k<5;k++)
            {
                if(arr[i][j+k]==2&&j+k<20)
                {
                    cnt1++;
                }
                if(arr[i+k][j]==2&&i+k<20)
                {
                    cnt2++;
                }
                if(arr[i+k][j+k]==2&&i+k<20&&j+k<20)
                {
                    cnt3++;
                }
                if(i+k<20&&j-k>=0&&arr[i+k][j-k]==2)
                {
                    cnt4++;
                }
            }
            if(cnt1==5) {
                ans=2;
                x=i;
                y=j+2;
                ck=1;
                break;
            }
            else if(cnt2==5) {
                ans=2;
                x=i+2;
                y=j;
                ck=1;
                break;
            }
            else if(cnt3==5)
            {
                ans=2;
                x=i+2;
                y=j+2;
                ck=1;
                break;
            }
            else if(cnt4==5)
            {
                ans=2;
                x=i+2;
                y=i-2;
                ck=1;
                break;
            }
        }
    }
    if(ck==1) break;
}
if(ck==0) ans=0;
cout<<ans<<endl;
if(ans!=0)
{
    cout<<x<<' '<<y;
}
    return 0;
}