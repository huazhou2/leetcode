class Stack {
private:
    queue<int> q1,q2;
public:
    // Push element x onto stack.

    void push(int x) {
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();}
        q1.push(x);
    while (!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    }
    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
        
    }    
// Get the top element.
    int top() {
        return q1.front();
        
    }
    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
