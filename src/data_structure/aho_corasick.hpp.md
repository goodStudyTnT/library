---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/aho_corasick.md
    document_title: "AC \u81EA\u52A8\u673A"
    links: []
  bundledCode: "#line 1 \"src/data_structure/aho_corasick.hpp\"\n#include <bits/stdc++.h>\r\
    \n\r\n#line 2 \"src/string/trie.hpp\"\n\r\nusing namespace std;\r\n\r\n/*\r\n\
    @brief Trie\r\n@docs docs/trie.md\r\n*/\r\n\r\nstruct TrieNode {\r\n    vector<int>\
    \ nxt;\r\n    TrieNode(int char_size) {\r\n        nxt.resize(char_size, -1);\r\
    \n    }\r\n    // \u4E00\u4E9B hook \u51FD\u6570\uFF0C\u7528\u4E8E Trie \u7B97\
    \u6CD5\u4EE5\u53CA ac \u81EA\u52A8\u673A, \u53EF\u4EE5\u8986\u76D6\u8FD9\u4E9B\
    \u51FD\u6570\u6765\u5B9E\u73B0\u4E00\u4E9B\u529F\u80FD\r\n\r\n    void update_when_finish_in_trie()\
    \ {\r\n        /*\r\n         * \u5F53\u52A0\u5165\u5230\u5B57\u5178\u6811\u540E\
    \uFF0C\u5BF9\u6700\u7EC8\u7684\u8282\u70B9(\u5F53\u524D\u8282\u70B9)\u8FDB\u884C\
    \u4E00\u4E9B\u64CD\u4F5C\r\n         */\r\n        return;\r\n    }\r\n\r\n  \
    \  void update_when_push_in_trie(TrieNode &child_node) {\r\n        /*\r\n   \
    \      * \u5F53\u52A0\u5165\u5230\u5B57\u5178\u6811\u65F6\uFF0C\u6839\u636E\u5F53\
    \u524D\u8282\u70B9\u548C\u5B50\u8282\u70B9\u7684\u4FE1\u606F\uFF0C\u5BF9\u5F53\
    \u524D\u8282\u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n         */\r\n    \
    \    return;\r\n    }\r\n\r\n    void update_when_build_fail(TrieNode &fail_node)\
    \ {\r\n        /*\r\n         * \u5F53\u6784\u5EFA fail \u51FD\u6570\u65F6\uFF0C\
    \u6839\u636E\u5F53\u524D\u8282\u70B9\u548C fail \u8282\u70B9\u7684\u4FE1\u606F\
    \uFF0C\u5BF9\u5F53\u524D\u8282\u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n \
    \        */\r\n        return;\r\n    }\r\n};\r\n\r\nstruct Trie {\r\n    vector<TrieNode>\
    \ nodes;\r\n    int root;\r\n\r\n    int char_size;\r\n    int margin;\r\n\r\n\
    \    Trie(int char_size, int margin) : root(0), char_size(char_size), margin(margin)\
    \ {\r\n        nodes.push_back(TrieNode(char_size));\r\n    }\r\n\r\n    void\
    \ add(const string &s, int s_idx, int node_idx) {\r\n        /*\r\n         *\
    \ \u5C06\u5B57\u7B26\u4E32 s \u7684 s_idx \u4F4D\u7F6E\u5F00\u59CB\u7684\u540E\
    \u7F00\u52A0\u5165\u5230\u5B57\u5178\u6811\u4E2D. node_idx \u4E3A\u5F53\u524D\u8282\
    \u70B9\u7684\u4E0B\u6807\r\n         */\r\n        if (s_idx == s.size()) {\r\n\
    \            // \u5B8C\u6210\u52A0\u5165\r\n            nodes[node_idx].update_when_finish_in_trie();\r\
    \n        } else {\r\n            const int c = s[s_idx] - margin;\r\n       \
    \     if (nodes[node_idx].nxt[c] == -1) {\r\n                nodes[node_idx].nxt[c]\
    \ = nodes.size();\r\n                nodes.push_back(TrieNode(char_size));\r\n\
    \            }\r\n            add(s, s_idx + 1, nodes[node_idx].nxt[c]);\r\n \
    \           // \u6839\u636E\u5F53\u524D\u8282\u70B9\u7684\u5B50\u8282\u70B9\u66F4\
    \u65B0\u5F53\u524D\u8282\u70B9\r\n            nodes[node_idx].update_when_push_in_trie(nodes[nodes[node_idx].nxt[c]]);\r\
    \n        }\r\n    }\r\n\r\n    void add(const string &s) {\r\n        add(s,\
    \ 0, root);\r\n    }\r\n};\r\n#line 4 \"src/data_structure/aho_corasick.hpp\"\n\
    using namespace std;\r\n\r\n/*\r\n@brief AC \u81EA\u52A8\u673A\r\n@docs docs/aho_corasick.md\r\
    \n*/\r\n\r\nstruct AhoCorasick : Trie {\r\n    vector<int> fail;\r\n\r\n    void\
    \ build() {\r\n        /*\r\n         * build fail \u51FD\u6570\r\n         */\r\
    \n        queue<int> Q;\r\n        fail.resize(this->nodes.size());\r\n      \
    \  int root = this->root;\r\n        fail[root] = root;\r\n\r\n        for (int\
    \ i = 0; i < char_size; i++) {\r\n            if (this->nodes[root].nxt[i] ==\
    \ -1) {\r\n                this->nodes[root].nxt[i] = root;\r\n            } else\
    \ {\r\n                fail[this->nodes[root].nxt[i]] = root;\r\n            \
    \    Q.push(this->nodes[root].nxt[i]);\r\n            }\r\n        }\r\n\r\n \
    \       while (!Q.empty()) {\r\n            int node = Q.front();\r\n        \
    \    Q.pop();\r\n\r\n            // \u6839\u636E fail \u8282\u70B9\u66F4\u65B0\
    \u5F53\u524D\u8282\u70B9\r\n            this->nodes[node].update_when_build_fail(nodes[fail[node]]);\r\
    \n\r\n            for (int i = 0; i < char_size; i++) {\r\n                if\
    \ (this->nodes[node].nxt[i] == -1) {\r\n                    this->nodes[node].nxt[i]\
    \ = this->nodes[fail[node]].nxt[i];\r\n                } else {\r\n          \
    \          fail[this->nodes[node].nxt[i]] = this->nodes[fail[node]].nxt[i];\r\n\
    \                    Q.push(this->nodes[node].nxt[i]);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"./src/string/trie.hpp\"\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief AC \u81EA\u52A8\u673A\r\n@docs docs/aho_corasick.md\r\
    \n*/\r\n\r\nstruct AhoCorasick : Trie {\r\n    vector<int> fail;\r\n\r\n    void\
    \ build() {\r\n        /*\r\n         * build fail \u51FD\u6570\r\n         */\r\
    \n        queue<int> Q;\r\n        fail.resize(this->nodes.size());\r\n      \
    \  int root = this->root;\r\n        fail[root] = root;\r\n\r\n        for (int\
    \ i = 0; i < char_size; i++) {\r\n            if (this->nodes[root].nxt[i] ==\
    \ -1) {\r\n                this->nodes[root].nxt[i] = root;\r\n            } else\
    \ {\r\n                fail[this->nodes[root].nxt[i]] = root;\r\n            \
    \    Q.push(this->nodes[root].nxt[i]);\r\n            }\r\n        }\r\n\r\n \
    \       while (!Q.empty()) {\r\n            int node = Q.front();\r\n        \
    \    Q.pop();\r\n\r\n            // \u6839\u636E fail \u8282\u70B9\u66F4\u65B0\
    \u5F53\u524D\u8282\u70B9\r\n            this->nodes[node].update_when_build_fail(nodes[fail[node]]);\r\
    \n\r\n            for (int i = 0; i < char_size; i++) {\r\n                if\
    \ (this->nodes[node].nxt[i] == -1) {\r\n                    this->nodes[node].nxt[i]\
    \ = this->nodes[fail[node]].nxt[i];\r\n                } else {\r\n          \
    \          fail[this->nodes[node].nxt[i]] = this->nodes[fail[node]].nxt[i];\r\n\
    \                    Q.push(this->nodes[node].nxt[i]);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n};"
  dependsOn:
  - src/string/trie.hpp
  isVerificationFile: false
  path: src/data_structure/aho_corasick.hpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/aho_corasick.hpp
layout: document
redirect_from:
- /library/src/data_structure/aho_corasick.hpp
- /library/src/data_structure/aho_corasick.hpp.html
title: "AC \u81EA\u52A8\u673A"
---
# AC 自动机


## Summary

## 题目链接
https://codeforces.com/contest/1739/submission/174501979