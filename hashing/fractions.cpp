/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
*/

string toString (long long int n) {
    string s;
    if (n == 0) {
        s.push_back('0');
        return s;
    }
    while (n > 0) {
        char d = (n % 10) + '0';
        s.insert(s.begin(), d);
        n = n / 10;
    }
    return s;
}
 
string Solution::fractionToDecimal(int a, int b) {
    if (a == 0) {
        string s;
        s.push_back('0');
        return s;
    }
    map <long long int, long long int> m;
    bool isNeg = false;
    if (a > 0 && b < 0) isNeg = true;
    if (a < 0 && b > 0) isNeg = true;
    const long long int one = -1;
    long long int A = a < 0 ? (a * one) : a;
    long long int B = b < 0 ? (b * one) : b;
    long long int q = A / B;
    long long int rem = A % B;
    string ans = toString (q);
    if (rem == 0) return ans;
    ans.push_back('.');
    while (rem > 0) {
        if (m.find(rem) == m.end()){
           long long int x = (rem * 10) / B;
           ans.push_back(x + '0');
           m[rem] = ans.size() - 1;
           rem = (rem * 10) % B;
        }
        else {
            ans.insert(m[rem] + ans.begin(), '(');
            ans.push_back(')');
            break;
        }
    }
    if (isNeg) ans.insert(ans.begin(), '-');
    return ans;
}
