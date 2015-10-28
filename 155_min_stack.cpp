class MinStack {
public:
    void push(int x) {
        if (s1.empty()) {s1.push(x);min=x;s2.push(min);}
        else 
        {s1.push(x);
        if(x<min) min=x; 
            s2.push(min);
        }
        
    }

    void pop() {
        s1.pop();
        s2.pop();
        if (s1.empty()) min=INT_MAX;
        else min=s2.top();
    }

    int top() {return s1.top();
        
    }

    int getMin() {
        if (s1.empty()) return INT_MAX;
        return min;
        
    }
private:
    int min;
    stack<int> s1,s2;
};
