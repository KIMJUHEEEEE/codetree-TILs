#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class person{
public:
int n;
int cheese;
int time;
};

bool cmp(person a, person b)
{
    return a.n<b.n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m,d,s;
    cin>>n>>m>>d>>s;
    person pe[10001];
    for(int i=0;i<d;i++)
    {
        int p,mm,t;
        cin>>p>>mm>>t;
        pe[i].n=p;
        pe[i].cheese=mm;
        pe[i].time=t;
    }
    sort(pe,pe+d,cmp);
    bool ckch[101]={0,};
    int sick[101]={0,};
    for(int i=0;i<s;i++)
    {
        int p,t;
        cin>>p>>t;
        sick[p]=t;
    }
    for(int i=0;i<d;i++)
    {
        if(sick[pe[i].n]!=0)
        {
            if(pe[i].time<sick[pe[i].n])
            {ckch[pe[i].cheese]=1;}
        }
    }
    for(int i=1;i<=m;i++)
    {
        int cnt=0;
        for(int j=0;j<d;j++)
        {
            
            if(ckch[i]==1&&pe[j].cheese==i)
            {
                if(sick[pe[j].n]>0)
                {
                    cnt++;
                }
            }
        }
        if(cnt!=s)
        {
            ckch[i]=0;
        }
    }
    int max=0;
    for(int i=1;i<=m;i++)
    {
        int cnt=0;
        for(int j=0;j<d;j++)
        {
            if(pe[j].cheese==i)
            {
                cnt++;
            }
        }
        if(max<cnt) max=cnt;
    }
    cout<<max;
    return 0;
}