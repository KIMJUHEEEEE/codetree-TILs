#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    char arr[20001]={' ',};
    cin>>n;
    int dx=10000;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        if(b=='R')
        {
            for(int j=0;j<a;j++){
                arr[dx+j]='b';
        }
        dx+=a-1;
        }
        else if(b=='L'){
            for(int j=0;j<a;j++)
            {
                arr[dx-j]='w';
            }
            dx=dx-a+1;
        }
    }
    int w=0;
    int b=0;
    for(int i=0;i<20001;i++)
    {
        if(arr[i]=='b') b++;
        else if(arr[i]=='w') w++;
    }
    cout<<w<<' '<<b;
    return 0;
}