#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 287. 寻找重复数

//      https://leetcode.cn/problems/find-the-duplicate-number/

//      给定一个包含 n + 1 个整数的数组 nums ，
//      其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
//      假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
//      你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
//      示例 1：
//          输入：nums = [1,3,4,2,2]
//          输出：2
//      示例 2：
//          输入：nums = [3,1,3,4,2]
//          输出：3
//      提示：
//          1 <= n <= 105
//          nums.length == n + 1
//          1 <= nums[i] <= n
//          nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
//      进阶：
//          如何证明 nums 中至少存在一个重复的数字?
//          你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int len);
vector<int> shuffleVec(vector<int> vec);
void printVecElement(vector<int> vec);

int FindDuplicate_A(vector<int> &nums);
int FindDuplicate_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec0 = generateRandomVec(n);
    vector<int> vec = shuffleVec(vec0);
    printVecElement(vec);
    int ans_A = FindDuplicate_A(vec);
    int ans_B = FindDuplicate_B(vec);
    printf("(快慢指针)  数组中重复的数为 %d\n", ans_A);
    printf("(数组哈希)  数组中重复的数为 %d\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        vec.push_back(i + 1);
    }
    int v = rand() % len;
    vec.push_back(vec[v]);
    return vec;
}

vector<int> shuffleVec(vector<int> vec){
    srand((int)time(0));
    random_shuffle(vec.begin(), vec.end());
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

// 快慢指针:
//    类似于 环形链表
// Time: O(N)
// Space: O(1)
int FindDuplicate_A(vector<int>& nums){
    int slow = 0;
    int fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = 0;
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// 数组哈希：
// Time: O(N)
// Space: O(1)
int FindDuplicate_B(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        while(i < nums.size() && nums[i] != nums[nums[i] - 1]){
            swap(nums[i], nums[nums[i] - 1]);
        }
        if(i + 1 != nums[i]){
            return nums[i];
        }
    }
    return -1;
}