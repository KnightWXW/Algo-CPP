#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 15. 三数之和

//      链接1 ：https://leetcode.cn/problems/3sum/
//      链接2 ：https://leetcode.cn/problems/1fGaJU/?favorite=e8X3pBZi

//      给你一个整数数组 nums ，
//      判断是否存在三元组 [nums[i], nums[j], nums[k]]
//      满足 i != j、i != k 且 j != k ，
//      同时还满足 nums[i] + nums[j] + nums[k] == 0。
//      请你返回所有和为 0 且不重复的三元组。
//      注意：答案中不可以包含重复的三元组。
//      示例 1：
//          输入：nums = [-1,0,1,2,-1,-4]
//          输出：[[-1,-1,2],[-1,0,1]]
//          解释：
//              nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//              nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//              nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//              不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//              注意，输出的顺序和三元组的顺序并不重要。
//      示例 2：
//          输入：nums = [0,1,1]
//          输出：[]
//          解释：唯一可能的三元组和不为 0 。
//      示例 3：
//          输入：nums = [0,0,0]
//          输出：[[0,0,0]]
//          解释：唯一可能的三元组和为 0 。
//      提示：
//          3 <= nums.length <= 3000
//          -105 <= nums[i] <= 105

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);
void print2DVecElement(vector<vector<int>> vec);

vector<vector<int>> ThreeSum(vector<int> &nums);

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

// 排序 + 双指针：
// Time: O(N2)
// Space: O(logN)
vector<vector<int>> ThreeSum(vector<int> &nums)
{
    int l = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int first = 0; first < nums.size(); first++)
    {
        if (nums[first] > 0)
        {
            break;
        }
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        int second = first + 1;
        int third = l - 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];
            if (sum == 0)
            {
                ans.push_back({nums[first], nums[second], nums[third]});
                while (second < third && nums[second] == nums[second + 1])
                {
                    second++;
                }
                while (second < third && nums[third] == nums[third - 1])
                {
                    third--;
                }
                second++;
                third--;
            }
            else if (sum < 0)
            {
                second++;
            }
            else
            {
                third--;
            }
        }
    }
    return ans;
}