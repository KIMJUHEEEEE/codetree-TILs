#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<string,string> ma;
    unordered_map<string,string> sa;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        ma.insert({str,to_string(i)});
        sa.insert({to_string(i),str});
    }
    for(int j=0;j<m;j++)
    {
        string str;
        cin>>str;
        if(ma.find(str)!=ma.end()) cout<<ma[str]<<endl;
        else cout<<sa[str]<<endl;
    }
    return 0;
}