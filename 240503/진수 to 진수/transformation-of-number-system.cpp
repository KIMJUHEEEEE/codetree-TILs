#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    int a,b;
    cin>>a>>b;
    cin>>str;
    int arr[101]={0,};
    int num=0;
    for(int i=0;i<str.size();i++)
    {
        arr[i]=int(str[i])-48;
        num=a*num+arr[i];
    }
    int newarr[101]={0,};
    int cnt=0;
    while(num>=1)
    {
        newarr[cnt]=num%b;
        num/=b;
        if(num==0) break;
        cnt++;
    }
    for(int i=cnt;i>=0;i--)
    {
        cout<<newarr[i];
    }
    return 0;
}