#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 2645. 构造有效字符串的最少插入数

//      链接：https://leetcode.cn/problems/minimum-additions-to-make-valid-string/

//      给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，
//      返回使 word 有效 需要插入的最少字母数。
//      如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。
//      示例 1：
//          输入：word = "b"
//          输出：2
//          解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
//      示例 2：
//          输入：word = "aaa"
//          输出：6
//          解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。
//      示例 3：
//          输入：word = "abc"
//          输出：0
//          解释：word 已经是有效字符串，不需要进行修改。 
//      提示：
//          1 <= word.length <= 50
//          word 仅由字母 "a"、"b" 和 "c" 组成。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int AddMinimum(string word);

int main()
{
    int n = generateRandomNum(1, 20);
    string str = generateRandomString(n);
    printString(str);
    int ans_A = AddMinimum(strs);
    printf("使 word 有效 需要插入的最少字母数：%d\n", ans_A);
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
    char arr[] = "abc";
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

int AddMinimum(string word)
{
    
}