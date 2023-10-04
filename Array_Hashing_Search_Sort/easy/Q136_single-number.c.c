//find non-repeating element
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        int i;
        for (i=0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end())
                m[nums[i]]++;
            else
                m[nums[i]]=1;
        }

        for (i=0; i < nums.size(); i++)
            if (m[nums[i]] == 1)
                break;

        return nums[i];
        
    }
};
