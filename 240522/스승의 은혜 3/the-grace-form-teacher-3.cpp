#include <iostream>
#include <algorithm>
using namespace std;

class present{
    public:
    int price;
    int deli;
};
bool cmp(present a, present b)
{
    if(a.price==b.price)
    {
        return a.deli<b.deli;
    }
    return a.price<b.price;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n,b;
    cin>>n>>b;
    present p[1001];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        p[i].price=a;
        p[i].deli=b;
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        present tmp[1001];
        for(int j=0;j<n;j++)
        {
            tmp[j]=p[j];
        }
        tmp[i].price/=2;
        sort(tmp,tmp+n,cmp);
        int sum=0;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            int tmpsum=sum+tmp[j].price+tmp[j].deli;
            cnt++;
            if(tmpsum>b)
            {
                cnt--;
                break;
            }
            else
            {
                sum+=tmp[j].price+tmp[j].deli;
            }
        }
        if(max<cnt) max=cnt;
    }
    cout<<max;
    return 0;
}