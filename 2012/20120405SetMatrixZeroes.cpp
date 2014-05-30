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
    void setZeroes(vector<vector<int> > &matrix) {
        int m,n;
        m=matrix.size();
        if(!m)return;
        n=matrix[0].size();
        int *a = new int[m+n];
        int i,j;
        memset(a,0,sizeof(int)*(m+n));
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(!matrix[i][j])a[i]=a[m+j]=1;
        for(i=0;i<m;i++)
            if(a[i])
                for(j=0;j<n;j++)matrix[i][j]=0;
        for(i=0;i<n;i++)
            if(a[m+i])
                for(j=0;j<m;j++)matrix[j][i]=0;
        return;
    }
};

int main()
{
    Solution sol;
    int a[5][5] = {{0,2,3,4,5},{0,4,5,6,7},
        {5,6,0,8,9},{2,3,4,5,6},{4,5,6,7,8}	};
	vector<vector<int> > vc;
	vector<int> v1(a[0],a[0]+5),v2(a[1],a[1]+5),v3(a[2],a[2]+5),
	v4(a[3],a[3]+5),v5(a[4],a[4]+5);
	vc.push_back(v1),vc.push_back(v2),vc.push_back(v3),
	vc.push_back(v4),vc.push_back(v5);
    cout<<"before "<<endl;
    FOR(i,vc.size()){
        FOR(j,vc[i].size())cout<<vc[i][j]<<" ";
        cout<<endl;
	}
    sol.setZeroes(vc);
    cout<<"after "<<endl;
	FOR(i,vc.size()){
        FOR(j,vc[i].size())cout<<vc[i][j]<<" ";
        cout<<endl;
	}
    return 0;
}
