class Solution {
public:
    int totalMoney(int n) {
      int weeks = n / 7;        
        int days = n % 7;       

        // Formula for total after k weeks: 28*k + 7*(k*(k-1))/2
        int total = weeks * 28 + 7 * (weeks * (weeks - 1)) / 2;

        for (int i = 1; i <= days; ++i)
            total += weeks + i;

        return total;
    }
};