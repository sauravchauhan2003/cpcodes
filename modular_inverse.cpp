int inverse(int x){
        return exponent(x,1e9+5)%((int)1e9+7);
    }
    int exponent(int x,int n){
        int z=1e9+7;
        long long ans=1;
        if(n==1){
            return x;
        }
        else{
            if(n%2==1){
                int y=exponent(x,n/2);
                return (((1LL*y*y)%z)*x)%z;
            }
            else{
                int y=exponent(x,n/2);
                return (1LL*y*y)%z;
            }
        }
    }
