/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        //important for a single elem in the array
        if (nums.size() <= 1) return nums[0];

        int cnt =0, i;
        for (i=1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                cnt++;

                if (cnt >= nums.size()/2) 
                    break;
            } else {
                cnt=1;
            }
        }
        return nums[i];
    }
};
