#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<int,int> ma;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(ma.find(a)==ma.end())
        {
            ma.insert({a,1});
        }
        else
        {
            ma[a]+=1;
        }
    }
    for(int j=0;j<m;j++)
    {
        int b;
        cin>>b;
        cout<<ma[b]<<' ';
    }
    return 0;
}