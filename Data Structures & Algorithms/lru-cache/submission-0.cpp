class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto itr = lmap.find(key);
        if(itr != lmap.end()) {
            int value = (*(itr->second))[1];
            lst.erase(itr->second);
            lst.push_back({key, value});
            lmap[key] = --lst.end();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lmap.find(key) != lmap.end()) {
            lst.erase(lmap[key]);
        } else if(lst.size() == size) {
            auto vec = lst.front();
            lmap.erase(vec[0]);
            lst.pop_front();
        }
        lst.push_back({key, value});
        lmap[key] = --lst.end();
    }
    /// key <address>
    unordered_map<int,std::list<vector<int>>::iterator> lmap;
    list<vector<int>> lst;  /// key value
    int size;
};
