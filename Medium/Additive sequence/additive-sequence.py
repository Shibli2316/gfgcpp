#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

# return 1 in case of True and 0 in case of False
class Solution:
    def isAdditiveSequence(self, n):
        def is_valid(num1, num2, string):
            while string:
                num3 = str(int(num1) + int(num2))
                if not string.startswith(num3):
                    return 0
                string = string[len(num3):]
                num1, num2 = num2, num3
            return 1
    
        if len(n) < 3:
            return 0
    
        for i in range(1, len(n)):
            for j in range(i + 1, len(n)):
                num1 = n[:i]
                num2 = n[i:j]
                if (len(num1) > 1 and num1[0] == '0') or (len(num2) > 1 and num2[0] == '0'):
                    continue
                if is_valid(num1, num2, n[j:]):
                    return 1
    
        return 0
        #code here

#{ 
 # Driver Code Starts.
        
if __name__ == "__main__":
    sol = Solution()
    t = int(input())
    for _ in range(t):
        s = input()
        print(sol.isAdditiveSequence(s))

# } Driver Code Ends