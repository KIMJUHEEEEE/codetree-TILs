#include <iostream>
#include <climits>
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
    int minarea=INT_MAX;
    for(int i=0;i<n;i++)
    {     int maxx=INT_MIN;
          int maxy=INT_MIN;
          int minx=INT_MAX;
          int miny=INT_MAX;
        for(int j=0;j<n;j++)
        {
          if(i!=j)
          {
            if(arrx[j]<minx) minx=arrx[j];
            if(arry[j]<miny) miny=arry[j];
            if(arrx[j]>maxx) maxx=arrx[j];
            if(arry[j]>maxy) maxy=arry[j];
          }
        }
        int area=(maxx-minx)*(maxy-miny);
        if(area<minarea) minarea=area;
    }
    cout<<minarea;
    return 0;
}