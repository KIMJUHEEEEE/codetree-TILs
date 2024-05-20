#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    int arra[1001]={0,};
    int arrb[1001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arra[i]>>arrb[i];
        for(int j=arra[i];j<arrb[i];j++)
        {
            arr[j]++;
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        int time=0;
        for(int j=arra[i];j<arrb[i];j++)
        {
            arr[j]--;
        }
        for(int k=0;k<1001;k++)
        {
                if(arr[k]>0) time++;
        }
        if(time>max) max=time;
        for(int j=arra[i];j<arrb[i];j++)
        {
            arr[j]++;
        }
    }
    cout<<max;
    return 0;
}