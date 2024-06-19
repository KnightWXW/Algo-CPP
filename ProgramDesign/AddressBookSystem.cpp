#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      Huawei: 通讯录系统

//      请你设计一个通讯录系统，实现以下功能：
//      void Add(string name, string number): 添加联系人：
//          姓名为 name, 电话号码为 number, 若已存在则不作处理:
//      string Update(string name, string number): 更新联系人：
//          若已存在联系人name, 则将此联系人的电话号码改为 number；
//          若不存在联系人name, 则不做处理并返回 “No Such Person”；
//      string Delete(string name): 删除联系人：
//          若已存在联系人name, 则删除此联系人记录，并返回其电话号码；
//          若不存在联系人name, 则返回 “No Such Person”；
//      vector<string> Prefer(string s): 过滤联系人：
//          把前缀为 s 的联系人过滤出来(区分大小写),
//          并把记录按照名字的字典序返回;

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

class AddressBookSystem
{
public:
    unordered_map<string, string> hmap;

    AddressBookSystem()
    {
    }

    void Add(string name, string number)
    {
        if (hmap.find(name) != hmap.end())
        {
            return;
        }
        hmap[name] = number;
        return;
    }

    string Update(string name, string number)
    {
        if (hmap.find(name) != hmap.end())
        {
            string tem = hmap[name];
            hmap[name] = number;
            return tem;
        }
        else
        {
            return string("No Such Person");
        }
    }

    string Delete(string name)
    {
        if (hmap.find(name) != hmap.end())
        {
            string tem = hmap[name];
            hmap.erase(name);
            return tem;
        }
        else
        {
            return string("No Such Person");
        }
    }

    vector<string> Prefer(string s)
    {
        int l = s.size();
        vector<string> ans;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            string pre = it->first.substr(0, l);
            if (s.compare(pre) == 0)
            {
                ans.push_back(it->first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    AddressBookSystem *addressBookSystem = new AddressBookSystem();
    addressBookSystem->Add("Herry", "123");
    addressBookSystem->Add("Merry", "456");
    string a1 = addressBookSystem->Update("Merry", "789"); // 456
    printf("更新结果为:\n");
    printString(a1);
    vector<string> a2 = addressBookSystem->Prefer("Me"); // {"Merry", "789"}
    printf("查询结果为:\n");
    printStringVector(a2);
    string a3 = addressBookSystem->Delete("Merry"); // 789
    printf("删除结果为:\n");
    printString(a3);
    addressBookSystem->Add("Herry", "234");
    addressBookSystem->Add("Henry", "2564");
    string a4 = addressBookSystem->Update("Merry", "111"); // No Such Person
    printf("更新结果为:\n");
    printString(a4);
    vector<string> a5 = addressBookSystem->Prefer("He"); // {{"Henry", "2564"},{"Herry", "234"}}
    printf("查询结果为:\n");
    printStringVector(a5);
}