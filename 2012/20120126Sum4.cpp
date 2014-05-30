#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum2(vector<int> &num, int target) {  // TLE, although seems O(n^2)
        vector<vector<int> > ans;
        if(num.size()<4)return ans;
        sort(num.begin(),num.end());
        unsigned int i,j;
        int s;
        map<int, vector<pair<int,int> > > mp;
        vector<int> vct;
        for(i=0;i<num.size()-1;i++){
            for(j=i+1;j<num.size();j++){
                s=num.at(i)+num.at(j);
                if(!mp.count(s))vct.push_back(s);
                mp[s].push_back(make_pair(i,j));
            }
        }
        int a,b,c,d;
        vector<int>::iterator it;
        vector<pair<int,int> >::iterator it2,it3;
        map<int,bool> mib;
        for(it=vct.begin();it!=vct.end();it++){
            s=target-*it;
            if(mib.count(*it)||mib.count(s))continue;
            mib[*it]=true,mib[s]=true;
            if(!mp.count(s))continue;
            for(it2=mp[*it].begin();it2!=mp[*it].end();it2++){
                a=(*it2).first;
                b=(*it2).second;
                for(it3=mp[s].begin();it3!=mp[s].end();it3++){
                    c=(*it3).first;
                    d=(*it3).second;
                    if(c>a)swap(a,c);
                    if(b>d)swap(b,d);
                    if(b>c)swap(b,c);
                    if(a==b||b==c||c==d)continue;
                    vector<int> v(4);
                    v[0]=num[a],v[1]=num[b],v[2]=num[c],v[3]=num[d];
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
    // From:http://discuss.leetcode.com/questions/199/4sum?sort=newest
    vector<vector<int> > fourSum(vector<int> &num, int target) { // AC, 100ms. Although seems O(n^4)
        vector<vector<int> > ans;
        vector<int> item(4,0);
        if(num.size()<4) return ans;
        sort(num.begin(),num.end());
        int size=num.size();
        int limit1=target-num[size-1]-num[size-2]-num[size-3];
        int limit2=target-num[size-1]-num[size-2];
        int limit3=target-num[size-1];
        int sumi, sumj, sumk, suml;

        for(int i=0; i<num.size()-3; ++i) {
            sumi = num[i];
            if(sumi<limit1 || (i!=0 && num[i]==num[i-1])) continue;
            if(sumi+num[i+1]+num[i+2]+num[i+3]>target) break;
            for(int j=i+1; j<num.size()-2; ++j){
                sumj = sumi+num[j];
                if(sumj<limit2 || (j!=i+1 && num[j]==num[j-1])) continue;
                if(sumj+num[j+1]+num[j+2]>target) break;
                for(int k=j+1; k<num.size()-1; ++k){
                    sumk = sumj+num[k];
                    if(sumk<limit3 || (k!=j+1 && num[k]==num[k-1])) continue;
                    if(sumk+num[k+1]>target) break;
                    for(int l=k+1; l<num.size(); ++l){
                        suml = sumk+num[l];
                        if(suml<target || (l!=k+1 && num[l]==num[l-1])) continue;
                        if(suml>target) break;
                        item[0]=num[i],item[1]=num[j],item[2]=num[k],item[3]=num[l];
                        ans.push_back(item);
                        break;
                    }//end l
                }//end k
            }//end j
        }//end i
        return ans;
    }
};

int main()
{
    Solution sol;
    //int arr[]={91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    //vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
    vector<int> v(8);
    v[0]=1,v[1]=-2,v[2]=-5,v[3]=-4,v[4]=-3,v[5]=3,v[6]=3,v[7]=5;
    vector<vector<int> > ans = sol.fourSum(v,-11);
    cout<<ans.size()<<endl;
    return 0;
}
