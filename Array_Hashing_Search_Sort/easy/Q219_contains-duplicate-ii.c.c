class Solution {
public:

/*
    //O(n2) solution , timeout
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //can be done using nested loops
        

        for (int i=0; i< nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[i] == nums[j] && i!=j && abs(i-j) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
*/

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //add number with indexes in map

        //elem, index
        unordered_map<int, int> mp;
        bool found = false;


        for (int i=0; i<nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {    //found
                int index = mp[nums[i]];    //saved from prev encountered num
                int curIndex = i;

                if (curIndex != index && abs(curIndex-index) <= k) {
                    found = true;
                } else {
                    mp[nums[i]] = curIndex; //update with latest encountered index
                }

            }
            
        }

        return found;


    }

};
