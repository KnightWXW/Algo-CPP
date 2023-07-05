#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 670. 最大交换

//      链接：https://leetcode.cn/problems/maximum-swap/

//      给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
//      示例 1 :
//          输入: 2736
//          输出: 7236
//          解释: 交换数字2和数字7。
//      示例 2 :
//          输入: 9973
//          输出: 9973
//          解释: 不需要交换。
//      注意:
//          给定数字的范围是 [0, 108]

int generateRandomNum(int low, int high);

int MaximumSwap_A(int num);
int MaximumSwap_B(int num);

int main()
{
    int num = generateRandomNum(0, 10000000);
    int ans_A = MaximumSwap_A(num);
    int ans_B = MaximumSwap_B(num);
    printf("至多可以交换一次 %d 中的任意两位。\n能得到的最大值为 %d。\n", num, ans_A);
    printf("至多可以交换一次 %d 中的任意两位。\n能得到的最大值为 %d。\n", num, ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

// 暴力双循环：
// Time: O(N^2)
// Space: O(N)
int MaximumSwap_A(int num)
{
    if (num >= 0 && num <= 9)
    {
        return num;
    }
    string str = to_string(num);
    int l = str.size();
    int maxVal = num;
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            swap(str[i], str[j]);
            maxVal = max(maxVal, atoi(str.c_str()));
            swap(str[i], str[j]);
        }
    }
    return maxVal;
}

// 贪心：
// Time: O(N)
// Space: O(N)
int MaximumSwap_B(int num)
{
    if (num >= 0 && num <= 9)
    {
        return num;
    }
    string str = to_string(num);
    int l = str.size();
    int maxIndex = l - 1;  // 记录最大元素的索引位置
    int indexMin = -1;
    int indexMax = -1;
    for (int i = l - 1; i >= 0; i--) 
    {
        // 找到最大元素
        if (str[i] > str[maxIndex])
        {
            maxIndex = i;
        }
        // 找到最大元素的左侧比它小的元素
        else if (str[i] < str[maxIndex])
        {
            indexMin = i;
            indexMax = maxIndex;
        }
    }
    
    if (indexMin >= 0)
    {
        swap(str[indexMin], str[indexMax]);
        return atoi(str.c_str());
    }
    else
    {
        return num;
    }
}