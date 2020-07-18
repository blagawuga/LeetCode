class Solution {
public:
    int numTrees(int n) {
        if (n==0)
            return 1;
        if (n==1)
            return 1;
        if (n==2)
            return 2;
        
        vector<int> C(n+1, 0);
        C[0] = 1;
        C[1] = 1;
        C[2] = 2;
        
        for (int i=3; i<=n; i++) {
            C[i] = 0;
            for (int j=0; j<i; j++) {
                C[i] += C[j]*C[i-1-j];
            }
        }
        
        return C[n];
    }
};