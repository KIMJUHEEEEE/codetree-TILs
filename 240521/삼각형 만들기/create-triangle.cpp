#include <iostream>
#include<climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arrx[101]={0,};
    int arry[101]={0,};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arrx[i]>>arry[i];
    } 
    int max=INT_MIN;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int area=0;
                if(arrx[i]==arrx[j])
                {
                    if(arry[i]==arry[k])
                    {
                        area=abs(arry[i]-arry[j])*abs(arrx[i]-arrx[k]);
                    }
                    else if(arry[j]==arry[k])
                    {
                        area=abs(arry[i]-arry[j])*abs(arrx[j]-arrx[k]);
                    }
                }
                else if(arrx[j]==arrx[k])
                {
                    if(arry[i]==arry[k])
                    {
                        area=abs(arry[k]-arry[j])*abs(arrx[i]-arrx[k]);
                    }
                    else if(arry[j]==arry[i])
                    {
                        area=abs(arry[k]-arry[j])*abs(arrx[j]-arrx[i]);
                    }
                }
                else if(arrx[k]==arrx[i])
                {
                    if(arry[j]==arry[k])
                    {
                        area=abs(arry[i]-arry[k])*abs(arrx[j]-arrx[k]);
                    }
                    else if(arry[i]==arry[j])
                    {
                        area=abs(arry[i]-arry[k])*abs(arrx[j]-arrx[i]);
                    }
                }
                if(area>max) max=area;
            }
        }
    }
    cout<<max;
    return 0;
}