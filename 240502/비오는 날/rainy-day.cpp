#include <iostream>
#include <string>
using namespace std;

class weather{
public:
string date;
string week;
string info;
weather(){}
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    weather wt[101];
    for(int i=0;i<n;i++)
    {
        string date;
        string week;
        string info;
        cin>>date>>week>>info;
        wt[i].date=date;
        wt[i].week=week;
        wt[i].info=info;
    }
    string mini="9999-99-99";
    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(wt[i].info=="Rain")
        {
            if(mini>wt[i].date)
            {
                mini=wt[i].date;
                idx=i;
            }
        }
    }
    cout<<wt[idx].date<<' '<<wt[idx].week<<' '<<wt[idx].info;
    return 0;
}