#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int cnt=1;
    int si=0;
    int ei=-1;
    if(m==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=v.size()-1;i>=0;i--)
    {       
        if(v[i]==v[i-1])
        {
            cnt+=1;
            si=i-1;
            if(ei==-1) ei=i+1;
        }
        else
        {
            if(cnt>=m)
            {
                v.erase(v.begin()+si,v.begin()+ei);
                i=si+1;
            }
            cnt=1;
            si=0;
            ei=-1;
        }
    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}