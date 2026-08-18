#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> d(n+1);
        d[0] = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(!d[i-j*j]) {
                    d[i]=true;
                    break;
                }
            }
        }
        return d[n];
    }
};

int main()
{
    int n=1;
    Solution sol;
    bool ans = sol.winnerSquareGame(n);
    if(ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}