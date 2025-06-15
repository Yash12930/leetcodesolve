class Solution {
public:
    void backtrack(int col, vector<string>& board, vector<vector<string>>& result, int n, unordered_set<int>& rows, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            int diagonal1 = row + col;
            int diagonal2 = row - col;

            if (rows.find(row) == rows.end() && 
                diag1.find(diagonal1) == diag1.end() && 
                diag2.find(diagonal2) == diag2.end()) {

                board[row][col] = 'Q';
                rows.insert(row);
                diag1.insert(diagonal1);
                diag2.insert(diagonal2);
                
                backtrack(col + 1, board, result, n, rows, diag1, diag2);
                
                board[row][col] = '.';
                rows.erase(row);
                diag1.erase(diagonal1);
                diag2.erase(diagonal2);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> rows, diag1, diag2;
        backtrack(0, board, result, n, rows, diag1, diag2);
        return result;
    }
};
