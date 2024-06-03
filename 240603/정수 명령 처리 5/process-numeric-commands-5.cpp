#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        string str;
        int a;
        cin>>str;
        if(str=="push_back") {cin>>a; v.push_back(a);}
        else if(str=="get") { cin>>a; cout<<v[a-1]<<endl;}
        else if(str=="size") cout<<v.size()<<endl;
        else if(str=="pop_back") v.pop_back();
    }
    return 0;
}