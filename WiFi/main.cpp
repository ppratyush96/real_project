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
#define mod1e9+7

#define gcd(a,b) __gcd(a,b)

using namespace std;
double powmod(int a,int b)
{
    int y;
    double x;
    x = 1;
    y = a;
    while(b>0)
    {
        if(b%2)
            x = x*y;
        y = y*y;
        b=b/2;
    }
    return x;
}
double comb(int n,int r)
{
    if(r==0)
        return 1;
   double ans = n;
    for(int i=2;i<=r;i++)
     ans = (ans*(n-i+1))/i;
    return ans;

}
int main()
{
    string s1,s2;
    cin >> s1 ;
    cin >> s2;
    int a1=0,a2=0,q=0,x=0;
    double ans;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='+')
            a1++;
        else
            a1--;
    }
    for(int i=0;i<s2.length();i++)
    {
        if(s2[i]=='+')
            a2++;
        else if(s2[i]=='-')
            a2--;
        else
            q++;
    }
    //cout << a1 << " " << a2 << " " << q << endl;

    x = (q+a1-a2)/2;
  //  cout << x << endl;;
    if(x<0)
        ans = 0;
    else if((s1=="-")&&(s2=="?"))
            ans = 0.5;
    else if(x==0)
        ans = 1;
    else if(x>q)
        ans = 0;
    else
        ans=comb(q,min(x,q-x))/powmod(2,q);
   // cout << comb(q,min(x,q-x)) << endl;
  // cout << powmod(2,q) << endl;
    printf("%0.12f\n",ans);
}
