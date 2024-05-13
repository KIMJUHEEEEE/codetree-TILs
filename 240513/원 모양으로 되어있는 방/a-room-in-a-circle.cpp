#include <iostream>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1005]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int min=999999999;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        int cnt=1;
        for(int j=i+1;j<n;j++)
        {
            sum+=arr[j]*cnt;
            cnt++;
        }
        if(cnt<n)
        {
            for(int j=0;j<i;j++)
            {
                sum+=arr[j]*cnt;
                cnt++;
            }
        }
        if(min>sum) min=sum;
    }
    cout<<min;
    return 0;   
}