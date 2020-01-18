#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#define vvi vector< vector<lli> >

bool valid(lli i, lli j, lli n, lli m) {
  if(i>=0 and i<n and j>=0 and j<m)
  {
    return true;
  }
  return false;
}

lli solve(vvi &mat,lli i,lli j,lli n,lli m) {
  // Moving up,down,left and right.
  lli ans=0;
  lli a=i,b=i,c=j,d=j,vert=j,hori=i;
  while(valid(a,vert,n,m) and valid(b,vert,n,m) and valid(hori,c,n,m) and valid(hori,d,n,m))
  {
    if(mat[b][vert]==mat[a][vert] and mat[hori][c]==mat[hori][d])
    {
      --a;
      ++b;
      --c;
      ++d;
      ++ans;
    }
    else
    {
      break;
    }
  }
  return ans;

}

int main() {
	lli t;
	cin>>t;
	while(t--) {
    lli n,m;
    cin>>n>>m;
    vector< vector<lli> > mat(n,vector<lli> (m,0));
    for(lli i=0;i<n;i++)
      for(lli j=0;j<m;j++)
        cin>>mat[i][j];
    
    lli ans=0;

    for(lli i=0;i<n;i++)
      for(lli j=0;j<m;j++)
        ans+=solve(mat,i,j,n,m);
    cout<<ans<<endl;

	}
}

