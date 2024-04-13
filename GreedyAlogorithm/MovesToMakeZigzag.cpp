#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 1144. 递减元素使数组呈锯齿状

//      链接：https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/

//      给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。
//      如果符合下列情况之一，则数组 A 就是 锯齿数组：
//      每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
//      或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
//      返回将数组 nums 转换为锯齿数组所需的最小操作次数。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：2
//          解释：我们可以把 2 递减到 0，或把 3 递减到 1。
//      示例 2：
//          输入：nums = [9,6,1,6,2]
//          输出：4
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 1000

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MovesToMakeZigzag(vector<int> &nums);
int MovesToMakeZigzagDFS(vector<int> &nums, int start);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    int ans = MovesToMakeZigzag(vec);
    printf("将数组 转换为锯齿数组 所需的最小操作次数 %d。\n", ans);
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

// 贪心：
// Time: O(N)
// Space: O(1)
int MovesToMakeZigzag(vector<int> &nums)
{
    return min(MovesToMakeZigzagDFS(nums, 0), MovesToMakeZigzagDFS(nums, 1));
}

int MovesToMakeZigzagDFS(vector<int> &nums, int start)
{
    int l = nums.size();
    int ans = 0;
    for (int i = start; i < l; i += 2)
    {
        int cnt = 0;
        if (i - 1 >= 0)
        {
            cnt = max(cnt, nums[i] - nums[i - 1] + 1);
        }
        if (i + 1 < l)
        {
            cnt = max(cnt, nums[i] - nums[i + 1] + 1);
        }
        ans += cnt;
    }
    return ans;
}

