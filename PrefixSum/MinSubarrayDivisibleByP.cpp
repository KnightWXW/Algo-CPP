#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 1590. 使数组和能被 P 整除

//      链接：https://leetcode.cn/problems/make-sum-divisible-by-p/

//      给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），
//      使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
//      请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1。
//      子数组 定义为原数组中连续的一组元素。
//      示例 1：
//          输入：nums = [3,1,4,2], p = 6
//          输出：1
//          解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4]，
//              剩余元素的和为 6 。
//      示例 2：
//          输入：nums = [6,3,5,2], p = 9
//          输出：2
//          解释：我们无法移除任何一个元素使得和被 9 整除，
//               最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9。
//      示例 3：
//          输入：nums = [1,2,3], p = 3
//          输出：0
//          解释：和恰好为 6 ，已经能被 3 整除了。
//               所以我们不需要移除任何元素。
//      示例 4：
//          输入：nums = [1,2,3], p = 7
//          输出：-1
//          解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
//      示例 5：
//          输入：nums = [1000000000,1000000000,1000000000], p = 3
//          输出：0
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 109
//          1 <= p <= 109

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

int MinSubarrayDivisibleByP(vector<int> &nums, int p);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    vector<int> ans = NextPermutation(vec);
    printf("下一个排列为：\n");
    printVecElement(ans);
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

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 前缀和 + 哈希表：
// Time: O(N)
// Space: O(N)
int MinSubarrayDivisibleByP(vector<int> &nums, int p)
{
    int l = nums.size();
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum = (nums[i] + sum) % p;
    }
    if (sum == 0)
    {
        return 0;
    }
    unordered_map<int, int> hMap;
    hMap[0] = -1;
    int pre = 0;
    int ans = l;
    for (int i = 0; i < l; i++)
    {
        pre = (pre + nums[i]) % p;
        int target = (pre - sum + p) % p;
        if (hMap.count(target) > 0)
        {
            ans = min(ans, i - hMap[target]);
        }
        hMap[pre] = i;
    }
    return ans == l ? -1 : ans;
}