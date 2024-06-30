#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      Huawei: 电话号码转换

//      某语音翻译软件，需要实现如下中英文电话号码转换功能：
//      若输入的是英文数字单词或Double组成的电话号码，则输出对应的中文数字单词
//      若输入的是中文数字单词组成的电话号码，则输出对应的英文数字单词
//      若输入不合法，则输出字符串ERROR
//      中文数字，英文数字分别见下表：
//          中文数字单词：Yi Er San Si Wu Liu Qi Ba Jiu Ling
//          英文数字单词：One Two Three Four Five Six Seven Eight Nine Zero
//      说明：
//          1、输入若存在Double，其后必须跟随英文数字单词，代表两个该数字。
//              如输入DoubleSix，代表 SixSix
//          2、输入保证要么全中文，要么全英文（含Double）,
//              并且每个单词都是合法的英文的数字单词/中文数字单词/Double
//          3、输入不合法的场景，仅为Double后跟随的不是英文数字单词，如DoubleLiu非法。
//      输入:
//          一行仅有大小写字母组成的字符串，非空且长度不大于500
//      输出：
//          一个字符串，表示转换后的电话号码，若输入不合法输出ERROR
//      示例1：
//          输入
//              SixOneThreeOneDoubleZero
//          输出
//              LiuYiSanYiLingLing
//      示例2：
//          输入
//              YiLingSanSanJiu
//          输出
//              OneZeroThreeThreeNine
//      示例3：
//          输入
//              DoubleLiu
//          输出
//              ERROR

void printString(string s);
void printStringVector(vector<string> vec);

bool JudgeChineseWord(string s);
vector<string> SplitWord(string s);
string PhoneNumberConversion(string phone);

int main()
{
    string s1 = "SixOneThreeOneDoubleZero";
    printString(s1);
    string ans1 = PhoneNumberConversion(s1);
    printString(ans1); // LiuYiSanYiLingLing

    string s2 = "YiLingSanSanJiu";
    printString(s2);
    string ans2 = PhoneNumberConversion(s2);
    printString(ans2); // OneZeroThreeThreeNine

    string s3 = "DoubleLiu";
    printString(s3);
    string ans3 = PhoneNumberConversion(s3);
    printString(ans3); // ERROR
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

vector<string> SplitWord(string s)
{
    vector<string> ans;
    for (int i = 0; i < sizeof(s);)
    {
        string tem = "";
        if (isupper(s[i]))
        {
            tem += s[i++];
            while (!isupper(s[i]) && i < s.size())
            {
                tem += s[i++];
            }
            ans.push_back(tem);
            continue;
        }
        i++;
    }
    return ans;
}

string PhoneNumberConversion(string phone)
{
    unordered_map<string, string> CtoEmap = {{"Ling", "Zero"}, {"Yi", "One"}, {"Er", "Two"}, {"San", "Three"}, {"Si", "Four"}, {"Wu", "Five"}, {"Liu", "Six"}, {"Qi", "Seven"}, {"Ba", "Eight"}, {"Jiu", "Nine"}};
    unordered_map<string, string> EtoCmap = {{"Zero", "Ling"}, {"One", "Yi"}, {"Two", "Er"}, {"Three", "San"}, {"Four", "Si"}, {"Five", "Wu"}, {"Six", "Liu"}, {"Seven", "Qi"}, {"Eight", "Ba"}, {"Nine", "Jiu"}};
    int l = phone.size();
    string ans = "";
    vector<string> vec = SplitWord(phone);
    for (int i = 0; i < vec.size(); i++)
    {
        if (CtoEmap.find(vec[i]) != CtoEmap.end())
        {
            ans += CtoEmap[vec[i]];
        }
        else if (EtoCmap.find(vec[i]) != EtoCmap.end())
        {
            ans += EtoCmap[vec[i]];
        }
        else if (vec[i] == "Double" && (i + 1) < vec.size())
        {
            if (EtoCmap.find(vec[i + 1]) != EtoCmap.end())
            {
                ans += EtoCmap[vec[i + 1]];
            }
            else
            {
                return "Error";
            }
        }
    }
    return ans;
}