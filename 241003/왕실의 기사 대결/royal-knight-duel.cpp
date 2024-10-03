#include <iostream>
#include <queue>
using namespace std;
int map[41][41];
int kmap[41][41];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int L, N, Q;
struct kn {
    int y;
    int x;
    int h;
    int w;
    int heart;
    int damage;
    int state;
};
kn knights[31];

void resetkmap()
{
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            kmap[i][j] = 0;
        }
    }
}

void drawkmap()
{
    resetkmap();
    for (int i = 1; i <= N; i++)
    {
        for (int h = 0; h < knights[i].h; h++)
        {
            for (int c = 0; c < knights[i].w; c++)
            {
                if(knights[i].state!=-1)
                    kmap[knights[i].y + h][knights[i].x + c] = i;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> L >> N >> Q;
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int a = 1; a <= N; a++)
    {
        cin >> knights[a].y >> knights[a].x >> knights[a].h >> knights[a].w >> knights[a].heart;
    }
    drawkmap();
    for (int a = 0; a < Q; a++)
    {
        queue<int> q;
        bool check[31] = { 0, };
        int id, d;
        cin >> id >> d;
        q.push(id);
        check[id] = 1;
        bool wall = 0;
        if (knights[id].state == -1) continue;
        while (q.size() > 0)
        {
            int num = q.front();
            q.pop();
            int kx = knights[num].x;
            int ky = knights[num].y;
            int kw = knights[num].w;
            int kh = knights[num].h;
        
            for (int j = 0; j < kw; j++)
            {
                for (int k = 0; k < kh; k++) {
                    if (map[ky + dy[d] + k][kx + j + dx[d]] == 2||ky+dy[d]+k<1||ky+dy[d]+k>L||kx+j+dx[d]<1||kx+dx[d]+j>L) {
                        wall = 1; break;
                    }
                    else if (kmap[ky+dy[d]+k][kx + j+dx[d]] != 0 && check[kmap[ky +dy[d]+k][kx+dx[d]+j]] == 0)
                    {
                        q.push(kmap[ky +dy[d]+k][kx + j+dx[d]]);
                        check[kmap[ky +dy[d]+k][kx+j+dx[d]]] = 1;
                    }

                }
            }
            if (wall == 1)
            {
                for (int i = 1; i <= N; i++) check[i] = 0;
                break;
            }
        }
        if (wall == 0)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[j] == 1)
                {
                    knights[j].y += dy[d];
                    knights[j].x += dx[d];
                }
            }

            drawkmap();
            for (int i = 1; i <= L; i++)
            {
                for (int j = 1; j <= L; j++)
                {
                    if (map[i][j] == 1 && kmap[i][j] > 0&&kmap[i][j]!=id&&check[kmap[i][j]]==1)
                    {
                        knights[kmap[i][j]].damage++;
                    }
                }
            }
            for (int i = 1; i <= N; i++)
            {
                if (knights[i].heart - knights[i].damage <= 0) knights[i].state = -1;
            }
            for (int i = 1; i <= L; i++)
            {
                for (int j = 1; j <= L; j++)
                {
                    if (kmap[i][j] > 0&&knights[kmap[i][j]].state == -1)
                    {
                        kmap[i][j] = 0;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (knights[i].state != -1)
        {
            ans += knights[i].damage;
        }
    }
    cout << ans;
    return 0;
}