#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//      Huawei: 文件名生成器

//      假设从浏览器下载若干个文件，保存到本地硬盘的同一个目录(初始目录为空)，
//      需要对文件名进行处理，处理规则如下：
//          1、如果已经存在同名文件，则后面生成的文件名加后缀(k),
//             其中k为从2开始递增的整数，表示该文件名已出现的次数(含本次)；
//          2、如果无同名文件，则文件名不变。
//      给定一批被下载的文件名，请输出按顺序下载后生成的文件名。
//      样例1：
//          输入：
//              4
//              myfile yourfile myfile myfile
//          输出：
//              myfile yourfile myfile(2) myfile(3)
//      样例2：
//          输入：
//              4
//              filea filea fileb fileb
//          输出：
//              filea filea(2) fileb fileb(2)

void printString(string s);
void printStringVector(vector<string> vec);

vector<string> GenerateFileName(vector<string> vec);

int main()
{
    vector<string> vec1 = {"myfile", "yourfile", "myfile", "myfile"};
    printf("文件名初始值：\r\n");
    printStringVector(vec1);
    vector<string> ans1 = GenerateFileName(vec1);
    printf("文件名更新值：\r\n");
    printStringVector(ans1);

    vector<string> vec2 = {"filea", "filea", "fileb", "fileb"};
    printf("文件名初始值：\r\n");
    printStringVector(vec2);
    vector<string> ans2 = GenerateFileName(vec2);
    printf("文件名更新值：\r\n");
    printStringVector(ans2);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printString(vec[i]);
    }
}

vector<string> GenerateFileName(vector<string> vec)
{
    int l = vec.size();
    vector<string> ans(vec.begin(), vec.end());
    unordered_map<string, int> hmap;
    for (int i = 0; i < l; i++)
    {
        hmap[ans[i]]++;
        if (hmap[ans[i]] > 1)
        {
            ans[i] = ans[i] + "(" + to_string(hmap[ans[i]]) + ")";
        }
    }
    return ans;
}