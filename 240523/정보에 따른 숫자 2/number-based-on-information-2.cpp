#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int T,a,b;
    cin>>T>>a>>b;

    char arr[1001]={0,};
    for(int i=0;i<T;i++)
    {
        char c;
        int x;
        cin>>c>>x;
        arr[x]=c;
    }
    int ans=0;
    for(int i=a;i<=b;i++)
    {
        int d1=10000;
        int d2=10000;
        for(int j=0;j<1000;j++)
        {
            if(arr[i-j]=='S')
            {
                if(d1>abs(-j)) d1=abs(-j);
            }
            if(arr[i+j]=='S')
            {
                if(d1>j) d1=j;
            }
            if(arr[i-j]=='N')
            {
                if(d2>abs(-j)) d2=abs(-j);
            }
            if(arr[i+j]=='N')
            {
                if(d2>j) d2=j;
            }
            if(d1<1000&&d2<1000) break;
        }
        if(d1<=d2) 
        {
            ans++;
        }

    }
    cout<<ans;
    return 0;
}