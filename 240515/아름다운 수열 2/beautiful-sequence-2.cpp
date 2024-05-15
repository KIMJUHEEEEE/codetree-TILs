#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arra[101]={0,};
    int arrb[101]={0,};
    //bool ck[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arra[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arrb[i];
    }
    int ans=0;
    for(int i=0;i<=n-m;i++)
    {
        bool ck[101]={0,};
        int cnt=0;
        for(int j=0;j<m;j++)
        { 
            if(arra[i]==arrb[j])
            {
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        
                        if(arra[i+k]==arrb[l]&&ck[l]==0)
                        {
                            cnt++;
                            ck[l]=1;
                        }
                    }
                }
                ck[101]={0,};
               
            }
        }
         if(cnt==m) ans++;
    }
    cout<<ans;
    return 0;
}