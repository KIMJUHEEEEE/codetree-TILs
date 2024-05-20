#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arrx1[101]={0,};
    int arrx2[101]={0,};
    bool ck[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arrx1[i]>>arrx2[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
         if(arrx1[j]<arrx2[i]&&arrx1[j]>arrx1[i])
         {
            ck[j]=1;
            ck[i]=1;
         }
        }
    }
    int sum=0;
    for(int i=0;i<101;i++)
    {
        if(ck[i]==1) sum++;
    }
    cout<<n-sum;
    return 0;
}