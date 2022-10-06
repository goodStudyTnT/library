#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
/*
@brief 带权并查集
@docs docs/weighted_dsu.md
*/

// 带权并查集
struct WeightedDSU {
    std::vector<int> f, g;
    WeightedDSU(int n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0); }
    std::array<int, 2> leader(int x) {
        if (f[x] == x) {
            return {x, 0};
        }
        auto [y, z] = leader(f[x]);
        f[x] = y;
        g[x] ^= z;
        return {f[x], g[x]};
    }
    bool merge(int a, int b, int z) {
        auto [x, u] = leader(a);
        auto [y, v] = leader(b);
        if (x == y) {
            return (u ^ v ^ z) == 0;
        }
        f[x] = y;
        g[x] = u ^ v ^ z;
        return true;
    }
};
