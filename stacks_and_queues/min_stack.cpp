/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. push(x) – Push element x onto stack.
2. pop() – Removes the element on top of the stack.
3. top() – Get the top element.
4. getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.
*/

stack<int> s;
stack<int> least;
 
MinStack::MinStack() {
    while (!s.empty()) s.pop();
    while(!least.empty()) least.pop();
}
 
void MinStack::push(int x) {
    s.push(x);
    if (least.empty() || least.top() >= x) least.push(x);
    return;
}
 
void MinStack::pop() {
    if (s.empty()) return;
    if (!least.empty() && s.top() == least.top()) least.pop();
    s.pop();
    return;
}
 
int MinStack::top() {
    if (s.empty()) return -1;
    return s.top();
}
 
int MinStack::getMin() {
    if (least.empty()) return -1;
    return least.top();
}
 
