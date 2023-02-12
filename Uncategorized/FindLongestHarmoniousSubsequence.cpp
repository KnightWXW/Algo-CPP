#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      LeetCode 594. 最长和谐子序列

//      链接：https://leetcode.cn/problems/longest-harmonious-subsequence/

//      和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//      给你一个整数数组 nums，请你在所有可能的子序列中找到最长的和谐子序列的长度。
//      数组的子序列是一个由数组派生出来的序列，
//      它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
//      示例 1：
//          输入：nums = [1,3,2,2,5,2,3,7]
//          输出：5
//          解释：最长的和谐子序列是 [3,2,2,2,3]
//      示例 2：
//          输入：nums = [1,2,3,4]
//          输出：2
//      示例 3：
//          输入：nums = [1,1,1,1]
//          输出：0
//      提示：
//          1 <= nums.length <= 2 * 104
//          -109 <= nums[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int FindLongestHarmoniousSubsequence_A(vector<int> nums);
int FindLongestHarmoniousSubsequence_B(vector<int> nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 10, n);
    printVecElement(vec);
    int ans_A = FindLongestHarmoniousSubsequence_A(vec);
    int ans_B = FindLongestHarmoniousSubsequence_A(vec);
    printf("数组最长的和谐子序列的长度为 %d。\n", ans_A);
    printf("数组最长的和谐子序列的长度为 %d。\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 滑动窗口：
// Time: O(N)
// Space: O(1)
int FindLongestHarmoniousSubsequence_A(vector<int> nums)
{
    vector<int> arr(nums);
    sort(arr.begin(), arr.end());
    int l = nums.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    while (right < l)
    {
        while(left < right && arr[right] - arr[left] > 1)
        {
            left++;
        }
        if(arr[right] - arr[left] == 1)
        {
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}

// 哈希表：
// Time: O(N)
// Space: O(N)
int FindLongestHarmoniousSubsequence_B(vector<int> nums)
{
    vector<int> arr(nums);
    int ans = 0;
    unordered_map<int, int> hmap;
    for(int i = 0; i < arr.size(); i++){
        hmap[arr[i]]++;
    }
    for(auto [key, val] : hmap){
        if(hmap.count(key + 1)){
            ans = max(ans, val + hmap[key + 1]);
        }
        if(hmap.count(key - 1)){
            ans = max(ans, val + hmap[key - 1]);
        }
    }
    return ans;
}