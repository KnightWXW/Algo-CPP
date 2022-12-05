#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//      LeetCode 523. 连续的子数组和

//      链接：https://leetcode.cn/problems/continuous-subarray-sum/

//      给你一个整数数组 nums 和一个整数 k，
//      编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
//           子数组大小 至少为 2 ，且
//           子数组元素总和为 k 的倍数。
//      如果存在，返回 true ；否则，返回 false 。
//      如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。
//      0 始终视为 k 的一个倍数。

//      示例 1：
//          输入：nums = [23,2,4,6,7], k = 6
//          输出：true
//          解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。

//      示例 2：
//          输入：nums = [23,2,6,4,7], k = 6
//          输出：true
//          解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。
//                42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。

//      示例 3：
//           输入：nums = [23,2,6,4,7], k = 13
//           输出：false

//      提示：
//          1 <= nums.length <= 105
//          0 <= nums[i] <= 109
//          0 <= sum(nums[i]) <= 2^31 - 1
//          1 <= k <= 2^31 - 1

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
void printBool(bool b);
vector<int> generateRandomVec(int low, int high, int len);

bool checkSubarraySum_A(vector<int> &nums, int k);
bool checkSubarraySum_B(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    int k = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 20, n);
    printVecElement(vec);
    bool ans1 = checkSubarraySum_A(vec, k);
    printBool(ans1);
    bool ans2 = checkSubarraySum_B(vec, k);
    printBool(ans2);
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

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
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

// 前缀和：
// Time: O(n2)
// Space: O(n)

// 同余性质:
// 为什么想要 b - a 为 k 的倍数，只需要确保 b 和 a 模 k 相同即可？
// 我们令 b = x * k + r1，a = y * k + r2，那么 r1 和 r2 分别为 b 和 a 模 k 的值。
// 即有： b - a = (x * k + r1) - (y * k + r2) =(x - y) * k + (r1 - r2)
// 由 b - a 为 k 的倍数，可以推导出 r1 = r2，即 b 和 a 模 k 相同。
// 反过来由「b 和 a 模 k 相同」可推导出「b - a 为 k 的倍数」。
bool checkSubarraySum_A(vector<int> &nums, int k)
{
    int l = nums.size();
    vector<int> preSum (l + 1, 0);
    for(int i = 1; i <= l; i++){
        preSum[i] = preSum[i - 1] + nums[i - 1];
    }

    for(int i = 0; i <= l - 2; i++){
        for(int j = i + 2; j <= l; j++){
            int tem = preSum[j] - preSum[i];
            if(tem % k == 0){
                return true;
            }
        }
    }
    return false;
}

// 前缀和 + 哈希表：
// Time: O(n)
// Space: O(n)
bool checkSubarraySum_B(vector<int> &nums, int k)
{
    int l = nums.size();
    vector<int> preSum (l + 1, 0);
    unordered_map<int,bool> hmap;
    for(int i = 1; i <= l; i++){
        preSum[i] = preSum[i - 1] + nums[i - 1];
    }

    for(int i = 2; i <= l; i++){
        hmap[preSum[i - 2] % k] = true;
        if(hmap[preSum[i] % k] == true){
            return true;
        }
    }
    return false;
}