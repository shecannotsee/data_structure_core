class array{
    InitList(L):构造一个长度为i的空的数组L。

    DestoryList(L):销毁数组L。
    前提：数组L已经存在。

    ClearList(L):将L重置为空表。
    前提：数组L已经存在。

    ListEmpty(L):若L为空返回TURE，否则返回FALSE。
    前提：数组L已经存在。

    ListLength(L):返回L中数据元素的个数。也可以叫做数组的长度。
    前提：数组L已经存在。

    GetElement(L,i):返回L中第i个元素的值。
    前提：数组L已经存在。i的合法性判断。

    InsertElement(L,i,e):往L中的第i个位置插入一个值为e的元素。
    前提：数组L已经存在。i的合法性判断。

    DeleteElement(L,i):删除L中的第i个元素。
    前提：数组L已经存在。i的合法性判断。

}