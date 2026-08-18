#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int h=0,t=label;
        while(t){
            h++;
            t=t/2;
        }
        vector<int> out(h);
        out[0]=1;
        out[h-1]=label;
        int l,r;
        for(int i=h-2;i>0;i--){
            l=1<<i;
            r=(1<<(i+1))-1;
            label=r-(label-r+1)/2+1;
            out[i] = label;
        }
        return out;
    }
};

int main()
{
    int label=14;
    Solution sol;
    vector<int> ans = sol.pathInZigZagTree(label);
    cout<<"[";
    for(int i=0;i<ans.size()-1;i++) {
        cout<<ans[i]<<",";
    }
    cout<<ans[ans.size()-1]<<"]"<<endl;
    return 0;
}