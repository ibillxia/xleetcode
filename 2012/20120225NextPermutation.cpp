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
    void nextPermutation(vector<int> &num) {
		#define vit vector<int>::iterator
		vit itb,itn,itl,itn1,itm; // begin,next,last
		itb=num.begin();
		itn=itl=num.end();
		if(itb==itl || itb==--itn)return;
		while(1){
			itn1=itn; // the it last
			if(*--itn<*itn1){
				itm=itl; // mid
				while(*itn>=*--itm);
				iter_swap(itn,itm);
				reverse(itn1,itl);
				return;
			}
			if(itn==itb){ // pure descending, flip all
				reverse(itb,itl);
				return;
			}
		}
    }
};

int main()
{
    Solution sol;
	int a[] = {5,4,7,5,3,2};
	vector<int> v(a,a+6);
    sol.nextPermutation(v);
	FOR(i,v.size())cout<<v[i]<<" ";
	cout<<endl;
    return 0;
}
