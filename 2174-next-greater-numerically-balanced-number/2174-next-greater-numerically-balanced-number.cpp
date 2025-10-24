class Solution {
public:
    bool isBalanced(int x) {
        vector<int> count(10, 0);
        int y = x;
        while (y > 0) {
            int d = y % 10;
            if (d == 0) return false;
            count[d]++;
            y /= 10;
        }
        for (int d = 1; d <=9; ++d){
            if(count[d] > 0 && count[d] != d){
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n+1; i<= 1224444; ++i){
            if (isBalanced(i)) {
                return i;
            }
        }
        return -1;
    }
};