#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1283. 使结果不超过阈值的最小除数

//      链接：https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/

//      给你一个整数数组 nums 和一个正整数 threshold，
//      你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
//      请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
//      每个数除以除数后都向上取整，比方说 7/3 = 3，10/2 = 5。
//      题目保证一定有解。
//      示例 1：
//          输入：nums = [1,2,5,9], threshold = 6
//          输出：5
//          解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
//          如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
//      示例 2：
//          输入：nums = [2,3,5,7,11], threshold = 11
//          输出：3
//      示例 3：
//          输入：nums = [19], threshold = 5
//          输出：4
//      提示：
//          1 <= nums.length <= 5 * 10^4
//          1 <= nums[i] <= 10^6
//          nums.length <= threshold <= 10^6

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int SmallestDivisor(vector<int> &nums, int threshold);
bool JudgeMatchedDivisor(vector<int> &nums, int threshold, int div);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 30, n);
    int k = generateRandomNum(n, 30);
    printVec(vec);
    int ans = SmallestDivisor(vec, k);
    printf("结果 小于等于阈值 %d 的除数中 最小 的 为 %d。", k, ans);
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
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int SmallestDivisor(vector<int> &nums, int threshold)
{
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeMatchedDivisor(nums, threshold, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

bool JudgeMatchedDivisor(vector<int> &nums, int threshold, int div)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] / div;
        if (nums[i] % div != 0)
        {
            sum++;
        }
    }
    return sum <= threshold;
}