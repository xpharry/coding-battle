/*
 * DFS + DP
 *
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // the longest length of the increasing array starting from i, j
        
        // dfs
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] > 0) return dp[i][j];
        
        dp[i][j] = 1;
        int m = matrix.size(), n = matrix[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int k = 0; k < 4; k++) {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1+dfs(matrix, dp, x, y));
            }
        }
        return dp[i][j];
    }
};

// Conclusion:
//


/*
 * BFS + DP
 *
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j]) continue;
                // bfs
                queue<pair<int, int>> q;
                q.push({i, j});
                int level = 1;
                while(!q.empty()) {
                    level++;
                    int sz = q.size();
                    for(int k = 0; k < sz; k++) {
                        auto cur = q.front();
                        q.pop();
                        for(int l = 0; l < 4; l++) {
                            int x = cur.first + dirs[l][0];
                            int y = cur.second + dirs[l][1];
                            if(x >= 0 && x < m && y >= 0 && y < n
                               && matrix[x][y] > matrix[cur.first][cur.second]
                               && level > dp[x][y]) {
                                dp[x][y] = level;
                                res = max(res, level);
                                q.push({x, y});
                            }
                        }                        
                    }
                }
            }
        }
        
        return res;
    }
};

// Conclusion:
//

