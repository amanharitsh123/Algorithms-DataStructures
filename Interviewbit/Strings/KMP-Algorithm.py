class kmp:
    def __init__(self,text,pattern):
        self.pattern = pattern
        self.text = text
        self.lps = [0]*(len(pattern))
        self.computelps()
        # print("computed lps is ",self.lps)
        # self.match()
    
    def computelps(self):
        i = 0
        pat = self.pattern
        j = 1
        lps = self.lps
        while j<len(pat):
            if pat[i] == pat[j]:
                i += 1
                lps[j] = i
                j += 1
            else:
                if i != 0:
                    i = lps[i-1]
                else:
                    lps[i] = 0
                    j += 1
    
    def match(self):
        text = self.text
        pattern = self.pattern
        i = 0
        j = 0
        lps = self.lps
        while i<len(text):
            if text[i] == pattern[j]:
                i+=1
                j+=1
                if j == len(pattern):
                    # print("Found at ",i - len(pattern))
                    return i-len(pattern)
            else:
                if j!=0:
                    j = lps[j-1]
                else:
                    i += 1
                    j = 0
        return -1

class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def strStr(self, A, B):
        if not len(A) or not len(B): 
            return -1
        obj = kmp(A,B)
        return obj.match()
            
