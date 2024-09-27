#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long n,k;
    cin>>n>>k;
    unordered_map<long long, long long> ma;
    unordered_map<long long, long long> ord;
    for(int i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        ord.insert({i,a});
        if(ma.find(a)==ma.end())
        {
            ma.insert({a,1});
        }   
        else ma[a]++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ma.find(ord[i])!=ma.end()&&ma.find(k-ord[i])!=ma.end())
        {
            if(ord[i]==k-ord[i]) ans+=(ma[ord[i]]*(ma[ord[i]]-1))/2;
            else
                ans+=ma[ord[i]]*ma[k-ord[i]];
            ma.erase(ord[i]);
            ma.erase(k-ord[i]);
        }
    }
    cout<<ans;
    return 0;
}