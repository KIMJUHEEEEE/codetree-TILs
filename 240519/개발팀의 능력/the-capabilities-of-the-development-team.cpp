#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[5]={0,};
    int sum=0;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int min=INT_MAX;
    for(int i=0;i<5;i++)
    {
        int c=arr[i];
        int teammax=c;
        int teammin=c;
        for(int j=0;j<4;j++)
        {
            if(i==j) continue;
            for(int k=j+1;k<5;k++)
            {
                if(i==k) continue;
                int tmp=arr[j]+arr[k];
                int tmpsum=sum-c-tmp;
                if(teammax<tmp) teammax=tmp;
                if(teammax<tmpsum) teammax=tmpsum;
                if(teammin>tmp) teammin=tmp;
                if(teammin>tmpsum) teammin=tmpsum;
                if(c!=tmp&&tmp!=tmpsum&&c!=tmpsum)
                {
                    
                    if(min>teammax-teammin) min=teammax-teammin;
                }
            }
        }
    }
    if(min==INT_MAX) min=-1;
    cout<<min;
    return 0;
}