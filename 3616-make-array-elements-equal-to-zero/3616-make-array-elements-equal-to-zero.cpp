class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        auto simulate = [&](int start, int dir) {
            vector<int> arr = nums;
            int curr = start;

            while (curr >= 0 && curr < n) {
                if (arr[curr] == 0) {
                    curr += dir;
                } else {
                    arr[curr]--;
                    dir = -dir;
                    curr += dir;
                }
            }

            for (int val : arr)
                if (val != 0) return false;

            return true;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(i, 1)) count++;  
                if (simulate(i, -1)) count++; 
            }
        }

        return count;
    }
};