#include <iostream>
#include <cstdlib>
using namespace std;

class dis {
    int x;
    int y;
public:
    dis() {this->x = 0; this->y = 0; }
    void set(int x,int y){ this->x = x; this->y = y; }
    int getx(){return x;}
    int gety(){return y;}
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    dis distance[101];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        distance[i].set(x,y);

    }
    int x=distance[0].getx();
    int y=distance[0].gety();
    int min=9999999;
    for(int i=1;i<n-1;i++)
    {
        int sum=0;
        for(int j=0;j<n-1;j++)
        {
            int start=j;int end=j+1;
            if(end==i) end++;
            else if(start==i) start++;
            int xlen=abs(distance[start].getx()-distance[end].getx());
            int ylen=abs(distance[start].gety()-distance[end].gety());
            sum=sum+xlen+ylen;
        }
        if(sum<min) min=sum;
    }
    cout<<min;
    return 0;
}