#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      变式题目：
//          给定一个数组arr，给定一个值v，
//          求 子数组平均值 小于等于v 的 最长子数组长度。

//      每个数字 都 减去v，然后 计算 这个数组中 累加和 小于等于 0 的 最长子数组的长度

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int digitSum(vector<int> vec, int start, int end);
int minElementOfVec(vector<int> vec, int start, int end);
int maxElementOfVec(vector<int> vec, int start, int end);
int longestSubArrayLengthLessAndEqualAverageSum_A(vector<int> vec, int k);
int longestSubArrayLengthLessAndEqualAverageSum_B(vector<int> vec, int k);
int longestSubArrayLengthLessAndEqualAverageSum_C(vector<int> vec, int k);

int main()
{
    vector<int> vec = generateRandomVec(-2, 2, 5);
    int sumAll = digitSum(vec, 0, vec.size() - 1);
    int minNum = minElementOfVec(vec, 0, vec.size() - 1);
    int maxNum = maxElementOfVec(vec, 0, vec.size() - 1);
    printVecElement(vec);
    int k = generateRandomNum(minNum, maxNum);
    printf("(假设答案法)子数组平均值 小于等于%d 的 最长子数组长度为%d\n", k, longestSubArrayLengthLessAndEqualAverageSum_A(vec, k));
    printf("(暴力循环)子数组平均值 小于等于%d 的 最长子数组长度为%d\n", k, longestSubArrayLengthLessAndEqualAverageSum_B(vec, k));
    printf("(前缀和数组)子数组平均值 小于等于%d 的 最长子数组长度为%d\n", k, longestSubArrayLengthLessAndEqualAverageSum_C(vec, k));
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

int maxElementOfVec(vector<int> vec, int start, int end)
{
    int maxNum = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        maxNum = max(vec[i], maxNum);
    }
    return maxNum;
}

// 假设答案法（滑动窗口 + 预处理结构）
// Time: O(n)
// Space: O(n)
int longestSubArrayLengthLessAndEqualAverageSum_A(vector<int> vec, int k)
{
    if (vec.size() <= 0)
    {
        return 0;
    }
    int n = vec.size();
    vector<int> arr(n, 0);
    vector<int> minSum(n, 0);
    vector<int> minEnd(n, 0);

    for (int i = 0; i < n; i++)
    {
            arr[i] = vec[i] - k;
    }

    minSum[n - 1] = arr[n - 1];
    minEnd[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (minSum[i + 1] >= 0)
        {
            minSum[i] = arr[i];
            minEnd[i] = i;
        }
        else
        {
            minSum[i] = arr[i] + minSum[i + 1];
            minEnd[i] = minEnd[i + 1];
        }
    }

    int end = 0, sum = 0, ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (end < arr.size() && minSum[end] + sum <= 0)
        {
            sum += minSum[end];
            end = minEnd[end] + 1;
        }

        ans = max(ans, end - i);

        if (end > i)
        {
            sum -= arr[i];
        }
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
int longestSubArrayLengthLessAndEqualAverageSum_B(vector<int> vec, int k)
{
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            if (digitSum(vec, i, j) <= k * (j - i + 1))
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
int longestSubArrayLengthLessAndEqualAverageSum_C(vector<int> vec, int k)
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
            if (sumArr[j] - sumArr[i] <= k * (j - i))
            {
                ans = max(ans, j - i);
            }
        }
    }
    return ans;
}