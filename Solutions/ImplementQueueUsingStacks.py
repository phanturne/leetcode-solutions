// Leetcode #232: https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue:

    def __init__(self):
        self.oldStack, self.newStack = [], []

    def push(self, x: int) -> None:
        # Push element to top of new stack
        self.newStack.append(x)

    def pop(self) -> int:
        # If stack is empty, return -1
        self.transferStack()
        if self.empty():
            return -1
        
        # Else pop from the old stack and return the popped val
        return self.oldStack.pop()

    def peek(self) -> int:
        # If stack is empty, return -1
        self.transferStack()
        if self.empty():
            return -1
        # Else return the value on the top of the old stack
        return self.oldStack[-1]

    def empty(self) -> bool:
        return (not self.oldStack) and (not self.newStack)

    def transferStack(self):
        # If oldStack is empty, pop each element from the newStack and push to oldStack
        # This simulates a queue b/c the oldest elements will be on top of oldStack
        if not self.oldStack:
            while self.newStack:
                self.oldStack.append(self.newStack.pop())

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
