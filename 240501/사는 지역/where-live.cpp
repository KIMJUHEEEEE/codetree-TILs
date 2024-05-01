#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class info {
public:
    string name;
    string number;
    string location;
    info() {}
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;
    info person[11];
    string max;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        string name;
        string number;
        string location;
        cin >> name >> number >> location;
        person[i].name = name;
        person[i].number = number;
        person[i].location = location;
        if (max < name) {
            max = name; idx = i;
        }
        
    }
    cout << "name " << person[idx].name << endl;
    cout << "addr " << person[idx].number << endl;
    cout << "city " << person[idx].location << endl;
    return 0;
}