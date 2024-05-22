#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,b;
    cin>>n>>b;
    int arra[1001]={0,};
    int arrb[1001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arra[i]>>arrb[i];
    }
    int max=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arra[i]>arra[j])
            {
                int tmp=arra[i];
                arra[i]=arra[j];
                arra[j]=tmp;
                tmp=arrb[i];
                arrb[i]=arrb[j];
                arrb[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(i==j) {
                sum+=arra[i]/2+arrb[i];
                cnt++;
                if(sum>b) {cnt--; break;}
                continue;
            }
            int tmpsum=sum+arra[j]+arrb[j];
            cnt++;
            if(tmpsum>b) {
                cnt--;
            }
            else{
                sum+=arra[j]+arrb[j];
            }
        }
        if(max<cnt) max=cnt;
    }
    cout<<max;
    return 0;
}