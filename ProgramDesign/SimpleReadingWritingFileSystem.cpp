#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      Huawei: 简易文件读写系统

//      请实现一个简易的文本文件读写系统，提供如下文件操作系统：
//          TextFileSystem(): 系统初始化，此时无任何文件
//          int Open(string filename, string mode): 打开或新建文件。
//              打开模式mode仅为r,r+,w,w+,a,a+:
//              文件filename不存在：仅当mode为r或r+时失败，其他模式时会新建此文件并打开文件。
//              文件filename已存在：处于未打开状态时，打开成功；处于已打开状态时，打开失败。
//              成功打开后，按下表处理，并返回0,失败返回-1。
//         --------------------------------------------------------------------
//         |       内容处理规则          |  r  |  r+  |  w  |  w+  |  a  |  a+  |
//         |    打开时是否清空内容       |   n  |   n  |  y  |  y   |  n  |  n   |
//         | 打开时位置指示器的初始位置   | 开头 | 开头 | 末尾 | 末尾 | 末尾 | 末尾 |
//         |     打开后是否可读          |  y   |  y  |  n   |  y   |  n  |  y   |
//         |      打开后是否可写         |  n   |  y  |  y   |  y   |  y  |  y   |
//         ---------------------------------------------------------------------
//          int Close(string filename): 关闭文件filename,
//              若处于已打开状态时，关闭该文件，并返回0；否则返回-1；
//          int Write(string filename, string content): 往文件filename中写入content,
//              若处于已打开状态且可写时，则按照【内容处理规则】，
//              在位置指示器的当前位置写入content内容，返回写入文件内容的长度，否则返回-1；
//              写入后，位置指示器移动到本次写入内容的末尾。
//          string ReadAll(string filename): 读出文件filename中的全部内容
//              若文件处于打开状态且可读，则按照【内容处理规则】，读出文件全部内容并返回，
//              当文件内容为空时，返回字符串null，否则，返回字符串error。
//              readAll操作不改变位置指示器
//                  r:  只读方式打开已存在的文件
//                  r+: 读写方式打开已存在的文件
//                  w:  只写方式打开或新建一个文件
//                  w+: 读写方式打开或新建一个文件
//                  a:  追加方式打开或新建一个文件，用于写
//                  a+: 追加方式打开或新建一个文件，用于读写
//      输入：
//          首行一个整数num, 表示文件操作的个数，1 <= num <= 100
//          接下来num行，每行一个文件操作，格式为 操作 = 参数1 参数2
//      输入：11
//          TextFileSys
//          Open = f a
//          Write = f hello
//          Close = f
//          Open = f w+
//          ReadAll = f
//          Write = f how
//          Close = f
//          Open = f a+
//          Write = f areyou
//          ReadAll = r
//      输出:
//          null 0 5 0 0 null 3 0 0 9 howareyou

void printString(string s)
{
    printf("%s\n", s.c_str());
}

class SimpleReadingWritingFileSystem
{
public:
    SimpleReadingWritingFileSystem()
    {
    }

    unordered_map<string, string> contentMap;
    unordered_map<string, int> statusMap;
    unordered_map<string, int> positionMap;

    int Open(string filename, string mode)
    {
        // 文件不存在 并且 模式为 r 或 r+
        if (statusMap.find(filename) == statusMap.end() && (mode == "r" || mode == "r+"))
        {
            return -1;
        }
        // 文件存在 且 打开：
        if (statusMap[filename] != 0)
        {
            return -1;
        }

        // 模式为 w 或 w+, 打开时内容清空
        if (mode == "w" || mode == "w+")
        {
            contentMap[filename].clear();
        }

        // 模式为 r 或 r+ , 位置指示器在开头, 否则 位置指示器在末尾
        if (mode != "r" && mode != "r+")
        {
            positionMap[filename] = contentMap[filename].size();
        }
        else
        {
            positionMap[filename] = 0;
        }

        // 模式不为 r 或 r+ : 为 可写 状态
        if (mode != "r" && mode != "r+")
        {
            statusMap[filename] |= 2;
        }
        // 模式不为 w 或 w+ : 为 可读 状态
        if (mode != "w" && mode != "w+")
        {
            statusMap[filename] |= 1;
        }
        return 0;
    }

    int Close(string filename)
    {
        // 若文件不存在，或者未打开状态时，返回-1
        if (statusMap.find(filename) == statusMap.end() || statusMap[filename] == 0)
        {
            return -1;
        }
        statusMap[filename] = 0;
        return 0;
    }

    int Write(string filename, string content)
    {
        if (statusMap.find(filename) == statusMap.end() || (statusMap[filename] & 2 == 0))
        {
            return -1;
        }
        // 更新后的 content:
        string tem = contentMap[filename].substr(0, positionMap[filename]) + content;
        positionMap[filename] += content.size();
        if (tem.size() < contentMap[filename].size())
        {
            tem += contentMap[filename].substr(positionMap[filename]);
        }
        contentMap[filename] = tem;
        return contentMap[filename].size();
    }

    string ReadAll(string filename)
    {
        // 文件不存在 或 文件不可读
        if (statusMap.find(filename) == statusMap.end() || (statusMap[filename] & 1 == 0))
        {
            return "error";
        }
        // 文件存在 但 为空
        if (contentMap[filename].empty())
        {
            return "null";
        }
        return contentMap[filename];
    }
};

int main()
{
    SimpleReadingWritingFileSystem *simpleReadingWritingFileSystem = new SimpleReadingWritingFileSystem();
    int o1 = simpleReadingWritingFileSystem->Open("f", "a");
    printf("打开文件结果为 %d\n", o1);
    int w1 = simpleReadingWritingFileSystem->Write("f", "hello");
    printf("写入文件结果为 %d\n", w1);
    int c1 = simpleReadingWritingFileSystem->Close("f");
    printf("关闭文件结果为 %d\n", c1);
    int o2 = simpleReadingWritingFileSystem->Open("f", "w+");
    printf("打开文件结果为 %d\n", o2);
    string r1 = simpleReadingWritingFileSystem->ReadAll("f");
    printf("读取文件结果为:\n");
    printString(r1);
    int w2 = simpleReadingWritingFileSystem->Write("f", "how");
    printf("写入文件结果为 %d\n", w2);
    int c2 = simpleReadingWritingFileSystem->Close("f");
    printf("关闭文件结果为 %d\n", c2);
    int o3 = simpleReadingWritingFileSystem->Open("f", "a+");
    printf("打开文件结果为 %d\n", o3);
    int w3 = simpleReadingWritingFileSystem->Write("f", "areyou");
    printf("写入文件结果为 %d\n", w3);
    string r2 = simpleReadingWritingFileSystem->ReadAll("f");
    printf("读取文件结果为:\n");
    printString(r2);
}