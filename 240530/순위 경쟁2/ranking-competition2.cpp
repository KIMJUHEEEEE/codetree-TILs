#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int ans = 0;
    int cnta = 0;
    int cntb = 0;
    int price = 0;//0:a&b, 1:a, 2:b
    for (int i = 0; i < n; i++)
    {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'A') cnta += b;
        else if (a == 'B') cntb += b;
        if (cnta == cntb && price != 0) { ans++; price = 0; }
        if (cnta > cntb && price != 1) {  ans++; price = 1;}
        if (cnta < cntb && price != 2) {  ans++; price = 2;}
    }
    cout << ans;
    return 0;
}