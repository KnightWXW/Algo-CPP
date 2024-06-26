#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

//      Huawei: 大熊猫拍照

//      卧龙大熊猫基地要对今年新出生的大熊猫进行拍照合影。
//      但是熊猫不太听话，有的面向前方，有的面向后方。
//      为了拍到所有熊猫的正脸，使用了一台自动给熊猫转向的机器。
//      通过用户预先设定一个数值K，可以给连续的K个熊猫进行转向
//      (单次操作翻转的数量必须为K个)。
//      请求出在不同K值下，让所有熊猫都面朝前方的最小操作数。
//      输入：
//          第一行为熊猫个数N，
//          第二行为每个熊猫的面向：F为向前，B为向后
//      输出：
//          最少的操作次数
//      输入样例:
//          7
//          BBFBFBB
//      输出样例 3

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int TakingPhotosOfRedPandas(string s);

int main()
{
    int n = generateRandomNum(1, 30);
    string str = generateRandomString(n);
    printString(str);
    int ans_A = TakingPhotosOfRedPandas(str);
    printf("让所有熊猫都面朝前方的最小操作数为：%d\n", ans_A);
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
    char arr[] = "BF";
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

int HelperTakingPhotosOfRedPandas(string s, int k)
{
    int l = s.size();
    int cnt = 0;
    queue<int> q;
    for (int i = 0; i < l; i++)
    {
        if (q.size() > 0 && i - k + 1 > q.front())
        {
            q.pop();
        }
        if ((q.size() % 2 == 0 && s[i] == 'B') || (q.size() % 2 == 1 && s[i] == 'F'))
        {
            if (i + k > s.size())
            {
                return -1;
            }
            q.push(i);
            cnt++;
        }
    }
    return cnt;
}

int TakingPhotosOfRedPandas(string s)
{
    int l = s.size();
    int ans = l + 1;
    for (int i = 1; i <= l; i++)
    {
        int tem = HelperTakingPhotosOfRedPandas(s, i);
        if (tem > 0)
        {
            ans = min(ans, tem);
        }
    }
    return ans;
}