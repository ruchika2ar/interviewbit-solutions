/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.
*/

bool check (const vector<string>& A, const string& B, int be, int r, int c){
    if (be >= B.size()) return true;
    if (r < 0 || c < 0 || r >= A.size() || c >= A[0].size()) return false;
    if (A[r][c] != B[be]) return false;
    const vector<int> dirX{1, -1, 0 ,0};
    const vector<int> dirY{0, 0, 1, -1};
    for (int i = 0; i < 4; i++){
        bool found = check(A, B, be + 1, r + dirX[i], c + dirY[i]);
        if (found) return true;
    }
    return false;
}
 
int Solution::exist(vector<string> &A, string B) {
    if (B.size() == 0) return true;
    if (A.size() == 0 || A[0].size() == 0) return false;
    for (int r = 0; r < A.size(); r++){
        for (int c = 0; c < A[0].size(); c++){
            bool found = check(A, B, 0, r, c);
            if (found) return true;
        }
    }
    return false;
}
