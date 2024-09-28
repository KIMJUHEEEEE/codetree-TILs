#include <iostream>
#include <map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    map<string,int> ma;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(ma.find(str)==ma.end()) ma.insert({str,1});
        else ma[str]++;
    }
    map<string,int>::iterator it;
    for(it=ma.begin();it!=ma.end();it++)
    {
        cout<<(it->first)<<' '<<(it->second)<<endl;
    }
    return 0;
}