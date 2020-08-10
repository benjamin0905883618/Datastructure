class Node:
    def __init__(self,p,n,d):
        self.data = d
        self.prev = p
        self.next = n
    def insertAfter(self,datum):
        temp = Node(self,self.next,datum)
        temp.next.prev = temp
        temp.prev.next = temp
    def insertBefore(self,datum):
        temp = Node(self.prev,self,datum)
        temp.next.prev = temp
        temp.prev.next = temp
    def remove(self):
        self.next.prev = self.prev
        self.prev.next = self.next
        del self
class queue:
    def __init__(self):
        self.head = Node(None,None,0)
        self.tail = Node(self.head,None,0)
        self.head.next = self.tail
    def push(self,d):
        self.tail.insertBefore(d)
    def top(self):
        return self.head.next.data
    def pop(self):
        self.head.next.remove()
    def empty(self):
        return self.head.next == self.tail
    def clear(self):
        while not self.empty():
            self.pop()
q = queue()
for i in range(0,10,2):
    #print(i)
    q.push(i)
for i in range(2):
    print(q.top())
    q.pop()
print(q.top())
q.clear()
print(q.top())
    
    
        
