#include <iostream>
using namespace std;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};//동남북서

int dir(char d)
{
    if(d=='U') return 2;
    else if(d=='d') return 1;
    else if(d=='R') return 0;
    else return 3;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,t;
    cin>>n>>t;
    int r,c;//초기 위치 x=r,y=c;
    char d;
    cin>>r>>c>>d;
    int dd=dir(d);
    for(int i=0;i<t;i++)
    {
        if(r+dx[dd]==0||c+dy[dd]==0||r+dx[dd]==n||c+dy[dd]==n)
        {
            dd=3-dd;
        }
        else
        {
            r+=dx[dd];
            c+=dy[dd];
        }
    }
    cout<<r<<' '<<c;
    
    return 0;
}