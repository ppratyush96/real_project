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
int a[100006];
int main()
{
    ios::sync_with_stdio(false);
    int i,c1,c0,t,n,l;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        c1 = 0;
        l=0;
        c0 = 0;
       cin >> s ;
       l = s.length();
       if(s.length()<20)
       {
           for(i=0;i<s.length();i++)
           {
               if(s[i]=='1')
                c1++;
               else
                c0++;
           }
           if(c1>c0)
            printf("WIN\n");
           else
            printf("LOSE\n");
       }
       else
       {
           for(i=20;i<s.length();i=i+2)
           {
               if((s[i]=='1')&&(s[i+1]=='1'))
                printf("WIN\n");
               else if((s[i]=='0')&&(s[i+1]=='0'))
                printf("LOSE\n");
                else
                    i--;
           }
       }
    }
}
