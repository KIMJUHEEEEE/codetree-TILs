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
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                int tmp=arr[j];
                arr[j]= arr[min];
                arr[min]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}