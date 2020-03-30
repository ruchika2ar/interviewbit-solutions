/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining
*/

int Solution::trap(const vector<int> &A) {
    if (A.size() < 2) return 0;
    vector<int> v(A.size(), -1);
    stack<int> s;
    for(int i = A.size() - 1; i >= 0; i--){
        while (!s.empty() && A[s.top()] < A[i]){
            if (v[i] == -1 || A[v[i]] < A[s.top()]) v[i] = s.top();
            s.pop();
        }
        if (!s.empty()) v[i] = s.top();
        s.push(i);
    }
    int be = 0, en = v[0];
    int ans = 0;
    while (en < A.size() && en != -1){
        int ht = min(A[be], A[en]);
        int pos = ht * (en - be + 1);
        for (int i = be; i <= en; i++) pos -= min(A[i], ht);
        ans += pos;
        be = en; en = v[be];
    }
    return ans;
}
