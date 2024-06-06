#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)
    {
        int idx=i;
        
        for(int j=i-1;j>=0;j--)
        {
            int key=arr[idx];
            if(key<arr[j])
            {
                int tmp=arr[j];
                arr[j]=arr[idx];
                arr[idx]=tmp;
                idx=j;
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}