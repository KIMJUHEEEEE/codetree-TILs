#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[5][5];
int cpmap[5][5];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;
queue<int> q_num;

void copy()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cpmap[i][j] = map[i][j];
        }
    }
}

void rotate(int y, int x)
{
    int tmp = cpmap[y - 1][x - 1];
    cpmap[y - 1][x - 1] = cpmap[y + 1][x - 1];
    cpmap[y + 1][x - 1] = cpmap[y + 1][x + 1];
    cpmap[y + 1][x + 1] = cpmap[y - 1][x + 1];
    cpmap[y - 1][x + 1] = tmp;
    tmp = cpmap[y - 1][x];
    cpmap[y - 1][x] = cpmap[y][x - 1];
    cpmap[y][x - 1] = cpmap[y + 1][x];
    cpmap[y + 1][x] = cpmap[y][x + 1];
    cpmap[y][x + 1] = tmp;

}

int getsth()
{
    queue<pair<int, int>> q;
    int value = 0;
    bool checked[5][5] = { 0, };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bool visited[5][5] = { 0, };
            q.push(make_pair(i, j));
            int cnt = 0;
            while (q.size() > 0)
            {
                int y = q.front().first;
                int x = q.front().second;
                visited[y][x] = 1;
                int num = cpmap[y][x];
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    if (y + dy[d] < 0 || y + dy[d] == 5 || x + dx[d] < 0 || x + dx[d] == 5) continue;
                    if (visited[y + dy[d]][x + dx[d]] == 0 && cpmap[y + dy[d]][x + dx[d]] == num&&checked[y+dy[d]][x+dx[d]]==0)
                    {
                        visited[y + dy[d]][x + dx[d]] = 1;
                        q.push(make_pair(y + dy[d], x + dx[d]));
                        cnt++;
                    }
                }
            }
            if (cnt >= 2)
            {
                value += cnt+1;
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        if (visited[y][x] == 1)
                            checked[y][x] = 1;
                    }
                }
            }

        }
    }
    return value;
}

bool getvalue()
{
    bool getv = false;
    queue<pair<int, int>> q;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bool visited[5][5] = { 0, };
            q.push(make_pair(i, j));
            int cnt = 0;
            while (q.size() > 0)
            {
                int y = q.front().first;
                int x = q.front().second;
                visited[y][x] = 1;
                int num = cpmap[y][x];
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    if (y + dy[d] < 0 || y + dy[d] == 5 || x + dx[d] < 0 || x + dx[d] == 5) continue;
                    if (visited[y + dy[d]][x + dx[d]] == 0 && cpmap[y + dy[d]][x + dx[d]] == num)
                    {
                        visited[y + dy[d]][x + dx[d]] = 1;
                        q.push(make_pair(y + dy[d], x + dx[d]));
                        cnt++;
                    }
                }
            }
            if (cnt >= 2)
            {
                getv = true;
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        if (visited[y][x] == 1)
                            cpmap[y][x] = 0;
                    }
                }
            }

        }
    }
    return getv;
}

class valueth {
public:
    int v;
    int a;
    int r;
    int c;
    valueth(int value, int angle, int rows, int cols)
    {
        v = value;
        a = angle;
        r = rows;
        c = cols;
    }
};

bool cmp(valueth v1, valueth v2)
{
    if (v1.v > v2.v) return true;
    else if (v1.v == v2.v)
    {
        if (v1.a < v2.a) return true;
        else if (v1.a == v2.a)
        {
            if (v1.c > v2.c) return true;
            else if (v1.c == v2.c)
            {
                if (v1.r > v2.r) return true;
                else return false;
            }
        }
    }
    return false;
}

void insertvalue()
{
    
    for (int j = 0; j < 5; j++)
    {
        for (int i = 4; i >= 0; i--)
        {
            if (cpmap[i][j] == 0)
            {
                int num = q_num.front();
                q_num.pop();
                cpmap[i][j] = num;
            }
        }
    }
}

int explore()
{
    vector<valueth> getv;
    int vvalue = 0;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            copy();
            for (int t = 0; t < 3; t++)
            {
                rotate(i, j);
                int v = getsth();
                getv.push_back(valueth(v, t, i, j));
            }
        }
    }
    copy();
    sort(getv.begin(), getv.end(), cmp);
    for (int t = 0; t <= getv[0].a; t++)
    {
        rotate(getv[0].r, getv[0].c);
    }
    vvalue = getv[0].v;
    while (1)
    {   
        bool ck = getvalue();
        if (ck == true)
        {   
            insertvalue();
            vvalue += getsth();
        }
        else break;
    }
    return vvalue;
}

void copy2()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            map[i][j] = cpmap[i][j];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    int K, M;
    cin >> K >> M;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        q_num.push(num);
    }
    for (int i = 0; i < K; i++)
    {
        int checkvalue = explore();
        if (checkvalue == 0) return 0;
        copy2();
        cout << checkvalue << ' ';
    }
    return 0;
}