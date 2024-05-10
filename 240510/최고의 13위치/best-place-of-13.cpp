#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[21][21]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n-2;j++)
        {int cnt=0;
            for(int k=j;k<j+3;k++)
            {
                if(arr[i][k]==1) cnt++;
            }
            if(max<cnt) max=cnt;
        }
    }
    cout<<max;
    return 0;
}