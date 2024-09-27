#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long n,k;
    cin>>n>>k;
    unordered_map<long long, long long> ma;
    for(int i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        if(ma.find(a)==ma.end())
        {
            ma.insert({a,1});
        }   
        else ma[a]++;
    }
    int ans=0;
    for(int i=0;i<=k/2;i++)
    {
        int a=ma[i];
        int b=ma[k-i];
        ans+=a*b;
    }
    cout<<ans;
    return 0;
}