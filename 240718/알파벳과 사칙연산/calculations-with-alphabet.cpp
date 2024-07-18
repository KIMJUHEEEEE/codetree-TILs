#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;
string str;
int ans = INT_MIN;
vector<int> v;
int calculate(int a, int b, int c, int d, int e, int f)
{
    int pre = 0, next=0;
    if (str[0] == 'a') pre = v[0];
    else if (str[0] == 'b') pre = v[1];
    else if (str[0] == 'c') pre = v[2];
    else if (str[0] == 'd') pre = v[3];
    else if (str[0] == 'e') pre = v[4];
    else if (str[0] == 'f') pre = v[5];

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '-')
        {
            if (str[i + 1] == 'a') next = v[0];
            else if (str[i + 1] == 'b') next = v[1];
            else if (str[i + 1] == 'c') next = v[2];
            else if (str[i + 1] == 'd') next = v[3];
            else if (str[i + 1] == 'e') next = v[4];
            else if (str[i + 1] == 'f') next = v[5];
            pre = pre - next;
            i++;
        }
        else if (str[i] == '+')
        {
            if (str[i + 1] == 'a') next = v[0];
            else if (str[i + 1] == 'b') next = v[1];
            else if (str[i + 1] == 'c') next = v[2];
            else if (str[i + 1] == 'd') next = v[3];
            else if (str[i + 1] == 'e') next = v[4];
            else if (str[i + 1] == 'f') next = v[5];
            pre = pre + next;
            i++;
        }
        else if (str[i] == '*')
        {
            if (str[i + 1] == 'a') next = v[0];
            else if (str[i + 1] == 'b') next = v[1];
            else if (str[i + 1] == 'c') next = v[2];
            else if (str[i + 1] == 'd') next = v[3];
            else if (str[i + 1] == 'e') next = v[4];
            else if (str[i + 1] == 'f') next = v[5];
            pre = pre * next;
            i++;
        }
    }
    return pre;
}
void rec(int idx)
{
    if (idx == 6)
    {
        ans = max(ans, calculate(v[0], v[1], v[2], v[3], v[4], v[5]));
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        v.push_back(i);
        rec(idx + 1);
        v.pop_back();
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;
    rec(0);
    cout << ans;
    return 0;
}