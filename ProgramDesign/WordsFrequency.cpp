#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

//      LeetCode 面试题 16.02. 单词频率

//      链接：https://leetcode.cn/problems/words-frequency-lcci/

//      设计一个方法，找出任意指定单词在一本书中的出现频率。
//      你的实现应该支持如下操作：
//          WordsFrequency(book)构造函数，参数为字符串数组构成的一本书
//          get(word)查询指定单词在书中出现的频率
//      示例：
//          WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
//          wordsFrequency.get("you"); //返回0，"you"没有出现过
//          wordsFrequency.get("have"); //返回2，"have"出现2次
//          wordsFrequency.get("an"); //返回1
//          wordsFrequency.get("apple"); //返回1
//          wordsFrequency.get("pen"); //返回1
//      提示：
//          book[i]中只包含小写字母
//          1 <= book.length <= 100000
//          1 <= book[i].length <= 10
//          get函数的调用次数不会超过100000

class WordsFrequency
{
public:
    unordered_map<string, int> hmap;
    WordsFrequency(vector<string> book)
    {
        for (int i = 0; i < book.size(); i++)
        {
            hmap[book[i]]++;
        }
    }

    int get(string word)
    {
        return hmap[word];
    }
};

int main()
{
    WordsFrequency *wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
    int g1 = wordsFrequency->get("you"); // 返回0，"you"没有出现过
    printf("该单词频率为 %d\n", g1);
    int g2 = wordsFrequency->get("have"); // 返回2，"have"出现2次
    printf("该单词频率为 %d\n", g2);
    int g3 = wordsFrequency->get("an"); // 返回1
    printf("该单词频率为 %d\n", g3);
    int g4 = wordsFrequency->get("apple"); // 返回1
    printf("该单词频率为 %d\n", g4);
    int g5 = wordsFrequency->get("pen"); // 返回1
    printf("该单词频率为 %d\n", g5);
}