#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cstring>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}


lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,p1=0,p2=0,h;
    cin>>n;
    h=n/2;
    lli mat[n][n];
    for(lli i=0;i<n;i++) {
      lli sum=0;
      string inp;
      cin>>inp;

      for(lli j=0;j<n/2;j++) {
        mat[i][j]=inp[j]-'0';
        sum+=mat[i][j];
      }
      
      mat[i][h-1]=sum;
      p1+=sum;
      sum=0;
      for(lli j=n/2;j<n;j++) {
        mat[i][j]=inp[j]-'0';
        sum+=mat[i][j];
      }

      mat[i][n/2]=sum;
      p2+=sum;
    }

    lli ans=abs(p1-p2);
    for(lli i=0;i<n;i++) {
      lli x=mat[i][h-1];
      lli y=mat[i][h];
      //cout<<x<<" "<<y<<endl;
      ans=min(ans,abs(p1-x+y-p2+y-x));
      //cout<<"***************"<<endl;
      //cout<<abs(p1-x+y-p2+y-x)<<endl;
    }

    cout<<ans<<endl;
	}
}

