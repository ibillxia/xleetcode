#include<iostream>

class Solution
{
public:
    double findMedianSortedArrays(int A[],int m,int B[],int n)
    {
        if(!n)return m&0x1 ? A[m/2] : (A[m/2-1]+A[m/2])/2.0;
        if(!m)return n&0x1 ? B[n/2] : (B[n/2-1]+B[n/2])/2.0;
        if(A[0]>=B[n-1]) {
            if(m==n)return (A[0]+B[n-1])/2.0;
            if((m+n)& 0x1)return m>n ? A[(m-n)/2] : B[(m+n)/2];
            return m>n ? (A[(m-n)/2-1]+A[(m-n)/2])/2.0 : (B[(m+n)/2-1]+B[(m+n)/2])/2.0;
        }
        if(B[0]>=A[m-1]) {
            if(m==n)return (B[0]+A[m-1])/2.0;
            if((m+n)& 0x1)return m<n ? B[(n-m)/2] : A[(m+n)/2];
            return m<n ? (B[(n-m)/2-1]+B[(n-m)/2])/2.0 : (A[(m+n)/2-1]+A[(m+n)/2])/2.0;
        }
        if((m+n)& 0x1)return findKthSortedArrays(A,m,B,n,(m+n)/2+1);
        return (findKthSortedArrays(A,m,B,n,(m+n)/2)+findKthSortedArrays(A,m,B,n,(m+n)/2+1))/2.0;
    }
private:
    int findKthSortedArrays(int A[],int m,int B[],int n,int k)
    {
        int *pa=A,*pb=B,kk;
        while(k>16) {
            if(m>n) std::swap(pa,pb),std::swap(m,n);
            if(!m)return B[k-1];
            kk=std::min(m,k/2);
            if(*(pa+kk-1)<*(pb+k-kk-1)) {
                pa+=kk;
                m-=kk;
                k-=kk;
            } else {
                pb+=k-kk;
                n-=k-kk;
                k=kk;
            }
        }
        if(k==1)return std::min(*pa,*pb);
        int i=0,j=0;
        kk=k;
        while(i<m&&j<n) {
            if(*(pa+i)<*(pb+j)) {
                if(!--kk)return *(pa+i);
                i++;
            } else {
                if(!--kk)return *(pb+j);
                j++;
            }
        }
        if(i==m)return *(pb+k-i-1);
        return *(pa+k-j-1);
    }
};

int main()
{
    int A[]= {1,3,4};
    int B[]= {2};
    Solution sol;
    double mid = sol.findMedianSortedArrays(A,3,B,1);
    std::cout<<mid<<std::endl;
    return 0;
}
