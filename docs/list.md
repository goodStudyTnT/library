
# 概要
链表 List 是一种线性表，用一组任意的内存空间，依次存储线性表的数据元素。它由以下两部分组成：
## `Node`
`Node` 是链表中的一个节点，它包含了一个数据元素和一个指向下一个节点的指针。使用时可以往 `Node` 中存储任意类型的数据。
## `List`
`List` 是算法模板类，需要传入 `Node`。主要有以下几个功能：
- `int init()` 初始化链表, 返回链表的头指针的下标
- `int new_node(int idx, Node it)` 在链表的第 idx 个节点后插入一个新节点, 返回新节点的下标
- `int erase_node(int idx)` 删除链表的第 idx 个节点, 返回下一个节点的下标


# 常见问题

# 题集