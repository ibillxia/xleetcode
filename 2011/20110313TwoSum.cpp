#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> ret;
		map<int,int>mp;
		int i;
		for(i=0;i<numbers.size();++i){
			mp[numbers[i]]=i;
		}
		for(i=0;i<numbers.size();++i){
			if(target>=numbers[i]&&mp.count(target-numbers[i])&&mp[target-numbers[i]]!=i)break;
		}
		ret.push_back(i+1);
		ret.push_back(mp[target-numbers[i]]+1);
		return ret;
	}
};

int main()
{
	int in[] = {2,7,11,15};
	vector<int> nums(in,in+sizeof(in)/sizeof(int));
	int target = 9;
	vector<int> idxs;
	Solution slt;
	idxs = slt.twoSum(nums,target);
	cout<<idxs[0]<<idxs[1]<<endl;
}