#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 18. 四数之和

//      链接：https://leetcode.cn/problems/4sum/

//      给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
//      请你找出并返回满足下述全部条件且不重复的四元组
//          [nums[a], nums[b], nums[c], nums[d]]
//      （若两个四元组元素一一对应，则认为两个四元组重复）：
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

vector<vector<int>> FourSum(vector<int> &nums, int target);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(-99, 99, n);
    printVec(vec);
    int target = generateRandomNum(-100, 100);
    vector<vector<int>> ans = FourSum(vec, target);
    printf("返回所有和为 %d 且不重复的四元组.\n", target);
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
// Time: O(N3)
// Space: O(logN)
vector<vector<int>> FourSum(vector<int> &nums, int target)
{
    int l = nums.size();
    vector<vector<int>> ans;
    if (l < 4)
    {
        return ans;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < l - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < l - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1;
            int right = l - 1;
            while (left < right)
            {
                long long tem = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (tem == target)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (tem < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return ans;
}