class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==1)return A[0];
        int i,t=0,msum=-0x7fffffff;
        for(i=0;i<n;i++){
            t+=A[i];
            if(t>msum)msum=t;
            if(t<0)t=0;
        }
        return msum;
    }
};