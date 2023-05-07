#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

//      Huawei: 租房信息查询系统

//      请设计一个租房信息查询系统，需要实现如下功能：
//      bool AddRoom(int id, int area, int price, int rooms, int[] address)：
//          在系统中增加一套编号为 id，面积为 area，月租金为 price，卧室数量为 rooms，
//          地址坐标为 address(格式为 [横坐标x, 纵坐标y])的房源：
//          若系统中不存在编号为 id的房源，则添加该房源，返回 true；
//          若已存在，则将对应房源信息 更新 为新传入的 area、price、rooms 与 address，
//          并返回 false；
//      bool DeleteRoom(int id)：删除系统中编号为 id 的房源：
//          若存在编号为 id 的房源，删除此房源并返回 true；若不存在，返回 false。
//      vector<int> QueryRoom(int area, int price, int rooms, int[] address, int[][] orderBy)：
//          查询系统中符合筛选条件的房源，并按排序要求返回房源编号的序列。其中：
//          筛选条件：面积大于等于 area，月租金小于等于 price，卧室数为 rooms 的房源；
//          排序要求：按orderBy中的排序条件依次进行排序；
//              若按orderBy排序结果仍相同（含orderBy为空），则按房源编号升序排列。
//              orderBy的元素格式为 [parameter,order]。
//              parameter取值范围[1,3]:1（area）2（price）3（房源坐标与address的曼哈顿距离）；
//              order取值仅为 1 和 -1，1（表示升序）、-1（表示降序）。
//              例如 orderBy = [[3,1],[1,-1]] 表示先按照曼哈顿距离升序排列；
//              若曼哈顿距离相同，再按照面积降序排列；若依然相同，则按编号升序排列。
//      示例 1：
//      输入：
//          ["RentingSystem","addRoom","addRoom","queryRoom","deleteRoom"]
//          [[],[3,24,200,2,[0,1]],[1,10,400,2,[1,0]],[1,400,2,[1,1],[[3,1],[2,-1]]],[3]]
//      输出：[null,true,true,[1,3],true]
//      解释：
//          RentingSystem obj = RentingSystem();
//          obj.addRoom(3,24,200,2,[0,1]);
//              在系统中添加编号为 3，面积为 24，月租金为 200，卧室数为 2，
//              坐标为 [0,1] 的房源，返回 true
//          obj.addRoom(1,10,400,2,[1,0]);
//              在系统中添加编号为 1，面积为 10，月租金为 400，卧室数为 2，
//              坐标为 [1,0] 的房源，返回 true
//          obj.queryRoom(1,400,2,[1,1],[[3,1],[2,-1]]);
//              查询系统中面积大于等于 1，月租金小于等于 400，卧室数为 2 的房源，
//              查询所在地坐标为 [1,1]，先按照距离升序排序，结果相同，
//              再按照月租金降序排序，编号为 1 的月租金大于编号为 3 的月租金，所以返回 [1,3]
//          obj.deleteRoom(3);
//              删除编号为 3 的房源，返回 true
//      注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
//      示例 2：
//      输入：
//          ["RentingSystem","deleteRoom","addRoom","addRoom","addRoom","addRoom","addRoom","addRoom","queryRoom","queryRoom"]
//          [[],[10],[3,24,200,2,[0,1]],[3,24,500,2,[0,1]],[3,27,500,4,[1,1]],
//           [1,27,500,4,[20,43]],[6,35,227,4,[2,4]],[9,20,3540,4,[4,321]],
//           [25,900,4,[10,1],[[1,1],[2,-1],[3,1]]],[25,900,4,[10,1],[]]]
//          输出：[null,false,true,false,false,true,true,true,[3,1,6],[1,3,6]]
//      解释：
//          RentingSystem obj = RentingSystem();
//          obj.deleteRoom(10); // 返回 false
//          obj.addRoom(3,24,200,2,[0,1]); // 返回 true
//          obj.addRoom(3,24,500,2,[0,1]); // 返回 false
//          obj.addRoom(3,27,500,4,[1,1]); // 返回 false
//          obj.addRoom(1,27,500,4,[20,43]) // 返回 true
//          obj.addRoom(6,35,227,4,[2,4]) // 返回 true
//          obj.addRoom(9,20,3540,4,[4,321]) // 返回 true
//          obj.queryRoom(25,900,4,[10,1],[[1,1],[2,-1],[3,1]])
//              查询系统中面积大于等于 25，月租金小于等于 900，卧室数为 4 的房源，
//              先按照面积升序排列，接着按月租金降序排列，最后按曼哈顿距离升序排列。
//              返回 [3,1,6]。
//          obj.queryRoom(25,900,4,[10,1],[])
//              查询系统中面积大于等于 25，月租金小于等于 900，卧室数为 4 的房源，
//              由于orderBy为空，则按房源编号升序排列。返回 [1,3,6]。
//          注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
//      提示：
//          3 <= addRoom, deleteRoom, queryRoom 累计操作数 <= 1000
//          1 <= id <= 1000
//          1 <= area <= 1000
//          1 <= price <= 10^4
//          1 <= rooms <= 10
//          address.length == 2
//          0 <= address[0], address[1] <= 10^4
//          0 <= orderBy.length <= 3, orderBy[i].length == 2
//          1 <= orderBy[i][0] <= 3
//          orderBy[i][1] == -1 or 1
//          若 i != j 则 orderBy[i][0] != orderBy[j][0]
//          曼哈顿距离：地址1(x1, y1) 与 地址2(x2, y2)的曼哈顿距离，
//                     计算公式 = |x1 - x2| + |y1 - y2|。

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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class RentingSystem1
{
public:
    unordered_map<int, tuple<int, int, int, vector<int>>> rentMap;
    int Digitdistance(vector<int> v1, vector<int> v2)
    {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }

    bool OrderBy(const vector<vector<int>> &ob, tuple<int, int, int, int> t1, tuple<int, int, int, int> t2)
    {
        bool ans = get<0>(t1) < get<0>(t2);
        for (int i = ob.size() - 1; i >= 0; i--)
        {
            bool flag = ob[i][1] == 1;
            if (ob[i][0] == 1)
            {
                if (get<1>(t1) == get<1>(t2))
                {
                    continue;
                }
                ans = !(flag ^ (get<1>(t1) < get<1>(t2)));
            }
            if (ob[i][0] == 2)
            {
                if (get<2>(t1) == get<2>(t2))
                {
                    continue;
                }
                ans = !(flag ^ (get<2>(t1) < get<2>(t2)));
            }
            if (ob[i][0] == 3)
            {
                if (get<3>(t1) == get<3>(t2))
                {
                    continue;
                }
                ans = !(flag ^ (get<3>(t1) < get<3>(t2)));
            }
        }
        return ans;
    }

    RentingSystem1()
    {
    }

    bool AddRoom(int id, int area, int price, int rooms, vector<int> address)
    {
        bool flag = rentMap.find(id) != rentMap.end() ? true : false;
        rentMap[id] = make_tuple(area, price, rooms, address);
        return flag;
    }

    bool DeleteRoom(int id)
    {
        bool flag = false;
        if (rentMap.find(id) != rentMap.end())
        {
            flag = true;
            rentMap.erase(id);
        }
        return flag;
    }

    vector<int> QueryRoom(int area, int price, int rooms, const vector<int> &address, const vector<vector<int>> &orderBy)
    {
        vector<int> ans;
        vector<tuple<int, int, int, int>> rentVec;
        for (auto v : rentMap)
        {
            if (get<0>(v.second) >= area && get<1>(v.second) <= price && get<2>(v.second) == rooms)
            {
                int temDis = Digitdistance(get<3>(v.second), address);
                rentVec.push_back(make_tuple(v.first, get<0>(v.second), get<1>(v.second), temDis));
            }
        }
        sort(rentVec.begin(), rentVec.end(), [=](tuple<int, int, int, int> t1, tuple<int, int, int, int> t2) -> bool
             { return OrderBy(orderBy, t1, t2); });
        for (auto v : rentVec)
        {
            ans.push_back(get<0>(v));
        }
        return ans;
    }
};

struct RentInfo
{
    int id;
    int area;
    int price;
    int rooms;
    vector<int> address;

public:
    RentInfo &operator=(const RentInfo &info)
    {
        id = info.id;
        area = info.area;
        price = info.price;
        rooms = info.rooms;
        address = info.address;
        return *this;
    }
};

class RentingSystem2
{
public:
    unordered_map<int, RentInfo> rentMap;
    int Digitdistance(vector<int> v1, vector<int> v2)
    {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }

    RentingSystem2()
    {
    }

    bool AddRoom(int id, int area, int price, int rooms, vector<int> address)
    {
        bool flag = rentMap.find(id) != rentMap.end() ? true : false;
        RentInfo info = {id, area, price, rooms, address};
        rentMap[id] = info;
        return flag;
    }

    bool DeleteRoom(int id)
    {
        bool flag = false;
        if (rentMap.find(id) != rentMap.end())
        {
            flag = true;
            rentMap.erase(id);
        }
        return flag;
    }

    vector<int> QueryRoom(int area, int price, int rooms, const vector<int> &address, const vector<vector<int>> &orderBy)
    {
        vector<int> ans;
        vector<RentInfo> rentVec;
        for (auto v : rentMap)
        {
            if (v.second.area >= area && v.second.price <= price && v.second.rooms == rooms)
            {
                rentVec.push_back(v.second);
            }
        }
        sort(rentVec.begin(), rentVec.end(), [&](const RentInfo &r1, const RentInfo &r2) -> bool
             {
                for(int i = orderBy.size() - 1; i >= 0 ; i--){
                    int distance1 = Digitdistance(r1.address, address);
                    int distance2 = Digitdistance(r2.address, address);
                    if(orderBy[i][0] == 1 && r1.area != r2.area){
                        return orderBy[i][1] == 1 ? r1.area < r2.area : r1.area > r2.area;
                    }
                    if(orderBy[i][0] == 2 && r1.price != r2.price){
                        return orderBy[i][1] == 1 ? r1.price < r2.price : r1.price > r2.price;
                    }
                    if(orderBy[i][0] == 3 && distance1 != distance2){
                        return orderBy[i][1] == 1 ? distance1 < distance2 : distance1 > distance2;
                    }
                }
                return r1.id < r2.id; });
        for (auto v : rentVec)
        {
            ans.push_back(v.id);
        }
        return ans;
    }
};

int main()
{
    printf("----------------------------------------\n");
    RentingSystem1 obj11 = RentingSystem1();
    bool b11 = obj11.AddRoom(3, 24, 200, 2, {0, 1});
    printBool(b11); // 返回 true
    bool b12 = obj11.AddRoom(1, 10, 400, 2, {1, 0});
    printBool(b12); // 返回 true
    vector<int> v11 = obj11.QueryRoom(1, 400, 2, {1, 1}, {{3, 1}, {2, -1}});
    printVec(v11); // 返回 [1, 3]
    bool b13 = obj11.DeleteRoom(3);
    printBool(b13); // 返回 true
    printf("----------------------------------------\n");
    RentingSystem1 obj12 = RentingSystem1();
    bool b21 = obj12.DeleteRoom(10);
    printBool(b21); // 返回 false
    bool b22 = obj12.AddRoom(3, 24, 200, 2, {0, 1});
    printBool(b22); // 返回 true
    bool b23 = obj12.AddRoom(3, 24, 500, 2, {0, 1});
    printBool(b23); // 返回 false
    bool b24 = obj12.AddRoom(3, 27, 500, 4, {1, 1});
    printBool(b24); // 返回 false
    bool b25 = obj12.AddRoom(1, 27, 500, 4, {20, 43});
    printBool(b25); // 返回 true
    bool b26 = obj12.AddRoom(6, 35, 227, 4, {2, 4});
    printBool(b26); // 返回 true
    bool b27 = obj12.AddRoom(9, 20, 3540, 4, {4, 321});
    printBool(b27); // 返回 true
    vector<int> v21 = obj12.QueryRoom(25, 900, 4, {10, 1}, {{1, 1}, {2, -1}, {3, 1}});
    printVec(v21); // 返回 [3,1,6]。
    vector<int> v22 = obj12.QueryRoom(25, 900, 4, {10, 1}, {});
    printVec(v22); // 返回 [1,3,6]。

    printf("----------------------------------------\n");
    RentingSystem2 obj21 = RentingSystem2();
    bool b31 = obj21.AddRoom(3, 24, 200, 2, {0, 1});
    printBool(b31); // 返回 true
    bool b32 = obj11.AddRoom(1, 10, 400, 2, {1, 0});
    printBool(b32); // 返回 true
    vector<int> v31 = obj21.QueryRoom(1, 400, 2, {1, 1}, {{3, 1}, {2, -1}});
    printVec(v31); // 返回 [1, 3]
    bool b33 = obj21.DeleteRoom(3);
    printBool(b33); // 返回 true
    printf("----------------------------------------\n");
    RentingSystem1 obj22 = RentingSystem1();
    bool b41 = obj22.DeleteRoom(10);
    printBool(b41); // 返回 false
    bool b42 = obj12.AddRoom(3, 24, 200, 2, {0, 1});
    printBool(b42); // 返回 true
    bool b43 = obj12.AddRoom(3, 24, 500, 2, {0, 1});
    printBool(b43); // 返回 false
    bool b44 = obj12.AddRoom(3, 27, 500, 4, {1, 1});
    printBool(b44); // 返回 false
    bool b45 = obj12.AddRoom(1, 27, 500, 4, {20, 43});
    printBool(b45); // 返回 true
    bool b46 = obj12.AddRoom(6, 35, 227, 4, {2, 4});
    printBool(b46); // 返回 true
    bool b47 = obj12.AddRoom(9, 20, 3540, 4, {4, 321});
    printBool(b47); // 返回 true
    vector<int> v41 = obj12.QueryRoom(25, 900, 4, {10, 1}, {{1, 1}, {2, -1}, {3, 1}});
    printVec(v41); // 返回 [3,1,6]。
    vector<int> v42 = obj12.QueryRoom(25, 900, 4, {10, 1}, {});
    printVec(v42); // 返回 [1,3,6]。
}