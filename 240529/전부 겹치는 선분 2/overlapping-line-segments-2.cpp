#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++)
        {
            arr[j]++;
        }
    }
    for(int i=0;i<101;i++)
    {
        if(arr[i]==n-1) 
        {cout<<"Yes";
        return 0;}
    }
    cout<<"No";
    return 0;
}