#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[11][11]={0,};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]++;
        arr[b][a]++;
    }
    int max=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(max<arr[i][j])
            {
                max=arr[i][j];
            }
        }
    }
    cout<<max;
    return 0;
}