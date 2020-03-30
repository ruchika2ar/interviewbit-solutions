/*
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
Chech whether A has redundant braces or not.
Return 1 if A has redundant braces, else return 0.
Note: A will be always a valid expression
*/

int Solution::braces(string A) {
    stack<char> s;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == ')'){
            if (s.top() == '(') return true;
            else {
                while (s.top() != '(') s.pop();
                s.pop();
            }
        } else {
            if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/') s.push(A[i]);
            if (A[i] == '(') s.push(A[i]);
        }
    }
    return false;
}
