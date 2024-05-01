#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0,k=0;
    string str="";
    cin>>n>>k>>str;
    string words[101]={"",};
    int idx=0;
    for(int i=0;i<n;i++)
    {
        string str1="";
        cin>>str1;
        int cnt=0;
        for(int j=0;j<str.size();j++)
        {
            if(str[j]!=str1[j]) break;
            else cnt++;
        }
        if(cnt==str.size()) {words[idx]=str1;
        idx++;
        }
    }
    sort(words,words+idx);
    cout<<words[k-1];


    return 0;
}