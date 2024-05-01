#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    string str[101]={"",};
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    sort(str,str+n);
    for(int i=0;i<n;i++)
    {
        cout<<str[i]<<endl;
    }
    return 0;
}