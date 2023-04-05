#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 面试题 16.01. 交换数字

//      链接：https://leetcode.cn/problems/swap-numbers-lcci/

//      编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
//      示例：
//          输入: numbers = [1,2]
//          输出: [2,1]
//      提示：
//          numbers.length == 2
//          -2147483647 <= numbers[i] <= 2147483647

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> SwapNumbers(vector<int>& numbers);

int main()
{
    vector<int> vec = generateRandomVec(0, 100, 2);
    printVec(vec);
    vector<int> ans = SwapNumbers(vec);
    printf("交换数字后数组为：\n");
    printVec(ans);
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
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 位运算：
// Time: O(N)
// Space: O(1)
vector<int> SwapNumbers(vector<int>& numbers)
{
    numbers[0] ^= numbers[1];
    numbers[1] ^= numbers[0];
    numbers[0] ^= numbers[1];
    return numbers;
}