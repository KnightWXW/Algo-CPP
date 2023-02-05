#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode8. 字符串转换整数 (atoi)

//      链接：https://leetcode.cn/problems/string-to-integer-atoi/

//      请你来实现一个 myAtoi(string s) 函数，
//      使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
//      函数 myAtoi(string s) 的算法如下：
//          读入字符串并丢弃无用的前导空格
//          检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。
//          确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//          读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。
//          字符串的其余部分将被忽略。
//          将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。
//          如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//      如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，
//      需要截断这个整数，使其保持在这个范围内。
//      具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，
//      大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
//      返回整数作为最终结果。
//      注意：
//          本题中的空白字符只包括空格字符 ' ' 。
//          除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
//      示例 1：
//          输入：s = "42"
//          输出：42
//          解释：加粗的字符串为已经读入的字符，插入符号是当前读取的字符。
//              第 1 步："42"（当前没有读入字符，因为没有前导空格）
//              第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//              第 3 步："42"（读入 "42"）
//              解析得到整数 42 。
//              由于 "42" 在范围 [-231, 231 - 1] 内，最终结果为 42 。
//      示例 2：
//          输入：s = "   -42"
//          输出：-42
//          解释：
//          第 1 步："   -42"（读入前导空格，但忽视掉）
//          第 2 步："   -42"（读入 '-' 字符，所以结果应该是负数）
//          第 3 步："   -42"（读入 "42"）
//          解析得到整数 -42 。
//          由于 "-42" 在范围 [-231, 231 - 1] 内，最终结果为 -42 。
//      示例 3：
//          输入：s = "4193 with words"
//          输出：4193
//          解释：
//              第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
//              第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//              第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
//              解析得到整数 4193 。
//              由于 "4193" 在范围 [-231, 231 - 1] 内，最终结果为 4193 。
//      提示：
//          0 <= s.length <= 200
//          s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

string& Trim(string &s); 
string RemovePrefixAndSuffixZeros(string str);
bool StringIsValid(string str);
int MyAtoI(string s);

int main()
{
    int num = generateRandomNum(1, 15);
    string s = generateRandomString(num);
    int ans_A = MyAtoI(s);
    printf("罗马数字为: \n");
    printString(s);
    printf("将其转换成整数为 %d。\n", ans_A);
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
    char arr[] = "+-abcABC1234567890 ";
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

string& Trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

string RemovePrefixAndSuffixZeros(string str)
{
    int l = str.size();
    bool r = (str[0] == '+' || str[0] == '-');
    int start = r ? 1 : 0;
    for (; start < l; start++)
    {
        if (str[start] != '0')
        {
            break;
        }
    }
    // s 到了第一个不是'0'字符的位置
    int end = -1;
    // 左<-右
    for (int i = l - 1; i >= (r ? 1 : 0); i--)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            end = i;
        }
    }
    // e 到了最左的 不是数字字符的位置
    string tag = (r ? str.substr(0, 1) : "");
    int endRange = end == -1 ? l : end;
    return tag + str.substr(start, endRange - start);
}

bool StringIsValid(string str)
{
    int l = str.size();
    if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
    {
        return false;
    }
    if ((str[0] == '-' || str[0] == '+') && l == 1)
    {
        return false;
    }
    // 0 +... -... num
    for (int i = 1; i < l; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int MyAtoI(string s)
{
    if (s == "")
    {
        return 0;
    }
    string str = RemovePrefixAndSuffixZeros(Trim(s));
    int l = str.size();
    if (str == "")
    {
        return 0;
    }
    if (!StringIsValid(str))
    {
        return 0;
    }
    bool tag = str[0] == '-' ? false : true;
    int divide = INT_MIN / 10;
    int remainder = INT_MIN % 10;
    int ans = 0;
    int cur = 0;
    int index = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    while (index < l)
    {
        cur = '0' - str[index];
        if ((ans < divide) || (ans == divide && cur < remainder))
        {
            return tag ? INT_MAX : INT_MIN;
        }
        ans = ans * 10 + cur;
        index++;
    }
    if (tag && ans == INT_MIN)
    {
        return INT_MAX;
    }
    return tag ? -ans : ans;
}