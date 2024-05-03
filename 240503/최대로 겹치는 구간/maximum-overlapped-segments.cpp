#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[201]={0,};
    for(int i=0;i<n;i++)
    {
        int x1,x2;
        cin>>x1>>x2;
        for(int j=x1;j<x2;j++)
        {
            arr[j+100]++;
        }
    }
    int cnt=0;
    for(int i=0;i<201;i++)
    {
        if(cnt<arr[i])
            {
                cnt=arr[i];
            }
    }
    cout<<cnt;
    return 0;
}