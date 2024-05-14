#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    char arr[51][51]={0,};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='L')
            {
                if(arr[i][j+1]=='E'&&arr[i][j+2]=='E'&&j+1<m&&j+2<m) cnt++;
                if(arr[i+1][j]=='E'&&arr[i+2][j]=='E'&&i+1<n&&i+2<n) cnt++;
                if(arr[i+1][j+1]=='E'&&arr[i+2][j+2]=='E'&&i+1<n&&i+2<n&&j+1<m&&j+2<m) cnt++;
                if(arr[i+1][j-1]=='E'&&arr[i+2][j-2]=='E'&&i+1<n&&i+2<n&&j-1>=0&&j-2>=0) cnt++;
                if(arr[i-1][j]=='E'&&arr[i-2][j]=='E'&&i-1>=0&&i-2>=0) cnt++;
                if(arr[i][j-1]=='E'&&arr[i][j-2]=='E'&&j-1>=0&&j-2>=0) cnt++;
                if(arr[i-1][j+1]=='E'&&arr[i-2][j+2]=='E'&&i-1>=0&&i-2>=0&&j+1<m&&j+2<m) cnt++;
                if(arr[i-1][j-1]=='E'&&arr[i-2][j-2]=='E'&&i-1>=0&&i-2>=0&&j-1>=0&&j-2>=0) cnt++;

            }
        }
    }
    cout<<cnt;
    return 0;
}