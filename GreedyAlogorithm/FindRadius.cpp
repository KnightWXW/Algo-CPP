#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 475. 供暖器

//      链接：https://leetcode.cn/problems/heaters/

//      冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
//      在加热器的加热半径范围内的每个房屋都可以获得供暖。
//      现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，
//      请你找出并返回可以覆盖所有房屋的最小加热半径。
//      说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
//      示例 1:
//          输入: houses = [1,2,3], heaters = [2]
//          输出: 1
//          解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，
//               那么所有房屋就都能得到供暖。
//      示例 2:
//          输入: houses = [1,2,3,4], heaters = [1,4]
//          输出: 1
//          解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，
//                这样所有房屋就都能得到供暖。
//      示例 3：
//          输入：houses = [1,5], heaters = [2]
//          输出：3
//      提示：
//          1 <= houses.length, heaters.length <= 3 * 104
//          1 <= houses[i], heaters[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVecA(int low, int high, int len);
vector<int> generateRandomVecB(int low, int high, int len);
void printVec(vector<int> &vec);

bool JudgeFindRadius(vector<int> &houses, vector<int> &heaters, int i, int j);
int FindRadius(vector<int> &houses, vector<int> &heaters);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> houses = generateRandomVecA(1, 50, n);
    vector<int> heaters = generateRandomVecB(1, 30, n);
    printVec(houses);
    printVec(heaters);
    int ans = FindRadius(houses, heaters);
    printf("可以覆盖所有房屋的最小加热半径 %d。", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVecA(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

vector<int> generateRandomVecB(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int FindRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i = 0, j = 0; i < houses.size(); i++)
    {
        while (JudgeFindRadius(houses, heaters, i, j))
        {
            j++;
        }
        ans = max(ans, abs(heaters[j] - houses[i]));
    }
    return ans;
}

bool JudgeFindRadius(vector<int> &houses, vector<int> &heaters, int i, int j)
{
    if (j == heaters.size() - 1 || abs(heaters[j + 1] - houses[i]) > abs(heaters[j] - houses[i]))
    {
        return true;
    }
    return false;
}