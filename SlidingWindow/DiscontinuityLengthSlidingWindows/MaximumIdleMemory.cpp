#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      Huawei: 最长空闲内存

//      某系统中有一空间连续的内存，被划分为多个大小相同的内存块
//      内存的使用状态记录在字符串memeory中，每个内存块的状态用字符X或者.表示，其中：
//          .   表示该内存块空闲
//          X   表示该内存块被使用
//      现在最多可释放cnt个内存块(字符串的X变为.)来获得空间连续的内存，
//      求可以获得的最长空闲的连续内存块数量
//      示例1：
//          输入：memory = "..X..X..XX..."  cnt = 2
//          输出：8
//      示例2：
//          输入：memory = "....X."  cnt = 3
//          输出：6
//      示例3：
//          输入：memory = "XX.X..XX....X..."  cnt = 0
//          输出：4
//      提示：0 <= cnt <= memory.size() <= 10^5

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int MaximumIdleMemory(string s, int cnt);

int main()
{
    int n = generateRandomNum(0, 100);
    string s = generateRandomString(n);
    printString(s);
    int cnt = generateRandomNum(0, n);
    int ans = MaximumIdleMemory(s, cnt);
    printf("最多可释放 %d 个内存块, \n可以获得的最长空闲的连续内存块块数量为 %d\n", cnt, ans);
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

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int MaximumIdleMemory(string s, int cnt)
{
    int l = s.size();
    int left = 0;
    int right = 0;
    int cur = 0;
    int ans = 0;
    while (right < l)
    {
        if (s[right] == 'X')
        {
            cur++;
        }
        while (cur > cnt)
        {
            if (s[left] == 'X')
            {
                cur--;
            }
            left++;
        }
        ans = max(left, right - left + 1);
        right++;
    }
    return ans;
}