class Heap:
    def __init__(self, N):
        self.len = 0
        self._items = [None] * N
    
    def _get_parent_node(self, node):
        return int((node - 1) / 2)
    
    def _get_left_child_node(self, node):
        return int((node * 2) + 1)
    
    def _get_right_child_node(self, node):
        return int((node * 2) + 2)
    
    def _has_parent(self, node):
        return self._get_parent_node(node) >= 0
    
    def _has_left_child(self, node):
        return self._get_left_child_node(node) < self.len
    
    def _has_right_child(self, node):
        return self._get_right_child_node(node) < self.len
    
    def swap(self, a, b):
        temp = self._items[a]
        self._items[a] = self._items[b]
        self._items[b] = temp
    
    def add(self, num):
        self._items[self.len] = num
        self.len = self.len + 1
        node = self.len - 1
        while self._has_parent(node) and self._items[self._get_parent_node(node)] > self._items[node]:
            self.swap(node, self._get_parent_node(node))
            node = self._get_parent_node(node)
    
    def peek(self):
        if self.len == 0:
            raise Exception("Argument invalid")
        return self._items[0]
    
    def printf(self):
        print(*self._items, sep = ", ")
    
    def pop(self):
        if self.len == 0:
            raise Exception("Invalid argument")
        self._items[0] = self._items[self.len - 1]
        self.len = self.len - 1
        node = 0
        while self._has_left_child(node):
            smallest = self._get_left_child_node(node)
            if self._has_right_child(node) and self._items[smallest] > self._items[self._get_right_child_node(node)]:
                smallest = self._get_right_child_node(node)
            
            if self._items[node] < self._items[smallest]:
                break
                
            self.swap(node, smallest)
            node = smallest
                      
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self._k = k
        self._heap = Heap(10005)
        
        for num in nums:
            self._heap.add(num)
            if self._heap.len > 0 and self._heap.len > k:
                self._heap.pop()
        
        #self._heap.printf()

    def add(self, val: int) -> int:
        self._heap.add(val)
        
        while self._heap.len > self._k:
            self._heap.pop()

        return self._heap.peek()
            

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)