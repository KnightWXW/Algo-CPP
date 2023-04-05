#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//      LeetCode 504. 七进制数

//      链接：https://leetcode.cn/problems/base-7/

//      给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
//      示例 1:
//          输入: num = 100
//          输出: "202"
//      示例 2:
//          输入: num = -7
//          输出: "-10"
//      提示：
//          -107 <= num <= 107

int generateRandomNum(int low, int high);
void printString(string s);

string ConvertToBase7(int num);

int main()
{
    int n = generateRandomNum(-1000000, 1000000);
    string ans = ConvertToBase7(n);
    printf("整数 %d, 将其转化为 7 进制为：\n", n);
    printString(ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

string ConvertToBase7(int num)
{
    bool flag = true;
    int k = num;
    string ans = "";
    if (k == 0)
    {
        return "0";
    }
    else if (k < 0)
    {
        flag = false;
        k = -k;
    }
    while (k != 0)
    {
        int tem = k % 7;
        ans = to_string(tem) + ans;
        k /= 7;
    }
    if (flag == false)
    {
        return "-" + ans;
    }
    else
    {
        return ans;
    }
}