class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //put num1 in hashmap with cnt and check num2 is in hashmap 
        //with same count  then add it in the result

        //elem, cnt
        unordered_map<int, int> s;
        vector<int> res;
        vector<int> temp, temp1;

        //put the bigger array in set
        //and use the smaller one to compare with the bigger one later.
        if (nums1.size() > nums2.size()) {
            temp = nums1;
            temp1 = nums2;
        } else if (nums1.size() < nums2.size()) {
            temp = nums2;
            temp1 = nums1;           
        } else { //==
            temp = nums1;
            temp1 = nums2;            
        }

        for (int i=0; i<temp.size(); i++) {
            s[temp[i]]++;
        }

        for (int i=0; i<temp1.size(); i++) {
            if (s.find(temp1[i]) != s.end()) {
                s[temp1[i]]--;
                if (s[temp1[i]] == 0) {
                    s.erase(temp1[i]);
                }
                res.push_back(temp1[i]);
            }
        }

        return res;
    }
};
