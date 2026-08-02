/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t = head;
        vector<Node*> vec;
        map<Node*,int>    mp;  /// Node with index
        map<Node*,vector<Node*>>  mt;   /// Node with random 
       
        while(t != NULL) {
            Node* a = new Node(t->val);
            vec.push_back(a);

            if(t->random != NULL) {
                mt[t->random].push_back(t); 
            } 
            t = t->next;
        }

        t = head;
        int index = 0;
        while(t != NULL) {
            
            auto itr = mt.find(t);
            if(itr != mt.end()) {
                for (auto itv : itr->second) {
                    mp[itv] = index;
                }
            }
            index++;
            t = t->next;
        }

        for(int i = 1 ; i < vec.size(); i++) {
            vec[i-1]->next = vec[i];
            vec[i-1]->random = NULL;
        }

        t = head;
        int i = 0;
        while(t != NULL) {
            auto itr = mp.find(t);
            if(itr != mp.end()) {
                vec[i]->random = vec[itr->second];
            }
            t = t->next;
            i++;
        }
        
        if(vec.empty())
            return NULL;
        Node *headN = vec[0];
        return headN;
         
        
        
    }
};
