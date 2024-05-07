#include <iostream>
using namespace std;
int arr[2001][2001];

int main() {
    // 여기에 코드를 작성해주세요.

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int minx=x1;
    int maxx=x2;
    int miny=y1;
    int maxy=y2;
    for (int i = x1+ 1000; i <= x2+ 1000; i++)
    {
        for (int j = y1+ 1000; j <= y2+ 1000; j++)
        {
            arr[i][j ] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1<minx) minx=x1; 
    if(x2>maxx) maxx=x2;
    if(y1<miny) miny=y1;
    if(y2>maxy) maxy=y2;
    for (int i = x1+ 1000; i <= x2+ 1000; i++)
    {
        for (int j = y1+ 1000; j <= y2+ 1000; j++)
        {
            arr[i ][j ] = 0;
        }
    }
    int maxw = -9999;
    int maxh = -9999;
    int minw=9999;
    int minh=9999;
    for (int i = minx+1000; i <= maxx+1000; i++)
    {
        for (int j = miny+1000; j <= maxy+1000; j++)
        {
            if (arr[i][j] == 1)
            {
                if(minw>j) minw=j;
                if(minh>i) minh=i;
                if(maxw<j) maxw=j;
                if(maxh<i) maxh=i;
               
            }
        }
    }
    cout << (maxw-minw) * (maxh-minh);
    return 0;
}