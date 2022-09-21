#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      给定一个 字符串str，只由 'X' 和 '.' 两种字符构成
//      'X' 表示墙，不能放灯，也不需要点亮；
//      '.' 表示居民点，可以放灯，需要点亮
//      如果灯放在 i 位置，可以让 i-1 ，i 和 i+1 三个位置被点亮
//      返回如果点亮 str 中所有需要点亮的位置，至少需要几盏灯

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int minLightNum(string s);

int main()
{
    int n = generateRandomNum(0, 50);
    string s = generateRandomString(n);
    printf("s 字符串为：");
    printString(s);

    printf("点亮 s 中所有需要点亮的位置, 至少需要 %d 盏灯 \n", minLightNum(s));
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
    char arr[] = ".X";
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
// Time: O(N)
// Space: O(N)
int minLightNum(string s)
{
    int ans = 0;
    int index = 0;
    while (index < s.size())
    {
        if (s[index] == 'X')
        {
            index++;
        }
        else
        {
            ans++;
            if (index + 1 < s.size())
            {
                if (s[index + 1] == '.')
                {
                    index += 3;
                }
                else
                {
                    index += 2;
                }
            }
        }
    }
    return ans;
}