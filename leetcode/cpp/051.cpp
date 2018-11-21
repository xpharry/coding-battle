/*
 * Backtracking
 *
 * Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 * Space: O(n)
 *
 * Go row by row, and in each position, we need to check if the column, the 45° diagonal
 * and the 135° diagonal had a queen before.
 *
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        solver(res, nQueens, 0, n);
        return res;
    }

private:
	void solver(vector<vector<string>>& res, vector<string>& nQueens, int row, int n) {
		if(row == n) {
			res.push_back(nQueens);
			return;
		}
		for(int col = 0; col < n; col++) {
			if(isValid(nQueens, row, col, n)) {
				nQueens[row][col] = 'Q';
				solver(res, nQueens, row+1, n);
				nQueens[row][col] = '.';
			}
		}
	}

	bool isValid(vector<string>& nQueens, int row, int col, int n) {
		// col
		for(int i = 0; i < row; i++) {
			if(nQueens[i][col] == 'Q') {
				return false;
			}
		}
		// 45 degree
		for(int i = row-1 , j = col-1; i >= 0 && j >= 0; i--, j--) {
			if(nQueens[i][j] == 'Q') {
				return false;
			}
		}
		// 135 degree
		for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
			if(nQueens[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
};