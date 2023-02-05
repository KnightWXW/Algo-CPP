#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 分页器

//      在平时的网页中，我们经常看到信息内容通过分页来展示，
//      分页器通常会根据我们的当前页码显示不同的页码按钮，
//      用来引导用户翻页。下图所示的分页器，总页数为64（首页码为1，尾页码为64），
//      最大显示宽度为 9，当前页码为 9
//      显示宽度为页码按钮和...的数量，...表示页码不连续。
//      给定总页数、最大显示宽度、当前页码，请模拟输出分页器的显示形态：
//      总页数小于等于最大显示宽度时，显示与总页数相等的按钮
//      总页数大于最大显示宽度时，需依次符合下面条件：
//          1 显示按钮与...的数量之和等于最大显示宽度。
//          2 第一个和最后一个按钮固定显示首尾页码，当前页码的按钮一定显示(可能是首尾页码按钮)
//          3 当且仅当首页或尾页与相邻按钮的页码不连续时，需使用...间隔。
//          4 除首、尾、当前页外，其它按钮显示与当前页码前后连续的页码：
//      选择当前页码的前面按钮数与后面按钮数的差值的绝对值最小的方案；
//      如果差值最小有多个方案，选择前面按钮数多的方案。
//      显示按钮按页码从小到大排列
//      输入
//          三个正整数 pageCount maxWidth currentPage，
//          分别表示总页数、最大显示宽度、当前页码
//          2 <= pageCount <= 1000,
//          5 <= maxWidth <= 10,
//          1 <= currentPage <= pageCount
//      输出
//          一个字符串，表示分页器的显示形态，用单空格间隔页码与...
//      样例
//          输入样例 1
//              7 6 4
//          输出样例 1
//              1 ... 3 4 ... 7
//          提示样例 1
//              首页1、尾页7、当前页4，一定显示。
//              当前页前面按钮数与后面按钮数差值最小的方案有两种：1 … 3 4 … 7 或 1 … 4 5 … 7 ，选择前面按钮数多的方案。
//              其他方案，比如：1 2 3 4 … 7 的当前页前面按钮数（3个）与后面按钮数（1个）的差值不是最小； 1 … 3 4 5 7 的尾页7与相邻按钮的页码5不连续时没有 …
//          输入样例 2
//              8 7 5
//          输出样例 2
//              1 ... 4 5 6 ... 8
//          提示样例 2
//              首页1、尾页8、当前页5，一定显示。 首页和尾页都与相邻按钮的页码不连续，使用 … 。 当前页前后按钮数相差最小（为0）。
//              错误答案如 1 … 4 5 6 7 8 ，该方案的前后按钮数相差 1
//          输入样例 3
//              7 6 5
//          输出样例 3
//              1 ... 4 5 6 7
//          提示样例 3
//              当前页前后按钮数相差最小（为0）
//              错误答案如 1 … 4 5 … 7 ，该方案的前后按钮数相差 1
//          输入样例 4
//              5 10 3
//          输出样例 4
//              1 2 3 4 5
//          提示样例 4
//              最大显示宽度足以显示所有页码，按实际页码数显示

int generateRandomNum(int low, int high);
void printString(string s);

string PageToString(vector<int> pages, int start, int end);
string DisplayPages_A(int pageCount, int maxWidth, int currentPage);
string DisplayPages_B(int pageCount, int maxWidth, int currentPage);

int main()
{
    int pageCount = generateRandomNum(2, 1000);
    int maxWidth = generateRandomNum(5, 10);
    int currentPage = generateRandomNum(1, pageCount);
    string ans_A = DisplayPages_A(pageCount, maxWidth, currentPage);
    string ans_B = DisplayPages_B(pageCount, maxWidth, currentPage);
    printf("总页数为 %d, 最大显示宽度为 %d, 当前页码为 %d。\n", pageCount, maxWidth, currentPage);
    printf("分页显示结果为: \n");
    printString(ans_A);
    printString(ans_B);
    // int pageCount1 = 7;
    // int maxWidth1 = 6;
    // int currentPage1 = 4;
    // string ans1A = DisplayPages_A(pageCount1, maxWidth1, currentPage1);
    // string ans1B = DisplayPages_B(pageCount1, maxWidth1, currentPage1);
    // printf("分页显示结果为: \n");
    // printString(ans1A);
    // printString(ans1B);
    // int pageCount2 = 8;
    // int maxWidth2 = 7;
    // int currentPage2 = 5;
    // string ans2A = DisplayPages_A(pageCount2, maxWidth2, currentPage2);
    // string ans2B = DisplayPages_B(pageCount2, maxWidth2, currentPage2);
    // printf("分页显示结果为: \n");
    // printString(ans2A);
    // printString(ans2B);
    // int pageCount3 = 7;
    // int maxWidth3 = 6;
    // int currentPage3 = 5;
    // string ans3A = DisplayPages_A(pageCount3, maxWidth3, currentPage3);
    // string ans3B = DisplayPages_B(pageCount3, maxWidth3, currentPage3);
    // printf("分页显示结果为: \n");
    // printString(ans3A);
    // printString(ans3B);
    // int pageCount4 = 5;
    // int maxWidth4 = 10;
    // int currentPage4 = 3;
    // string ans4A = DisplayPages_A(pageCount4, maxWidth4, currentPage4);
    // string ans4B = DisplayPages_B(pageCount4, maxWidth4, currentPage4);
    // printf("分页显示结果为: \n");
    // printString(ans4A);
    // printString(ans4B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

// 数组转换成字符串
string PageToString(vector<int> pages, int start, int end)
{
    string ans = "";
    for (int i = start; i <= end; i++)
    {
        if (pages[i] < 0)
        {
            ans += "... ";
            continue;
        }
        ans += to_string(pages[i]) + " ";
    }
    return ans.substr(0, ans.size() - 1);
}

// iota(pages.begin(), pages.end(), 1)： 递增操作函数
string DisplayPages_A(int pageCount, int maxWidth, int currentPage)
{
    // 总页数小 <= 最大显示宽度：显示所有页
    if (pageCount <= maxWidth)
    {
        vector<int> pages(pageCount);
        iota(pages.begin(), pages.end(), 1);
        return PageToString(pages, 0, pages.size() - 1);
    }
    // 当前页 在 中间页的左侧，只显示右侧省略号
    if (currentPage <= maxWidth / 2)
    {
        vector<int> pages(maxWidth);
        iota(pages.begin(), pages.end(), 1);
        pages[maxWidth - 1] = pageCount;
        pages[maxWidth - 2] = -1;
        return PageToString(pages, 0, pages.size() - 1);
    }
    // 当前页 在 中间页的右侧，只显示左侧省略号
    if (pageCount - currentPage < maxWidth / 2)
    {
        vector<int> pages(maxWidth);
        iota(pages.begin(), pages.end(), pageCount - maxWidth + 1);
        pages[0] = 1;
        pages[1] = -1;
        return PageToString(pages, 0, pages.size() - 1);
    }
    // 当前页在中间，显示左右两个省略号：
    // 左右侧分别插值
    vector<int> pages{1, -1, currentPage, -1, pageCount};
    int left = 1;  // 记录 左侧 数值个数
    int right = 1; // 记录 右侧 数值个数
    while (pages.size() < maxWidth)
    {
        if (left <= right)
        {
            pages.insert(pages.begin() + 2, currentPage - left);
            left++;
        }
        else
        {
            pages.insert(pages.end() - 2, currentPage + right);
            right++;
        }
    }
    return PageToString(pages, 0, pages.size() - 1);
}

string DisplayPages_B(int pageCount, int maxWidth, int currentPage)
{
    // 总页数小 <= 最大显示宽度：显示所有页
    if (pageCount <= maxWidth)
    {
        vector<int> pages(pageCount);
        iota(pages.begin(), pages.end(), 1);
        return PageToString(pages, 0, pages.size() - 1);
    }
    // 当前页 在 中间页的左侧，只显示右侧省略号
    if (currentPage <= maxWidth / 2)
    {
        vector<int> pages(maxWidth);
        iota(pages.begin(), pages.end(), 1);
        string ans = PageToString(pages, 0, pages.size() - 3) + " ... " + to_string(pageCount);
        return ans;
    }
    // 当前页 在 中间页的右侧，只显示左侧省略号
    if (pageCount - currentPage < maxWidth / 2)
    {
        vector<int> pages(maxWidth);
        iota(pages.begin(), pages.end(), pageCount - maxWidth + 1);
        string ans = to_string(1) + " ... " + PageToString(pages, 2, pages.size() - 1);
        return ans;
    }
    vector<int> pages(maxWidth);
    iota(pages.begin(), pages.end(), currentPage - maxWidth / 2);
    string ans = to_string(1) + " ... " + PageToString(pages, 2, pages.size() - 3) + " ... " + to_string(pageCount);
    return ans;
}