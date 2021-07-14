 double helper(double x, double n)
    {
        if(n==0)
            return 1;
        else if(n==1)
            return x;
       double y = helper(x, (int)(n/2));
        if(n%2==0)
            return y*y;

        return y*y*x;
    }
    public double myPow(double x, int n) {
        
        if(n < 0)
            return ((double)1 / helper(x, n));
        return helper(x,n);
    }







     double myPow(double x, int y) {
        double a=x;
        bool ne=y<0;
        long n=abs(y);
        double ans=1;
        while(n){
            if(n&1) ans*=a;
            a*=a;
            n>>=1;
        }
        return ne?1.0/ans:ans;
    }