#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef unsigned long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#define COUNT 1000000

lli solve(lli n) {
  lli count=1;
  while(n>1) {
    ++count;
    if(n%2)
      n=3*n+1;
    else
      n=n/2;
  }
  return count;
}

int main() {

  lli i,j;
  lli *freq=new lli[COUNT];
  for(lli I=1;I<COUNT;I++) {
    freq[I]=solve(I);
  }
  while(cin >> i >> j)
  {
    lli ma=0;
    lli I=min(i,j);
    lli J=max(i,j);
    if(J>=COUNT)
        return 0;
    for(lli x=I;x<=J;x++)
      if(freq[x]>ma)
        ma=freq[x];
    cout << i << " " << j << " " << ma << "\n";
  }
  free(freq);
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