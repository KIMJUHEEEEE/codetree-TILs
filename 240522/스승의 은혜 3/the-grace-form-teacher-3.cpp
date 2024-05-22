#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,b;
    cin>>n>>b;
    int arr[1001][2]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(i==j) {
                sum+=arr[i][0]/2+arr[i][1];
                cnt++;
                if(sum>b) cnt--;
                continue;
            }
            int tmpsum=sum+arr[j][0]+arr[j][1];
            cnt++;
            if(tmpsum>b) {
                cnt--;
            }
            else{
                sum+=arr[j][0]+arr[j][1];
            }
        }
        if(max<cnt) max=cnt;
    }
    cout<<max;
    return 0;
}