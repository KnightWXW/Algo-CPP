#include <stdio.h>
#include <string>
#include <string.h>
#include <unordered_map>

using namespace std;

#define TRIE_TREE_NEXT_LEN 26

class TrieNode
{
public:
    int pass;
    int end;
    unordered_map<int, TrieNode*> next;

    TrieNode()
    {
        pass = 0;
        end = 0;
        unordered_map<int, TrieNode*> nexts;
    }
};

class TrieTree
{
private:
    TrieNode *root;
public:
    // 构造函数：
    TrieTree()
    {
        root = new TrieNode();
    }

    // 析构函数：
    ~TrieTree(){};

    // 向 TrieTree 中 插入 word:
    void insert(string word)
    {
        if (word == "")
        {
            return;
        }
        TrieNode *node = root;
        node->pass++;
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->next.find(index) == node->next.end())
            {
                node->next.insert(make_pair(index, new TrieNode()));
            }
            node = node->next[index];
            node->pass++;
        }
        node->end++;
    }

    // 查找 TrieTree 中 是否 存在 word:
    int search(string word)
    {
        if (word == "")
        {
            return 0;
        }
        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->next.find(index) == node->next.end())
            {
                return 0;
            }
            node = node->next[index];
        }
        return node->end;
    }

    // 从 TrieTree 中 删除 word:
    void remove(string word)
    {
        if (search(word) != 0)
        {
            TrieNode *node = root;
            node->pass--;
            int index = 0;
            for (int i = 0; i < word.size(); i++)
            {
                index = word[i] - 'a';
                if (node->next[index]->pass == 1)
                {
                    node->next[index]->pass--;
                    node->next[index] = NULL;
                    return;
                }
                node = node->next[index];
            }
            node->end--;
        }
    }

    // 在 TrieTree 中 查找 以 word 为 前缀 的 字符串:
    int searchPrefix(string word)
    {
        if (word == "")
        {
            return 0;
        }
        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->next.find(index) == node->next.end())
            {
                return 0;
            }
            node = node->next[index];
        }
        return node->pass;
    }
};

int main()
{
    TrieTree root;
    string s1 = "abc";
    root.insert(s1);
    string s2 = "abcd";
    root.insert(s2);    
    string s3 = "abcde";
    root.insert(s3);
    string s4 = "abc";
    root.insert(s4);

    printf("前缀树 中存在 %d 条 目标字符串\n", root.search("abcde")); // 1
    printf("前缀树 中存在 %d 条 目标字符串\n", root.search("abc")); // 1
    root.remove("abc");
    printf("前缀树 中存在 %d 条 目标字符串\n", root.search("abc")); // 1

    printf("前缀树 中存在 %d 条 以目标字符串开头的字符串\n", root.searchPrefix("ab"));  // 5
    string s5 = "abcdef";
    root.insert(s5);
    printf("前缀树 中存在 %d 条 以目标字符串开头的字符串\n", root.searchPrefix("ab"));  // 5


    // TrieTree root;
    // string s1 = "qwerty";
    // string s2 = "qwe";
    // string s3 = "qwedf";
    // string s4 = "qwe";
    // string s5 = "qty";

    // root.insert(s1);
    // root.insert(s2);
    // root.insert(s3);
    // root.insert(s4);
    // root.insert(s5);

    // printf("前缀树 中存在 %d 条 目标字符串\n", root.search("qwerty")); // 1
    // printf("前缀树 中存在 %d 条 目标字符串\n", root.search("qwe"));    // 3
    // printf("前缀树 中存在 %d 条 以目标字符串开头的字符串\n", root.searchPrefix("qwe"));  // 5
    // root.remove("qwe");
    // printf("前缀树 中存在 %d 条 目标字符串\n", root.search("qwe"));    // 2
}