#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    int cnt;    int mul = 1;
    if (n > 5) {
        cnt = 250; 
        if (a1 >= n - 1) a1 -=n;
        if (b1 >= n - 1) b1 -= n;
        if (c1 >= n - 1) c1 -= n;
        if (a2 >= n - 1) a2 -= n;
        if (b2 >= n - 1) b2 -= n;
        if (c2 >= n - 1) c2 -= n;
        n = 5;
        if (abs(a1 - a2) <= n - 1) mul *= abs(n - abs(a1 - a2));
        if (abs(b1 - b2) <= n - 1) mul *= abs(n - abs(b1 - b2));
        if (abs(c1 - c2) <= n - 1) mul *= abs(n - abs(c1 - c2));
    }
    else
    {
        cnt = n * n * n * 2;
        if (abs(a1 - a2) <= n - 1) mul *= n;
        if (abs(b1 - b2) <= n - 1) mul *= n;
        if (abs(c1 - c2) <= n - 1) mul *= n;
    }
    cout << cnt - mul;
    return 0;
}