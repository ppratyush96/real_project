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

#define ll unsigned long long
#define maxNo 100000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL

#define gcd(a,b) __gcd(a,b)

using namespace std;

vector<int> g;
int prime[maxN+5];

void pre()
{
	int i,j;
	fill(prime,prime+maxN+2,1);
	prime[0]=prime[1]=0;
	for(i=2;i<=sqrt(maxN);i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=maxN;j+=i)
				prime[j]=0;
		}
	}
}

pair<int,int> compute(int k,int v)
{
	int i,p,q,x,s,e,c;
	if(k==2)
	{
		g.push_back(v+1);
		g.push_back(v);
		return make_pair(2,1);
	}
	if(k==3)
	{
		g.push_back(v+2);
		g.push_back(v+1);
		g.push_back(v);
		return make_pair(3,1);
	}
	if(k==5)
	{
		g.push_back(v+4);
		g.push_back(v+3);
		g.push_back(v+2);
		g.push_back(v+1);
		g.push_back(v);
		return make_pair(5,1);
	}
	p=q=0;
	if(prime[k])
	{
		s=g.size();
		pair<int,int> f;
		f=compute(k-1,v);
		p=p+f.first+1;
		q=f.second;
		e=g.size()-1;
		for(i=s;i<=e;i++)
			g[i]++;
		//shifting
		c=f.second;
		g.push_back(g[e]);
		c=c-2;
		while(c--)
		{
			g[e]=g[e-1];
			e=e-1;
		}
		g[e]=v;
	}
	else
	{
		x=k;
		for(i=2;i<=sqrt(x);i++)
		{
			while(x%i==0)
			{
				pair<int,int> f;
				f=compute(i,v);
				v=v+f.first;
				p=p+f.first;
				q=q+f.second;
				x=x/i;
			}
		}
		if(x>1)
		{
			pair<int,int> f;
			f=compute(x,v);
			p=p+f.first;
			v=v+f.first;
			q=q+f.second;
		}
	}
	return make_pair(p,q);
}

int main()
{
    #ifndef ONLINE_JUDGE
    	//freopen("in.txt","r",stdin);
    	//freopen("out.txt","w",stdout);
    #endif
    pre();
	int t,n,k,i,j,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		if(k==1)
		{
			printf("1\n");
			printf("1\n");
			continue;
		}
		g.clear();
		n=compute(k,1).first;
		printf("%d\n",n);
		for(i=0;i<n;i++)
			printf("%d ",g[i]);
		printf("\n");
	}
    return 0;
}
