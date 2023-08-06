#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

//      LeetCode 2517. 礼盒的最大甜蜜度

//      链接：https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

//      给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。
//      商店组合 k 类 不同 糖果打包成礼盒出售。
//      礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。
//      返回礼盒的 最大 甜蜜度。
//      示例 1：
//          输入：price = [13,5,1,8,21,2], k = 3
//          输出：8
//          解释：选出价格分别为 [13,5,21] 的三类糖果。
//              礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
//              可以证明能够取得的最大甜蜜度就是 8 。
//      示例 2：
//          输入：price = [1,3,1], k = 2
//          输出：2
//          解释：选出价格分别为 [1,3] 的两类糖果。
//              礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
//              可以证明能够取得的最大甜蜜度就是 2 。
//      示例 3：
//          输入：price = [7,7,7,7], k = 2
//          输出：0
//          解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
//      提示：
//          2 <= k <= price.length <= 105
//          1 <= price[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaximumTastiness(vector<int> &price, int k);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 20, n);
    int k = generateRandom(1, 20);
    int ans = MaximumTastiness(vec, k);
    printVecElement(vec);
    printf("商店组合 %d 类 不同 糖果打包成礼盒出售。\n能够取得的最大甜蜜度是 %d\n", k, ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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

int MaximumTastiness(vector<int> &price, int k)
{

}