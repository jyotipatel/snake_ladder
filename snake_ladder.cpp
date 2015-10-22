#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define print(a) printf("%d",a)
#define printl(a) printf("%lld",a)
#define fin(i,j,n) for(int i=j;i<n;i++)
#define f0n(i,n) fin(i,0,n)
#define MAX 100000
#define mod 10
#define INF 1000000000
using namespace std;

typedef pair<int,int>pii;
typedef long long LL;

struct node
{
	int nod,cost;
	
};
bool cmp(const pii &left,const pii &right)
{
	return left.second<right.second;
}
bool operator<(const node a,const node b)
{
	return a.cost < b.cost;
}
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
		return gcd(b,a%b);
}

int dist[MAX],p[MAX];
vector<node>g[MAX];
void path(int n)
{
	if(n==1)
	{
		return;
	}
	cout<<" <- "<<p[n];
	return path(p[n]);
}
int dijkstra(int n)
{
	int source=1,dest=n;
	priority_queue<node>q;
	q.push((node){source,0});
	for(int i=0;i<=n;i++)
	{
		dist[i]=INF;
	}
	dist[source]=0;
	while(!q.empty())
	{
		node a=q.top();
		q.pop();
		int sz=g[a.nod].size();
		for(int i=0;i<sz;i++)
		{
			node k=g[a.nod][i];
			if(dist[k.nod]>dist[a.nod]+k.cost)
			{
				dist[k.nod]=dist[a.nod]+k.cost;
				p[k.nod]=a.nod;
				q.push(k);
			}
		}
	}
	
	cout<<"Distance to destination is:"<<dist[dest]<<endl;
	cout<<"Path is: "<<n;
	path(n);
}

int main()
{
	int n,a,b,k;
	cin>>n>>k;
	
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		g[a].push_back((node){b,0});
		
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0)
		{
			for(int j=1;j<=6;j++)
			{
				g[i].push_back((node){i+j,1});
			}
		}
	}
	dijkstra(n);
}

