#include <iostream>
#include <map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="add")
        {
            int a, b;
            cin>>a>>b;
            if(m.find(a)==m.end())
                m.insert({a,b});
            else m[a]=b;
        }
        else if(str=="find")
        {
            int a;
            cin>>a;
            if(m.find(a)==m.end()) cout<<"None"<<endl;
            else cout<<m[a]<<endl;;
        }
        else if(str=="print_list")
        {
            map<int,int>::iterator it;
            if (m.size() == 0) cout << "None" << endl;
            else{
            for(it=m.begin();it!=m.end();it++)
            {
                cout<<(it->second)<<' ';
            }
            cout<<endl;
            }
        }
        else
        {
            int a;
            cin>>a;
            m.erase(a);
        }
    }
    return 0;
}