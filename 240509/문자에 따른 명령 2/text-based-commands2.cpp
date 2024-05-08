#include <iostream>
#include <string>
using namespace std;
int dx[4]={0,1,0,-1};//북동남서
int dy[4]={1,0,-1,0};

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin>>str;
    int x=0;
    int y=0;
    int d=0;//북
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='L')
        {
            d=(d+4-1)%4;
            
        }
        else if(str[i]=='R')
        {
            d=(d+1)%4;

        }
        else if(str[i]=='F')
        {
            x+=dx[d];
            y+=dy[d];
        }
    }
    cout<<x<<' '<<y;
    return 0;
}