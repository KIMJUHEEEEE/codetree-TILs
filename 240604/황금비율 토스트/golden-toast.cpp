#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    list<char> l;
    for(int i=0;i<n;i++)
    {
        l.push_back(str[i]);
    }
    list<char>::iterator it;
    it=l.end();
    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        if(c=='L'){
            if(it!=l.begin())
            {
                it--;
            }
        }
        else if(c=='R'){
            if(it!=l.end())
            {
                it++;
            }
        }
        else if(c=='P')
        {
            char a;
            cin>>a;
            l.insert(it,a);
        }
        else if(c=='D')
        {
            if(it!=l.end())
            {it=l.erase(it);}

        }
    }
    for(it =l.begin();it!=l.end();it++)
    {
        cout<<*it;
    }
    return 0;
}