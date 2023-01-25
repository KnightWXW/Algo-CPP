#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 55. 跳跃游戏

//      链接：https://leetcode.cn/problems/jump-game/

//      给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//      数组中的每个元素代表你在该位置可以跳跃的最大长度。
//      判断你是否能够到达最后一个下标。

//      示例 1：
//      输入：nums = [2,3,1,1,4]
//      输出：true
//      解释：可以先跳 1 步，从下标 0 到达下标 1,
//            然后再从下标 1 跳 3 步到达最后一个下标。
//      示例 2：
//      输入：nums = [3,2,1,0,4]
//      输出：false
//      解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ，
//           所以永远不可能到达最后一个下标。
//      提示：
//          1 <= nums.length <= 3 * 104
//          0 <= nums[i] <= 105

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

bool CanJumpI_A(vector<int> nums);
bool CanJumpI_B(vector<int> nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> arr = generateRandomVec(0, 3, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    if (CanJumpI_A(arr))
    {
        printf("能够 到达最后一个下标。\n");
    }
    else
    {
        printf("不能够 到达最后一个下标。\n");
    }

    if (CanJumpI_B(arr))
    {
        printf("能够 到达最后一个下标。\n");
    }
    else
    {
        printf("不能够 到达最后一个下标。\n");
    }
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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

bool CanJumpI_A(vector<int> nums){
    int maxRange = 0;
    for(int i = 0; i < nums.size(); i++){
        if (i > maxRange){
            return false;
        }
        maxRange = max(maxRange, i + nums[i]);
    }
    return true;
}

bool CanJumpI_B(vector<int> nums){
    int maxRange = 0;
    for(int i = 0; i < nums.size(); i++){
        if (i <= maxRange){
            maxRange = max(maxRange, i + nums[i]);
            if(maxRange >= nums.size() - 1){
                return true;
            }
        }
    }
    return false;
}