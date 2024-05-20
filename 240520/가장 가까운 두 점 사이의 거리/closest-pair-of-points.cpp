#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int arrx[101]={0,};
    int arry[101]={0,};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arrx[i]>>arry[i];
    }
    int min=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int dis=abs(arrx[i]-arrx[j])*abs(arrx[i]-arrx[j])+abs(arry[i]-arry[j])*abs(arry[i]-arry[j]);
            if(dis<min) min=dis;
        }
    }
    cout<<min;
    return 0;
}