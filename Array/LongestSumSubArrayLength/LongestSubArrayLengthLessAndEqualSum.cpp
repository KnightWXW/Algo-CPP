#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//      给定一个无序数组arr（arr[i] 可正，可负，可零）与一个正整数 k，
//      找到 arr 的所有 子数组 里，
//      累加和 小于等于 k，并且长度最大的子数组，并返回其最大长度。

//      变式题目：
//          给定一个数组arr，给定一个值v，
//          求 子数组平均值 小于等于v 的 最长子数组长度。

//      每个数字都减v，然后 计算 这个数组中 累加和 小于等于0 的 最长子数组的长度

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int digitSum(vector<int> vec, int start, int end);
int minElementOfVec(vector<int> vec, int start, int end);
int longestSubArrayLengthLessAndEqualSum_A(vector<int> vec, int k);
int longestSubArrayLengthLessAndEqualSum_B(vector<int> vec, int k);
int longestSubArrayLengthLessAndEqualSum_C(vector<int> vec, int k);

int main()
{
    vector<int> vec = generateRandomVec(-10, 10, 7);
    int sumAll = digitSum(vec, 0, vec.size() - 1);
    int minNum = minElementOfVec(vec, 0, vec.size() - 1);
    printVecElement(vec);
    int k = generateRandomNum(minNum, sumAll);
    printf("(假设答案法)累加和小于等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthLessAndEqualSum_A(vec, k));
    printf("(暴力循环)累加和小于等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthLessAndEqualSum_B(vec, k));
    printf("(前缀和数组)累加和小于等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthLessAndEqualSum_C(vec, k));
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

int digitSum(vector<int> vec, int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += vec[i];
    }
    return sum;
}

int minElementOfVec(vector<int> vec, int start, int end)
{
    int minNum = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        minNum = min(vec[i], minNum);
    }
    return minNum;
}

// 假设答案法（）：
// Time: O(n)
// Space: O(n)
int longestSubArrayLengthLessAndEqualSum_A(vector<int> vec, int k)
{
    if (vec.size() <= 0)
    {
        return 0;
    }
    int n = vec.size();
    // minSum：从vec[i] 开始 的 所有的子数组中，最小累加和 为 minSum[i]
    // minEnd：获得 最小累加和minSum[i] 的 右边界索引 为 minEnd[i]
    vector<int> minSum(n, 0);
    vector<int> minEnd(n, 0);

    minSum[n - 1] = vec[n - 1];
    minEnd[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (minSum[i + 1] >= 0)
        {
            minSum[i] = vec[i];
            minEnd[i] = i;
        }
        else
        {
            minSum[i] = vec[i] + minSum[i + 1];
            minEnd[i] = minEnd[i + 1];
        }
    }

    int end = 0, sum = 0, ans = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        // while循环 
        // sum 存储 自 i 为 起始索引 的 所有子数组 在 <= k 条件下 的 最大长度。
        // end 存储 累加和 为 sum 的 子数组 右边界索引 + 1。 
        while (end < vec.size() && minSum[end] + sum <= k)
        {
            sum += minSum[end];
            end = minEnd[end] + 1;
        }

        // while循环结束之后：
		// (1) 若 以 i 开头，累加和 <=k 的 最长子数组 是 arr[i ... end-1]，
        //                  看看这个 子数组长度 能不能更新res；
		// (2) 若 以 i 开头，累加和 <=k 的 最长子数组 比 arr[i ... end-1] 更短，
        //                  更新 还是 不更新 res，都不会影响 最终结果；

        ans = max(ans, end - i);

        // 滑动窗口 大小 [i : end)：
        // 当 i < end 时, 将 sum 减去 vec[i]，看 再加上vec[end] 能否 增大长度
        if (i < end)
        {
            sum -= vec[i];
        }
        // 当 i >= end 时, 此时的滑动窗口已不存在：
        // 将 end 向右 滑动一格，与 外循环的 i 一起递增
        else
        {
            end = i + 1;
        }
    }
    return ans;
}

// 暴力循环：
// Time: O(n^3)
// Space: O(1)
int longestSubArrayLengthLessAndEqualSum_B(vector<int> vec, int k)
{
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            if (digitSum(vec, i, j) <= k)
            {
                ans = max(j - i + 1, ans);
            }
        }
    }
    return ans;
}

// 前缀和数组：
// Time: O(n^2)
// Space: O(n)
int longestSubArrayLengthLessAndEqualSum_C(vector<int> vec, int k)
{
    int ans = 0;
    vector<int> sumArr(vec.size() + 1, 0);

    for (int i = 1; i < sumArr.size(); i++)
    {
        sumArr[i] = sumArr[i - 1] + vec[i - 1];
    }

    for (int i = 0; i <= vec.size(); i++)
    {
        for (int j = i; j <= vec.size(); j++)
        {
            if (sumArr[j] - sumArr[i] <= k)
            {
                ans = max(ans, j - i);
            }
        }
    }
    return ans;
}