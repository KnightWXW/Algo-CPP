#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string>

using namespace std;

//      LeetCode 1166: 设计文件系统

//      你需要设计一个能提供下面两个函数的文件系统：
//      bool Create(path, value):
//          创建一个新的路径，并尽可能将值 value 与路径 path 关联，然后返回 True。
//          如果路径已经存在或者路径的父路径不存在，则返回 False。
//      int Get(path):
//          返回与路径关联的值。如果路径不存在，则返回 -1。
//      “路径” 是由一个或多个符合下述格式的字符串连接起来形成的：
//      在 / 后跟着一个或多个小写英文字母。
//      例如 /leetcode 和 /leetcode/problems 都是有效的路径，
//      但空字符串和 / 不是有效的路径。
//      好了，接下来就请你来实现这两个函数吧！（请参考示例以获得更多信息）
//      示例 1：
//          输入：
//              ["FileSystem","create","get"]
//              [[],["/a",1],["/a"]]
//          输出：
//              [null,true,1]
//          解释：
//              FileSystem fileSystem = new FileSystem();
//              fileSystem.create("/a", 1); // 返回 true
//              fileSystem.get("/a"); // 返回 1
//      示例 2：
//          输入：
//              ["FileSystem","create","create","get","create","get"]
//              [[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
//          输出：
//              [null,true,true,2,false,-1]
//          解释：
//              FileSystem fileSystem = new FileSystem();
//              fileSystem.create("/leet", 1); // 返回 true
//              fileSystem.create("/leet/code", 2); // 返回 true
//              fileSystem.get("/leet/code"); // 返回 2
//              fileSystem.create("/c/d", 1); // 返回 false 因为父路径 "/c" 不存在。
//              fileSystem.get("/c"); // 返回 -1 因为该路径不存在。
//      提示：
//          对两个函数的调用次数加起来小于等于 10^4
//          2 <= path.length <= 100
//          1 <= value <= 10^9

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
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

class FileSystem
{
public:
    unordered_map<string, int> hmap;
    FileSystem()
    {
    }

    bool Create(string path, int value)
    {
        if (hmap.find(path) != hmap.end())
        {
            return false;
        }
        int l = path.size();
        int index = l - 1;
        while (path[index] != '/')
        {
            index--;
        }
        string s = path.substr(0, index);
        if (s == "" || hmap.find(s) != hmap.end())
        {
            hmap[path] = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    int Get(string path)
    {
        if (hmap.find(path) == hmap.end())
        {
            return -1;
        }
        return hmap[path];
    }
};

int main()
{
    FileSystem *fileSystem = new FileSystem();
    bool b1 = fileSystem->Create("/leet", 1);
    printBool(b1); // true
    bool b2 = fileSystem->Create("/leet/code", 2);
    printBool(b2); // true
    int g1 = fileSystem->Get("/leet/code");
    printf("与路径关联的值为 %d \n", g1);
    bool b3 = fileSystem->Create("/c/d", 1);
    printBool(b3); // true
    int g2 = fileSystem->Get("/c");
    printf("与路径关联的值为 %d \n", g2);
}