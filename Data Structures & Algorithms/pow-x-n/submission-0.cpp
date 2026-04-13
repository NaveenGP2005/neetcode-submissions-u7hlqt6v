class Solution {
public:
    double myPow(double x, int n) {
        long long exponent=n;
        double res=1.0;
        if(n==0) return 1;
        if(x==0) return 0;
        if(x==1) return 1;
        if(exponent<0){
            exponent=-exponent;
            x=1/x;
        }
        while(exponent){
            if(exponent%2==1){
                res*=x;
            }
            x*=x;
            exponent/=2;
        }
        return res;
    }
};
