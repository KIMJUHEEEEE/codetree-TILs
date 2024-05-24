#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    string str;
    cin>>str;
    int max=0;
    for(int i=0;i<n-1;i++)
    {
        int cnt=0;
        for(int j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
            {
                
                while(str[i+cnt]==str[j+cnt])
                {
                    cnt++;
                }
            }
            if(max<cnt) max=cnt;
        }
    }
    cout<<max+1;
    return 0;
}