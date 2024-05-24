#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[11][2]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=1;i<arr[0][1];i++)
    {
        int cnt=0;
        int tmp=i;
        for(int j=0;j<n;j++)
        {
            if(tmp*2>=arr[j][0]&&tmp*2<=arr[j][1])
            {
                cnt++;
                tmp*=2;
            }
        }
        if(cnt==n)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}