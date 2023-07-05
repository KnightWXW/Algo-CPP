



//      Huawei: 高铁选座

//      在某趟高铁列车上，每个车厢内共有rows行座位，
//      每行/列座位的序号和分布如图一所示      
//          窗口      1A   1B   1C   通道   1D    1F
//          窗口      2A   2B   2C   通道   2D    2F
//          窗口      3A   3B   3C   通道   3D    3F
//      列表seats中保存了此车厢已被购买的座位。若列表为空，
//      表示该车厢内的座位还未被购买，且每个座位只能被购买一次
//      根据seats显示的售卖情况，
//      请问可以订到多少对(2张)同一行并且相邻的座位("C" 和 "D"跨过道不相邻)
//      示例1：
//          输入: rows = 4, seats = ["3A", "4F", "3B"]
//          输出：6
//      注意：
//          1 <= rows <= 10^9
//          0 <= seats.size() <= 10^5

int SeatSelectionOfHighSpeedRail(int rows, vector<string> seats);


