#include <iostream>
#include <string>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};//동남서북

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin>>str;
    int dir=3;
    int x=0;
    int y=0;
    int cnt=0;
    int ans=-1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='L')
        {
         cnt++;
         dir=(dir+4-1)%4;   
        }
        else if(str[i]=='R')
        {
            cnt++;
            dir=(dir+1)%4;
        }
        else{
            x+=dx[dir];
            y+=dy[dir];
            cnt++;
            if(x==0&&y==0)
            {
                ans=cnt;
                break;
            }
        }
        
    }
    cout<<ans;
    return 0;
}