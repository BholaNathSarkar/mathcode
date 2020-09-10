#define mod 1000000007
bool isPrime(long long int n)
{
    if(n==1) return false;
    long long int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;

}

/*primality test technique which is used to generate prime numbers in a given range like from 1 to N , where N is not more than 10^7 , yes we would be studying Sieve of Eratosthenes.


The running time complexity of this algorithm is O(Nlog(logN)).
The Space Complexity of this algorithm is O(N) */

int is_prime[1000000];

void primality_test()
{
    int maxN=1000000;
    for(int i=1;i<=maxN;i++) is_prime[i]=1;
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=maxN;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }

}
//Prime Factorization in O(sqrt(N))

 vector<pair<int,int>> primeFact(int n)
{
    vector<pair<int,int>>vp;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;

            }
            vp.push_back({i,cnt});
           // cout<<i<<"^"<<cnt<<'\n';

        }
    }
    if(n>1)
            {
             vp.push_back({n,1});
            //cout<<n<<"^"<<1<<endl;
            }
    return vp;
}



/*how we can calculate A^N efficiently.
calculate this in O(logN) time complexity. */


int power(int base,int n)
{
    int res=1;
    while(n)
    {
        if(n%2)
        {
            res=(res*1LL*base)%mod;
            n--;
        }
        else
        {
            base=(base*1LL*base)%mod;
            n/=2;
        }
    }
    return res;

}

//Prime Factorization using Sieve in O(log(N))
int sieve[1000001];
void sieveFun()
{
    int maxN=1000000;
    for(int i=1;i<=maxN;i++) sieve[i]=-1;

    for(int i=2;i<=maxN;i++)
    {

        if(sieve[i]==-1)
        {
            for(int j=i;j<=maxN;j+=i)
            {
                if(sieve[j]==-1)
                {
                    sieve[j]=i;
                }
            }
        }
    }


}

//Binomial Coefficient using Modulo inverse
int C(int N,int R,int F[])
{

    if(R>N) return 0;
    int res=F[N];
    res=(res*1LL*power(F[R],mod-2))%mod;
    res=(res*1LL*power(F[N-R],mod-2))%mod;
    return res;
}





