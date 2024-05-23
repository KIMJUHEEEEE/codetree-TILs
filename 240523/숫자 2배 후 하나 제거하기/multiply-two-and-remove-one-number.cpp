#include <iostream>
#include <vector>
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
    int min=10000;
    for(int i=0;i<n;i++)
    {
        arr[i]*=2;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            else
            {
                vector<int> v;
                for(int k=0;k<n;k++)
                {
                    if(k!=j) v.push_back(arr[k]);
                }

                for(int k=0;k<v.size()-1;k++)
                {
                    sum=sum+abs(v[k+1]-v[k]);
                }
            }
        if(min>sum) min=sum;
        }
        arr[i]/=2;
    }
    cout<<min;
    return 0;
}