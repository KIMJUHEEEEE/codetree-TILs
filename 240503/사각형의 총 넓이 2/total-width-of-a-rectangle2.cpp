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
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<x2;j++)
        {
            for(int z=y1;z<y2;z++)
            {
                if(arr[j][z]==0) cnt++;
                arr[j][z]=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}