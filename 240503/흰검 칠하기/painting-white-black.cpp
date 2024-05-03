#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int white[20001]={0,};
    int black[20001]={0,};
    char now[20001]={0,};
    int n=0;
    cin>>n;
    int dx=10000;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        if(b=='R')
        {
            for(int j=0;j<a;j++)
            {
                white[dx+j]++;
                now[dx+j]='b';
            }
            dx=dx+a-1;
        }
        else
        {
            for(int j=0;j<a;j++)
            {
                black[dx-j]++;
                now[dx-j]='w';
            }
            dx=dx-a+1;
        }
    }
    int gray=0;
    int bb=0;
    int ww=0;
    for(int i=0;i<20001;i++)
    {
        if(white[i]>=2&&black[i]>=2)
        {
            gray++;
            now[i]='g';
        }
        else
        {
            if(now[i]=='b') bb++;
            else if(now[i]=='w') ww++;
        }
    }
    cout<<ww<<' '<<bb<<' '<<gray;
    return 0;
}