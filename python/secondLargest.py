#User function Template for python3
class Solution:
    def getSecondLargest(self, arr):
        # Code Here
        largest = -1
        sLargest = -1
        for i in arr:
            if i > largest:
                sLargest = largest
                largest = i
            if i < largest and i > sLargest:
                sLargest = i
        return sLargest        


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSecondLargest(arr)
        print(ans)

# } Driver Code Ends