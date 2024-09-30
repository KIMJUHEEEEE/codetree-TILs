#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N, M, P, C, D;
int map[51][51];
int rdx[8] = { 0,1,1,1,0,-1,-1,-1 };
int rdy[8] = { -1,-1,0,1,1,1,0,-1 };
int sdx[4] = { 0,1,0,-1 };
int sdy[4] = { -1,0,1,0 };
int ruy, rux;

class sa {
public:
    int y;
    int x;
    int score;
    int state;
    int number;
    sa(int sy, int sx, int sco, int sta, int num)
    {
        y = sy;
        x = sx;
        score = sco;
        state = sta;
        number = num;
    }
};

vector<sa> santa;

int findclosestsanta(int ry, int rx)
{
    int distance = 9999999;
    int idx = 0;
    int my;
    int mx;
    bool ck = false;
    for (int i = 1; i <= P; i++)
    {
        if (santa[i].state >= 0) ck = true;
        if (santa[i].y<1 || santa[i].y>N || santa[i].x<0 || santa[i].x>N || santa[i].state == -1) continue;
        int cal = (ry - santa[i].y) * (ry - santa[i].y) + (rx - santa[i].x) * (rx - santa[i].x);
        if (distance > cal)
        {
            distance = cal;
            idx = i;
            my = santa[i].y;
            mx = santa[i].x;
        }
        else if (distance == cal)
        {
            if (my < santa[i].y)
            {
                idx = i;
                my = santa[i].y;
            }
            else if (my == santa[i].y)
            {
                if (mx < santa[i].x) {
                    idx = i;
                    mx = santa[i].x;
                }
            }
        }
    }
    if (ck == false) idx = -1;
    return idx;
}

void interactionru(int idx, int sy, int sx)
{
    queue <int> mn;
    int y = sy;
    int x = sx;
    mn.push(map[y][x]);
    while (1)
    {
        if (mn.size() > 0)
        {
            mn.push(map[y + rdy[idx]][x + rdx[idx]]);
            map[y+rdy[idx]][x+rdx[idx]] = mn.front();
            mn.pop();
            santa[map[y + rdy[idx]][x + rdx[idx]]].y = y + rdy[idx];
            santa[map[y + rdy[idx]][x + rdx[idx]]].x = x + rdx[idx];
        }

        y += rdy[idx];
        x += rdx[idx];
        if (y<1 || y>N || x<1 || x>N) break;
    }
}

void interactionsa(int idx, int sy, int sx)
{
    queue <int> mn;
    int y = sy;
    int x = sx;
    mn.push(map[y][x]);
    while (1)
    {
        if (mn.size() > 0)
        {
            mn.push(map[y - sdy[idx]][x - sdx[idx]]);
            map[y - sdy[idx]][x - sdx[idx]] = mn.front();
            mn.pop();
            santa[map[y - sdy[idx]][x - sdx[idx]]].y = y - sdy[idx];
            santa[map[y - sdy[idx]][x - sdx[idx]]].x = x - sdx[idx];
        }
        y -= sdy[idx];
        x -= sdx[idx];
        if (y<1 || y>N || x<1 || x>N) break;

    }
}

void crushru(int ry, int rx, int idx)
{
    santa[map[ry][rx]].score += C;
    santa[map[ry][rx]].state = 3;
    if (map[santa[map[ry][rx]].y + rdy[idx] * C][santa[map[ry][rx]].x + rdx[idx] * C] != 0)
    {
        interactionru(idx, santa[map[ry][rx]].y + rdy[idx] * C, santa[map[ry][rx]].x + rdx[idx] * C);
        santa[map[ry][rx]].y += rdy[idx] * C;
        santa[map[ry][rx]].x += rdx[idx] * C;
        map[santa[map[ry][rx]].y][santa[map[ry][rx]].x] = santa[map[ry][rx]].number;

    }
    else
    {
        santa[map[ry][rx]].y += rdy[idx] * C;
        santa[map[ry][rx]].x += rdx[idx] * C;
        map[santa[map[ry][rx]].y][santa[map[ry][rx]].x] = santa[map[ry][rx]].number;
    }
    map[ry][rx] = -1;
}

void moveru(int sy, int sx)
{
    int dis = 99999999;
    int idx = 0;
    for (int i = 0; i < 8; i++)
    {
        if (ruy + rdy[i]<1 || ruy + rdy[i]>N || rux + rdx[i]<1 || rux + rdx[i]>N) continue;
        int cal = (ruy + rdy[i] - sy) * (ruy + rdy[i] - sy) + (rux + rdx[i] - sx) * (rux + rdx[i] - sx);
        if (dis > cal)
        {
            dis = cal;
            idx = i;
        }
    }
    map[ruy][rux] = 0;
    if (map[ruy + rdy[idx]][rux + rdx[idx]] == 0)
    {
        map[ruy + rdy[idx]][rux + rdx[idx]] = -1;
        ruy = ruy + rdy[idx];
        rux = rux + rdx[idx];
    }
    else
    {
        crushru(ruy + rdy[idx], rux + rdx[idx], idx);
        ruy = ruy + rdy[idx];
        rux = rux + rdx[idx];
    }
}

void movesanta()
{
    for (int i = 1; i <= P; i++)
    {
        int dis = (santa[i].y - ruy) * (santa[i].y - ruy) + (santa[i].x - rux) * (santa[i].x - rux);
        int idx = -1;
        if (santa[i].state == -1) continue;
        if (santa[i].state > 0)
        {
            santa[i].state--;
            if(santa[i].state>0)
                continue;
        }
        for (int j = 0; j < 4; j++)
        {
            if (santa[i].y + sdy[j]<1 || santa[i].y + sdy[j]>N || santa[i].x + sdx[j]<1 || santa[i].x + sdx[j]>N || map[santa[i].y + sdy[j]][santa[i].x + sdx[j]] > 0) continue;
            else {
                int cal = (ruy - (santa[i].y + sdy[j])) * (ruy - (santa[i].y + sdy[j])) + (rux - (santa[i].x + sdx[j])) * (rux - (santa[i].x + sdx[j]));
                if (dis > cal)
                {
                    dis = cal;
                    idx = j;
                }
            }
        }
        if (idx == -1) continue;
        if (map[santa[i].y + sdy[idx]][santa[i].x + sdx[idx]] == 0)
        {
            map[santa[i].y][santa[i].x] = 0;
            santa[i].y += sdy[idx];
            santa[i].x += sdx[idx];
            map[santa[i].y][santa[i].x] = santa[i].number;
        }
        else if (map[santa[i].y + sdy[idx]][santa[i].x + sdx[idx]] == -1)
        {
            map[santa[i].y][santa[i].x] = 0;
            santa[i].score += D;
            santa[i].state = 2;
            if (map[santa[i].y + sdy[idx] - sdy[idx] * D][santa[i].x + sdx[idx] - sdx[idx] * D] == 0)
            {
                map[santa[i].y][santa[i].x] = 0;
                santa[i].y = santa[i].y + sdy[idx] - sdy[idx] * D;
                santa[i].x = santa[i].x + sdx[idx] - sdx[idx] * D;
                map[santa[i].y][santa[i].x] = santa[i].number;
            }
            else
            {
                interactionsa(idx, santa[i].y + sdy[idx] - sdy[idx] * D, santa[i].x + sdx[idx] - sdx[idx] * D);
                map[santa[i].y][santa[i].x] = 0;
                santa[i].y = santa[i].y + sdy[idx] - sdy[idx] * D;
                santa[i].x = santa[i].x + sdx[idx] - sdx[idx] * D;
                map[santa[i].y][santa[i].x] = santa[i].number;
            }
        }
    }
}

void checksantastate()
{
    for (int i = 1; i <= P; i++)
    {
        if (santa[i].y<1 || santa[i].y>N || santa[i].x<1 || santa[i].x>N) santa[i].state = -1;
        if (santa[i].state >= 0) santa[i].score++;
    }
}
bool cmp(sa v1, sa v2)
{
    if (v1.number < v2.number) return true;
    return false;
}
int main() {
    santa.push_back(sa(0, 0, 0, -1, 0));
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> P >> C >> D;

    cin >> ruy >> rux;
    map[ruy][rux] = -1;
    for (int i = 1; i <= P; i++)
    {
        int sy, sx, sn;
        cin >> sn >> sy >> sx;
        santa.push_back(sa(sy, sx, 0, 0, sn));
        map[sy][sx] = sn;
    }
    sort(santa.begin(), santa.end(), cmp);

    for (int i = 0; i < M; i++)
    {
        int santanum = findclosestsanta(ruy, rux);
        if (santanum == -1) break;
        int sy = santa[santanum].y;
        int sx = santa[santanum].x;
        moveru(sy, sx);
        movesanta();
        checksantastate();

    }

    for (int i = 1; i <= P; i++)
    {
        cout << santa[i].score << ' ';
    }
    return 0;
}