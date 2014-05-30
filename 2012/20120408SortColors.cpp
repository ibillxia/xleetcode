#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<2)return;
        int a,b,i;
        a=b=0;
        for(i=0;i<n;i++){
            if(!A[i])a++;
            else if(1==A[i])b++;
        }
        memset(A,0,sizeof(int)*n);
        for(i=a;i<a+b;i++)A[i]=1;
        for(;i<n;i++)A[i]=2;
        return;
    }
};

int main()
{
    Solution sol;
    int A[]={0,1,2,0,2,1,2,1,0,2,1};
    sol.sortColors(A,11);
    FOR(i,11)cout<<A[i]<<" ";
    return 0;
}
