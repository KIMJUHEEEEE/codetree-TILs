#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    int cnt[101]={0,};
    int mini=9999;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
        mini=min(arr[i],mini);
    }
    int value=0;
    for(int i=mini+1;i<101;i++)
    {
        if(cnt[i]==1)
        {
            value=i;
            break;
        }
        else if(cnt[i]>1)
        {
            cout<<-1;
            return 0;
        }
    }
    if(value==0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(value==arr[i])
        {
            cout<<i+1;
        }
    }
    return 0;
}