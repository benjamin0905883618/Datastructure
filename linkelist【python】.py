class Node:
    def __init__(self,p,n,d):
        self.data = d
        self.prev = p
        self.next = n
    def insertAfter(self,datum):
        temp = Node(self,self.next,datum)
        temp.next.prev = temp
        temp.prev.next = temp
    def remove(self):
        self.next.prev = self.prev
        self.prev.next = self.next
        del self
head = Node(None,None,0)
tail = Node(head,None,-50)
head.next = tail
for i in range(5):
    head.insertAfter(i)
for i in range(5):
    print(head.next.data)
    head.next.remove()
print(head.next.data)
        
