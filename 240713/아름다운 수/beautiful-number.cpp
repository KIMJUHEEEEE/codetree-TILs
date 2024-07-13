#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt;
vector<int> v;
bool check()
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1) continue;
        if(v[i]==2)
        {
            if(v[i+1]!=2||i+1>=v.size()) return false;
            i++;
        }
        else if(v[i]==3)
        {
            if(i+1>=v.size()||i+2>=v.size()) return false;
            if(v[i+1]==3&&v[i+2]==3)
            {
                
                i+=2;
                continue;
            }
            else return false;
        }
        else if(v[i]==4)
        {
            if(i+1>=v.size()||i+2>=v.size()||i+3>=v.size()) return false;
            if(v[i+1]==4&&v[i+2]==4&&v[i+3]==4)
            {
                
                i+=3;
                continue;
            }
            else return false;
        }
    }
    return true;
}
void rec(int idx)
{
    if(idx==n)
    {
        if(check()==true) cnt++;
        return;
    }
    for(int i=1;i<=4;i++)
    {
        v.push_back(i);
        rec(idx+1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    if(n==1) cnt=1;
    else{
    rec(0);
    }
    cout<<cnt;
    return 0;
}