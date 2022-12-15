# Leetcode #232: https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue:

    def __init__(self):
        self.inStack, self.outStack = [], []

    def push(self, x: int) -> None:
        # Push the element onto the input stack
        self.inStack.append(x)

    def pop(self) -> int:
        # Shift elements and then pop from the output stack
        self.shiftStack()
        return self.outStack.pop()
        
    def peek(self) -> int:
        # Shift elements and return the element at the top of the output stack
        self.shiftStack()
        return self.outStack[-1]

    def empty(self) -> bool:
        # If both stacks are empty, then the queue is empty
        return (not self.inStack) and (not self.outStack)

    # Helper function to shift elements from input stack to output stack if output stack is empty
    def shiftStack(self) -> None:
        # If output stack is empty, pop all elements from input stack and push to output stack
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
