#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<string,int> m;
    int n;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(m.find(str)==m.end())
        {
            m.insert({str,1});
        }
        else
        {
            m[str]++;
            ans=max(ans,m[str]);
        }
    }
    cout<<ans;
    return 0;
}