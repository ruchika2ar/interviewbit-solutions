/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character
*/

int Solution::minDistance(string org, string target) {
    int R = org.size(), C = target.size();
    vector<vector<int>> v(R + 1);
    for (int r = 0; r <= R; r++){
        vector<int> temp(C + 1, INT_MAX);
        v[r] = temp;
    }
    for (int r = 0; r <= R; r++) v[r][0] = r;
    for (int c = 0; c <= C; c++) v[0][c] = c;
    for (int r = 1; r <= R; r++){
        for (int c = 1; c <= C; c++){
            if (org[r - 1] == target[c - 1]) v[r][c] = min(v[r][c], v[r - 1][c - 1]);
            int pos = min(v[r - 1][c - 1], min(v[r - 1][c], v[r][c - 1])) + 1;
            v[r][c] = min(v[r][c], pos);
        }
    }
    return v[R][C];
}
