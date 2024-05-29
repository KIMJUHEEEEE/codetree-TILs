#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arra[101]={0,};
    int arrb[101]={0,};
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for(int i=0;i<n;i++)
    {
        cin>>arra[i]>>arrb[i];
        if((arra[i]==1&&arrb[i]==2)||(arra[i]==2&&arrb[i]==3)||(arra[i]==3&&arrb[i]==1)) cnt1++;
        if((arra[i]==1&&arrb[i]==3)||(arra[i]==3&&arrb[i]==2)||(arra[i]==2&&arrb[i]==1)) cnt2++;
        if((arra[i]==3&&arrb[i]==2)||(arra[i]==2&&arrb[i]==1)||(arra[i]==1&&arrb[i]==3)) cnt3++;
    }
    int maxi=max(cnt1,cnt2);
    cout<<max(maxi,cnt3);
    return 0;
}