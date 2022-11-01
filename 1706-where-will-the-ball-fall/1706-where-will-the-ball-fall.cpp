class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int c = i;
            int k;
            for (int j = 0; j < m; ++j) {
                k = c + grid[j][c];
                if (k < 0 || k >= n || grid[j][k] != grid[j][c]) {
                c = -1;
                    break;
                }
                c = k;
            }
            res.push_back(c);
        }
        return res;
    }
};