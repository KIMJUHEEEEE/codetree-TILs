#include <iostream>
using namespace std;

int arr[4][4]={0,};
void mergeleft()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==arr[i][j+1])
            {
                arr[i][j]=arr[i][j]*2;
                arr[i][j+1]=0;
                j++;
            }
        }
    }
}
void mergeright()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if(arr[i][j]==arr[i][j-1])
            {
                arr[i][j]=arr[i][j]*2;
                arr[i][j-1]=0;
                j--;
            }
        }
    }
}
void mergeup()
{
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<3;i++)
        {
            if(arr[i][j]==arr[i+1][j])
            {
                arr[i][j]=arr[i][j]*2;
                arr[i+1][j]=0;
                i++;
            }
        }
    }
}
void mergedown()
{
    for(int j=0;j<4;j++)
    {
        for(int i=3;i>0;i--)
        {
            if(arr[i][j]==arr[i-1][j])
            {
                arr[i][j]=arr[i][j]*2;
                arr[i-1][j]=0;
                i--;
            }
        }
    }
}
void moveright()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=arr[i][j-1];
                arr[i][j-1]=0;
            }
        }
    }
}
void moveleft()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=0;
            }
        }
    }
}
void moveup()
{
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<3;i++)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=arr[i+1][j];
                arr[i+1][j]=0;
            }
        }
    }
}
void movedown()
{
    for(int j=0;j<4;j++)
    {
        for(int i=3;i>0;i--)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=arr[i-1][j];
                arr[i-1][j]=0;
            }
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    char c;
    cin>>c;
    if(c=='L')
    {
        moveleft();
        mergeleft();
        moveleft();
    }
    if(c=='R')
    {
        moveright();
        mergeright();
        moveright();
    }
    if(c=='U')
    {
        moveup();
        mergeup();
        moveup();
    }
    if(c=='D')
    {
        movedown();
        mergedown();
        movedown();
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}