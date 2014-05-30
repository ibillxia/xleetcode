class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)return 0;
        int i,j;
        for(i=j=1;i<n;i++){
            if(A[i]!=A[i-1])A[j++]=A[i];
        }
        return j;
    }
};