// taken reference from https://www.youtube.com/watch?v=xDEuM5qa0zg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=79
class LRUCache {
    int capacity;
    int timestamp;
    int size;
    map<int, pair<int, int>> m;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->timestamp = 0;
        this->size = 0;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            m[key].second = timestamp;
            this->timestamp++;
            return m[key].first;
        }
        this->timestamp++;
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key].first = value;
            m[key].second = timestamp;
            this->timestamp++;
        }
        else{
            if(this->size<this->capacity){
                pair<int, int> p;
                p.first = value;
                p.second = timestamp;
                m[key] = p;
                this->size++;
                this->timestamp++;
            }
            else{
                int minkey;
                int minval = INT_MAX;
                map<int,pair<int, int>>::iterator it = m.begin();
                while (it != m.end()) { 
                    if(it->second.second<minval){
                        minval = it->second.second;
                        minkey = it->first;
                    }
                    it++;
                } 
                m.erase(minkey);
                pair<int, int> p;
                p.first = value;
                p.second = timestamp;
                m[key] = p;
                this->timestamp++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
