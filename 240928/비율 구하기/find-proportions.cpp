#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(m.find(str)==m.end())
        {
            m.insert({str,1});
        }
        else m[str]++;
    }
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<fixed;
        cout.precision(4);
        cout<<(it->first)<<' '<<(double)(it->second)/(double)n*100<<endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}