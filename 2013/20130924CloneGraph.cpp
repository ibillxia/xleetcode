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

// define for undirected graph
struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
		if(!node)return NULL;
		if(node->neighbors.empty()){
			UndirectedGraphNode *ans = new UndirectedGraphNode(node->label);
			ans->neighbors=vector<UndirectedGraphNode*>();
			return ans;
		}

		queue<UndirectedGraphNode*> q;
		map<const UndirectedGraphNode*,UndirectedGraphNode*> cloned;
		q.push(node);
		cloned[node]=new UndirectedGraphNode(node->label);
		while(q.size()){ // BFS
			const UndirectedGraphNode *nd = q.front();
			q.pop();
			for(auto it=nd->neighbors.begin();it!=nd->neighbors.end();it++){
				if(cloned.find(*it)!=cloned.end()){
					cloned[nd]->neighbors.push_back(cloned[*it]);
				}else{
					UndirectedGraphNode *newnd = new UndirectedGraphNode((*it)->label);
					cloned[*it]=newnd;
					cloned[nd]->neighbors.push_back(newnd);
					q.push(*it);
				}
			}
		}
		return cloned[node];
	}
};

int main()
{
	Solution sol;
	UndirectedGraphNode n0(0),n1(1),n2(2);
	n0.neighbors.push_back(&n1);
	n0.neighbors.push_back(&n2);
	n1.neighbors.push_back(&n2);
	n2.neighbors.push_back(&n2);
	UndirectedGraphNode *ans = sol.cloneGraph(&n0);
	return 0;
}

