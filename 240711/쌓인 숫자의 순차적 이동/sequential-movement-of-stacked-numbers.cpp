#include <iostream>
#include <vector>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> arr[101][101];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            arr[i][j].push_back(num);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int beads;
        cin >> beads;
        bool ck = 0;
        int idx = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                for (int s = 0; s < arr[y][x].size(); s++)
                {
                    if (beads == arr[y][x][s])
                    {
                        idx = s;
                        ck = 1; break;
                    }
                }
                if (ck == 0) continue;
                if(ck==1)
                { int max = 0;
                        int maxx = x;
                        int maxy = y;
                        ck = 1;
                        int cnt=0;
                        for (int k = 0; k < 8; k++)
                        {
                            if (y + dy[k] < 0 || y + dy[k] == n || x + dx[k] < 0 || x + dx[k] == n) continue;
                            else
                            {
                                //if (arr[y][x].size() == 0) continue;
                                for (int s = 0; s < arr[y+dy[k]][x+dx[k]].size(); s++)
                                {
                                    if (arr[y + dy[k]][x + dx[k]].size() > 0)
                                    {
                                        cnt++;
                                        if (arr[y + dy[k]][x + dx[k]][s] > max)
                                        {
                                            max = arr[y + dy[k]][x + dx[k]][s];
                                            maxx = x + dx[k];
                                            maxy = y + dy[k];
                                        }
                                    }
                                }
                            }
                        }
                        if(cnt>0)
                        {for (int s = idx; s < arr[y][x].size(); s++)
                        {
                            if (arr[y][x][s] != 0)
                            {
                                arr[maxy][maxx].push_back(arr[y][x][s]);

                            }
                        }
                        for (int s = idx; s < arr[y][x].size(); s++)
                        {
                            arr[y][x].pop_back();
                            s--;
                        }}
                        break;
                }
                if (ck == 1) break;
            }
            if (ck == 1) break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j].size() == 0) cout << "None" << endl;
            else
            {
                for (int k = arr[i][j].size() - 1; k >= 0; k--)
                {
                    cout << arr[i][j][k] << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}