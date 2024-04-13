#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 228. 汇总区间

//      链接：https://leetcode.cn/problems/summary-ranges/

//      给定一个  无重复元素 的 有序 整数数组 nums 。
//      返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
//      也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
//      并且不存在属于某个范围但不属于 nums 的数字 x 。
//      列表中的每个区间范围 [a,b] 应该按如下格式输出：
//      "a->b" ，如果 a != b
//      "a" ，如果 a == b
//      示例 1：
//          输入：nums = [0,1,2,4,5,7]
//          输出：["0->2","4->5","7"]
//          解释：区间范围是：
//              [0,2] --> "0->2"
//              [4,5] --> "4->5"
//              [7,7] --> "7"
//      示例 2：
//          输入：nums = [0,2,3,4,6,8,9]
//          输出：["0","2->4","6","8->9"]
//          解释：区间范围是：
//              [0,0] --> "0"
//              [2,4] --> "2->4"
//              [6,6] --> "6"
//              [8,9] --> "8->9"
//      提示：
//          0 <= nums.length <= 20
//          -231 <= nums[i] <= 231 - 1
//          nums 中的所有值都 互不相同
//          nums 按升序排列

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void printString(string s);
void printStringVector(vector<string> vec);

vector<string> SummaryRanges(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 100, n);
    sort(vec.begin(), vec.end());
    printVecElement(vec);
    vector<string> ans_A = SummaryRanges(vec);
    printf("恰好覆盖数组中所有数字 的 最小有序 区间范围列表为: \n");
    printStringVector(ans_A);
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

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printString(vec[i]);
    }
}

vector<string> SummaryRanges(vector<int>& nums)
{
    int l = nums.size();
    
}