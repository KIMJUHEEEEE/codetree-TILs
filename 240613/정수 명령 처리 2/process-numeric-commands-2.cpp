#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="push")
        {
            int a=0;
            cin>>a;
            q.push(a);
        }
        else if(str=="front")
        {
            cout<<q.front()<<endl;
        }
        else if(str=="size")
        {
            cout<<q.size()<<endl;
        }
        else if(str=="empty")
        {
            cout<<q.empty()<<endl;
        }
        else if(str=="pop")
        {
            cout<<q.front()<<endl;
            q.pop();
        }
    }
    return 0;
}