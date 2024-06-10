#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i].size() < 6)
        {
            string str = "";
            for (int j = 0; j < 6 - v[i].size(); j++)
            {
                str += "0";
            }
            str += v[i];
            v[i] = str;
        }
    }
    for (int k = 0; k < 6; k++) {
        vector<vector<string>> new_v(10);
        for (int i = 0; i < n; i++) {
                char digit = v[i][v[i].size() - k - 1];
                new_v[(int)digit - '0'].push_back(v[i]);
        }
        vector<string> store_v;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < new_v[i].size(); j++) {
                store_v.push_back(new_v[i][j]);
            }
        }
        v = store_v;
    }
    for (int i = 0; i < n; i++) {
        bool ck=0;
        for(int j=0;j<6;j++)
        {
            if(v[i][j]!='0')
            {
                ck=1;
            }
            if(ck==1)
            {
                cout<<v[i][j];
            }
        }
        cout<<' ';
    }
}