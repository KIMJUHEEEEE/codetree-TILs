#include <iostream>
#include <vector>
using namespace std;
int arr[11][11];
int n,m,c;
int ans;
int a[5];
int max_v;
void maxsum(int idx, int weight, int val)
{
    if(idx==m)
    {
        if(weight<=c) max_v=max(max_v,val);
        return;
    }
    maxsum(idx+1,weight,val);
    maxsum(idx+1,weight+a[idx],val+a[idx]*a[idx]);
}
int findmax(int x, int y)
{
    for(int i=x;i<=x+m-1;i++)
    {
        a[i-x]=arr[y][i];
    }
    max_v=0;
    maxsum(0,0,0);
    return max_v;
}

bool possible(int x1, int y1, int x2,int y2)
{
    if(x1+m-1>=n||x2+m-1>=n) return false;
    if(y1!=y2) return true;
    if(y1==y2&&x2>=x1&&x2<x1+m-1) return false;
    if(y1==y2&&x1>=x2&&x1<x2+m-1) return false;
    return true;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m>>c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int y1=0;y1<n;y1++)
    {
        for(int x1=0;x1<n;x1++)
        {
            for(int y2=0;y2<n;y2++)
            {
                for(int x2=0;x2<n;x2++)
                {
                    if(possible(x1,y1,x2,y2))
                    {
                        ans=max(ans,findmax(x1,y1)+findmax(x2,y2));
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}