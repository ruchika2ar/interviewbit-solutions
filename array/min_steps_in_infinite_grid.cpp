/*
You are in an infinite 2D grid where you can move in any of the 8 directions :
You are given a sequence of points and the order in which you need to cover the points. 
Give the minimum number of steps in which you can achieve it. 
You start from the first point.
*/

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int ans = 0;
    for (int i = 0; i < X.size() - 1; i++){
        if (X[i + 1] == X[i]) ans += abs(Y[i + 1] - Y[i]);
        else if (Y[i + 1] == Y[i]) ans += abs(X[i + 1] - X[i]);
        else {
            int add = abs(X[i + 1] - X[i]);
            if (Y[i + 1] > Y[i]) add += abs(Y[i + 1] - (Y[i] + add));
            else add += abs(Y[i + 1] - (Y[i] - add));
            int sub = abs(Y[i + 1] - Y[i]);
            if (X[i + 1] > X[i]) sub += abs(X[i + 1] - (X[i] + sub));
            else sub += abs(X[i + 1] - (X[i] - sub));
            ans += min(add, sub);
        }
    }
    return ans;
}
