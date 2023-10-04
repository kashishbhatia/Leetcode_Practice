class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j=0;

        double sum = 0;    //sum of window
        double maxAvg = INT_MIN;

        while (j < nums.size()) {
            //do calc
            sum += nums[j];

            if (j-i+1 < k) {
                j++;
            } else if (j-i+1 == k) {
                //find solution, business logic
                double avg = sum/k;
                maxAvg = max(maxAvg, avg);

                //shift window, remove i
                sum -= nums[i];
                i++;
                j++;
            }
        }

        return maxAvg;
    }
};
