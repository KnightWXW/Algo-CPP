#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 2226. 每个小孩最多能分到多少糖果

//      链接：https://leetcode.cn/problems/maximum-candies-allocated-to-k-children/

//      给你一个 下标从 0 开始 的整数数组 candies 。
//      数组中的每个元素表示大小为 candies[i] 的一堆糖果。
//      你可以将每堆糖果分成任意数量的 子堆 ，但 无法 再将两堆合并到一起。
//      另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。
//      每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。
//      返回每个小孩可以拿走的 最大糖果数目 。
//      示例 1：
//          输入：candies = [5,8,6], k = 3
//          输出：5
//          解释：可以将 candies[1] 分成大小分别为 5 和 3 的两堆，
//               然后把 candies[2] 分成大小分别为 5 和 1 的两堆。
//               现在就有五堆大小分别为 5、5、3、5 和 1 的糖果。
//               可以把 3 堆大小为 5 的糖果分给 3 个小孩。
//               可以证明无法让每个小孩得到超过 5 颗糖果。
//      示例 2：
//          输入：candies = [2,5], k = 11
//          输出：0
//          解释：总共有 11 个小孩，但只有 7 颗糖果，
//               但如果要分配糖果的话，必须保证每个小孩至少能得到 1 颗糖果。
//               因此，最后每个小孩都没有得到糖果，答案是 0 。
//      提示：
//          1 <= candies.length <= 105
//          1 <= candies[i] <= 107
//          1 <= k <= 1012

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int MaximumCandies(vector<int> &candies, long long k);
bool JudgeCandiesMatch(vector<int> &candies, long long k, long long cur);

int main()
{
    vector<int> vec = generateRandomVec(1, 30, 25);
    long long k = (long long)generateRandomNum(1, 30);
    printVec(vec);
    int ans = MaximumCandies(vec, k);
    printf("将糖果分配给 %lld 个小孩完成, 使每个小孩分到 相同数量 的糖果。\n每个小孩可以拿走的 最大糖果数目为 %d。", k, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
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
    printf("vector的元素依次为: ");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int MaximumCandies(vector<int> &candies, long long k)
{
    long long sumAll = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        sumAll += candies[i];
    }
    if (sumAll < k)
    {
        return 0;
    }
    long long left = 1;
    long long right = sumAll / k;
    long long ans = 0;
    while (left <= right)
    {
        long long mid = left + ((right - left) >> 1);
        if (JudgeCandiesMatch(candies, k, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return (int)ans;
}

bool JudgeCandiesMatch(vector<int> &candies, long long k, long long cur)
{
    int l = candies.size();
    long long cnt = 0;
    for (int i = 0; i < l; i++)
    {
        cnt += (long long)(candies[i] / cur);
    }
    return cnt >= k;
}