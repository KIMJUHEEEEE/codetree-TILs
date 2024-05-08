#include <iostream>
using namespace std;

int arr[101];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int a=0;
        cin>>a;
        arr[a]++;
        if(arr[a]>=k&&ans==0) {ans=a;}
    }
    if(ans==0) cout<<-1;
    else cout<<ans;
    return 0;
}