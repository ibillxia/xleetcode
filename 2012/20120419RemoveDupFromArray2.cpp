#include<iostream>
using namespace std;
class Solution{
public:
    int removeDuplicates(int A[],int n){
        if(n<3)return n;
        int i,j;
        for(j=1,i=2;i<n;i++){
            if(A[i]==A[j]&&A[i]==A[j-1])continue;
            A[++j]=A[i];
        }
        return j+1;
    }
};

int main()
{
    Solution sol;
    int A[]={1,1,2,2,2,3,3,3};
    int n=sol.removeDuplicates(A,8);
    cout<<n<<endl;
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<",";
    }
    cout<<A[n-1]<<endl;
    return 0;
}
