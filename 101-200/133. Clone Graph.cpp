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
class Solution {
public:
    queue<UndirectedGraphNode* > qu;
    map<UndirectedGraphNode*, UndirectedGraphNode*> hash;  
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        qu.push(node);
        UndirectedGraphNode * head = new UndirectedGraphNode(node->label);  
        hash[node] = head; 
        while(!qu.empty()){            
            auto tmp = qu.front();  
            qu.pop();  
            for(auto val: tmp->neighbors)  
            {  
                if(hash.find(val) == hash.end())  
                {  
                    hash[val] = new UndirectedGraphNode(val->label);  
                    qu.push(val);  
                }  
                hash[tmp]->neighbors.push_back(hash[val]);  
            }  
        }
        return head;
    }
};