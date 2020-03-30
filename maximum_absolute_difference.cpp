/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x
*/


int Solution::maxArr(vector<int> &A) {
    if (A.size() <= 1) return 0;
    int ans = 0;
    int one = A[0], two = A[0] , three = A[0] * -1, four = three;
    for (int i = 0; i < A.size(); i++){
        int f = A[i] + i;
        int s = A[i] - i;
        int t = s * -1;
        int q = f * -1;
        one = max(one, f);
        two = max(two, s);
        three = max(three, t);
        four = max(four, q);
    }
    return max(one + four, two + three);
}
