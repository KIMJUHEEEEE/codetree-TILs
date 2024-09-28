#include <iostream>
#include <map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    map<int,int> ma;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(ma.find(a)==ma.end()) ma.insert({a,i+1});
    }
    map<int,int>::iterator it;
    for(it=ma.begin();it!=ma.end();it++)
    {
        cout<<(it->first)<<' '<<(it->second)<<endl;
    }
    return 0;
}