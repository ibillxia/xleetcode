#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> mp;
        int it,lt,rt,tlen,mlen=0;
        for(unsigned int i=0;i<num.size();i++){
            if(mp.count(num[i]))continue;
            it=num[i],lt=it-1,rt=it+1;
            tlen=mp[it]=1;
            if(mp.count(lt))tlen+=mp[lt-mp[lt]+1];
            if(mp.count(rt))tlen+=mp[rt+mp[rt]-1];
            if(mp.count(lt))mp[lt-mp[lt]+1]=tlen;
            if(mp.count(rt))mp[rt+mp[rt]-1]=tlen;
            mp[it]=tlen;
            if(tlen>mlen)mlen=tlen;
        }
        return mlen;
    }
};

int main()
{
    Solution sol;
    vector<int> v(6);
    v[0]=4,v[1]=5,v[2]=5,v[3]=3,v[4]=5,v[5]=5;
    int ans = sol.longestConsecutive(v);
    cout<<ans<<endl;
    return 0;
}
