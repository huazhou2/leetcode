class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total=(C-A)*(D-B)+(G-E)*(H-F);
        int leftx=max(A,E);
        int lefty=max(B,F);
        int rightx=min(C,G);
        int righty=min(D,H);
        if (leftx<=C && lefty<=D && rightx>=A && righty>=B) 
            return (total-(rightx-leftx)*(righty-lefty));
        else return total;
        }
};
