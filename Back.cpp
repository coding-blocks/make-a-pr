/*
     Authors:Raghav Bansal
     IIIT Una
                  */
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define BOLT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fil(a,val) memset(a,val,sizeof(a))
#define sz(a) sizeof(a)
#define X first
#define Y second
#define db double
#define MAX 1000001
#define endl "\n"
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
const db PI=acos(-1);
//using namespace __gnu_pbds;
//template < typename T > using indexed_set = //tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
//template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;
//template < typename T > T getsum(int bit[],int r){T sum=0;while(r){sum+=bit[r]; r-=(r&(-r));}return sum; }
//template < typename T > void update(int bit[],int idx,int val){while(idx<=n){bit[idx]+=val; idx+=(idx&(-idx));}}
//template < typename T > T range(T l,T r){return getsum<int>(bit,r)-getsum<int>(bit,l-1);}
int dp[301][301];
int32_t main(){
	BOLT;
	int n;
	cin>>n;
	int idx=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		for(int j=1;j<=n;j++)
		{
			dp[j][i]=++idx;
		}
		else
		for(int j=n;j>=1;j--)
		{
			dp[j][i]=++idx;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}
}
