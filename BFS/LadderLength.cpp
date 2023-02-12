#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

using namespace std;

//      LeetCode 127. 单词接龙

//      链接: https://leetcode.cn/problems/word-ladder/

//      字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
//      是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
//      每一对相邻的单词只差一个字母。
//      对于 1 <= i <= k 时，每个 si 都在 wordList 中。
//      注意， beginWord 不需要在 wordList 中。
//      sk == endWord
//      给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
//      返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目。
//      如果不存在这样的转换序列，返回 0 。
//      示例 1：
//          输入：beginWord = "hit",
//               endWord = "cog",
//               wordList = ["hot","dot","dog","lot","log","cog"]
//          输出：5
//          解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//               返回它的长度 5。
//      示例 2：
//          输入：beginWord = "hit",
//                endWord = "cog",
//                wordList = ["hot","dot","dog","lot","log"]
//          输出：0
//          解释：endWord "cog" 不在字典中，所以无法进行转换。
//      提示：
//          1 <= beginWord.length <= 10
//          endWord.length == beginWord.length
//          1 <= wordList.length <= 5000
//          wordList[i].length == beginWord.length
//          beginWord、endWord 和 wordList[i] 由小写英文字母组成
//          beginWord != endWord
//          wordList 中的所有字符串 互不相同

int DigitWordDistance(string &wordA, string &wordB);
vector<string> FindNeighborWords(string word, vector<string> &wordList);
int LadderLength_A(string beginWord, string endWord, vector<string> &wordList);
int LadderLength_B(string beginWord, string endWord, vector<string> &wordList);

int main()
{
    string beginWord_A = "hit";
    string endWord_A = "cog";
    vector<string> wordList_A = {"hot","dot","dog","lot","log","cog"};
    int ans_AA = LadderLength_A(beginWord_A, endWord_A, wordList_A);
    int ans_AB = LadderLength_B(beginWord_A, endWord_A, wordList_A);
    printf("从 %s 到 %s 的 最短转换序列 中的 单词数目为 %d。\n", beginWord_A.c_str(), endWord_A.c_str(), ans_AA);
    printf("从 %s 到 %s 的 最短转换序列 中的 单词数目为 %d。\n", beginWord_A.c_str(), endWord_A.c_str(), ans_AB);
    
    string beginWord_B = "hit";
    string endWord_B = "cog";
    vector<string> wordList_B = {"hot","dot","dog","lot","log"};
    int ans_BA = LadderLength_A(beginWord_B, endWord_B, wordList_B);
    int ans_BB = LadderLength_B(beginWord_B, endWord_B, wordList_B);
    printf("从 %s 到 %s 的 最短转换序列 中的 单词数目为 %d。\n", beginWord_B.c_str(), endWord_B.c_str(), ans_BA);
    printf("从 %s 到 %s 的 最短转换序列 中的 单词数目为 %d。\n", beginWord_B.c_str(), endWord_B.c_str(), ans_BB);
}

int DigitWordDistance(string &wordA, string &wordB)
{
    int distance = 0;
    for (int i = 0; i < wordA.size(); i++)
    {
        if (wordA[i] != wordB[i])
        {
            distance++;
        }
    }
    return distance;
}

vector<string> FindNeighborWords(string word, vector<string> &wordList)
{
    vector<string> ans;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (DigitWordDistance(word, wordList[i]) == 1)
        {
            ans.push_back(wordList[i]);
        }
    }
    return ans;
}

int LadderLength_A(string beginWord, string endWord, vector<string> &wordList)
{
    int l = wordList.size();
    unordered_map<string, int> hmap;
    deque<string> d1;
    deque<string> d2;
    d1.push_back(beginWord);
    hmap[beginWord]++;
    int ans = 0;
    while (!d1.empty() || !d2.empty())
    {
        if (d1.empty())
        {
            swap(d1, d2);
            ans++;
        }
        string cur = d1.front();
        d1.pop_front();
        vector<string> vec = FindNeighborWords(cur, wordList);
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == endWord)
            {
                return ans + 2;
            }
            if (hmap[vec[i]] == 0)
            {
                hmap[vec[i]]++;
                d2.push_back(vec[i]);
            }
        }
    }
    return 0;
}

int LadderLength_B(string beginWord, string endWord, vector<string> &wordList)
{
    int l = wordList.size();
    int ans = 0;
    unordered_set<string> hset;
    unordered_map<string, int> hmap;
    deque<string> d;
    for(int i = 0 ; i < wordList.size(); i++){
        hset.insert(wordList[i]);
    }
    if(hset.count(endWord) == 0){
        return 0;
    }
    d.push_back(beginWord);
    hmap[beginWord]++;
    while (!d.empty())
    {
        int size = d.size();
        for(int i = 0; i < size; i++){
            string cur = d.front();
            d.pop_front();
            if(cur == endWord){
                return ans + 1;
            }
            for(auto tem : hset){
                if (DigitWordDistance(cur, tem) == 1 && hmap[tem] == 0)
                {
                    d.push_back(tem);
                    hmap[tem]++;
                }
            }
        }
        ans++;
    }
    return 0;
}