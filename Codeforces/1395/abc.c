#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long int lli;
int main() {
  int testcases;
  scanf("%d", &testcases);
  while(testcases--){
      lli k,d1,d2;
      scanf("%lld %lld %lld", &k, &d1, &d2);
      int sum=0;
      int cursum=d1+d2;
      int present[10];
      memset(present, 0, sizeof(present));
      while(1) {
        cursum+=cursum;
        cursum%=10;
        sum+=cursum;
        if(present[cursum])
          break;
        present[cursum]=1;
      }
      if((sum)%3==0)
        printf("YES\n");
      else
        printf("NO\n");
  }
  return 0;
}

