class Node: 
	def __init__(self, data=None, next=None): 
		self.data = data 
		self.next = next    
	def __str__(self): 
		return str(self.data)
		
def cyclic(head):
	node1 = node2 = head
	if node1 is None:
		return False
	while True:
		node1 = node1.next		
		node2 = node2.next
		if node2 is None:
			return False
		node2 = node2.next
		if node2 is None:
			return False
		if node1 == node2:
			return node2, True
			
if __name__ == '__main__':
	head = Node(1)
	curr = head
	curr.next = Node(2)
	curr = curr.next
	tmp = curr
	curr.next = Node(3)
	curr = curr.next 
	curr.next = Node(4)
	curr = curr.next
	curr.next = Node(5)
	curr = curr.next
	curr.next = Node(6)
	curr = curr.next
	curr.next = Node(7)
	curr = curr.next
	curr.next = tmp
	
	now = head
	for i in range(30):
		print now, '-->',
		now = now.next
	print now
	
	node, cycle = cyclic(head)
	print 'cyclic(head) = ', cycle
	print 'node = ', node
	now = head
	while True:
		print now, '-->',
		if now == node:
			break
		now = now.next
	print '|='
	
	x = Node(1)
	x.next = x
	node, cycle = cyclic(x)
	print 'cyclic(x) = ', cycle
	print 'node = ', node
	
	print 'cyclic(Node(1,Node(2,(Node(3))))) = ', cyclic(Node(1,Node(2,(Node(3)))))
		