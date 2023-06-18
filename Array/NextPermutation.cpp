#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 31. 下一个排列

//      链接：https://leetcode.cn/problems/next-permutation/

//      整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
//      例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：
//          [1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
//      整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
//      更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
//      那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
//      如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列
//      （即，其元素按升序排列）。
//      例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
//      类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
//      而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，
//      因为 [3,2,1] 不存在一个字典序更大的排列。
//      给你一个整数数组 nums ，找出 nums 的下一个排列。
//      必须 原地 修改，只允许使用额外常数空间。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：[1,3,2]
//      示例 2：
//          输入：nums = [3,2,1]
//          输出：[1,2,3]
//      示例 3：
//          输入：nums = [1,1,5]
//          输出：[1,5,1]
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 100

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> NextPermutation(vector<int> &vec);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    vector<int> ans = NextPermutation(vec);
    printf("下一个排列为：\n");
    printVecElement(ans);
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

vector<int> NextPermutation(vector<int> &vec)
{
    vector<int> nums(vec);
    int l = nums.size();
    int i = l - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = l - 1;
        while(j >= 0 && nums[i] >= nums[j]){
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
    return nums;
}