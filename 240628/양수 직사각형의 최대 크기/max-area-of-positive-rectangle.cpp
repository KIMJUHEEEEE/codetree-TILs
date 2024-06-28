#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[21][21]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int y=0;y<n-i;y++)
            {
                for(int x=0;x<m-j;x++)
                {
                    int a=y;
                    int b=x;
                    bool check=1;
                    for(int c=0;c<=a;c++)
                    {
                        for(int d=0;d<=b;d++)
                        {
                            if(arr[i+c][j+d]<=0)
                            {
                                check=0;
                                break;
                            }
                        }
                        if(check==0) break;
                    }
                    if(check==1)
                    {
                        ans=max(ans,(a+1)*(b+1));
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}