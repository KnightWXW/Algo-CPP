#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//      得物: 不包含110的最长子串的长度

//      自从学习了计算机编程，小明就彻底差上了0和1，很多01串经常在他脑子里面浮现。
//      但是他从小就害怕警察，虽然他并没有犯过啥大错误，
//      最多就是在小花的新衣服上画朵小花，在小红的白裙子上点上几个小红点….
//      所以他很害怕110。现在给你一个01串，
//      请你编写一个程序计算在这个01串中不包含110的最长子串的长度。
//      输入描述：
//          输入一行，包含一个01串S(在S中只包含0和1，有可能输入全为0或者1的串)，
//          其长度1≤|S|≤1000000.
//      输出描述：
//          输出01串S中不包含110的最长子串的长度

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int SubStringExcluding110(string str);

int main()
{
    int n = generateRandomNum(1, 10);
    string str = generateRandomString(n);
    printString(str);
    int ans_A = SubStringExcluding110(str);
    printf("不包含110的最长子串的长度：%d\n", ans_A);
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

// 贪心:
// Time: O(N)
// Space: O(1)
int SubStringExcluding110(string str)
{
    int l = str.size();
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < l; i++)
    {
        cur++;
        if (i >= 2 && str[i - 2] == '1' && str[i - 1] == '1' && str[i] == '0')
        {
            cur = 2;
        }
        ans = max(ans, cur);
    }
    return ans;
}