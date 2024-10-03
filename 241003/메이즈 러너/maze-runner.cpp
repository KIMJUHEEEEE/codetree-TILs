#include <iostream>
using namespace std;
int N, M, K;
int map[11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
pair<int, int> exits;
struct p {
    int y;
    int x;
    int sumdis;
    int state;
};
p person[11];

int direction(int y, int x)
{
    int now = abs(y - exits.first) + abs(x - exits.second);
    int ids = -1;
    for (int i = 0; i < 4; i++)
    {
        if ((y + dy[i]<1 || y + dy[i]>N || x + dx[i] > N || x + dx[i] < 1)||map[y+dy[i]][x+dx[i]]!=0) continue;
        else
        {
            int dis = abs(y + dy[i] - exits.first) + abs(x + dx[i] - exits.second);
            if (dis < now&&map[y+dy[i]][x+dx[i]]==0)
            {
                now = dis;
                ids = i;
            }
        }
    }
    return ids;
}

void findrec()
{
    int minx = 100;
    int maxx = 0;
    int miny = 100;
    int maxy = 0;
    int depth = 1;
    bool ck = 0;

    while (1) {
        for (int y = exits.first - depth; y <= exits.first; y++)
        {
            if (y<1 || y>N) continue;
            for (int x = exits.second - depth; x <= exits.second; x++)
            {
                if (x<1 || x>N) continue;
                for (int a = 0; a <= depth; a++)
                {
                    for (int b = 0; b <= depth; b++)
                    {
                        for (int i = 1; i <= M; i++)
                        {
                            if (person[i].y == y + a && person[i].x == x + b && ck == 0&&person[i].state!=-1)
                            {
                                ck = 1;
                                miny = y;
                                maxy = y + depth;
                                minx = x;
                                maxx = x + depth;
                            }
                            if (ck == 1) break;
                        }
                        if (ck == 1) break;
                    }
                    if (ck == 1) break;
                }
                if (ck == 1) break;
            }
            if (ck == 1) break;           
        } 
        if (ck == 1) break;
        depth++;
    }
    for (int d = 0; d < depth; d++)
    {
        int tmp = map[miny][minx];
        int y = miny;
        int x = minx;
        int idx = 0;
        for (int i = 1; i <= M; i++)
        {
            if (person[i].y == y && person[i].x == x) idx = i;
        }
        bool checkexit = 0;
        if (miny == exits.first && minx == exits.second) checkexit = 1;
        for (int i = 1; i <= depth; i++)
        {
            map[y][x] = map[y + 1][x];
            for (int k = 1; k <= M; k++)
            {
                if (person[k].y == y+1 && person[k].x == x)
                    person[k].y--;
            }
            if (exits.first == y+1 && exits.second == x) exits.first--;
            y++;
            
        }
        for (int i = 1; i <= depth; i++)
        {
            map[y][x] = map[y][x + 1];
            for (int k = 1; k <= M; k++)
            {
                if (person[k].y == y && person[k].x == x+1)
                    person[k].x--;
            }
            if (exits.first == y && exits.second == x+1) exits.second--;
            x++;
        }
        for (int i = 1; i <= depth; i++)
        {
            map[y][x] = map[y - 1][x];
            for (int k = 1; k <= M; k++)
            {
                if (person[k].y == y-1 && person[k].x == x)
                    person[k].y++;
            }
            if (exits.first == y-1 && exits.second == x) exits.first++;
            y--;
        }
        for (int i = 1; i < depth; i++)
        {
            map[y][x] = map[y][x - 1];
            for (int k = 1; k <= M; k++)
            {
                if (person[k].y == y && person[k].x == x-1)
                    person[k].x++;
            }
            if (exits.first == y && exits.second == x-1) exits.second++;
            x--;
        }
        map[miny][minx + 1] = tmp;
        person[idx].x++;
        if (checkexit==1&&exits.first == miny && exits.second == minx) exits.second++;
    }
    for (int i = miny; i <= maxy; i++)
    {
        for (int j = minx; j <= maxx; j++)
        {
            if (map[i][j] > 0) map[i][j]--;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> person[i].y >> person[i].x;
    }

    cin >> exits.first >> exits.second;
    for (int tc = 0; tc < K; tc++)
    {
        for (int i = 1; i <= M; i++)
        {
            if (person[i].state == -1) continue;
            int dir = direction(person[i].y, person[i].x);
            if (dir == -1) continue;
            if (map[person[i].y + dy[dir]][person[i].x + dx[dir]] == 0)
            {
                person[i].y += dy[dir];
                person[i].x += dx[dir];
                person[i].sumdis += abs(dy[dir]);
                person[i].sumdis += abs(dx[dir]);
                if (person[i].y == exits.first && person[i].x == exits.second) person[i].state = -1;
            }
        }
        findrec();
    }
    int sumdis = 0;
    for (int i = 1; i <= M; i++)
    {
        sumdis += person[i].sumdis;
    }
    cout << sumdis << endl << exits.first << ' ' << exits.second;
    return 0;
}