#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    bool arr[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    int score[3]={0,};
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=0;j<3;j++)
        {
            int tmp=arr[j][a];
            arr[j][a]=arr[j][b];
            arr[j][b]=tmp;
            if(arr[j][c]==1) score[j]++;
        }

    }
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(ans<score[i]) ans=score[i];
    }
    cout<<ans;
    return 0;
}