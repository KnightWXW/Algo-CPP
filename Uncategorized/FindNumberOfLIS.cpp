#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 673. 最长递增子序列的个数

//      链接：https://leetcode.cn/problems/number-of-longest-increasing-subsequence/

//      给定一个未排序的整数数组 nums，返回最长递增子序列的个数 。    
//      注意 这个数列必须是 严格 递增的。
//      示例 1:
//          输入: [1,3,5,4,7]
//          输出: 2
//          解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
//      示例 2:
//          输入: [2,2,2,2,2]
//          输出: 5
//          解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
//      提示: 
//          1 <= nums.length <= 2000
//          -106 <= nums[i] <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

int FindNumberOfLIS(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 100, n);
    printf("数组元素为：\n");
    printVecElement(vec);
    int ans_A = FindNumberOfLIS(vec);
    printf("最长递增子序列的个数为：%d \n", ans_A);
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

int FindNumberOfLIS(vector<int>& nums)
{

}