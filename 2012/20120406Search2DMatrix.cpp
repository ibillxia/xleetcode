#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m,n;
        m=matrix.size();
        if(!m)return false;
        n=matrix[0].size();
        if(matrix[0][0]>target||matrix[m-1][n-1]<target) return false;
        int l,r,t,mid;
        l=0,r=m-1;
        while(l<=r){
			//cout<<l<<" "<<r<<endl;
            mid=(l+r)/2;
            if(matrix[mid][0]>target)r=mid-1;
			else if(target==matrix[mid][0])return true;
            else l=mid+1;
        }
		t=r,l=0,r=n-1;
		//cout<<t<<endl;
        while(l<=r){
			//cout<<l<<" "<<r<<endl;
            mid=(l+r)/2;
            if(matrix[t][mid]>target)r=mid-1;
			else if(target==matrix[t][mid])return true;
            else l=mid+1;
        }
        if(target==matrix[t][r])return true;
        return false;
    }
};

int main()
{
    Solution sol;
    int a[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{15,16,17,18,19}
    ,{22,23,24,25,26},{34,35,36,37,38} };
	vector<vector<int> > vc;
	vector<int> v1(a[0],a[0]+5),v2(a[1],a[1]+5),v3(a[2],a[2]+5);
	vector<int> v4(a[3],a[3]+5),v5(a[4],a[4]+5);
	vc.push_back(v1),vc.push_back(v2),vc.push_back(v3);
	vc.push_back(v4),vc.push_back(v5);
    bool ans = sol.searchMatrix(vc,30);
    cout<<ans<<endl;
    return 0;
}
