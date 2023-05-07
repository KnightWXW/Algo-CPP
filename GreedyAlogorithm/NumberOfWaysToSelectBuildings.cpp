#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 2222. 选择建筑的方案数

//      链接：https://leetcode.cn/problems/number-of-ways-to-select-buildings/

//      给你一个下标从 0 开始的二进制字符串 s ，它表示一条街沿途的建筑类型，其中：
//          s[i] = '0' 表示第 i 栋建筑是一栋办公楼，
//          s[i] = '1' 表示第 i 栋建筑是一间餐厅。
//      作为市政厅的官员，你需要随机 选择 3 栋建筑。
//      然而，为了确保多样性，选出来的 3 栋建筑 相邻 的两栋不能是同一类型。
//      比方说，给你 s = "001101" ，我们不能选择第 1 ，3 和 5 栋建筑，
//      因为得到的子序列是 "011" ，有相邻两栋建筑是同一类型，所以 不合 题意。
//      请你返回可以选择 3 栋建筑的 有效方案数 。
//      示例 1：
//          输入：s = "001101"
//          输出：6
//          解释：
//              以下下标集合是合法的：
//              - [0,2,4] ，从 "001101" 得到 "010"
//              - [0,3,4] ，从 "001101" 得到 "010"
//              - [1,2,4] ，从 "001101" 得到 "010"
//              - [1,3,4] ，从 "001101" 得到 "010"
//              - [2,4,5] ，从 "001101" 得到 "101"
//              - [3,4,5] ，从 "001101" 得到 "101"
//              没有别的合法选择，所以总共有 6 种方法。
//      示例 2：
//          输入：s = "11100"
//          输出：0
//          解释：没有任何符合题意的选择。
//      提示：
//          3 <= s.length <= 105
//          s[i] 要么是 '0' ，要么是 '1' 。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

long long NumberOfWaysToSelectBuildings(string s);

int main()
{
    int n = generateRandomNum(3, 100);
    string str = generateRandomString(n);
    printf("街道沿途的建筑类型为：\n");
    printString(str);
    long long ans = NumberOfWaysToSelectBuildings(str);
    printf("有效方案数为：%d\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "01";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

// 贪心：
// 只有两种情况：“0 1 0” 和 “1 0 1”
long long NumberOfWaysToSelectBuildings(string s)
{
    int l = s.size();
    long long ans = 0;
    int cnt = 0;
    int ones = count(s.begin(), s.end(), '1');
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '1')
        {
            ans += (long long)(i - cnt) * (l - i - (ones - cnt));
            cnt++;
        }
        else
        {
            ans += (long long)(cnt) * (ones - cnt);
        }
    }
    return ans;
}