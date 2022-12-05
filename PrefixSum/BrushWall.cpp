#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      刷墙

//      链接：https://www.nowcoder.com/questionTerminal/748b891f208744a7b1f98cb4c45bde11?questionTypes=000100&mutiTagIds=1727&page=1&onlyReference=false

//      最近小明搬到了新家，他正在粉刷墙壁，但是不幸的是他粉刷的墙壁并不理想。
//      他的墙壁是一个长度为n的格子，每个格子用0表示红色，用1表示蓝色。
//      现在墙壁是一个非常混乱的颜色。
//      他想将墙壁涂成左边全是蓝色右边全是红色，可以将墙壁刷成全是红色或者蓝色。
//      请问他至少需要粉刷多少个格子墙壁刷成他想要的样子?

//      数据范围：1≤n≤10000
//      进阶：时间复杂度O(n) ，空间复杂度O(n)

//      输入描述:
//          第一行一个整数 n (1≤n≤100000)。
//          第二行个长度为 n 的 01串，0 表示红色，1 表示蓝色。
//      输出描述:
//          输出一个整数表示最少粉刷次数。

//      示例1
//          输入    3
//          输出    1
//          说明    只需要将最后一个刷成红色。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int BrushWall(vector<int> vec);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 1, n);
    printVecElement(vec);
    int ans = BrushWall(vec);
    printf("至少需要粉刷%d个格子墙壁 \n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// blue: i - preSum[i]           ---  vec[0 ... i - 1]将 0 变为 1 刷墙次数
// red: preSum[l] - preSum[i]    ---  vec[i ... l]    将 1 变为 0 刷墙次数
int BrushWall(vector<int> vec)
{
    int l = vec.size();
    vector<int> preSum = vector<int>(l + 1, 0);
    for (int i = 1; i <= l; i++)
    {
        preSum[i] = preSum[i - 1] + vec[i - 1];
    }
    int ans = l;
    for (int i = 1; i <= l; i++)
    {
        int blue = i - preSum[i];
        int red = preSum[l] - preSum[i];
        ans = min(blue + red, ans);
    }
    return ans;
}