#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    stack <int> s;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="push")
        {
            int a;
            cin>>a;
            s.push(a);
        }
        else if(str=="size")
        {
            cout<<s.size()<<endl;
        }
        else if(str=="empty")
        {
            if(s.size()==0) cout<<1<<endl;
            else cout<<0<<endl;        
        }
        else if(str=="pop")
        {
            cout<<s.top()<<endl;
            s.pop();
        }
        else if(str=="top")
        {
            cout<<s.top()<<endl;
        }
    }
    return 0;
}