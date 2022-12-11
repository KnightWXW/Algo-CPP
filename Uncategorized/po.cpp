

//有一个工厂具有多条流水线，流水线上均可生产多种产品，产品生产有一定的周期。完成 ProductionLineMgmtSys类。

//①ProductionLineMgmtSys()函数为初始化函数，入参是流水线条数num，以及各编号产品的生产周期，在一个数组中periods中。

//②Produce()函数为生产函数，入参是开始生产时间date，流水线编号assemblyId，以及产品编号productId。规则是：
//      i)若该流水线未被占用，则从此开始生产时间开始生产该编号的产品，并返回1；
//      ii)若该流水线正在被占用，且恰好是同一产品，则该流水线继续生产该产品，并返回0；
//      iii)若该流水线正在被占用，并且是另外一种产品，则直接在此开始生产时间开始生产新的产品，并返回-1；
//      iv)切换规则，比如上个产品在时刻2开始生产，其生产周期为3，则在时刻8切换生产新的产品时，上个产品已经生产了2个；
//          而在时刻10切换生产新的产品时，由于最后一个产品还没有生产完全，丢弃最后一个，仍然只算成功生产2个。

//③GetProductCount()函数为统计函数，入参是时刻date，以及产品编号productId，统计的是时刻date时，工厂生产编号为productId的产品的总数量，返回这个值。
//注：保证date是递增的。

//分别是map类型的myassemb，
//    key是流水线编号，value是一个pair，pair->first是该流水线生产该产品的开始时间；pair->second是该流水线正在生产的产品编号，

// vector<int>类型的productnum，存储各个产品编号生产好的产品数量（只记录已经被从流水线上替换下来的产品。
//  也就是说若一个产品还在流水线上生产，则该流水线本次生产的产品先不计入，待该流水线切换时统一存储进去）

// vector<int>类型的productperiods，其中存储的是各产品的生产周期。


// 在ProductionLineMgmtSys()函数中先初始化productperiods和productnum；
//   在Produce()函数中完成主要的生产活动；在GetProductCount()函数中统计产品数量，
//   其数量为已经存储在productnum中的数量加上还在生产线上生产中并且已经生产好的数量。