#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    string str;
    cin>>str;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int mini=0;
        string tmp=str;
        if(tmp[i]=='0')
        {
            tmp[i]='1';
            mini=9999;
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
                            mini=min(mini,dis);
                            //cout<<tmp<<' '<<i<<' '<<mini<<endl;
                            break;
                        }
                    }
                }
            }
        }
        ans=max(ans,mini);
    }
    cout<<ans;
    return 0;
}