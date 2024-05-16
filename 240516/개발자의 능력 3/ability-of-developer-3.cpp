#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[6]={0,};
    int sum=0;
    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int min= INT_MAX;
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            for(int k=j+1;k<6;k++)
            {
                int teama=arr[i]+arr[j]+arr[k];
                int teamb=sum-teama;
                if(min>abs(teama-teamb)) min=abs(teama-teamb);
            }
        }
    }
    cout<<min;
    return 0;
}