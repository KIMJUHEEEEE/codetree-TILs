#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            s.push('(');
        }
        else if(str[i]==')')
        {
            if(s.empty()==true) 
            {
                cout<<"No";
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty()==true)
        cout<<"Yes";
    else cout<<"No";
    return 0;
}