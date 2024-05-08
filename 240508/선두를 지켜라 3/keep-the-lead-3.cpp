#include <iostream>
using namespace std;
int arra[1000001];
int arrb[1000001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m,v,t;
    cin>>n>>m;
    char ck='0';
    int sa=0;
    int sb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v>>t;
        for(int j=0;j<t;j++)
        {
            sa++;
            arra[sa]=arra[sa-1]+v;
        }

    }
    for(int i=1;i<=m;i++)
    {
        cin>>v>>t;
        for(int j=0;j<t;j++)
        {
            sb++;
            arrb[sb]=arrb[sb-1]+v;
        }

    }
    int ans=1;
    for(int i=1;i<=sb;i++)
    {
        if(arra[i]>arrb[i])
        {
            if(ck=='0')
            {
                ck='a';
            }
            else if(ck!='a')
            {
                ans++;
                ck='a';
            }
        }
        else if(arra[i]==arrb[i])
        {
            if(ck=='0') ck='2';
            else if(ck!='2')
            {
                ans++;
                ck='2';
            }
        }
        else{
            if(ck=='0') ck='b';
            else if(ck!='b')
            {
                ans++;
                ck='b';
            }
        }
        
    }
    if(ck=='0') ans=0;
    cout<<ans;
    return 0;
}