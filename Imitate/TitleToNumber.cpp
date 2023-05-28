#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 171. Excel 表列序号

//      链接：https://leetcode.cn/problems/excel-sheet-column-number/

//      给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。
//      返回 该列名称对应的列序号 。
//      例如：
//          A -> 1
//          B -> 2
//          C -> 3
//          ...
//          Z -> 26
//          AA -> 27
//          AB -> 28
//          ...
//      示例 1:
//          输入: columnTitle = "A"
//          输出: 1
//      示例 2:
//          输入: columnTitle = "AB"
//          输出: 28
//      示例 3:
//          输入: columnTitle = "ZY"
//          输出: 701
//      提示：
//          1 <= columnTitle.length <= 7
//          columnTitle 仅由大写英文组成
//          columnTitle 在范围 ["A", "FXSHRXW"] 内

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int TitleToNumber_A(string columnTitle);
int TitleToNumber_B(string columnTitle);

int main()
{
    int num = generateRandomNum(1, 10);
    string s = generateRandomString(num);
    int ans_A = TitleToNumber_A(s);
    int ans_B = TitleToNumber_B(s);
    printf("字符串 columnTitle 为: \n");
    printString(s);
    printf("该列名称对应的列序号 为 %d。\n", ans_A);
    printf("该列名称对应的列序号 为 %d。\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

int TitleToNumber_A(string columnTitle)
{
     int l = columnTitle.size();
    int ans = 0;
    for (int i = 0; i < l ;i++)
    {
        int tem = columnTitle[i] - 'A' + 1;
        ans = ans * 26 + tem;
    }
    return ans;
}

int TitleToNumber_B(string columnTitle)
{
    int l = columnTitle.size();
    int ans = 0;
    long base = 1;
    for (int i = l - 1; i >= 0; i--)
    {
        int tem = columnTitle[i] - 'A' + 1;
        ans += tem * base;
        base *= 26;
    }
    return ans;
}