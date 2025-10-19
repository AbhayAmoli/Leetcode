class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string res = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            res = min(res, cur);

            string added = cur;
            for (int i = 1; i < added.size(); i += 2) {
                added[i] = (added[i] - '0' + a) % 10 + '0';
            }

            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);

            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return res;
    }
};