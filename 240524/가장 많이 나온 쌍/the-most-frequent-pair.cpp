#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arra[11]={0,};
    int arrb[11]={0,};
    for(int i=0;i<m;i++)
    {
        cin>>arra[i]>>arrb[i];
    }
    int max=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        { int cnt=0;
            for(int k=0;k<m;k++)
            {
                if(arra[k]==i&&arrb[k]==j) cnt++;
                else if(arra[k]==j&&arrb[k]==i) cnt++;
            }
            if(max<cnt) max=cnt;
        }
    }
    cout<<max;
    return 0;
}