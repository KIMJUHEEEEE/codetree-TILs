#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    char arr[16][16]={0,};
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    int x=0;
    int y=0;
    char st;
    int cnt=0;
    if(st==arr[r-1][c-1]) {cout<<0; return 0;}
    for(int i=x+1;i<r-2;i++)
    {
        for(int j=y+1;j<c-2;j++)
        {
            st=arr[0][0];
            if(st!=arr[i][j])
            {
                st=arr[i][j];
                for(int a=i+1;a<r-1;a++)
                {
                    for(int b=j+1;b<c-1;b++)
                    {
                        if(st!=arr[a][b]&&arr[a][b]!=arr[r-1][c-1])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}