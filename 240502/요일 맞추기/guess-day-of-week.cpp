#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int m1, m2, d1, d2;
    string week[7] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
    int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    cin >> m1 >> d1 >> m2 >> d2;
    int sum = 0;
    if(m1==m2)
    {
        sum=m2-m1;
        if(sum<0){
            sum=sum*(-1);
            sum=7-sum%7;
        }
    }   
    else if(m1<m2)
    {
        sum+=date[m1]-d1-1;
        sum+=d2-1;
        for(int i=m1+1;i<m2;i++)
        {
            sum+=date[i];
            if(i==m2-1) sum--;
        }
        sum=sum%7;
    }
    else{
        sum+=d1;
        sum+=date[m2]-d2;
        for(int i=m2+1;i<m1;i++)
        {
            sum+=date[i];
        }
        sum=7-sum%7;
    }
    cout<<week[sum];
}