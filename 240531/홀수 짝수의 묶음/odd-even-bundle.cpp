#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    int hol=0;
    int jjak=0;
    int sum[1000]={0,};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0) jjak++;
        else hol++;
    }
    if(hol==jjak)
    {
        cout<<n;
    }
    else if(jjak==0)
    {
        if(hol%5==0) cout<<hol/5*2;
        else cout<<hol/5*2+1;
    }
    else if(hol>jjak)
    {
        int sum=0;
        int tmp=hol-jjak;
        if(tmp%3==0) sum=jjak*2+tmp/3*2;
        else if(tmp%3==1) sum=hol+(hol-jjak+1)*2;
        else sum=jjak+hol/2;
        cout<<sum;
    }
    else if(jjak>hol)
    {
        if((jjak-hol)%2==1) cout<<hol*2;
        else cout<<hol*2+1;
    }
    else if(hol==0||hol==2)
    {
        cout<<1;
    }
    return 0;
}