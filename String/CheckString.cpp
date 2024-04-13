#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//      LeetCode 2124. 检查是否所有 A 都在 B 之前

//      链接：https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/

//      给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。
//      如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。
//      示例 1：
//          输入：s = "aaabbb"
//          输出：true
//          解释：
//              'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
//              因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//      示例 2：
//          输入：s = "abab"
//          输出：false
//          解释：
//              存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
//              因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
//      示例 3：
//          输入：s = "bbb"
//          输出：true
//          解释：
//              不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//      提示：
//          1 <= s.length <= 100
//          s[i] 为 'a' 或 'b'

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printBool(bool b);

bool CheckString_A(string s);
bool CheckString_B(string s);
bool CheckString_C(string s);

int main()
{
    int n = generateRandomNum(0, 30);
    string str = generateRandomString(n);
    printString(str);
    bool ans_A = CheckString_A(str);
    printf("是否所有 A 都在 B 之前: \n");
    printBool(ans_A);
    bool ans_B = CheckString_B(str);
    printf("是否所有 A 都在 B 之前: \n");
    printBool(ans_B);
    bool ans_C = CheckString_C(str);
    printf("是否所有 A 都在 B 之前: \n");
    printBool(ans_C);
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
    char arr[] = "ab";
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

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

bool CheckString_A(string s)
{
    int l = s.size();
    int indexA = -1;
    int indexB = l;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'a')
        {
            indexA = i;
        }
    }
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            indexB = i;
        }
    }
    return indexA < indexB;
}

bool CheckString_B(string s)
{
    int l = s.size();
    int indexA = -1;
    int indexB = l;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'a')
        {
            indexA = max(i, indexA);
        }else if(s[i]){
            indexB = min(i, indexB);
        }
    }
    return indexA < indexB;
}

bool CheckString_C(string s)
{
    int index = s.find("ba");
    return index == -1;
}