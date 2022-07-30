#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//      给定一个无序数组arr（arr[i] 可正可负，可零）与一个正整数 k，
//      找到 arr 的所有 子数组 里，
//      累加和 等于 k 并且长度最大的子数组，并返回其最大长度。
//
//      变式题目：
//          给定一个由0，1，-1组成的无序数组arr，
//          找到arr的所有子数组里，
//          累加和等于0，且长度最大的子数组，返回其最大长度。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int digitSum(vector<int> vec, int start, int end);
int minElementOfVec(vector<int> vec, int start, int end);
int longestSubArrayLengthEqualSum_A(vector<int> vec, int k);
int longestSubArrayLengthEqualSum_B(vector<int> vec, int k);
int longestSubArrayLengthEqualSum_C(vector<int> vec, int k);

int main()
{
    vector<int> vec = generateRandomVec(-5, 5, 30);
    int sumAll = digitSum(vec, 0, vec.size() - 1);
    int minNum = minElementOfVec(vec, 0, vec.size() - 1);
    printVecElement(vec);
    int k = generateRandomNum(minNum, sumAll);
    printf("(预处理结构（哈希表）优化)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthEqualSum_A(vec, k));
    printf("(暴力循环)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthEqualSum_B(vec, k));
    printf("(前缀和数组)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthEqualSum_C(vec, k));
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

// 预处理结构（哈希表）优化：
// Time: O(n)
// Space: O(n)
int longestSubArrayLengthEqualSum_A(vector<int> vec, int k)
{
    if (vec.size() <= 0)
    {
        return 0;
    }

    // map:  Key:     记录 前缀和 为 key
    //       Value:   记录 前缀和 为 key 最早 出现 的 位置为 value
    //                (value为该子数组的结尾索引)
    unordered_map<int, int> hashMap;
    hashMap[0] = -1;
    int ans = 0, sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        if (hashMap.find(sum - k) != hashMap.end())
        {
            ans = max(ans, i - hashMap[sum - k]);
        }
        if (hashMap.find(sum) == hashMap.end())
        {
            hashMap[sum] = i;
        }
    }
    return ans;
}

// 暴力循环：
// Time: O(n^3)
// Space: O(1)
int longestSubArrayLengthEqualSum_B(vector<int> vec, int k)
{
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            if (digitSum(vec, i, j) == k)
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
int longestSubArrayLengthEqualSum_C(vector<int> vec, int k)
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
            if (sumArr[j] - sumArr[i] == k)
            {
                ans = max(ans, j - i);
            }
        }
    }
    return ans;
}