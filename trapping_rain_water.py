class Solution(object):
   def trap(self, height):
      # Initialize an empty stack and a variable to store water
      stack = []
      water = 0
      i = 0

      # Iterate through the elements of the height array
      while i < len(height):
         # If the stack is empty or the current height is less than or equal to the height at the top of the stack
         if len(stack) == 0 or height[stack[-1]] >= height[i]:
            # Push the current index onto the stack and move to the next index
            stack.append(i)
            i += 1
         else:
            # If the current height is greater than the height at the top of the stack
            # Pop the index from the stack and calculate the trapped water
            x = stack[-1]
            stack.pop()
            if len(stack) != 0:
               # Calculate the amount of water that can be trapped between the current and previous indices
               temp = min(height[stack[-1]], height[i])
               dist = i - stack[-1] - 1
               water += dist * (temp - height[x])

      # Return the total amount of trapped water
      return water

# Create an instance of the Solution class and calculate trapped water for a given elevation map
ob = Solution()
ar = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(ob.trap(ar))
