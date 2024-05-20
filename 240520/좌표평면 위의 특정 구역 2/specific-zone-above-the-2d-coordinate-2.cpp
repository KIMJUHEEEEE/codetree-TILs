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
    {  
        for(int j=0;j<n;j++)
        {
          int maxx=INT_MIN;
          int maxy=INT_MIN;
          int minx=INT_MAX;
          int miny=INT_MAX;
          if(i!=j)
          {
            if(arrx[i]<minx) minx=arrx[i];
            if(arry[i]<miny) miny=arry[i];
            if(arrx[i]>maxx) maxx=arrx[i];
            if(arry[i]>maxy) maxy=arry[i];
            cout<<minx<<' '<<maxx<<' '<<miny<<' '<<maxy<<endl;
            int area=(maxx-minx)*(maxy-miny);
            if(area<minarea) minarea=area;
          }
        }
    }
    cout<<minarea;
    return 0;
}