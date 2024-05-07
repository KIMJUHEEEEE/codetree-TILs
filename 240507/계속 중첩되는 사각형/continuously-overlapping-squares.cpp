#include <iostream>
using namespace std;
int arr[201][201];
int main() {
    // 여기에 코드를 작성해주세요.
    bool now=0;//빨강 0 파랑 1
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1, x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1+100;x<x2+100;x++)
        {
            for(int y=y1+100;y<y2+100;y++)
            {
                if(now==0)
                {
                    arr[x][y]=1;
                }
                else
                {
                    arr[x][y]=2;//파랑
                }
            }
        }
        if(now==0) now=1;
        else now=0;
    }
    int cnt=0;
    for(int i=0;i<201;i++)
    {
        for(int j=0;j<201;j++)
        {
            if(arr[i][j]==2) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}