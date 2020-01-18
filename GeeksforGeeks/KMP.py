# KMP algorithm: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
'''
Main Idea:
1) Avoid matching characters that have matched.
2) Use of lps(longest proper prefix which is also a prefix) to find number of characters to be ignored.
3) Reduces worst case time complexity to O(N).

'''
class kmp:
    def __init__(self,string,pattern):
        self.string=string
        self.pat=pattern
        self.lps=self.ComputeLPS()
    
    def ComputeLPS(self):
        pat=self.pat
        lps=[0]*len(pat)
        i=1
        le=0
        while i<len(pat):
            if pat[le]==pat[i]:
                le+=1
                lps[i]=le
                i+=1
            else:
                if le!=0:
                    le=lps[le-1]
                else:
                    lps[i]=0
                    i+=1
        return lps
    
    def FindOccurence(self):
        i=0
        j=0
        st=self.string
        pat=self.pat
        if not pat:
            return 0
        lps=self.lps
        while i<len(st):
            # print(i,j)
            if st[i]==pat[j]:
                i+=1
                j+=1
                if j==len(pat):
                    print("found at ",i-len(pat))
                    # return i-len(pat)
                    j=lps[j-1]
            else:
                if j!=0:
                    j=lps[j-1]
                else:
                    i+=1
        return -1

text="ABABDABACDABABCABAB"
pattern="ABABCABAB"

obj=kmp(text,pattern)
obj.FindOccurence()