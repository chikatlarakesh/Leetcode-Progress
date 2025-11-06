#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[py] = px;
        return true;
    }
};

class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<bool> online(n + 1, true);

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            dsu.unite(u, v);
        }

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> component_heap;
        for (int station = 1; station <= n; ++station) {
            int root = dsu.find(station);
            component_heap[root].push(station);
        }

        vector<int> result;

        for (auto& query : queries) {
            int type = query[0], x = query[1];
            if (type == 2) {
                online[x] = false;
            } else {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    int root = dsu.find(x);
                    auto& heap = component_heap[root];

                    while (!heap.empty() && !online[heap.top()]) {
                        heap.pop();
                    }

                    result.push_back(heap.empty() ? -1 : heap.top());
                }
            }
        }

        return result;
    }
};