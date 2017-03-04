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
#define mp make_pair
#define pb push_back
#define gcd(a,b) __gcd(a,b)

using namespace std;

ll dp[(1<<10)+10],n,k;
char s[12],ch[12][7];
ll compute(ll mask,ll in)
{

    ll cnt,i,j;
    if(dp[mask]!=0)
        return dp[mask];
    if(in==(k-1))
    {
        for(i=0;i<n;i++)
        {
        cnt = 0;
        if(mask&(1<<i))
            continue;
        for(j=0;j<6;j++)
        {
            if(ch[i][j]==s[in])
                cnt=(cnt+1)%mod;
        }
        if(cnt>0)
        {
            dp[mask] = ((dp[mask]%mod)+(cnt%mod));
        }
       }
       return dp[mask]%mod;
    }
    for(i=0;i<n;i++)
    {
        cnt = 0;
        if(mask&(1<<i))
            continue;
        for(j=0;j<6;j++)
        {
            if(ch[i][j]==s[in])
                cnt=(cnt+1)%mod;
        }
        if(cnt>0)
        {
            dp[mask] = ((dp[mask]%mod)+(((cnt%mod)*(compute(mask|(1<<i),in+1)%mod))%mod)%mod)%mod;
        }
    }
    return dp[mask]%mod;
}
int main()
{
    ll i,j,ans=0;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
        for(j=0;j<6;j++)
           cin >> ch[i][j];
    cin >> s;
    ans = compute(0,0);
    cout << ans%mod << endl;
}


