#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int cnt=0;
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    bool visited[1000001]={0,};
    while(q.size()>0)
    {
        int num=q.front().first;
        int count=q.front().second;
        if(num==1)
        {
            cnt=count;
            break;
        }
        q.pop();
        if(visited[num+1]==0)
        {q.push(make_pair(num+1,count+1));
        visited[num+1]=1;}
        if(visited[num-1]==0)
        {q.push(make_pair(num-1,count+1));
        visited[num-1]=0;}
        if(num%2==0&&visited[num/2]==0)
        {
            q.push(make_pair(num/2,count+1));
            visited[num/2]=1;
        }
        if(num%3==0&&visited[num/3]==0)
        {
            q.push(make_pair(num/3,count+1));
            visited[num/3]=1;
        }
    }
    cout<<cnt;
    return 0;
}