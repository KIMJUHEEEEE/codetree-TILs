#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[11];
    for(int i=0;i<11;i++)
    {
        arr[i]=-1;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {  
        int a,b;
        cin>>a>>b;
        if(arr[a]==-1)
        {
            arr[a]=b;
        }
        else
        {
            if(b!=arr[a])
            {
                ans++;
                arr[a]=b;
            }
        }

    }
    cout<<ans;
    return 0;
}