#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map <int,int> m;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="add")
            {int a,b;
            cin>>a>>b;
            if(m.find(a)==m.end())
                m.insert({a,b});
            else
            {
                m[a]=b;
            }
            }
            else if(str=="remove"){
            int k;
            cin>>k;
            m.erase(k);
            }
            else if(str=="find"){
            int a;
            cin>>a;
            if(m.find(a)==m.end()) cout<<"None"<<endl;
            else cout<<m[a]<<endl;
            }
    }
    return 0;
}