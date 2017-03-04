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

#define ll int
#define maxN 200
#define maxVal 1e8
#define minVal -1e8
#define mod1e9+7

#define gcd(a,b) __gcd(a,b)

using namespace std;


ll a[105][105];
ll n;
ll compute(ll i,ll j,ll n1)
{
    if(n1==1)
    return a[i][j];
    else
    return a[i][j]+max(compute(i+1,j,n1-1),compute(i+1,j+1,n1-1));
}
int main()
{

    ios::sync_with_stdio(false);
    ll ans,t,i,j;
    cin >> t;
    while (t--){
       cin >> n;
       for(i=0;i<104;i++)
        for(j=0;j<104;j++)
           {a[i][j]=0;}
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
          {
              cin >> a[i][j] ;
          }
        }
    ans = compute(1,1,n);
    cout << ans << endl;
    }
}
