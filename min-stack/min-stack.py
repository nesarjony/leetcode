class MinStack:

    def __init__(self):
        self.list = []

    def push(self, val: int) -> None:
        if len(self.list) == 0:
            self.list.append({
                "value": val,
                "min": val
            })
        else:
            last = self.list[len(self.list) - 1]
            self.list.append({
                "value": val,
                "min": min(val, last["min"])
            })
        

    def pop(self) -> None:
        self.list.pop()

    def top(self) -> int:
        return self.list[len(self.list) - 1]["value"]

    def getMin(self) -> int:
        return self.list[len(self.list) - 1]["min"]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()