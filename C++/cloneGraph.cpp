/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        UndirectedGraphNode *result = dfs(node, visited);
        return result;
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &visited) {
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        visited[node] = copy;
        
        for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it++) {
            if (visited.find(*it) == visited.end()) {
                copy->neighbors.push_back(dfs(*it, visited));
            }
            else {
                copy->neighbors.push_back(visited[*it]);
            }
        }
        return copy;
    }
};
