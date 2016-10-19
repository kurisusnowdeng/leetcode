class Solution {
public:
    void search(vector<vector<char>> &board, vector<vector<int>> &color, int x, int y, int cnt) {
        if (x < board.size() && y < board[x].size() && board[x][y] == 'X' && color[x][y] == 0) {
            color[x][y] = cnt;
        }
        else {
            return;
        }
        
        search(board, color, x + 1, y, cnt);
        search(board, color, x, y + 1, cnt);
    }

    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        vector<vector<int>> color(row);
        for (int i = 0; i < row; i++) {
            color[i].resize(board[i].size());
            for (int j = 0; j < color[i].size(); j++) {
                color[i][j] = 0;
            }
        }
        int cnt = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (color[i][j] > 0)
                    continue;
                if (board[i][j] == 'X') {
                    search(board, color, i, j, cnt);
                    cnt++;
                }
            }
        }
        
        return cnt - 1;
    }
};
