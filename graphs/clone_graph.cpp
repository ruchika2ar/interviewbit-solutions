/* 
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    m[node] = root;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    while (!q.empty()){
        UndirectedGraphNode* cur = q.front();
        q.pop();
        vector<UndirectedGraphNode*> v = cur->neighbors;
        for (int i = 0; i < v.size(); i++){
            if (m.find(v[i]) == m.end()){
                UndirectedGraphNode* child = new UndirectedGraphNode(v[i]->label);
                m[v[i]] = child;
                q.push(v[i]);
            }
            m[cur]->neighbors.push_back(m[v[i]]);
        }
    }
    return root;
}

