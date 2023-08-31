

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1402. 做菜顺序

//      链接：https://leetcode.cn/problems/reducing-dishes/

//      一个厨师收集了他 n 道菜的满意程度 satisfaction，
//      这个厨师做出每道菜的时间都是 1 单位时间。
//      一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，
//      也就是 time[i]*satisfaction[i] 。
//      请你返回做完所有菜 「喜爱时间」总和的最大值为多少。
//      你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。
//      示例 1：
//          输入：satisfaction = [-1,-8,0,5,-9]
//          输出：14
//          解释：去掉第二道和最后一道菜，最大的喜爱时间系数和为 (-1*1 + 0*2 + 5*3 = 14) 。
//              每道菜都需要花费 1 单位时间完成。
//      示例 2：
//          输入：satisfaction = [4,3,2]
//          输出：20
//          解释：按照原来顺序相反的时间做菜 (2*1 + 3*2 + 4*3 = 20)
//      示例 3：
//          输入：satisfaction = [-1,-4,-5]
//          输出：0
//          解释：大家都不喜欢这些菜，所以不做任何菜可以获得最大的喜爱时间系数。
//      提示：
//          n == satisfaction.length
//          1 <= n <= 500
//          -1000 <= satisfaction[i] <= 1000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaxSatisfaction_A(vector<int> satisfaction);
int MaxSatisfaction_B(vector<int> satisfaction);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-1000, 1000, n);
    printVecElement(vec);
    int ans_A = MaxSatisfaction_A(vec);
    int ans_B = MaxSatisfaction_A(vec);
    printf("做完所有菜「喜爱时间」总和的最大值为: %d\n", ans_A);
    printf("做完所有菜「喜爱时间」总和的最大值为: %d\n", ans_B);
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

// 贪心：
//      所有的菜按照满意程度从大到小排序，随后依次遍历每一道菜。
//      如果加入这道菜导致总喜爱时间增加，我们就可以选取这道菜，否则我们直接退出循环。
// Time: O(NlogN)
// Space: O(logN)
int MaxSatisfaction_A(vector<int> satisfaction)
{
    int l = satisfaction.size();
    int ans = 0;
    int index = 0;
    int sum = 0;
    int k = 1;
    sort(satisfaction.begin(), satisfaction.end());
    for (int i = l - 1; i >= 0; i--)
    {
        sum += satisfaction[i];
        if (sum < 0)
        {
            index = i + 1;
            break;
        }
    }
    for (int i = index; i < l; i++)
    {
        ans += k * satisfaction[i];
        k++;
    }
    return ans;
}

int MaxSatisfaction_B(vector<int> satisfaction)
{
    int l = satisfaction.size();
    int ans = 0;
    int sum = 0;
    sort(satisfaction.rbegin(), satisfaction.rend());
    for (int i = 0; i < l; i++)
    {
        sum += satisfaction[i];
        if (sum < 0)
        {
            break;
        }
        ans += sum;
    }
    return ans;
}