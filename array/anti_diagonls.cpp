/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> v(0);
    if (A.size() == 0 || A[0].size() == 0) return v;
    for (int col = 0; col < A[0].size(); col++) {
        vector<int> temp(0);
        for (int c = col, r = 0; c >= 0 && r < A.size(); c--, r++){
            temp.push_back(A[r][c]);
        }
        v.push_back(temp);
    }
    for (int row = 1; row < A.size(); row++){
        vector<int> temp(0);
        for (int c = A[0].size() - 1, r = row; c >= 0 && r < A.size(); c--, r++){
            temp.push_back(A[r][c]);
        }
        v.push_back(temp);
    }
    return v;
}
