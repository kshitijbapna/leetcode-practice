class Solution {
public:
    long long int pow1[20005];
    long long int power1(long long int x,long long int y,long long int p)
    {
        long long int res = 1;     // Initialize result

        x = x % p; // Update x if it is more than or
                    // equal to p
        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;

            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
 
    long long int hash(string s,int mod,int pow){
        long long int ans=0;
        for(int i=0;i<s.size();i++){
            ans=(ans+(pow1[i]*(s[i]-'a'+1))%mod)%mod;
        }
        return ans%mod;
    }
    string subStrHash(string s, int power2, int modulo2, int k2, int hashValue2) {
        long long int power=power2%modulo2,modulo=modulo2,k=k2,hashValue=hashValue2,n=s.size(); 
        for(int i=1;i<20005;i++){
             pow1[i]=power1(power,i,modulo)%modulo;
         }
        pow1[0]=1;
        long long int kkk=hash(s.substr(n-k,k),modulo,power);
        string anss;
        if(kkk==hashValue)anss=s.substr(n-k,k);
        for(int i=n-k-1;i>=0;i--){
            kkk-=(pow1[k-1]*(s[i+k]-'a'+1))%modulo;
            kkk*=power;
            kkk%=modulo;
            kkk+=(s[i]-'a'+1);
            kkk%=modulo;
            if(kkk<0)kkk=kkk+modulo;
            kkk%=modulo;
            // cout<<s[i];
            // cout<<kkk<<" "<<s.substr(i,k)<<"\n";
            if(kkk==hashValue)anss=s.substr(i,k);
        }
        return anss;
    }  
};