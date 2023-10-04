class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        //elem, index
        set<pair<int, int>> odd_elems; 

        //find odd elems
        for (int i=0; i< nums.size(); i++) {
            if (i%2 ==0 && nums[i]%2 !=0) {
                odd_elems.insert({nums[i], i});
            }
        }

        //find misplaced even and swap them
        for (int i=0; i<nums.size(); i++) {
            if (i%2 !=0 && nums[i]%2 ==0) {

                auto temp = odd_elems.begin();
                
                
                int oddElem = temp->first;
                int idx= temp->second;
                //swap
                int t = nums[i];
                nums[i] = oddElem;
                nums[idx] = t;

                odd_elems.erase(odd_elems.begin());

            }
        }

        return nums;    
    }
};


//As this algo takes two traversal and also extra space. Can we do it in single traversal and no extra space

//Something where both l=0 till n-1 and r=n-1 till 0
//And l used for finding even misplaced and r for odd misplaced
//If l finds something it stops and let r find correspinding odd one

//int l=0;    //findng even elems 
//int r = nums.size()-1;  //responsible for finding odd elems & push them in map


/*
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        //i stands for even
        //j stands for odd
        while(i < n && j >= 0) {
            if   (nums[i]%2 == 0)    i += 2;
            else if(nums[j] %2 == 1) j -= 2;
            else                     swap(nums[i], nums[j]);
        }
        return nums;
    }


*/
