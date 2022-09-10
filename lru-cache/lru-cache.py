class DLL:
    def __init__(self, key = 0, value = 0, backward = None, forward = None):
        self.key = key
        self.value = value
        self.backward = backward
        self.forward = forward
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = DLL(0, 0)
        self.tail = DLL(0, 0, self.head)
        self.head.forward = self.tail
        self.map = {}
        

    def get(self, key: int) -> int:
        if key in self.map:
            node = self.map[key]
            current_next = node.forward
            current_back = node.backward
            current_next.backward = node.backward
            current_back.forward = current_next
            self.attach_after_head(node.key, node.value)
            #self.printForward()
            return node.value
        else:
            return -1
    
    def attach_after_head(self, key, value):
        head_next = self.head.forward
        node = DLL(key, value, self.head, self.head.forward)
        self.head.forward = node
        head_next.backward = node
        self.map[key] = node

    def remove_from_end(self):
        tail_prev = self.tail.backward
        self.tail.backward = tail_prev.backward
        self.tail.backward.forward = self.tail
        del self.map[tail_prev.key]
    
    def delete_given_node(self, node):
        node_prev = node.backward
        node_next = node.forward
        node_prev.forward = node_next
        node_next.backward = node_prev
        del self.map[node.key]
    
    def printForward(self):
        root = self.head
        while root:
            print("key = {}, value={}".format(root.key, root.value))
            root = root.forward
    
    def printBackward(self):
        root = self.tail
        while root:
            print("key = {}, value={}".format(root.key, root.value))
            root = root.backward
        
        
    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.delete_given_node(self.map[key])
            #print("deleteing")
            #self.printForward()
            
        if len(self.map) == self.capacity:
            self.remove_from_end()
            self.attach_after_head(key, value)
            #self.printForward()
        else:
            self.attach_after_head(key, value)
            #self.printForward()
            #print("Added {},{}".format(key, value))



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)