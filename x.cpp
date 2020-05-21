/*
 * first we just have to solve the problem on a grid 2 * n then the final answer is ans of 2*n  ^ (m-1) 
 * we have 2 rows so we use dp [i][j] , we are at the i'th element in first row and from the already drawn segments the j'th element in second row was the most right element which was an endpoint of an segment
 * dp [i][j] = dp [i-1][k] * ( j-k ) ^ 2 , k <= j , we avoid the k loop by memorizing the past sum and multiply it by 2 when we move j 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=666013;
const ld pai=acos(-1);
ll po , n ;
ll modularExponentiation(ll x , ll n , ll M){
        if ( n == 0 ) return 1;
        if ( n % 2 == 0 ) return modularExponentiation((x*x)%M,n/2,M);
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll dp [1009][1009] ;
int main () {
	ifstream fin ( "retea3.in" ) ;
	ofstream fout( "retea3.out") ; 
	fin >> po >> n , po -- ;
	dp [1][1] = dp [1][2] = 2 ;
	for ( int j = 3 ; j <= n ; j ++ ) {
		dp [1][j] = dp [1][j-1] * 2 ; 
		dp [1][j] %= mod ; 
	}
	for ( int i = 2 ; i <= n ; i ++ ) {
		ll sum = 0 ;
		for ( int j = 1 ; j <= n ; j ++ ) {
			sum *= 2 ;
			dp [i][j] += dp [i-1][j] + sum ;
			dp [i][j] %= mod ;
			sum += dp [i-1][j] ; 
			sum %= mod ; 
			dp [i][j] += dp [i-1][j] ;
			dp [i][j] %= mod ; 
		}
	}
	ll sum = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) sum += dp [n][i] , sum %= mod ;
	fout << modularExponentiation ( sum , po , mod ) << endl ;
}
