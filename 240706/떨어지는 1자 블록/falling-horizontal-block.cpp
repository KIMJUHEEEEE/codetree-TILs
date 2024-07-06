#include <iostream>
using namespace std;
int n,m,k;
int arr[101][101]={0,};

void movedown()
{
    int idx=0;
    while(1)
    {bool ck=0;
    if(idx==n-1) break;
    for(int i=k-1;i<k-1+m;i++)
    {
        if(arr[idx+1][i]==1)
        {  
            ck=1;
        }
    }
    if(ck==0)
    {
        for(int j=k-1;j<k-1+m;j++)
        {
            arr[idx+1][j]=1;
            arr[idx][j]=0;
        }
        idx++;
    }
    else break;
    }
}
int main() {
    // 여기에 코드를 작성해주세요.

    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int j=k-1;j<k-1+m;j++)
    {
        arr[0][j]=1;
    }
    movedown();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}