class Solution {
public:
    int numTrees(int n) {
        if(n<3)return n;
        int i,j,fn[1000];
        fn[0]=fn[1]=1,fn[2]=2;
        for(i=3;i<=n;i++){
            fn[i]=0;
            for(j=0;j<i;j++)fn[i]+=fn[j]*fn[i-j-1];
        }
        return fn[n];
    }
};
