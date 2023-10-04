class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();

        //elem, cnt
        map <int, int> s;

        for(int i=0; i<nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                ++s[nums[i]];

                if (s[nums[i]] >= 2) return true;
            } else {
                s[nums[i]] = 1;
            }
        }

        return false;

        
    }
};
