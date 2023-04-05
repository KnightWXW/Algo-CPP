#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//      LeetCode 1647. 字符频次唯一的最小删除次数

//      链接：https://leetcode.cn/problems/minimum-deletions-to-make-character-frequencies-unique/

//      如果字符串 s 中 不存在 两个不同字符 频次 相同的情况，就称 s 是优质字符串。
//      给你一个字符串 s，返回使 s 成为 优质字符串 需要删除的 最小 字符数。
//      字符串中字符的 频次 是该字符在字符串中的出现次数。
//      例如，在字符串 "aab" 中，'a' 的频次是 2，而 'b' 的频次是 1。
//      示例 1：
//          输入：s = "aab"
//          输出：0
//          解释：s 已经是优质字符串。
//      示例 2：
//          输入：s = "aaabbbcc"
//          输出：2
//          解释：可以删除两个 'b' , 得到优质字符串 "aaabcc" 。
//          另一种方式是删除一个 'b' 和一个 'c' ，得到优质字符串 "aaabbc" 。
//      示例 3：
//          输入：s = "ceabaacb"
//          输出：2
//          解释：可以删除两个 'c' 得到优质字符串 "eabaab" 。
//          注意，只需要关注结果字符串中仍然存在的字符。（即，频次为 0 的字符会忽略不计。）
//      提示：
//          1 <= s.length <= 105
//          s 仅含小写英文字母

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int MinDeletions(string s);

int main()
{
    int n = generateRandomNum(0, 60);
    string str = generateRandomString(n);
    printf("字符串为：");
    printString(str);
    int ans = MinDeletions(str);
    printf("成为 优质字符串 需要删除的 最小 字符数为: %d\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "abcdefghijkmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

int MinDeletions(string str)
{
    int l = str.size();
    int ans = 0;
    vector<int> cnt(26, 0);
    for(int i = 0; i < l; i++){
        cnt[str[i] - 'a']++;
    }
    set<int> s;
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] == 0){
            continue;
        }
        while(s.find(cnt[i]) != s.end())
        {
            cnt[i]--;
            ans++;
        }
        if(cnt[i] != 0){
            s.insert(cnt[i]);
        }
    }
    return ans;
}