#include <iostream>
using namespace std;
int arra[100001];
int arrb[100001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int da=0;
    int db=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=0;j<b;j++)
        {
            arra[da]=arra[da-1]+a;
            da++;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=0;j<b;j++)
        {
            arrb[db]=arrb[db-1]+a;
            db++;
        }
    }
    int cnt=0;
    char ck='0';
    for(int i=1;i<100001;i++)
    {
        if(i>db||i>da) break;
        if(arra[i]>arrb[i])
        {
            if(ck=='0') ck='a';
            if(ck!='a')
            {
                cnt++;
                ck='a';
            }
        }
        else if(arrb[i]>arra[i])
        {
            if(ck=='0') ck='b';
            if(ck!='b')
            {
                cnt++;
                ck='b';
            }
        }
    }
    cout<<cnt;
    return 0;
}