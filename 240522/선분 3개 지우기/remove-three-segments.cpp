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
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int ck[101]={0,};
                bool ov=0;
                for(int l=0;l<n;l++)
                {
                    if(l==i||l==j||l==k) continue;
                    for(int a=arr[l][0];a<=arr[l][1];a++)
                    {
                        ck[a]++;
                        if(ck[a]>1) {ov=1;
                        break;}
                    }
                    if(ov==1) break;
                }
                if(ov==0) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}