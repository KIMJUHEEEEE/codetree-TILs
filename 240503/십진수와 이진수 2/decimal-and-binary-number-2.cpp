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
    num=num*17;
    int newarr[101]={0,};
    int cnt=0;
    while(num>=1)
    {
        newarr[cnt]=num%2;
        num/=2;
        if(num==0) break;
        cnt++;
    }
    for(int i=cnt;i>=0;i--)
    {
        cout<<newarr[i];
    }
    return 0;
}