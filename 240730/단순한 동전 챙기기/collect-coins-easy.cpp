#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> s, e;
int n;
vector<string> st;
bool arr[10];
vector<pair<int, pair<int, int>>> v;
vector<int> choice;
int ans=999;

void rec(int idx)
{
    if (idx == 3)
    {
        int sum = abs(v[choice[0]-1].second.first-s.first)+abs(v[choice[0]-1].second.second-s.second);
        for (int i = 1; i < 3; i++)
        {
            sum += abs(v[choice[i]-1].second.first - v[choice[i - 1]-1].second.first) + abs(v[choice[i]-1].second.second - v[choice[i - 1]-1].second.second);
        }
        sum += abs(v[choice[2]-1].second.first - e.first) + abs(v[choice[2]-1].second.second - e.second);
        ans = min(ans, sum);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (arr[i] == 1)
        {
            if (choice.size() > 0&&i<=choice[choice.size()-1])
            {
                continue;
            }
            choice.push_back(i);
            rec(idx + 1);
            choice.pop_back();
        }
    }

}
int main() {
    // 여기에 코드를 작성해주세요.f
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        st.push_back(str);
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'S') { s.first = j; s.second = i; }
            else if (str[j] == 'E') {
                e.first = j; e.second = i;
            }
            else if (str[j] != '.')
            {
                int a = str[j] - 48;
                arr[a] = 1;
                v.push_back(make_pair(a, make_pair(j, i)));
            }
        }
    }
    sort(v.begin(), v.end());
    rec(0);
    if(ans==999) ans=-1;
    cout << ans;
    return 0;
}