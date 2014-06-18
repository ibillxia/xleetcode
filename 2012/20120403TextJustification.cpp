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
	vector<string> fullJustify(vector<string> &words, int L) { // AC
		vector<string> ans;
		int i,j,m,sum;
		m=words.size();
		if(!m)return ans;
		string si;
		for(i=0;i<m;i++){
			sum=-1;
			j=i;
			while(j<m && sum+words[j].size()+1<=L){
				sum+=words[j].size()+1;
				j++;
			}
			if(j<m)ans.push_back(justify(words,L,m,i,j-1,sum));
			else ans.push_back(justify(words,L,m,i,j-1,sum));
			i=j-1;
		}
		return ans;
	}

	string justify(vector<string> &words,int L,int m,int i,int j,int sum){
		int n,r;
		string s;
		if(i>j)return s;
		if(sum==L||m==j+1)n=1,r=0;
		else{ // sum<L
			sum-=j-i;
			if(i==j)n=L-sum,r=0;
			else n=(L-sum)/(j-i),r=(L-sum)%(j-i); // j>i
		}
		for(int ii=i;ii<j;ii++){
			s+=words[ii];
			if(ii-i<r)s.append(n+1,' ');
			else s.append(n,' ');
		}
		s+=words[j];
		if(i==j)s.append(L-sum,' ');
		else if(m==j+1)s.append(L-sum,' ');
		return s;
	}

	vector<string> fullJustify2(vector<string> &words, int L) { // MLE
		vector<string> ans;
		int i,ii,j,k,m,n,r,sum,flag=0;
		m=words.size();
		string si;
		if(!m)return ans;
		for(i=0;i<m;i++){
			sum=-1;
			j=i;
			while(sum<L&&j<m){
				sum+=words[j].size()+1;
				j++;
			}
			j--;
			if(sum==L)n=1,r=0;
			else{ // sum>L || j=m-1
				if(sum>L)sum-=words[j].size()+1;
				k=j>i ? j-i-1 : 0; // number of separations
				sum-=k;
				if(k){
					n=(L-sum)/k;
					r=(L-sum)%k;
				}else{
					n=L-sum;
					r=0;
				}
			}
			for(k=i;k<j-1;k++){
				si+=words[k];
				for(ii=0;ii<n;ii++)si+=' ';
				if(k-i<r)si+=' ';
			}
			si+=words[k];
			if(j-i<2){
				for(ii=0;ii<n;ii++)si+=' ';
			}
			ans.push_back(si);
			si.clear();
			if(flag)break;
			if(j==m-1)flag=1;
			i=j-1;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n,l;
	vector<string> words;
	vector<string> ans;
	string s;
	while(cin>>n){
		FOR(i,n){
			cin>>s;
			words.push_back(s);
		}
		cin>>l;
		ans = sol.fullJustify(words,l);
		FOR(i,ans.size())cout<<ans[i]<<"|"<<endl;
		words.clear();
	}
	return 0;
}

