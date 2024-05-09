#include <iostream>
using namespace std;
int arr[2001][2001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};//동남서북

int dir(char d)
{
    if(d=='N') return 3;
    else if(d=='E') return 0;
    else if(d=='W') return 2;
    else return 1;

}

int main() {
    int n;
    cin>>n;
    int x=1000;
    int y=1000;
    int cnt=0;
    bool ck=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char d;
        int a;
        cin>>d>>a;
        int dd=dir(d);
        for(int j=0;j<a;j++)
        {
            x+=dx[dd];
            y+=dy[dd];
            cnt++;
            if(x==1000&&y==1000&&ck==0) 
            {ck=1; 
            ans=cnt;
            }
        }
    }
    if(ck==1) cout<<ans;
    else cout<<-1;
    // 여기에 코드를 작성해주세요.
    return 0;
}