//SHORT OPTIMIsed SOLUTION WITH STL "list" and "splice"
//https://leetcode.com/problems/lru-cache/solutions/792449/simple-c-solution-with-detailed-explanation/



class LRUCache {
public:

        //key, val
        list<pair<int,int>> l;

        //key, ptr to queue node
        unordered_map<int,list<pair<int, int>>::iterator> m;

        //current size
        int size;   

        LRUCache(int capacity)
        {
            size=capacity;
        }

        int get(int key)
        {
            //if not found
            if(m.find(key)==m.end())
                return -1;

            //else found
            //move node from quque to front

            l.splice(l.begin(),l,m[key]);   //dest location, resultant list, src location

            //and return value
            return m[key]->second;
        }

        void put(int key, int value)
        {
            //if found
            if(m.find(key)!=m.end())
            {
                //move queue node to front of queue
                l.splice(l.begin(),l,m[key]);

                //update value of already existing key
                m[key]->second=value;

                return;
            }

            //else if not found

            //but queue is full, remove last node
            if(l.size()==size)
            {
                auto d_key=l.back().first;
                l.pop_back();
                m.erase(d_key);
            }

            //regradless, add new entry and update hashmap
            l.push_front({key,value});
            m[key]=l.begin();
        }

/*        



    //key, val
    list<pair<int, int>> q;
    int qsize;
    int cursize = 0;
    int pos = 0;        //front of lru

    //key, node pos in q
    unordered_map<int, list<pair<int, int>> :: iterator> mp;

    LRUCache(int capacity) {
        qsize = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) { //found

            //if keys are duplicate, we should only get the latest key inserted in front

            auto node = mp[key];  //itr position

            int val = node->second;
            pair<int, int> p1 = make_pair(node->first, node->second);
            //pair<int, int> p = q.at(posi);
            q.remove(p1);      //remove at fetched pos

            q.push_front(p1);
            mp[key] = q.begin();        //update position in map
            return val;

        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {

        if (mp.find(key) != mp.end()) { //if already present

            if (value != mp[key]->second) {
                //its a same key inserted with new value, juts add it in front

                if (q.size() == qsize) {
                    //evict last and then insert front
                    auto elem = q.back();

                    q.pop_back();  //remove at last elem
                    mp.erase(elem.first);   //key                 
                }

                //insert new one
                q.push_front({key, value});

                //update map
                mp[key] = q.begin();
            } else {
                //its referring the same key, value, jut move the existing
                //entry in from of queue

                auto node = mp[key];  //0 indexing

                
                pair<int, int> p1 = make_pair(node->first, node->second);
                //pair<int, int> p = q.at(posi);
                q.remove(p1);


                q.push_front(p1);
                mp[key] = q.begin();        //update position in map
            }

        } else {    //if not present

            if (q.size() == qsize) {
                //evict last and then insert front
                auto elem = q.back();

                q.pop_back();  //remove at last elem
                mp.erase(elem.first);   //key


                //insert at beg
                auto p1 = make_pair(key, value);
                q.push_front(p1);

                //update map
                mp[key] = q.begin();

            } else {
                //insert front
                
                q.push_front({key, value});

                //update map
                mp[key] = q.begin();

            }
        }
    }
*/

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
