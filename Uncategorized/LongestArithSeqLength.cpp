#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 1027. 最长等差数列

//      链接：https://leetcode.cn/problems/longest-arithmetic-subsequence/

//      给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
//      回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik]，
//      且 0 <= i1 < i2 < ... < ik <= nums.length - 1。
//      并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，
//      那么序列 seq 是等差的。
//      示例 1：
//          输入：nums = [3,6,9,12]
//          输出：4
//          解释： 
//              整个数组是公差为 3 的等差数列。
//      示例 2：
//          输入：nums = [9,4,7,2,10]
//          输出：3
//          解释：
//              最长的等差子序列是 [4,7,10]。
//      示例 3：
//          输入：nums = [20,1,15,3,10,5,8]
//          输出：4
//          解释：
//              最长的等差子序列是 [20,15,10,5]。
//      提示：
//          2 <= nums.length <= 1000
//          0 <= nums[i] <= 500

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int LongestArithSeqLength(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 500, n);
    printVecElement(vec);
    int ans_A = LongestArithSeqLength(vec);
    printf("最长的等差子序列长度 为：%d\n", ans_A);
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

int LongestArithSeqLength(vector<int>& nums)
{
    int l = nums.size();
    
}