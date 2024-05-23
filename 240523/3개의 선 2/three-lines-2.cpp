#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[21][2]={-1,};
    int cnt[11][2]={0,};
    int maxcntx=0;
    int maxcnty=0;
    int maxx=-1;
    int maxy=-1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        cnt[arr[i][0]][0]++;
        cnt[arr[i][1]][1]++;
        if(maxcntx<cnt[arr[i][0]][0]) {maxcntx=cnt[arr[i][0]][0]; maxx=arr[i][0];}
        if(maxcnty<cnt[arr[i][1]][1]) {maxcnty=cnt[arr[i][1]][1]; maxy=arr[i][1];}
    }
    for(int a=0;a<3;a++){
        //cout<<maxcntx<<' '<<maxcnty<<endl;
    if(maxcntx>=maxcnty)
    {
        cnt[maxx][0]=0;
        for(int i=0;i<n;i++)
        {
            if(maxx==arr[i][0])
            {
                arr[i][0]=-1;
                arr[i][1]=-1;
            }
        }
        maxcntx=-1;
        maxx=-1;
        maxy=-1;
        maxcnty=-1;
        cnt[11][1]={0,};
        cnt[11][0]={0,};
    }
    else if(maxcntx<maxcnty)
    {
        cnt[maxy][1]=0;
        for(int i=0;i<n;i++)
        {
            if(maxy==arr[i][1])
            {
                arr[i][0]=-1;
                arr[i][1]=-1;
            }
        }
        maxcntx=-1;
        maxx=-1;
        maxy=-1;
        maxcnty=-1;
        cnt[11][1]={0,};
        cnt[11][0]={0,};
    }
    for(int i=0;i<n;i++)
    {
        //cout<<arr[i][0]<<' '<<arr[i][1]<<endl;
        if(arr[i][0]==-1||arr[i][1]==-1) continue;
        cnt[arr[i][0]][0]++;
        cnt[arr[i][1]][1]++;
        if(maxcntx<cnt[arr[i][0]][0]) {maxcntx=cnt[arr[i][0]][0]; maxx=arr[i][0];}
        if(maxcnty<cnt[arr[i][1]][1]) {maxcnty=cnt[arr[i][1]][1]; maxy=arr[i][1];}
    }
    }
    int num=0;
    int tc=n;
    for(int i=0;i<tc;i++)
    {
        //cout<<arr[i][0]<<' ';
        if(arr[i][0]==-1&&arr[i][1]==-1) num++;
    }
    int ans=0;
    if(num==n) ans=1;
    cout<<ans;


    return 0;
}