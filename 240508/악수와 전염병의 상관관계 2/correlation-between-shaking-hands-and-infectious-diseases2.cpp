#include <iostream>
using namespace std;
int arr[260][2];
bool sick[101];
int cnt[101];

int main() {
    // 여기에 코드를 작성해주세요.
    int N,K,P,T;
    int t,x,y;
    cin>>N>>K>>P>>T;
    sick[P]=1;
    cnt[P]=K;
    for(int i=0;i<T;i++)
    {
        
        cin>>t>>x>>y;
        arr[t][0]=x;
        arr[t][1]=y;
    }
    for(int i=1;i<=t;i++)
    {
        if(sick[arr[i][0]]==1)
        {
            if(cnt[arr[i][0]]==0) continue;
            cnt[arr[i][0]]--;
            if(sick[arr[i][1]]==0)
            {
                sick[arr[i][1]]=1;
                cnt[arr[i][1]]=K;
            }            
        }
        else if(sick[arr[i][1]]==1)
        {
            if(cnt[arr[i][1]]==0) continue;
            cnt[arr[i][1]]--;
            if(sick[arr[i][0]]==0)
            {
                sick[arr[i][0]]=1;
                cnt[arr[i][0]]=K;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        cout<<sick[i];
    }
    return 0;
}