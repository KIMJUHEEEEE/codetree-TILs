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
        int a=0;
        cin>>a;
        v.push_back(a);
    }
    
    int cnt=1;
    int si=-1;
    int ei=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==v[i+1])
        {
            cnt++;
            if(si==-1) si=i;
            ei=i+2;
        }
        else
        {
            if(cnt>=m)
            {
                v.erase(v.begin()+si,v.begin()+ei);
                i=-1;
            }
            cnt=1;
            si=-1;
            ei=0;
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}