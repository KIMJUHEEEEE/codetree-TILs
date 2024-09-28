#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int Id;
    int parentId;
    int maxDeepth;
    int Color;
    int LastChange;
    vector<int> childs;
    
};

Node arr[100001];

bool checkChild(int pId,int depth)
{
    if (pId == -1) return true;
    if (arr[pId].maxDeepth <depth) return false;
    checkChild(arr[pId].parentId, depth + 1);
}
void changeColor(int mId, int color,int i)
{
    arr[mId].Color = color;
    arr[mId].LastChange = i;
}
int checkColor(int mId,int i,int color)
{
    if (arr[mId].parentId == -1) return color;
    if (arr[mId].LastChange > i)
    {
        i = arr[mId].LastChange;
        color = arr[mId].Color;
    }
    checkColor(arr[mId].parentId, i, color);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int mId, pId, color, max_depth;
        switch (num)
        {
        case 100:
            cin >> mId >> pId >> color >> max_depth;
            if (pId == -1)
            {
                arr[mId].Id=mId;
                arr[mId].parentId = pId;
                arr[mId].Color = color;
                arr[mId].LastChange = i;
                arr[mId].maxDeepth = max_depth;
                arr[pId].childs.push_back(mId);

            }
            else if(arr[mId].Id==0&&checkChild(pId, max_depth) == true)
            {
                arr[mId].Id = mId;
                arr[mId].parentId = pId;
                arr[mId].Color = color;
                arr[mId].LastChange = i;
                arr[mId].maxDeepth = max_depth;
                arr[pId].childs.push_back(mId);

            }
            break;
        case 200:
            cin >> mId >> color;
            changeColor(mId, color,i);
            break;
        case 300:
            cin >> mId;
            cout<<checkColor(mId,arr[mId].LastChange,arr[mId].Color);
            break;
        case 400:
            cout << 1<<endl;
            break;
        }
    }
    return 0;
}