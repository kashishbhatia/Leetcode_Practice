//ref : https://leetcode.com/problems/design-hashmap/

//https://www.geeksforgeeks.org/designing-a-hashmap-without-built-in-libraries/

#include <iostream>
#include <vector>

#if 0

We will use array size upto 1e6. We will initialize all the values of the array by -1, as a value to denote no element currently at this position. Thus, we can use this array for all of the functions mentioned above.

Steps that were to follow the above approach:
=================================================

There can be at max 10^4 key-value pairs so we create an array of size 10^4+ 1 (0-based indexing).
We initialize all the array values with -1 because by default they are 0 in an empty array and our value for a particular key can also be 0. So if we don’t initialize with something else it will give us the wrong outputs.
After that, everything is a piece of cake. We put() the given value at the specified index key and similarly get() the value stored at the index key.
When removing, we just initialize the specified index key back to -1.

#endif


using namespace std;

class MyHashMap {
    vector<int> mapArray;
public:
    MyHashMap() {
        mapArray = vector<int>(1000001, -1);
    }
    void put(int key, int value) {
        mapArray[key] = value;
    }
    int get(int key) {
        return mapArray[key];
    }
    void remove(int key) {
        mapArray[key] = -1;
    }
};

int main() {
    MyHashMap hashMap;

    //key, value
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl; // Output : 1
    cout << hashMap.get(3) << endl; // OUtput: -1 (not found)
    hashMap.put(2, 1);
    cout << hashMap.get(2) << endl; // Output: 1 (updated value)
    hashMap.remove(2);
    cout << hashMap.get(2) << endl; // Output: -1 (removed)
    return 0;
}
