#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 18. 四数之和

//      链接：https://leetcode.cn/problems/4sum/

//      给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
//      请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//      0 <= a, b, c, d < n
//      a、b、c 和 d 互不相同
//      nums[a] + nums[b] + nums[c] + nums[d] == target
//      你可以按 任意顺序 返回答案 。
//      示例 1：
//          输入：nums = [1,0,-1,0,-2,2], target = 0
//          输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//      示例 2：
//          输入：nums = [2,2,2,2,2], target = 8
//          输出：[[2,2,2,2]]
//      提示：
//          1 <= nums.length <= 200
//          -109 <= nums[i] <= 109
//          -109 <= target <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);
void print2DVecElement(vector<vector<int>> vec);

vector<vector<int>> FourSum(vector<int>& nums, int target);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-10, 10, n);
    printVec(vec);
    vector<vector<int>> ans = ThreeSum(vec);
    printf("返回所有和为 0 且不重复的三元组.\n");
    print2DVecElement(ans);
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
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<vector<int>> FourSum(vector<int>& nums, int target);