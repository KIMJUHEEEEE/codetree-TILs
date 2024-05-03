#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[2001]={0,};
    int n=0;
    cin>>n;
    int dx=1000;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        if(b=='R')
        {
            for(int j=0;j<a;j++)
            {
                arr[dx+j]++;
            }
            dx=dx+a;
        }
        else
        {
            for(int j=0;j<a;j++)
            {
                arr[dx-j]++;
            }
            dx=dx-a;
        }
    }
    int cnt=0;
    for(int i=0;i<2001;i++)
    {
        if(arr[i]>=2) cnt++;
    }
    cout<<cnt;
    return 0;
}