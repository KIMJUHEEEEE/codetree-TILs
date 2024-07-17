#include <iostream>
#include <vector>
using namespace std;
int arr[12][12];
int cparr[12][12];
int ans;
int n, m;
vector<int> answer;
vector<int> made;
void line(vector<int>& a)
{
    for (int i = 0; i < n; i++)
    {
        a.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void rec(int idx,int y, int x)
{
    if (idx >= ans)
    {
        made.clear();
        return;
    }
    if (made == answer )
    {
        ans = min(ans, idx);
        return;
    }
    else
    {
        made.clear();
    }
    for (int i = y; i < y+2; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i == y) j = x++;
            int cnt = idx;
            if (arr[i][j] == 0)
            {
                arr[i][j] = idx+1;
                line(made);
                rec(idx + 1,i,j);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    ans = m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b - 1][a - 1] = 1;
    }
    line(answer);
    int cnt=0;
    for(int i=0;i<answer.size();i++)
    {
        if(answer[i]==i) cnt++;
    }
    if(cnt==answer.size())
    {
        cout<<0;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    rec(0,0,0);
    cout << ans;
    return 0;
}