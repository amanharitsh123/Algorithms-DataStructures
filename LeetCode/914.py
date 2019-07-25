class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        dic={}
        for x in deck:
            if x in dic:
                dic[x]+=1
            else:
                dic[x]=1
        target=dic[deck[0]]
        for x in dic:
            if dic[x] != target:
                return False
        return True