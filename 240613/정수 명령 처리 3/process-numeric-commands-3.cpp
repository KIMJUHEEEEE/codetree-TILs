#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    deque<int> dq;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="push_back")
        {
            int a=0;
            cin>>a;
            dq.push_back(a);
        }
        else if(str=="push_front")
        {
            int a=0;
            cin>>a;
            dq.push_front(a);
        }
        else if(str=="pop_front")
        {
            cout<<dq.front()<<endl;
            dq.pop_front();
        }
        else if(str=="front")
        {
            cout<<dq.front()<<endl;
        }
        else if(str=="back")
        {
            cout<<dq.back()<<endl;
        }
        else if(str=="empty")
        {
            cout<<dq.empty()<<endl;
        }
        else if(str=="size")
        {
            cout<<dq.size()<<endl;
        }
        else if(str=="pop_back")
    {
        cout<<dq.back()<<endl;
        dq.pop_back();
    }
    }
    return 0;
}