#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 453. 最小操作次数使数组元素相等

//      链接：https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

//      给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。
//      返回让数组所有元素相等的最小操作次数。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：3
//          解释：
//              只需要3次操作（注意每次操作会增加两个元素的值）：
//              [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//      示例 2：
//          输入：nums = [1,1,1]
//          输出：0
//      提示：
//          n == nums.length
//          1 <= nums.length <= 105
//          -109 <= nums[i] <= 109
//          答案保证符合 32-bit 整数

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MinMovesToEqualArrayElements(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    int ans_A = MinMovesToEqualArrayElements(vec);
    printf("让数组所有元素相等的最小操作次数为: %d\n", ans_A);
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

// 每次操作既可以理解为使 n−1 个元素增加 1，也可以理解使 1 个元素减少 1
int MinMovesToEqualArrayElements(vector<int> &nums)
{
    int l = nums.size();
    int ans = 0;
    int minVal = *min_element(nums.begin(), nums.end());
    for (int i = 0; i < l; i++)
    {
        ans += (nums[i] - minVal);
    }
    return ans;
}