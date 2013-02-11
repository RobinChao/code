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
			if(curr1 == curr2)	return curr2;
		}
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
		
		curr = head;
		while(curr != Node.cyclic(head)) {
			System.out.print(curr.data + "-->");
			curr = curr.next;
		}
		System.out.println(curr.data);
	}
}