#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

//      一个数组中只有两种字符'A'和'B'，
//      可以让所有的A都放在左侧，所有的B都放在右侧
//      或者 可以让所有的A都放在右侧，所有的B都放在左侧，
//      但是只能在相邻字符之间进行交换操作，返回至少需要交换几次

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int PutCharacters(string s);
int PutCharactersHelper(string s, char c);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    int ans = PutCharacters(s);
    printf("达到 题目的要求，至少需要交换 %d 次。\n", ans);
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
    char arr[] = "AB";
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

int PutCharacters(string s)
{
    int ans1 = PutCharactersHelper(s, 'A');
    int ans2 = PutCharactersHelper(s, 'B');
    return min(ans1, ans2);
}

int PutCharactersHelper(string s, char c)
{
    int l = s.size();
    int cnt = 0;
    int left = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == c)
        {
            cnt += i - left;
            left++;
        }
    }
    return cnt;
}