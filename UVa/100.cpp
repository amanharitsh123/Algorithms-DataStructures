#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef unsigned long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#define COUNT 10000

lli solve(lli n) {
  lli count=1;
  while(n!=1) {
    ++count;
    if(n%2)
      n=3*n+1;
    else
      n=n/2;
  }
  return count;
}

int main() {

  lli freq[COUNT],i,j;
  For(1,COUNT) {
    freq[I]=solve(I);
  }
  while(scanf("%d %d",&i,&j)!=EOF)
  {
    lli ma=0;
    for(lli x=i;x<=j;x++)
      ma=max(ma,freq[x]);
    printf("%d %d %d\n",i,j,ma);
  }
  return 0;
}

/*

   Sample Input
   1 10
   100 200
   201 210
   900 1000
   Sample Output
   1 10 20
   100 200 125
   201 210 89
   900 1000 174

*/
