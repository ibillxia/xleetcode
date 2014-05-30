class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(!n)return 0;
        int i,j;
        for(i=j=0;i<n;i++){
            if(A[i]!=elem)A[j++]=A[i];
        }
        return j;
    }
};