#include <iostream>
using namespace std;
int arr[101][101];
int top=1;
int front=2;
int ri=3;
int n,m,r,c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m>>r>>c;
    int x=c-1;
    int y=r-1;
    arr[y][x]=6;
    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        if(c=='L')
        {
            x=x-1;
            y=y;
            if(x<0||y<0||x>=n||y>=n)
            {
                x=x+1;
                y=y;
                continue;
            }
            arr[y][x]=7-ri;
            int tmp=top;
            top=ri;
            front=front;
            ri=7-tmp;
        }
        else if(c=='R')
        {
            x=x+1;
            y=y;
            if(x<0||y<0||x>=n||y>=n)
            {
                x=x-1;
                y=y;
                continue;
            }
            arr[y][x]=ri;
            int tmp=top;
            top=7-ri;
            front=front;
            ri=tmp;
        }
        else if(c=='D')
        {
            x=x;
            y=y+1;
            if(x<0||y<0||x>=n||y>=n)
            {
                x=x;
                y=y-1;
                continue;
            }
            arr[y][x]=front;
            int tmp=top;
            top=7-front;
            front=tmp;
        }
        else if(c=='U')
        {
            x=x;
            y=y-1;
            if(x<0||y<0||x>=n||y>=n)
            {
                x=x;
                y=y+1;
                continue;
            }
            arr[y][x]=7-front;
            int tmp=top;
            top=front;
            front=7-tmp;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans+=arr[i][j];
        }
    }
    cout<<ans;
    return 0;
}