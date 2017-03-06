//Merge conflicts in text_edits


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <math.h>

#define ll long long int
#define maxN 200
#define maxVal 1e8
#define minVal -1e8
#define mod 1000000007

#define gcd(a,b) __gcd(a,b)

using namespace std;
ll powmod(ll a,ll b,ll m)
{
    ll x=1,y=b;
    while(b)
    {
        if(b%2==1)
            x=((x%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        b=b/2;
    }
    return x%m;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll t,r,l,m,t1,ans=0,a,b,n,k,i,j;
    ios::sync_with_stdio(false);
    cin >> t;t1=0;
    while(t--)
    {
        t1++;ans=0;
        cin >> a >> b >> n >> k;
        //cout << powmod(2,8,10000) << " " << powmod(3,5,1000009) << endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                if((powmod(i,a,k)+powmod(j,b,k))%k==0)
                    ans=((ans%mod)+1)%mod;
            }
        }
        cout << "Case #" << t1 << ": " << ans%mod << endl;
    }
}



