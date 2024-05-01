#include <iostream>
using namespace std;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<"HelloWorld"<<endl;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    print(n);
    return 0;
}