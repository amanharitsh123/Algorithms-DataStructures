#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
class pos{
    public:
    lli x,y,val;
};
bool cmp(pos p1,pos p2)
{
    return p1.val>p2.val;
}
int main() {
    lli t;
    cin>>t;
    while(t--) {
        lli n,m;
        cin>>n>>m;
        vector<pos> orders(n*m);
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        set<lli> s;
        unordered_map<int,int> floors;
        for(lli i=0;i<n;i++)
            for(lli j=0;j<n;j++)
            {
                lli temp;
                cin>>temp;
                pos p;
                p.x = i;
                p.y = j;
                p.val = temp;
                orders.push_back(p);
            }
        sort(orders.begin(),orders.end(),cmp);
        for(auto i:orders)
        {
            lli x = i.x, y = i.y, val = i.val;
            x = n-x+1;
            // mark clean
            ans[x][y] = 1;
            if(s.find(y)!=s.end())
            {
                ans[x][y]=0;
            } else
            {
                // Logic to check for safety of current block


            }
            s.insert(y);
            if(floors.find(y)!=floors.end())
            {
                if(floors[y]<x)
                    floors[y] = x;
            }
            else
            {
                floors[y] = x;
            }
            
            

        }
    }
}
