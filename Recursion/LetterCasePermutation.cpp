#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 784. 字母大小写全排列

//      链接：https://leetcode.cn/problems/letter-case-permutation/

//      给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，
//      我们可以获得一个新的字符串。
//      返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。

//      示例 1：
//          输入：s = "a1b2"
//          输出：["a1b2", "a1B2", "A1b2", "A1B2"]

//      示例 2:
//          输入: s = "3z4"
//          输出: ["3z4","3Z4"]
 
//      提示:
//          1 <= s.length <= 12
//          s 由小写英文字母、大写英文字母和数字组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

vector<string> letterCasePermutation(string s);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    
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
    char arr[] = "ab0cd1ef2gh3ij4kl5mn6op7qr8st9uvwxyz";
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

vector<string> letterCasePermutation(string s) {

}