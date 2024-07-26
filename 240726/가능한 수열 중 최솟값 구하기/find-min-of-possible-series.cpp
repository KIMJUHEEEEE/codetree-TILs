#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
vector<string> s;
bool e=false;
bool ck(string str)
{
    //cout << str << endl;
    for (int j = 2; j <= str.size() / 2; j++)
    {
        for (int i = 0; i <= str.size()-2*j; i++)
        {
            int cnt = 0;
            for (int k = 0; k < j; k++)
            {
                if (str[i + k] == str[i + k + j]) cnt++;
            }
            if (cnt == j) return false;
        }
    }
    return true;
}

void rec(int idx)
{
    string str;
    for (int i = 0; i < v.size(); i++)
    {
        str += to_string(v[i]);
    }
    if (ck(str) == false)
    {
        return;
    }
    if (idx == n)
    {
        e=true;
        s.push_back(str);
        return;
    }
    if(e==true) return;
    for (int i = 4; i < 7; i++)
    {
        if (v[v.size() - 1] != i)
        {
            v.push_back(i);
            rec(idx + 1);
            v.pop_back();
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    v.push_back(4);
    if (n == 1) {
        cout << 4; return 0;
    }
    else if (n == 2)
    {
        cout << 45; return 0;
    }
    else if (n == 3)
    {
        cout << 454; return 0;
    }
    if (n > 3)
    {
        v.push_back(5);
        v.push_back(4);
        rec(3);
        cout << s[0];
    }
    return 0;
}