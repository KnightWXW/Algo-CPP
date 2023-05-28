#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 66. 加一

//      链接：https://leetcode.cn/problems/plus-one/

//      给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//      最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//      你可以假设除了整数 0 之外，这个整数不会以零开头。
//      示例 1：
//          输入：digits = [1,2,3]
//          输出：[1,2,4]
//          解释：输入数组表示数字 123。
//      示例 2：
//          输入：digits = [4,3,2,1]
//          输出：[4,3,2,2]
//          解释：输入数组表示数字 4321。
//      示例 3：
//          输入：digits = [0]
//          输出：[1]
//      提示：
//          1 <= digits.length <= 100
//          0 <= digits[i] <= 9

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> PlusOne(vector<int> &digits);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 9, n);
    printVec(vec);
    vector<int> ans = PlusOne(vec);
    printf("该数的基础上加一后数组为：\n");
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

vector<int> PlusOne(vector<int> &digits)
{
    int l = digits.size();
    bool flag = true;
    for (int i = l - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            flag = false;
            break;
        }
        else
        {
            digits[i] = 0;
        }
    }
    vector<int> ans(l + 1, 1);
    copy(digits.begin(), digits.end(), ans.begin() + 1);
    return flag == true ? ans : digits;
}