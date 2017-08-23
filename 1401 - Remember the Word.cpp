#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
/*************NOTES*********************\
***************************************/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
const ll inf = 1e9;
const ll mod = 20071027;
const double eps = 1e-8;
const ll MAX = 3e5 + 20;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

struct trie{
    int nxt[26], val;
}node[MAX];

string s;
int sz = 1;


void in( string inp ){
    int now = 0;
    for( int i = 0; i < inp.size(); i++ ){
        int next = inp[i] - 'a';
        if( node[now].nxt[next] ) now = node[now].nxt[next];
        else{
            node[now].nxt[next] = sz++;
            now = node[now].nxt[next];
            node[now].val = 0;
            memset( node[now].nxt, 0 , sizeof( node[now].nxt ) );
        }
    }
    node[now].val = 1;
}

ll dp[MAX];

ll hope( int len ){
    if( len == s.size() ) return 1;
    ll &ret = dp[len];
    if( ret != -1 ) return ret;

    ret = 0;
    int now = 0;

    for( int i = len; i < s.size(); i++ ){
        if( !node[now].nxt[s[i] - 'a'] ) break;
        now = node[now].nxt[s[i] - 'a'];
        if( node[now].val ) ret = ( ret + hope( i + 1 ) ) % mod;
    }
    return ret % mod;

}


int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int ks = 1;
    while( cin >> s ){
        memset( node[0].nxt, 0 , sizeof( node[0].nxt ) );
        sz = 1;
        node[0].val = 0;
        int n;
        cin >> n;
        for( int i = 0; i < n; i++ ){
            string inp;
            cin >> inp;
            in( inp );
        }
        memset( dp, -1, sizeof( dp ) ) ;
        cout << "Case " << ks++ << ": ";
        cout << hope( 0 ) << "\n";
    }


    return 0;

}

