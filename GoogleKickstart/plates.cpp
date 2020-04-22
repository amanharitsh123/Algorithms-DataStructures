#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define kick(t,a) cout<<"Case #"<<t<<": "<<a<<endl;

using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases,ttt=0;
  cin>>testcases;
  while(testcases--) {
    ++ttt;
    lli N,K,P;
    cin>>N>>K>>P;
    lli mat[N][K];
    for(lli i=0;i<N;i++)
      for(lli j=0;j<K;j++)
        cin>>mat[i][j];

    lli dp[N+1][P+1];
    dp[0][0]=0;
    for(lli p=0;p<=P;p++) {
      for(lli i=1;i<=N;i++) {
        lli sum=0;
        lli count=0;
        dp[i][count]=0;
        for(auto x:mat[i-1]) {
          ++count;
          if(count>p)
            break;
          sum+=x;
          if((p-count)<=(i-1)*K)
            dp[i][p]=sum+dp[i-1][p-count];

          if(p<=(i-1)*K)
            dp[i][p]=max(dp[i][p],dp[i-1][p]);
        }
      }
    }
    cout<<dp[1][3]<<endl;
    kick(ttt,dp[N][P]);
  }
}

