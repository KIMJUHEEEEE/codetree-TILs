#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    int date[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    sum+=date[m1]-d1;
    sum+=d2;
    for(int i=m1+1;i<m2;i++)
    {
        sum+=date[i];
    }
    cout<<sum+1;
    return 0;
}