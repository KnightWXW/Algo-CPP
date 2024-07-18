#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

//      Huawei：浏览器历史系统

//      打开一个浏览器，此浏览器窗口一般具有浏览历史的特性，请实现如下功能：
//      BrowserHistorySys(string homepage, int maxCount):
//          初始化：homepage 作为当前页，并缓存到浏览历史中；
//              浏览历史中最多可以缓存maxCount个网页
//      int Visit(string url): 跳转访问页面 url, 返回访问后浏览历史中的缓存页面数量
//          如果入参 url 仍然是 当前页，则继续浏览此页面，即：
//          当前页不变，且浏览历史也不变
//          如果入参 url 不是 当前页，则跳转到此 url, 并把此 url 页面作为当前页；
//          同时清除 浏览历史中 原当前页的前进记录，再将此 url 缓存 到浏览器历史中。
//          如果新增缓存后，浏览历史缓存页面数量超过maxCount，则清除浏览器历史中最早的记录。
//      string Back(): 在浏览器历史中从当前页中当前页面后退一步，
//          返回停留页面的 url, 并作为当前页。
//          注：如果已退无可退，则不再后退，继续停留在当前当前页。
//      string Forward(): 在浏览历史中当前页前进一步，返回停留页面的url, 并作为当前页。
//          注：如果已进无可进，则不再前进，继续停留在当前当前页。

void printString(string s)
{
    printf("%s\n", s.c_str());
}

class BrowserHistorySys
{
public:
    int maxCount;
    int index;
    vector<string> his;
    BrowserHistorySys(string homepage, int maxCount)
    {
        this->maxCount = maxCount;
        this->index = 0;
        this->his.push_back(homepage);
    }

    int Visit(string url)
    {
        if (this->his[this->index] != url)
        {
            while (this->his.size() > this->index + 1)
            {
                this->his.pop_back();
            }
            this->his.push_back(url);
            if (this->his.size() > this->maxCount)
            {
                this->his.erase(this->his.begin());
            }
            this->index = this->his.size() - 1;
        }
        return this->his.size();
    }

    string Back()
    {
        if (this->index != 0)
        {
            this->index--;
        }
        return this->his[this->index];
    }

    string Forward()
    {
        if (this->index != this->his.size() - 1)
        {
            this->index++;
        }
        return this->his[this->index];
    }
};

int main()
{
    BrowserHistorySys *browserHistorySys = new BrowserHistorySys("w3.huawei.com", 10);
    int a1 = browserHistorySys->Visit("google.com");
    printf("访问后浏览历史中的缓存页面数量 为：%d\n", a1); // 2
    string a2 = browserHistorySys->Back();
    printf("后退一步 页面 为：\n");
    printString(a2); // w3.huawei.com
    string a3 = browserHistorySys->Forward();
    printf("前进一步 页面 为：\n");
    printString(a3); // google.com
    string a4 = browserHistorySys->Forward();
    printf("前进一步 页面 为：\n");
    printString(a4); // google.com
    int a5 = browserHistorySys->Visit("baidu.com");
    printf("访问后浏览历史中的缓存页面数量 为：%d\n", a5); // 3
    int a6 = browserHistorySys->Visit("youtube.com");
    printf("访问后浏览历史中的缓存页面数量 为：%d\n", a6); // 4
    string a7 = browserHistorySys->Back();
    printf("后退一步 页面 为：\n");
    printString(a7); // baidu.com
    int a8 = browserHistorySys->Visit("baidu.com");
    printf("访问后浏览历史中的缓存页面数量 为：%d\n", a8); // 4
    string a9 = browserHistorySys->Back();
    printf("后退一步 页面 为：\n");
    printString(a9); // google.com
    int a10 = browserHistorySys->Visit("mails.huawei.com");
    printf("访问后浏览历史中的缓存页面数量 为：%d\n", a10); // 3
}