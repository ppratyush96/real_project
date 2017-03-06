//checking changes to push

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
#define maxVal 1r8
#define minVal -1e8
#define mod 1e9+7
#define mp make_pair
#define pb push_back
#define gcd(a,b) __gcd(a,b)

using namespace std;
string s;
int main()
{
    freopen("in.txt","r",stdin);
    int i,n,c,d,ans,x,x1,x2,y,y1,y2;
    ios::sync_with_stdio(false);
    cin >> n >> s;
    x=y=x1=y1=x2=y2=0;
    int l=s.length();
    d=ans=0;
    for(i=0;i<l;i++)
    {
        if(s[i]=='R')
            x2++;
        else if(s[i]=='L')
            x2--;
        else if(s[i]=='U')
            y2++;
        else
            y2--;
        d++;
        if((abs(x2-x)+abs(y2-y))<d)
        {
            ans++;
            x = x1;
            y = y1;
            d = 0;
        }
        x1 = x2;
        y1 = y2;
    }
    cout << ans+1 << endl;
}
