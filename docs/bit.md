# 概要
树状数组（Binary Indexed Tree）是一种用于维护序列前缀和的数据结构。它的时间复杂度为 $O(\log n)$ 。
## `Fenwick`
`Fenwick` 类维护一个长度为 $n$ 的序列，支持以下操作：
- `Fenwick(int n)` : 构造一个长度为 $n$ 的序列，初始值均为 $0$ 。区间范围为 $[1, n]$ 。
- `void add(i, x)` : 将序列中第 $i$ 个数加上 $x$ 。
- `T query(i)` : 求序列中前 $i$ 个数的和。


# 常见问题

# 题集