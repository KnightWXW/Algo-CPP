#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

//      KMP是 三位大牛：D.E.Knuth、J.H.Morris和V.R.Pratt同时发现的。
//      问题描述：
//          字符串匹配问题:
//      寻找 一个字符串(s) 里是否包含 另一个字符串(t) 并可以返回 其包含的起始位置 index

//      时间复杂度：O(N)
//      空间复杂度：O(N)

int KMP(string s, string t);
vector<int> getNext(string s);

int main()
{
    string s("abcdefghijklmnopqrstuvwxyz");
    string t("jkl");
    printf("%s\n", s.c_str());
    printf("%s\n", t.c_str());
    printf("(KMP)计算可知 t 在 s 中的起始位置 为 %d", KMP(s, t));
}

int KMP(string s, string t)
{
    if (s.size() <= 0 || t.size() <= 0 || s.size() < t.size())
    {
        return -1;
    }
    int indexS = 0;
    int indexT = 0;
    vector<int> next = getNext(t);
    while(indexS < s.size() && indexT < t.size()){
        if (s[indexS] == t[indexT]){
            indexS++;
            indexT++;
        }else if(next[indexT] == -1){
            indexS++;
        }else{
            indexT = next[indexT];
        }
    }
    return indexT == t.size() ? indexS - indexT : -1;
}

// 获取 next数组：
// next数组：
//    next[i]: t[0 : i - 1] 中 
vector<int> getNext(string t){
    if(t.size() == 1){
        return vector<int> {-1};
    }
    vector<int> next(t.size(), 0);
    next[0] = -1;
    next[1] = 0;

    int i = 2;
    int index = 0;
    while(i < t.size()){
        if(t[i - 1] == t[index]){
            next[i++] = ++index;
        }else if(index > 0){
            index = next[index];
        }else{
            next[i++] = 0;
        }
    }
    return next;
}