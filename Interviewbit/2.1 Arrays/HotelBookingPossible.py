class Solution:
    # @param arrive : list of integers
    # @param depart : list of integers
    # @param K : integer
    # @return a boolean
    def hotel(self, arrive, depart, K):
        i=0
        j=0
        ans=0
        temp=0
        arrive.sort()
        depart.sort()
        while i<len(arrive) and j<len(depart):
            if arrive[i]<depart[j] or i==0:
                i+=1
                temp+=1
            else:
                j+=1
                temp-=1
            ans=max(ans,temp)
        return ans<=K
                
