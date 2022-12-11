#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 424. 替换后的最长重复字符

//      链接：https://leetcode.cn/problems/longest-repeating-character-replacement/

//      给你一个字符串 s 和一个整数 k 。
//      你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。
//      该操作最多可执行 k 次。
//      在执行上述操作后，返回包含相同字母的最长子字符串的长度。
//      示例 1：
//          输入：s = "ABAB", k = 2
//          输出：4
//          解释：用两个'A'替换为两个'B',反之亦然。
//      示例 2：
//          输入：s = "AABABBA", k = 1
//          输出：4
//          解释：
//          将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//          子串 "BBBB" 有最长重复字母, 答案为 4。
//      提示：
//          1 <= s.length <= 105
//          s 仅由大写英文字母组成
//          0 <= k <= s.length

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int CharacterReplacement(string s, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    string s = generateRandomString(n);
    int k = generateRandomNum(1, n / 5 + 1);
    int ans = CharacterReplacement(s, k);
    printf("在不超过 %d 次操作的情况下，\n%s\n中包含相同字母的最长子字符串的长度为 %d. \n", k, s.c_str(), ans);
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
    char arr[] = "ABCDE";
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

int CharacterReplacement(string s, int k){
    int l = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    int tem = 0;   // 记录 目前出现次数 最多 的字符 的 出现次数 
    vector<int> cnt(26, 0);

    while(right < l){
        cnt[s[right] - 'A']++;
        tem = max(tem, cnt[s[right] - 'A']);
        if(right - left + 1 <= tem + k){
            ans = max(ans, right - left + 1);
        }else{
            cnt[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return ans;
}