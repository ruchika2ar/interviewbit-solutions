/*
Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

vector<vector<bool>> v;
vector<vector<bool>> visited;
bool check (const string& A, const string& B, int beA, int beB){
    if (beA >= A.size() && beB >= B.size()) return true;
    if (beB >= B.size()) return false;
    if (beA >= A.size()){
        if (B[beB] == '*') return check(A, B, beA, beB + 1);
        else return false;
    }
    if (visited[beA][beB] == true) return v[beA][beB];
    visited[beA][beB] = true;
    if (B[beB] == '?'){
        v[beA][beB] = check (A, B, beA + 1, beB + 1);
        return v[beA][beB];
    } else if (B[beB] == '*'){
        v[beA][beB] = check (A, B, beA, beB + 1) || check(A, B, beA + 1, beB);
        return v[beA][beB];
    } else{
        if (A[beA] == B[beB]) v[beA][beB] = check (A, B, beA + 1, beB + 1);
        else v[beA][beB] = false;
        return v[beA][beB];
    }
    v[beA][beB] = false;
    return v[beA][beB];
}
 
int Solution::isMatch(const string A, const string B) {
    v.resize(0);
    vector<bool> temp(B.size(), false);
    for(int i = 0; i < A.size(); i++) v.push_back(temp);
    visited = v;
    return check(A, B, 0, 0);
}
