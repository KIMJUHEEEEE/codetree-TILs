#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    char arr[10][10]={0,};
    int lx=0;
    int ly=0;
    int bx=0;
    int by=0;
    int rx=0;
    int ry=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='B')
            {
                bx=j;
                by=i;
            }
            if(arr[i][j]=='L')
            {
                lx=j;ly=i;
            }
            if(arr[i][j]=='R')
            {
                rx=j;
                ry=i;
            }
        }
    }
    if((ry==by&&ry==ly&&rx<bx&&rx>lx)||(rx==bx&&rx==lx&&ry>ly&&ry<by)||(ry==by&&ry==ly&&rx>bx&&rx<lx)||(rx==bx&&rx==lx&&ry<ly&&ry>by))
    {
        cout<<abs(lx-bx)+abs(ly-by)+1;
    }
    else cout<<abs(lx-bx)+abs(ly-by)-1;
    return 0;
}