class Solution {
public:


    int missingNumber(vector<int>& nums) {

        int n = nums.size()+1; //hence elements shoud be in range of [0,n]

        vector<int> elem(n, -1);
        int i;
        for (i=0; i< nums.size(); i++) {

            elem[nums[i]] = 1;
        }

        for (i=0; i<n; i++) {
            if (elem[i] == -1)
                break;
        }
        return i;
    }

};
