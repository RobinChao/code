class Node {
	int data;
	Node next;
	
	static Node cyclic(Node head) {
		Node curr1 = head;
		Node curr2 = head;
		if (head == null)	return null;
		while(true) {
			curr1 = curr1.next;
			curr2 = curr2.next;
			if(curr2 == null)	return null;
			curr2 = curr2.next;
			if(curr2 == null)	return null;
			if(curr1 == curr2)	return getStartingLoopNode(head, curr2);
		}
	}
	
	static Node getStartingLoopNode(Node head, Node loopNode){
		Node curr1 = loopNode;
		int n = 1;	// no of loop nodes
		while (curr1.next != loopNode) {
			curr1 = curr1.next;
			++n;
		}
		
		Node curr2 = head;
		for (int i = 0; i < n; ++i)
			curr2 = curr2.next;
			
		curr1 = head;
		while (curr1 != curr2) {
			curr1 = curr1.next;
			curr2 = curr2.next;
		}
		return curr1;
	}
}

class Cyclic {
	
	public static void main(String[] args) {
		Node head = new Node();
		Node curr = head;
		Node temp;
		
		curr.data = 1;
		curr.next = new Node();
		curr = curr.next;
		temp = curr;
		curr.data = 2;
		curr.next = new Node();
		curr = curr.next;
		curr.data = 3;
		curr.next = new Node();
		curr = curr.next;
		curr.data = 4;
		curr.next = new Node();
		curr = curr.next;
		curr.data = 5;
		curr.next = temp;
		
		
		Node startingLoopNode = Node.cyclic(head);
		
		curr = head;
		while(curr != startingLoopNode) {
			System.out.print(curr.data + "-->");
			curr = curr.next;
		}
		System.out.print("[" + curr.data + "]"+ "-->");
		curr = curr.next;
		while(curr != startingLoopNode) {
			System.out.print(curr.data + "-->");
			curr = curr.next;
		}
		System.out.print("[" + curr.data + "]");
	}
}