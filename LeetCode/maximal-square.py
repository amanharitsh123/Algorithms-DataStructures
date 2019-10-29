class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        # DP solution
        ans=0
        # Corner Case
        if not matrix:
            return 0
        
        n,m=len(matrix),len(matrix[0])
        dp = [[0]*m for i in range(n)]

        # Base Case 
        for j in range(m):
            if matrix[0][j] == "1":
                dp[0][j] = 1
                ans = 1
                
        for i in range(1,n):
            
            if matrix[i][0] == "1":
                ans = max(ans, 1)
                dp[i][0] = 1
            
            for j in range(1,m):
                if matrix[i][j] == "1":
                    up = dp[i-1][j]
                    le = dp[i][j-1]
                    prev_square = dp[i-1][j-1]
                    dp[i][j] = 1 + min(up, le, prev_square)
                    ans = max(ans,dp[i][j]*dp[i][j])
        # print(dp)
        return ans