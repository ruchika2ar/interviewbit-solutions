/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. 
In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. 
By flipping, we mean change character 0 to 1 and vice-versa.
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. 
If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:
Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
*/

class Comp{
    public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};
 
vector<int> Solution::flip(string A) {
    vector<int> v(0);
    int zero = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == '0') zero++;
    }
    if (zero == 0) return v;
    vector<int> left(A.size(), 0);
    vector<int> right(A.size(), 0);
    vector<int> flipped(A.size(), 0);
    int l = 0, r = 0, f = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == '0') f++;
        else l++;
        flipped[i] = f;
        left[i] = l - f;
    }
    for (int i = A.size() - 1; i >= 0; i--){
        if (A[i] == '1') r++;
        right[i] = r;
    }
    right.push_back(0);
    int ans = 0, aBe = -1, aEn = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
    pq.push(make_pair(0, -1));
    for (int i = 0; i < A.size(); i++){
        pair<int ,int> p = make_pair (left[i], i);
        if (!pq.empty()){
            int cur = pq.top().first + flipped[i] + right[i + 1];
            if (cur > ans){
                aBe = pq.top().second + 1;
                aEn = i;
                ans = cur;
            }
        }
        pq.push(p);
    }
    v.push_back(aBe + 1);
    v.push_back(aEn + 1);
    sort(v.begin(), v.end());
    return v;
}
