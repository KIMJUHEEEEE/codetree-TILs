#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin>>str;
    int arr[str.size()]={0,};
    int num=0;
    for(int i=0;i<str.size();i++)
    {
        arr[i]=int(str[i])-48;
        num=2*num+arr[i];
    }
    
    cout<<num;
    return 0;
}