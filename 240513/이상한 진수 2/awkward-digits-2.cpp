#include <iostream>
#include <string>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    bool ck = 0;
    for (int i = 0; i<str.size(); i++)
    {
        if (str[i] == '0')
        {
            str[i] = '1'; ck = 1; break;
        }
    }
    if (ck == 0)
    {
        str[str.size()-1] = '0';
    }
    int po = 1;
    int ans = 0;
    for (int i = str.size()-1; i >=0;i--)
    {
        ans += (str[i] - 48) * po;
        po *= 2;
    }
    cout << ans;
    return 0;
}