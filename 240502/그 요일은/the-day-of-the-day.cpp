#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    string week[7] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
    string str;
    cin>>str;
    int idx=0;
    for(int i=0;i<7;i++)
    {
        if(week[i]==str)
        {
            idx=i;
            break;
        }
    }
    int date[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    if(m1==m2)
    {
        sum+=d2-d1;
    }
    else
    {
    sum += date[m1] - d1;
    sum += d2;
    for (int i = m1 + 1; i < m2; i++)
    {
    sum += date[i];
    }
    }
    int ans=sum/7;
    if(sum%7>=idx) ans++;
    cout<<ans;
    return 0;
}