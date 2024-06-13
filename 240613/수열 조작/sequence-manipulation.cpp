#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    deque<int> dq;
    for(int i=1;i<=n;i++)
    {
        dq.push_back(i);
    }
    while(dq.size()!=1)
    {
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<dq.front();
    return 0;
}