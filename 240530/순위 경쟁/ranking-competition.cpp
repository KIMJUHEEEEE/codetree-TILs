#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int cnta=0;
    int cntb=0;
    int cntc=0;
    int ans=0;
    int price=0;//0:a,b,c /1:a,b /2:a,c /3:b,c /4:a/5:b/6:c
    for(int i=0;i<n;i++)
    {
        char c;
        int a;
        cin>>c>>a;
        if(c=='A')
        {
            cnta+=a;
        }
        else if(c=='B')
        {
            cntb+=a;
        }
        else if(c=='C')
        {
            cntc+=a;
        }
        if(cnta==cntb&&cnta==cntc&&price!=0)
        {
            ans++; price=0;
        }
        else if(cnta==cntb&&cnta>cntc&&price!=1)
        {
            ans++;
            price=1;
        }
        else if(cnta==cntc&&cnta>cntb&&price!=2)
        {
            ans++;
            price=2;
        }
        else if(cntb==cntc&&cntb>cnta&&price!=3)
        {
            ans++;
            price=3;
        }
        else if(cnta>cntb&&cnta>cntc&&price!=4)
        {
            ans++;
            price=4;
        }
        else if(cntb>cnta&&cntb>cntc&&price!=5)
        {
            ans++;
            price=5;
        }
        else if(cntc>cnta&&cntc>cntb&&price!=6)
        {
            ans++;
            price=6;
        }
    }
    cout<<ans;
    return 0;
}