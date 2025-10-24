class Solution {
public:
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> count(10, 0);

        for (char c : s)
            count[c - '0']++;

        // Check numerical balance condition
        for (char c : s) {
            int d = c - '0';
            if (count[d] != d)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int num = n + 1;
        while (true) {
            if (isBalanced(num))
                return num;
            num++;
        }
    }
};