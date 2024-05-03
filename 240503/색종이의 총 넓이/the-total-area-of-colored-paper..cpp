#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[201][201]={0,};
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x1,y1;
        cin>>x1>>y1;
        x1+=100;
        y1+=100;
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<8;k++)
            {
                if(arr[x1+j][y1+k]==0) cnt++;
                arr[x1+j][y1+k]=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}