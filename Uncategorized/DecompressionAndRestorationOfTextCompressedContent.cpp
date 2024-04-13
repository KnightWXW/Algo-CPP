#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//      Huawei: 文本压缩内容的解压复原

//      有一种速记方式，针对重复内容有一套独特的缩写规则：
//          重复的部分会被以“(重复内容)<重复次数>”形式记录, 并且可能存在嵌套缩写关系。
//          不重复的部分按照原样记录。
//      现给一个符合此速记方式的字符串records。请以字符串形式返回复原后的内容。
//      注：records仅由小写字母，数字及<,>,(,)组成
//      示例1：
//          输入：records = “abc(d)<2>e”
//          输出：“abcdde” 
//      示例2：
//          输入：records = “a(b(c)<3>d)<2>e”
//          输出：“abcccdbcccde” 
//      提示：
//          1 <= records.size() <= 200
//          2 <= 重复次数 <= 10

void printString(string s);

string DecompressionAndRestorationOfTextCompressedContent(string records);

int main()
{
    string s1 = "abc(d)<2>e";
    string ans1 = DecompressionAndRestorationOfTextCompressedContent(s1);
    printString(s1);
    printString(ans1);
    string s2 = "a(b(c)<3>d)<2>e";
    string ans2 = DecompressionAndRestorationOfTextCompressedContent(s2);
    printString(s2);
    printString(ans2);
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}