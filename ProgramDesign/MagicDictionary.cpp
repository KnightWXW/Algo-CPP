#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

//      LeetCode 676. 实现一个魔法字典

//      链接1：https://leetcode.cn/problems/implement-magic-dictionary/
//      链接2：https://leetcode.cn/problems/US1pGT/

//      设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
//      如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，
//      使得所形成的新单词存在于你构建的字典中。
//      实现 MagicDictionary 类：
//          MagicDictionary(): 初始化对象
//          void buildDict(String[] dictionary):
//              使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
//          bool search(String searchWord):
//              给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，
//              使得所形成的新字符串能够与字典中的任一字符串匹配。
//              如果可以，返回 true ；否则，返回 false 。
//      示例：
//          输入
//              ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
//              [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
//          输出
//              [null, null, false, true, false, false]
//      解释
//          MagicDictionary magicDictionary = new MagicDictionary();
//          magicDictionary.buildDict(["hello", "leetcode"]);
//          magicDictionary.search("hello"); // 返回 False
//          magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
//          magicDictionary.search("hell"); // 返回 False
//          magicDictionary.search("leetcoded"); // 返回 False
//      提示：
//          1 <= dictionary.length <= 100
//          1 <= dictionary[i].length <= 100
//          dictionary[i] 仅由小写英文字母组成
//          dictionary 中的所有字符串 互不相同
//          1 <= searchWord.length <= 100
//          searchWord 仅由小写英文字母组成
//          buildDict 仅在 search 之前调用一次
//          最多调用 100 次 search

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

class MagicDictionary
{
public:
    vector<string> dictVec;
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        dictVec = dictionary;
    }

    bool search(string searchWord)
    {
        for (int i = 0; i < dictVec.size(); i++)
        {
            if (searchWord.size() != dictVec[i].size())
            {
                continue;
            }
            int dif = 0;
            for (int j = 0; j < dictVec[i].size(); j++)
            {
                if (dictVec[i][j] != searchWord[j])
                {
                    dif++;
                }
            }
            if (dif == 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    MagicDictionary *magicDictionary = new MagicDictionary();
    magicDictionary->buildDict({"hello", "leetcode"});
    bool s1 = magicDictionary->search("hello"); // 返回 False
    printf("匹配结果为：\n");
    printBool(s1);
    bool s2 = magicDictionary->search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    printf("匹配结果为：\n");
    printBool(s2);
    bool s3 = magicDictionary->search("hell"); // 返回 False
    printf("匹配结果为：\n");
    printBool(s3);
    bool s4 = magicDictionary->search("leetcoded"); // 返回 False
    printf("匹配结果为：\n");
    printBool(s4);
}