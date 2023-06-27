

//      Huawei: 共享单车管理系统

//      某城市有一个共享单车管理系统,可用一颗树表示，其中包含了仓库和租借点两种节点
//      根节点为仓库，能存放和提供不限量的共享单车
//      其余为租借点，可以租借和归还共享单车
//      请你实现管理系统的如下功能：
//          BikeManager(vector<int> preNode, int capacity): 初始化系统
//              共有preNode.size()个节点，节点编号从0开始；节点0是根节点仓库，其他节点为租界点
//              preNode[i]表示节点i的父节点编号，preNode[0]约定为-1；
//              租借点的容量为capacity,初始时均有[capacity / 2]辆共享单车
//          RentBikes(int nodeId, int num): 在租借点nodeId处租借出num辆共享单车，
//              返回借出后此节点剩余单车的量。
//              若节点nodeId放满共享单车后还有剩余，则将多余的共享单车归还给其父节点，
//              这一过程同样将向其父节点递归求解，直到成功归还。
//          Reset():重置租借点的共享单车数量，并返回被重置的节点数。
//              对于当前共享单车数量为0或者capacity的租借点，
//              将他们的共享单车数量重置为[capacity / 2], 其他节点不重置。
//          GetTop5Nodes():按规则返回top5的租借点编号，若租借点不足5个，则按实际数量返回。
//              规则:优先按剩余单车数量降序；若数量相同，则按编号升序。
//      注意：[x] 表示向下取整，即floor(x)
//      示例：
//          输入：
//              ["BikeManager", "RentBikes", "RentBikes", "GetTop5Nodes",
//              "ReturnBikes", "RentBikes","Reset", "RentBikes", "GetTop5Nodes"]
//              [[[-1, 0, 1, 1, 5, 0, 1, 0], 41], [2, 31], [3, 45], [], [5, 29],
//              [5, 100], [], [3, 12], []]
//          输出：
//              [null, 0, 0, [4, 5, 6, 7, 1], 41, 0, 4, 8, [1, 2, 4, 5, 6]]

class BikeManager
{
    BikeManager(vector<int> preNode, int capacity)
    {
    }
    RentBikes(int nodeId, int num)
    {
    }
    Reset()
    {
    }
    GetTop5Nodes()
    {
    }
};
