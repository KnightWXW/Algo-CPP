#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

//      Huawei: 破冰船的破冰次数

//      一艘破冰船在极地考察，航行区域视作一个矩阵（由若干个纵横排列的格子组成），
//      初始时破冰船周围均是冰层，船可以上下左右方向航行。
//      由于破冰船可以通过船头部分压碎冰，因此前进方向的一个格子的冰层压碎成【可通行的水域】。
//      【可通行的水域】在船离开limit时长后，将立刻重新结冻为冰层。
//      注意：当重复通过【可通行的水域】时，再次结冰时间会重置
//      船的初始位置是【可通行的水域】，现在给定航线route,其中U,D,L,R 表示上下左右的行驶方向：
//      每次行驶前进一格，问在行驶路线中，破冰船共破了多少次？
//      示例 1：
//          输入：route = "URDLR", limit = 3
//          输出：4
//      示例 2：
//          输入：route = "RDDUURDLLURU", limit = 4
//          输出：9

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int NumOfIceBreaking(string route, int limit);

int main()
{
    int n = generateRandomNum(1, 20);
    int limit = generateRandomNum(1, 7);
    string str = generateRandomString(n);
    printf("给定航线为：\n");
    printString(str);
    int ans = NumOfIceBreaking(str, limit);
    printf("在行驶路线中，破冰船共破了 %d 次。\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "UDLR";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

int NumOfIceBreaking(string route, int limit)
{
    int l = route.size();
    int x = 0;
    int y = 0;
    int ans = 0;
    map<pair<int, int>, int> hmap;
    for (int i = 0; i < l; i++)
    {
        hmap[make_pair(x, y)] = limit;
        if (route[i] == 'U')
        {
            y++;
        }
        else if (route[i] == 'D')
        {
            y--;
        }
        else if (route[i] == 'L')
        {
            x--;
        }
        else if (route[i] == 'R')
        {
            x++;
        }
        if (hmap[make_pair(x, y)] == 0)
        {
            ans++;
        }
        for (auto v : hmap)
        {
            if (v.second > 0)
            {
                hmap[v.first]--;
            }
        }
    }
    return ans;
}
