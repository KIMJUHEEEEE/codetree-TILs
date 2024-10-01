#include <iostream>
#include <queue>
using namespace std;
pair<int, int> santa[31];
int main() {
    // 여기에 코드를 작성해주세요.
    int N, M, P, C, D;
    int ruy, rux;
    int state[31] = { 0, };

    int score[31] = { 0, };
    cin >> N >> M >> P >> C >> D;
    cin >> ruy >> rux;
    int map[52][52] = { 0, };
    map[ruy][rux] = -1;
    for (int i = 0; i < P; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        santa[a].first = b;
        santa[a].second = c;
        map[b][c] = a;
    }

    for (int i = 0; i < M; i++)
    {
        //루돌프 이동
        int rdy[8] = { -1,-1,0,1,1,1,0,-1 };
        int rdx[8] = { 0,1,1,1,0,-1,-1,-1 };
        int santanum = 0;
        int mindis = 9999999;
        for (int j = 1; j <= P; j++)
        {
            if (state[j] == -1) continue;
            int distance = (ruy - santa[j].first) * (ruy - santa[j].first) + (rux - santa[j].second) * (rux - santa[j].second);
            if (mindis > distance)
            {
                mindis = distance;
                santanum = j;
            }
            else if (mindis == distance)
            {
                if (santa[santanum].first < santa[j].first)
                {
                    santanum = j;
                }
                else if (santa[santanum].first == santa[j].first)
                {
                    if (santa[santanum].second < santa[j].second)
                    {
                        santanum = j;
                    }
                }
            }
        }
        mindis = (ruy-santa[santanum].first)*(ruy-santa[santanum].first)+(rux-santa[santanum].second)*(rux-santa[santanum].second);
        int idx = 0;
        for (int j = 0; j < 8; j++)
        {
            if (ruy + rdy[j]<1 || ruy + rdy[j]>N || rux + rdx[j]<1 || rux + rdx[j]>N) continue;
            if (mindis > (ruy + rdy[j] - santa[santanum].first) * (ruy + rdy[j] - santa[santanum].first) + (rux + rdx[j] - santa[santanum].second) * (rux + rdx[j] - santa[santanum].second))
            {
                mindis = (ruy + rdy[j] - santa[santanum].first) * (ruy + rdy[j] - santa[santanum].first) + (rux + rdx[j] - santa[santanum].second) * (rux + rdx[j] - santa[santanum].second);
                idx = j;
            }
        }
        map[ruy][rux] = 0;
        ruy += rdy[idx];
        rux += rdx[idx];
        if (map[ruy][rux] > 0)
        {
            int sn = map[ruy][rux];
            score[sn] += C;
            santa[sn].first += rdy[idx] * C;
            santa[sn].second += rdx[idx] * C;
            state[sn] = 3;
            if (santa[sn].first<1 || santa[sn].first>N || santa[sn].second<1 || santa[sn].second>N) state[sn] = -1;
            if (map[santa[sn].first][santa[sn].second] != 0)
            {
                queue<int> q;
                q.push(sn);
                int y = santa[sn].first;
                int x = santa[sn].second;
                q.push(map[y][x]);
                while (q.size() > 0)
                {
                    int n = q.front();
                    q.pop();
                    if(map[y+rdy[idx]][x+rdx[idx]]>0)
                        q.push(map[y+rdy[idx] ][x+rdx[idx]]);
                    
                    map[y ][x ] = n;
                    if (n > 0)
                    {
                        if (y<1 || y>N || x<1 || x>N) state[n] = -1;
                        santa[n].first = y;
                        santa[n].second = x;
                    }
                    if (y<1 || y>N || x<1 || x>N) break;
                    y += rdy[idx];
                    x += rdx[idx];

                }

            }
            else map[santa[sn].first][santa[sn].second] = sn;

        } 
        map[ruy][rux] = -1;
        //산타 이동
        for (int j = 1; j <= P; j++)
        {
            if (state[j] == -1) continue;
            if (state[j] > 0) state[j]--;
            if (state[j] == 0)
            {
                int dis = (ruy - santa[j].first) * (ruy - santa[j].first) + (rux - santa[j].second) * (rux - santa[j].second);
                int sdx[4] = { 0,1,0,-1 };
                int sdy[4] = { -1,0,1,0 };
                int idx = -1;
                for (int k = 0; k < 4; k++)
                {
                    if (map[santa[j].first + sdy[k]][santa[j].second + sdx[k]] > 0) continue;
                    if (santa[j].first + sdy[k]<1 || santa[j].first + sdy[k]>N || santa[j].second+sdx[k]<1 || santa[j].second+sdx[k]>N) continue;
                    if (dis > ((ruy - (santa[j].first + sdy[k])) * (ruy - (santa[j].first + sdy[k])) + (rux - (santa[j].second + sdx[k])) * (rux - (santa[j].second + sdx[k]))))
                    {
                        dis = (ruy - (santa[j].first + sdy[k])) * (ruy - (santa[j].first + sdy[k])) + (rux - (santa[j].second + sdx[k])) * (rux - (santa[j].second + sdx[k]));
                        idx = k;
                    }
                }
                if (idx != -1)
                {
                    if (santa[j].first + sdy[idx]<1 || santa[j].first + sdy[idx]>N || santa[j].second + sdx[idx]<1 || santa[j].second + sdx[idx]>N) state[j] = -1;
                    if (map[santa[j].first + sdy[idx]][santa[j].second + sdx[idx]] == 0)
                    {
                        map[santa[j].first][santa[j].second] = 0;
                        santa[j].first += sdy[idx];
                        santa[j].second += sdx[idx];
                        map[santa[j].first][santa[j].second] = j;
                    }
                    else if (map[santa[j].first + sdy[idx]][santa[j].second + sdx[idx]] == -1)
                    {
                        state[j] = 2;
                        score[j] += D;
                        map[santa[j].first][santa[j].second] = 0;
                        if (santa[j].first + sdy[idx] - sdy[idx] * D < 1 || santa[j].first + sdy[idx] - sdy[idx] * D > N || santa[j].second + sdx[idx] - sdx[idx] * D<1 || santa[j].second + sdx[idx] - sdx[idx] * D>N) state[j] = -1;
                        else if (map[santa[j].first + sdy[idx] - sdy[idx] * D][santa[j].second + sdx[idx] - sdx[idx] * D] == 0)
                        {
                            map[santa[j].first + sdy[idx] - sdy[idx] * D][santa[j].second + sdx[idx] - sdx[idx] * D] = j;
                            santa[j].first = santa[j].first + sdy[idx] - sdy[idx] * D;
                            santa[j].second = santa[j].second + sdx[idx] - sdx[idx] * D;
                        }
                        else
                        {
                            queue<int> q;
                            q.push(j);
                            int y = santa[j].first + sdy[idx] - sdy[idx] * D;
                            int x = santa[j].second + sdx[idx] - sdx[idx] * D;
                            while (q.size() > 0)
                            {
                                int n = q.front();
                                q.pop();
                                if (map[y][x] > 0)
                                    q.push(map[y][x]);
                                map[y][x] = n;

                                if (n > 0)
                                {
                                    if (y<1 || y>N || x<1 || x>N) state[n] = -1;
                                    santa[n].first = y;
                                    santa[n].second = x;
                                }
                                if (y<1 || y>N || x<1 || x>N) break;
                                y -= sdy[idx];
                                x -= sdx[idx];
                            }

                        }
                    }
                }
            }
        }
        bool ck = false;
        for (int i = 1; i <= P; i++)
        {
            if (state[i] != -1)
            {
                score[i]++; ck = true;
            }
        }
        if (ck == false) break;
    }
    for (int i = 1; i <= P; i++)
    {
        cout << score[i] << ' ';
    }
    return 0;
}