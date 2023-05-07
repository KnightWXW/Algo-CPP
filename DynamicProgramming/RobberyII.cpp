#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//      LeetCode 213. 打家劫舍 II

//      链接：https://leetcode.cn/problems/house-robber-ii/

//      你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
//      这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//      同时，相邻的房屋装有相互连通的防盗系统，
//      如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//      给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下，
//      今晚能够偷窃到的最高金额。
//      示例 1：
//          输入：nums = [2,3,2]
//          输出：3
//          解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 
//                因为他们是相邻的。
//      示例 2：
//          输入：nums = [1,2,3,1]
//          输出：4
//          解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//                偷窃到的最高金额 = 1 + 3 = 4。
//      示例 3：
//          输入：nums = [1,2,3]
//          输出：3
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 1000

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int robberyII_A(vector<int> vec);
int dfsRobberyII_A(vector<int> vec, int index);
int robberyII_B(vector<int> vec);
int dfsRobberyII_B(vector<int> vec, int index, int *arr);
int robberyII_C(vector<int> vec);
int robberyII_D(vector<int> vec);

int main()
{
    vector<int> vec = generateRandomVec(1, 100, 25);
    printVecElement(vec);
    printf("暴力递归：%d\n", robbery_A(vec));
    printf("记忆化搜索：%d\n", robbery_B(vec));
    printf("动态规划：%d\n", robbery_C(vec));
    printf("动态规划(空间优化): %d\n", robbery_D(vec));
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

