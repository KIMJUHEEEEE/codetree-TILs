#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    list<int> l;
    for(int i=0;i<n;i++)
    {
        string str;
        int a;
        cin>>str;
        if(str=="push_back")
        {
            cin>>a;
            l.push_back(a);
        }
        else if(str=="push_front")
        {
            cin>>a;
            l.push_front(a);
        }
        else if(str=="pop_front")
        {
            cout<<l.front()<<endl;
            l.pop_front();
        }
        else if(str=="pop_back")
        {
            cout<<l.back()<<endl;
            l.pop_back();
        }
        else if(str=="front")
        {
            cout<<l.front()<<endl;
        }
        else if(str=="back")
        {
            cout<<l.back()<<endl;
        }
        else if(str=="size")
        {
            cout<<l.size()<<endl;
        }
        else if(str=="empty")
        {
            cout<<l.empty()<<endl;
        }
    }
    return 0;
}