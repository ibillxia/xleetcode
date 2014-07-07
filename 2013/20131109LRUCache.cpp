#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<list>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class LRUCache {
public:
	LRUCache(int capcity) {
		this->cap=capcity;
	}

	int get(int key){
		if(mp.find(key)!=mp.end()){
			CacheNode cn(key,mp[key]->val);
			lt.erase(mp[key]);
			lt.insert(lt.begin(),cn);
			mp[key]=lt.begin();
			return cn.val;
		}
		return -1;
	}

	void set(int key, int value){
		if(mp.find(key)!=mp.end()){ // already exist
			mp[key]->val=value;
			get(key);
		}else{ // new bie
			CacheNode cn(key,value);
			if(lt.size() < this->cap){ // in capcity
				lt.insert(lt.begin(),cn);
				mp[key]=lt.begin();
			}else{ // out of capcity
				// delete back one
				mp.erase(lt.back().key);
				lt.pop_back();
				// insert to front
				lt.insert(lt.begin(),cn);
				mp[key]=lt.begin();
			}
		}
	}

private:
	struct CacheNode{
		int key,val;
		CacheNode(int x,int y): key(x),val(y) {}
	};
	int cap; // capcity
	list<CacheNode> lt;
	map<int,list<CacheNode>::iterator> mp;
};

int main()
{
	LRUCache ca(10);
	int i,k,v;
	cout<<"=======input choice======"<<endl;
	cout<<"0: quit"<<endl;
	cout<<"1: get(key)"<<endl;
	cout<<"2: set(key,val)"<<endl;
	while(1){
		cin>>i;
		switch(i){
			case 0:
				return 0;
			case 1:
				cin>>k;
				cout<<"val: "<<ca.get(k)<<endl;
				break;
			case 2:
				cin>>k>>v;
				ca.set(k,v);
				cout<<"set OK"<<endl;
				break;
		}
	}
	return 0;
}

