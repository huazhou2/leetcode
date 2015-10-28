class Queue {
public:
	    // Push element x to the back of queue.
    void push(int x) {
        while(!s.empty()) {
            s1.push(s.top());
            s.pop();}
        s.push(x);
        while(!s1.empty()) {
            s.push(s1.top());
            s1.pop();}
    }
    // Removes the element from in front of queue.


    void pop(void) { s.pop();
        
    }
    // Get the front element.

    int peek(void) { return s.top();
        
    }
    // Return whether the queue is empty.


    bool empty(void) { return s.empty();
        
    }
    private:
    stack<int> s,s1;
};
