// 比较
// include <algorithm>
bool cmp(int a, int b){
    return a > b; 
}
sort(vec.begin(), vec.end(), cmp);

sort(vec.begin(), vec.end(), [](int a, int b){ 
        return a > b;
    });

// 求和:
// #include <numeric>
accumulate(vec.begin(), vec.end(), 0);

// 查询最大值/最小值的索引位置
// #include <algorithm>
// 参数：[begin : 序列起始地址（迭代器）]
//       [end : 序列结束地址（迭代器）]
// 返回值 : 序列中最大元素地址（迭代器）
max_element(vec.begin(), vec.end());
min_element(vec.begin(), vec.end());
// 获取该元素 *max_element(vec.begin(), vec.end());

// map 操作：
// #include <map>
// 初始化
    map<int, string> m;  
// 返回map中元素的个数
    m.size()          
// 插入数据
    m.insert(0, "abc"); 
    m[0] = "abc";
// 查找数据
    if(m.find(0) != m.end()){
        ......
    } 
    if(m.count(0) > 0){  // 因为key值不会重复，所以只能是 1 or 0
        ......
    }
// 判空
    m.empty()   // 如果map为空则返回true
// 清除所有元素
    m.clear() 
// 交换两个map
    m.swap(m0)
// 返回 target >= target 的第一个位置    <algorithm>   
    lower_bound(m.begin(), m.end(), target);   
// 返回 target > target 的第一个位置     <algorithm>   
    upper_bound(m.begin(), m.end(), target); 
// 删除元素  返回值为所删元素下一位置的迭代器；
    m.erase(iter)    