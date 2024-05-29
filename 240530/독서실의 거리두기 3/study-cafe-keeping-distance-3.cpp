#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    string str;
    cin>>n;
    cin>>str;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string tmp=str;
        if(tmp[i]=='0')
        {
            tmp[i]='1';
            int mini=1000;
            for(int j=0;j<n-1;j++)
            {
                int dis=0;
                if(tmp[j]=='1')
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(tmp[k]=='1')
                        {
                            dis=k-j;
                            break;
                        }
                    }
                    mini=min(mini,dis);
                }
            }
            ans=max(ans,mini);
        }
    }
    cout<<ans;
    return 0;
}