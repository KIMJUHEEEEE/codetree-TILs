#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101][2]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    int ans=9999999;
    for(int i=2;i<100;i=i+2)
    { 
        for(int j=2;j<100;j=j+2)
        {
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int max=0;
            for(int k=0;k<n;k++)
            {
                if(arr[k][0]<i&&arr[k][1]<j) a++;
                else if(arr[k][0]<i&&arr[k][1]>j) b++;
                else if(arr[k][0]>i&&arr[k][1]<j) c++;
                else if(arr[k][0]>i&&arr[k][1]>j) d++;
            }
            if(max<a) max=a;
            if(max<b) max=b;
            if(max<c) max=c;
            if(max<d) max=d;
            if(max<ans) ans=max;
        }
    }
    cout<<ans;
    return 0;
}