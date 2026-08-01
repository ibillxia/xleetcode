#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        int minimumPushes(string word) {
            int ans = 0;
            int cnt = word.size();
            int i=1;
            while(cnt>0){
                ans += (cnt>8? 8*i:cnt*i);
                cnt -= 8;
                i++;
            }
            return ans;
        }
    };

int main()
{
    string s;
    cin>>s;
    Solution sol;
    int ans = sol.minimumPushes(s);
    cout<<ans<<endl;
    return 0;
}