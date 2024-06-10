#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int maxsize=0;
    vector<string> arr;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr.push_back(s);
        maxsize=max(maxsize,(int)s.size());
    }
    int cnt=0;
    while(1)
    {
        if(cnt==maxsize)
        {
            break;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if (arr[i][arr[i].size()-1-cnt]>arr[j][arr[j].size()-1-cnt])
                {
                    string tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        cnt++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}