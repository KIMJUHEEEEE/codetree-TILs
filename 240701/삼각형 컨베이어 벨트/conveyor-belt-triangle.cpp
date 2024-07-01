#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,t;
    cin>>n>>t;
    int arr[3][201]={0,};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    while(t>0)
    {
        int tmp0=arr[0][n-1];
        int tmp1=arr[1][n-1];
        int tmp2=arr[2][n-1];
        for(int i=n-1;i>0;i--)
        {
            arr[0][i]=arr[0][i-1];
            arr[1][i]=arr[1][i-1];
            arr[2][i]=arr[2][i-1];
        }
        arr[0][0]=tmp2;
        arr[1][0]=tmp0;
        arr[2][0]=tmp1;
        t--;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<' ';
        }

        cout<<endl;
    }
    return 0;
}