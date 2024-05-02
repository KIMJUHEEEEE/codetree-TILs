#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int m1,m2,d1,d2;
    string week[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    int date[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    cin>>m1>>d1>>m2>>d2;
    int sum=0;
    if(m1==m2)
    {
        sum+=d2-d1;
    }
    else
    {
        sum+=date[m1]-d1;
        sum+=d2;
        for(int i=m1+1;i<m2;i++)
        {
            sum+=date[i];
        }
    }
    string ans;
    if(sum<0)
    {
        sum*=(-1);
        sum=7-sum%7;
        ans=week[sum];
    }
    else ans=week[sum%7];
    cout<<ans;
    return 0;
}