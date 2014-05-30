class Solution {
public:
    int reverse(int x) {
        if(!x)return x;
        int sgn,ans;
        if(x<0)sgn=-1,x=-x;
        else sgn=1;
        ans=0;
        while(x>0){
            ans=ans*10+x%10;
            x/=10;
        }
        return ans*sgn;
    }
};
