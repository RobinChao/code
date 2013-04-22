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
			return get_start_loop_node(head, node2), True
			
def get_start_loop_node(head, loop_node):
	n = 1;
	node1 = loop_node
	while node1.next != loop_node:
		node1 = node1.next
		n += 1
	
	node2 = head
	for i in range(n):
		node2 = node2.next
	
	node1 = head;	
	while node1 != node2:
		node1 = node1.next
		node2 = node2.next
	return node1;
			
			
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
	print 'starting loop node = ', node
	
	now = head
	while now != node:
		print now, '-->',
		now = now.next
	print '[', now, ']', '-->',
	now = now.next
	while now != node:
		print now, '-->',
		now = now.next
	print '[', now, ']'
	
	x = Node(1)
	x.next = x
	node, cycle = cyclic(x)
	print 'cyclic(x) = ', cycle
	print 'node = ', node
	
	print 'cyclic(Node(1,Node(2,(Node(3))))) = ', cyclic(Node(1,Node(2,(Node(3)))))
		