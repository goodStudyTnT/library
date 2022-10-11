#include <bits/stdc++.h>

using namespace std;

/*
@brief Trie
@docs docs/trie.md
*/

struct TrieNode {
    vector<int> nxt;
    TrieNode(int char_size) {
        nxt.resize(char_size, -1);
    }
    // 一些 hook 函数，用于 Trie 算法以及 ac 自动机, 可以覆盖这些函数来实现一些功能

    // 当加入到字典树后，对最终的节点(当前节点)进行一些操作
    void update_when_finish_in_trie(){};

    // 当加入到字典树时，根据当前节点和子节点的信息，对当前节点进行一些操作
    void update_when_push_in_trie(TrieNode &child_node){};

    // 当构建 fail 函数时，根据当前节点和 fail 节点的信息，对当前节点进行一些操作
    void update_when_build_fail(TrieNode &fail_node){};
};

template <typename T = TrieNode>
struct Trie {
   public:
    vector<T> nodes;
    int root;

    int char_size;
    int margin;

    Trie(int char_size, int margin) : root(0), char_size(char_size), margin(margin) {
        nodes.push_back(T(char_size));
    }

    void add(const string &s, int s_idx, int node_idx) {
        /*
         * 将字符串 s 的 s_idx 位置开始的后缀加入到字典树中. node_idx 为当前节点的下标
         */
        if (s_idx == s.size()) {
            // 完成加入
            nodes[node_idx].update_when_finish_in_trie();
        } else {
            const int c = s[s_idx] - margin;
            if (nodes[node_idx].nxt[c] == -1) {
                nodes[node_idx].nxt[c] = nodes.size();
                nodes.push_back(T(char_size));
            }
            add(s, s_idx + 1, nodes[node_idx].nxt[c]);
            // 根据当前节点的子节点更新当前节点
            nodes[node_idx].update_when_push_in_trie(nodes[nodes[node_idx].nxt[c]]);
        }
    }

    void add(const string &s) {
        add(s, 0, root);
    }
};
