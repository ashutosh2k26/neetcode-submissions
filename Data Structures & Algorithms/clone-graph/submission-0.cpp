/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        Node* cloned = new Node(node->val);
        //cout<<"cloned "<<cloned->val<<"\n";
        dfs(node,cloned);
        return cloned;
        
    }
    void dfs(Node* node, Node* cloned) {
        if(node == nullptr) {
            ///cout<<"returning\n";
            return;
        }

        visited.insert(node);
        nodeMap[node] = cloned;
        cout<<"node-val "<<node->val<<"\n";

        for(int i = 0 ; i < node->neighbors.size() ; i++) {
            ///cout<<"neighbors "<<node->neighbors[i]->val<<" \n";
            if(visited.find(node->neighbors[i]) == visited.end()){
                Node *pNew = new Node(node->neighbors[i]->val);
                ///cout<<"it's not in visited neigbor node val "<<node->neighbors[i]->val<<"\n";
                cloned->neighbors.push_back(pNew);
                dfs(node->neighbors[i],pNew);

            } else { /// node is already there
                auto itr = nodeMap.find(node->neighbors[i]);
                ///cout<<"it should be here\n";
                if (itr != nodeMap.end()) {
                    ///cout<<"updating neighbor neigbor node val "<<node->neighbors[i]->val<<"\n";
                    cloned->neighbors.push_back(itr->second);
                }
            }
        }
    }

    set<Node*> visited;
    map<Node*,Node*> nodeMap;
};
