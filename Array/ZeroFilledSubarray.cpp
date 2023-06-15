#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 2348. 全 0 子数组的数目

//      链接：https://leetcode.cn/problems/number-of-zero-filled-subarrays/

//      给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。
//      子数组 是一个数组中一段连续非空元素组成的序列。
//      示例 1：
//          输入：nums = [1,3,0,0,2,0,0,4]
//          输出：6
//          解释：
//              子数组 [0] 出现了 4 次。
//              子数组 [0,0] 出现了 2 次。
//              不存在长度大于 2 的全 0 子数组，所以我们返回 6 。
//      示例 2：
//          输入：nums = [0,0,0,2,0,0]
//          输出：9
//          解释：
//              子数组 [0] 出现了 5 次。
//              子数组 [0,0] 出现了 3 次。
//              子数组 [0,0,0] 出现了 1 次。
//              不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
//      示例 3：
//          输入：nums = [2,10,2019]
//          输出：0
//          解释：没有全 0 子数组，所以我们返回 0 。
//      提示：
//          1 <= nums.length <= 105
//          -109 <= nums[i] <= 109

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

long long ZeroFilledSubarray_A(vector<int> &nums);
long long ZeroFilledSubarray_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 100);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    long long ans_A = ZeroFilledSubarray_A(arr);
    long long ans_B = ZeroFilledSubarray_B(arr);
    printf("全部为 0 的 子数组 数目: %llu\n", ans_A);
    printf("全部为 0 的 子数组 数目: %llu\n", ans_B);
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

long long ZeroFilledSubarray_A(vector<int> &nums)
{
    int l = nums.size();
    long long zeroCnt = 0;
    long long ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == 0)
        {
            zeroCnt++;
        }
        else
        {
            ans += (zeroCnt + 1) * zeroCnt / 2;
            zeroCnt = 0;
        }
    }
    ans += (zeroCnt + 1) * zeroCnt / 2;
    return ans;
}

long long ZeroFilledSubarray_B(vector<int> &nums)
{
    int l = nums.size();
    long long zeroCnt = 0;
    long long ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == 0)
        {
            zeroCnt++;
            ans += zeroCnt;
        }
        else
        {
            zeroCnt = 0;
        }
    }
    return ans;
}