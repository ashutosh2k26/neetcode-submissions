
class TrieNode {
public:
    TrieNode() {
        endOfWord = false;
        for(int i = 0 ; i < 26 ; i++) {
            childs[i] = nullptr;
        }
    }
    bool endOfWord;
    TrieNode* childs[26];
    ///map<char,TrieNode*> childs;
    
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
        for(int i = 0; i < 26; i++) {
            root->childs[i] = nullptr;
        }
    }
    void insert(string word) {
        if(word.size() == 0) {
            return;
        }
        int index = 0;
        insertR(word,root,index);

    }

    bool search(string word) {
        if(word.size() == 0) {
            return false;
        }
        int index = 0;
        return searchR(word,root,index);
    }

    bool startsWith(string prefix) {
        int index = 0;
        return startsWithR(prefix,root,index);
    }

private:
bool searchR(string word,TrieNode* root,int index ) {
    
    TrieNode *pNode = root->childs[word[index] - 'a'];
    if(pNode == nullptr) {
        return false;
    }

    if(word.size() == index+1) {
        return pNode->endOfWord;
    }
    
    return searchR(word,pNode,index+1);
    
    /*
    auto itr = root->childs.find(word[index]);
    if(itr == root->childs.end()) {
        return false;
    }
    
    if( word.size() == index+1 && itr != root->childs.end()) {
        return itr->second->endOfWord;
    }
    
    return searchR(word,itr->second,index+1);
    */ 
}

void insertR(string word, TrieNode *root,int index) {
    
    TrieNode *pNode = root->childs[word[index] - 'a'];
    
    if(word.size() == index+1) {
        if(pNode == nullptr) {
            pNode = new TrieNode();
            pNode->endOfWord = true;
            root->childs[word[index] - 'a'] = pNode;
        } else {
            pNode->endOfWord = true;
        }
        return;
    }

    if(pNode == nullptr) {
        TrieNode *pNode = new TrieNode();
        root->childs[word[index] - 'a'] = pNode;
        insertR(word,pNode,index+1);
    } else {
        insertR(word,pNode,index+1);
    }
    
    /*
    auto itr = root->childs.find(word[index]);
        
    if(word.size() == index+1) {
        if(itr == root->childs.end()) {
            TrieNode *pNode = new TrieNode();
            pNode->endOfWord = true;
            root->childs[word[index]] = pNode;
        } else {
            TrieNode *pNode = itr->second;
            pNode->endOfWord = true;
        }
        return;
    }

    if(itr == root->childs.end()) {
        TrieNode *pNode = new TrieNode();
        root->childs[word[index]] = pNode;
        insertR(word,pNode,index+1);
    } else {
        insertR(word,itr->second,index+1);
    }
    */
}

bool startsWithR(string prefix,TrieNode *root,int index) {
    
    TrieNode *pNode = root->childs[prefix[index] - 'a'];
    if(pNode == nullptr) {
        return false;
    }

    if(prefix.size() == index+1) {
        return true;
    }
    
    return startsWithR(prefix,pNode,index+1);
    // auto itr = root->childs.find(prefix[index]);
    // if(itr == root->childs.end()) {
    //     return false;
    // }

    // if( prefix.size() == index+1 && itr != root->childs.end()) {
    //     return true;
    // }

    // return startsWithR(prefix,itr->second,index+1);
}

private:
    TrieNode *root;
};