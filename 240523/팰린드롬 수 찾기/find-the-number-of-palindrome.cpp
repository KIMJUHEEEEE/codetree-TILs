#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x,y;
    cin>>x>>y;
    int ans=0;
    for(int i=x;i<=y;i++)
    {
        int tmp=i;
        vector<int> v;
        while(tmp>0)
        {
            v.push_back(tmp%10);
            tmp/=10;
        }

            int cnt=0;
            for(int a=0;a<v.size()/2;a++)
            {
                if(v[a]!=v[v.size()-a-1]) break;
                cnt++;
            }
            if(cnt==v.size()/2)
            {
                ans++;
            }
        
    }
    cout<<ans;
    return 0;
}