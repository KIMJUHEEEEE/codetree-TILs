#include <iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101][101]={0,};
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int r,c;
        cin>>r>>c;
        arr[r][c]=1;
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            if(arr[r+dx[i]][c+dy[i]]==1)
            {
                cnt++;
            }
        }
        if(cnt==3)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}