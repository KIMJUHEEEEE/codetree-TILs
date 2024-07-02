#include <iostream>
#include <string>
#include <vector>
using namespace std;

void move(string &str)
{
    char c = str[str.size()-1];
    for (int i = str.size() - 1; i >0; i--)
    {
        str[i] = str[i - 1];
    }
    str[0] = c;
}

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    int ans = 20;
    int num = 0;
    while (num < 10)
    {
        vector<char> vc;
        vector<int> v;
        int cnt = 1;
        vc.push_back(str[0]);
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                cnt = 1;
                vc.push_back(str[i + 1]);
            }
        }
        v.push_back(cnt);
        ans = min(ans, int(vc.size() + v.size()));
        if(v[0]==10) ans++;
        move(str);
        num++;
    }
    cout << ans;
    return 0;
}