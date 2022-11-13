#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

void printBool(bool b);

#define TRIE_TREE_NEXT_LEN 26

class TrieNode
{
public:
    int pass;
    int end;
    TrieNode *next[TRIE_TREE_NEXT_LEN];

    TrieNode()
    {
        this->pass = 0;
        this->end = 0;
        memset(this->next, NULL, sizeof(TrieNode *) * TRIE_TREE_NEXT_LEN);
    }
};

class TrieTree
{
public:
    TrieNode *root;
public:
    TrieTree()
    {
        root = new TrieNode();
    }

    ~TrieTree(){};

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
            if (node->next[index] == NULL)
            {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
            node->pass++;
        }
        node->end++;
    }

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
            if (node->next[index] == NULL)
            {
                return 0;
            }
            node = node->next[index];
        }
        return node->end;
    }

    void remove(string word)
    {
        if (search(word) == 0)
        {
            return;
        }

        TrieNode *node = root;
        node->pass--;
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->next[index]->pass > 1)
            {
                node->next[index]->pass--;
            }
            else if (node->next[index]->pass == 1)
            {
                node->next[index]->pass--;
                node->next[index] = NULL;
                return;
            }
            node = node->next[index];
        }
        node->end--;
    }

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
            if (node->next[index] == NULL)
            {
                return 0;
            }
            node = node->next[index];
        }
        return node->pass;
    }

    bool searchWithPattern(string word, TrieNode *node, int k)
    {
        if (word == "")
        {
            return false;
        }

        if (node == NULL)
        {
            return false;
        }

        if (k >= word.size())
        {
            return node->end > 0;
        }

        char c = word[k];
        if (c == '.')
        {
            for (int j = 0; j < TRIE_TREE_NEXT_LEN; j++)
            {
                if (searchWithPattern(word, node->next[j], k + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            int i = c - 'a';
            return searchWithPattern(word, node->next[i], k + 1);
        }
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
    printf("前缀树 中存在 %d 条 目标字符串\n", root.search("abc"));   // 1
    root.remove("abc");
    printf("前缀树 中存在 %d 条 目标字符串\n", root.search("abc")); // 1

    printf("前缀树 中存在 %d 条 以目标字符串开头的字符串\n", root.searchPrefix("ab")); // 5
    string s5 = "abcdef";
    root.insert(s5);
    printf("前缀树 中存在 %d 条 以目标字符串开头的字符串\n", root.searchPrefix("ab")); // 5

    bool flag0 = root.searchWithPattern(".cde", root.root, 0);
    printf("前缀树 中 是否存在 以 “.cde” 匹配的字符串\n");
    printBool(flag0);
    bool flag1 = root.searchWithPattern("..cde", root.root, 0);
    printf("前缀树 中 是否存在 以 “..cde” 匹配的字符串\n");
    printBool(flag1);
    bool flag2 = root.searchWithPattern(".b.", root.root, 0);
    printf("前缀树 中 是否存在 以 “.b.” 匹配的字符串\n");
    printBool(flag2);
    bool flag3 = root.searchWithPattern(".bc", root.root, 0);
    printf("前缀树 中 是否存在 以 “.bc” 匹配的字符串\n");
    printBool(flag3);
    bool flag4 = root.searchWithPattern("a.", root.root, 0);
    printf("前缀树 中 是否存在 以 “a.” 匹配的字符串\n");
    printBool(flag4);
}

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