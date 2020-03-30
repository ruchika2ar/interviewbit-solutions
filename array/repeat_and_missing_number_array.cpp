/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    const long long int n = A.size();
    const long long int eSq = (n * (n + 1) * ((2 * n) + 1)) / 6;
    const long long int eSum = (n * (n + 1)) / 2;
    long long int sq = 0, sum = 0;
    for (int i = 0; i < A.size(); i++){
        long long int cur = A[i];
        sq += (cur * cur);
        sum += cur;
    }
    long long int sqDif = sq - eSq;
    //cout << sq << " " << eSq << " ";
    long long int AMinusB = sum - eSum;
    long long int APlusB = sqDif / AMinusB;
    long long int a = (APlusB + AMinusB) / 2;
    long long int b = (APlusB - AMinusB) / 2;
    //cout << sqDif << " " << AMinusB << " " << APlusB;
    vector<int> ans(2);
    ans[0] = a; ans[1] = b;
    return ans;
}
