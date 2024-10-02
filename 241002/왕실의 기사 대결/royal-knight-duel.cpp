#include <iostream>
using namespace std;
#define MAX_L 41
#define MAX_N 31
int L, N, Q;
int map[MAX_L][MAX_L];
int kmap[MAX_L][MAX_L];

struct kn {
    int y;
    int x;
    int w;
    int h;
    int heart;
    int state;
    int damage;
};
kn knights[MAX_N];

bool is_range(int y, int x)
{
    if (y<1 || y>L || x<1 || x>L) return false;
    return true;
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
    int da[MAX_N] = { 0, };
    for (int i = 1; i <= N; i++)
    {
        cin >> knights[i].y >> knights[i].x >> knights[i].h >> knights[i].w >> knights[i].heart;
        for (int a = 0; a < knights[i].h; a++)
        {
            for (int b = 0; b < knights[i].w; b++)
            {
                kmap[knights[i].y + a][knights[i].x + b] = i;
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int l, d;
        cin >> l >> d;
        if (knights[l].state == -1) continue;
        int y = knights[l].y;
        int x = knights[l].x;
        int minx =x;
        int maxx = x;
        int miny = y;
        int maxy = y;
        if (d == 0)
        {
            for (int j = 0; j < knights[l].w; j++)
            {
                int mminy = y;
                int mmaxy = y+knights[l].h-1;
                while (1)
                {
                    if (map[mminy][x+j] != 2 && kmap[mminy][x+j] == 0)
                    {
                        break;
                    }
                    else if(map[mminy][x+j]!=2&&kmap[mminy][x+j]>0)
                    {
                        if (knights[kmap[mminy][x+j]].x < minx) minx = knights[kmap[mminy][x+j]].x;
                        if (knights[kmap[mminy][x+j]].x > maxx+knights[kmap[mminy][x+j]].w) maxx = knights[kmap[mminy][x + j]].x + knights[kmap[mminy][x + j]].w;
                        if (knights[kmap[mminy][x+j]].y < mminy) mminy = knights[kmap[mminy][x+j]].y;
                    }
                    if (is_range(mminy-1, x+j) == false) break;
                    mminy -= 1;
                }
                miny = mminy+1;
                maxy = mmaxy;
                    
            }
            if (miny < 1) break;
            bool ck = true;
            for (int j = minx; j <= maxx; j++)
            {
                if (map[maxy - 1][j] == 2) ck = false;
            }
            if (ck == true)
            {
                bool arr[MAX_N] = { 0, };
                arr[l] = 1;
                for (int a = miny; a < maxy; a++)
                {
                    for (int b = minx; b <= maxx; b++)
                    {
                        arr[kmap[a - 1][b]] = 1;
                        kmap[a - 1][b] = kmap[a][b];
                        if (map[a - 1][b] == 1&&kmap[a-1][b]!=l) knights[kmap[a - 1][b]].damage++;

                        if (a == maxy) kmap[a][b] = 0;
                    }
                }
                for (int j = 1; j <= N; j++)
                {
                    if (arr[j] == 1)
                    {
                        knights[j].y--;
                    }
                }
            }
        }
        else if (d == 1)
        {
            for (int j = 0; j < knights[l].h; j++)
            {
                int mminx = x;
                int mmaxx = x+knights[l].w-1;
                while (1)
                {
                    if (map[y + j][mmaxx] != 2 && kmap[y + j][mmaxx] == 0)
                    {
                        break;
                    }
                    else if (map[y + j][mmaxx] != 2 && kmap[y + j][mmaxx] > 0)
                    {
                        if (knights[kmap[y + j][mmaxx]].x > maxx) maxx = knights[kmap[y + j][mmaxx]].x;
                        if (knights[kmap[y + j][mmaxx]].y+knights[kmap[y+j][mmaxx]].h > maxy) maxy = knights[kmap[y + j][mmaxx]].y + knights[kmap[y + j][mmaxx]].h-1;
                        if (knights[kmap[y + j][mmaxx]].y < miny) miny = knights[kmap[y + j][mmaxx]].y;
                    }
                    if (is_range(mmaxx + 1, y + j) == false) break;
                    mmaxx++;
                }
                maxx = mmaxx-1;
                minx = mminx;
            }
            if (maxx >L) break;
            bool ck = true;
            for (int j = miny; j <= maxy; j++)
            {
                if (map[j][maxx+1] == 2) ck = false;
            }
            if (ck == true)
            {
                bool arr[MAX_N] = { 0, };
                arr[l] = 1;
                for (int a = maxx; a >= minx; a--)
                {
                    for (int b = miny; b <= maxy; b++)
                    {
                        arr[kmap[b][a + 1]] = 1;
                        kmap[b][a + 1] = kmap[b][a];
                        if (map[b][a + 1] == 1&&kmap[b][a+1]!=l) knights[kmap[b][a + 1]].damage++;

                        if (a == minx) kmap[b][a] = 0;
                    }
                }
                for (int j = 1; j <= N; j++)
                {
                    if (arr[j] == 1) knights[j].x++;
                }
            }
        }
        else if (d == 2)
        {
            for (int j = 0; j < knights[l].w; j++)
            {
                int mminy = y;
                int mmaxy = y+knights[l].w-1;
                while (1)
                {
                    if (map[mmaxy][x + j] != 2 && kmap[mmaxy][x + j] == 0)
                    {
                        break;
                    }
                    else if (map[mmaxy][x + j] != 2 && kmap[mmaxy][x + j] > 0)
                    {
                        if (knights[kmap[mmaxy][x + j]].x < minx) minx = knights[kmap[mmaxy][x + j]].x;
                        if (knights[kmap[mmaxy][x + j]].x+knights[kmap[mmaxy][x+j]].w > maxx) maxx = knights[kmap[mmaxy][x + j]].x + knights[kmap[mmaxy][x + j]].w;
                        if (knights[kmap[mmaxy][x + j]].y < mminy) mmaxy = knights[kmap[mmaxy][x + j]].y;
                    }
                    if (is_range(mmaxy + 1, x + j) == false) break;
                    mmaxy += 1;
                }
                miny = mminy;
                maxy = mmaxy-1;

            }
            if (maxy > L) break;
            bool ck = true;
            for (int j = minx; j <= maxx;j++)
            {
                if (map[maxy + 1][j] == 2) ck = false;
            }
            if (ck == true)
            {
                bool arr[MAX_N] = { 0, };
                arr[l] = 1;
                for (int a = maxy; a >= miny; a--)
                {
                    for (int b = minx; b <= maxx; b++)
                    {
                        arr[kmap[a + 1][b]] = 1;
                        kmap[a + 1][b] = kmap[a][b];
                        if (map[a + 1][b] == 1&&kmap[a+1][b]!=l) knights[kmap[a + 1][b]].damage++;

                        if (a == miny) kmap[a][b] = 0;
                    }
                }
                for (int j = 1; j <= N; j++)
                {
                    if (arr[j] == 1) knights[j].y++;
                }
            }
        }
        else
        {
            for (int j = 0; j < knights[l].h; j++)
            {
                int mminx = x;
                int mmaxx = x+knights[l].w-1;
                while (1)
                {
                    if (map[y + j][mminx] != 2 && kmap[y + j][mminx] == 0)
                    {
                        break;
                    }
                    else if (map[y + j][mminx] != 2 && kmap[y + j][mminx] > 0)
                    {
                        if (knights[kmap[y + j][mminx]].x < minx) minx = knights[kmap[y + j][mminx]].x;
                        if (knights[kmap[y + j][mminx]].y + knights[kmap[y + j][mminx]].h > maxy) maxy = knights[kmap[y + j][mminx]].y + knights[kmap[y + j][mminx]].h - 1;
                        if (knights[kmap[y + j][mminx]].y < miny) miny = knights[kmap[y + j][mminx]].y;
                    }
                    if (is_range(mminx - 1, y + j) == false) break;
                    mminx--;
                }
                maxx = mmaxx;
                minx = mminx+1;
            }
            if (minx <1) break;
            bool ck = true;
            for (int j = miny; j <= maxy; j++)
            {
                if (map[j][miny] == 2) ck = false;
            }
            if (ck == true)
            {
                bool arr[MAX_N] = { 0, };
                arr[l] = 1;
                for (int a = minx; a < maxx; a++)
                {
                    for (int b = miny; b <= maxy; b++)
                    {
                        arr[kmap[b][a - 1]] = 1;
                        kmap[b][a - 1] = kmap[b][a];
                        if (map[b][a - 1] == 1&&kmap[b][a-1]!=l) knights[kmap[b][a - 1]].damage++;
                        if (a == maxx) kmap[b][a] = 0;
                    }
                }
                for (int j = 1; j <= N; j++)
                {
                    if (arr[j] == 1) knights[j].x--;
                }
            }
        }
        for (int a = 1; a <= N; a++)
        {
            da[a] = knights[a].damage;
            if (knights[a].damage > 0 && knights[a].heart - knights[a].damage <= 0)
            {
                knights[a].state = -1;
            }          
        }
        for (int a = 1; a <= L; a++)
        {
            for (int b = 1; b <= L; b++)
            {
                if (kmap[a][b] > 0 && knights[kmap[a][b]].state == -1)
                {
                    kmap[a][b] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if(knights[i].state!=-1)
            ans += knights[i].damage;
    }
    cout << ans;
    return 0;
}