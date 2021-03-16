# node class
class Node:
    def __init__(self, value):
	    self.value = value
	    self.next = None

class Queue:
	
# Initializing a queue
# Use a dummy node, which is 
# easier for handling edge cases. 
    def __init__(self):
	    self.head = Node("head")
	    self.size = 0

# String representation of the queue
    def __str__(self):
	    cur = self.head.next
	    out = ""
	    while cur:
		    out += str(cur.value) + ":-:"
		    cur = cur.next
	    return out[:-3] 
	
# Check if the stack is empty
    def isEmpty(self):
	    return self.size == 0
	
# Get the top item of the stack
    def peek(self):
	
	# Sanitary check to see if we 
	# are peeking an empty stack. 
	    if self.isEmpty():
		    raise TypeError("Peeking from an empty queue")
	    return self.head.next.value

# Push a value into the stack. 
    def enqueue(self, value):
	    node = Node(value)
	    node.next = self.head.next
	    self.head.next = node
	    self.size += 1
# Remove a value from the stack and return.	
    def dequeue(self):
        if self.isEmpty():
            raise TypeError("Popping from an empty Queue")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -=1
        return remove.value

cont = True
# Driver Code
if __name__ == "__main__":
    Queue = Queue()
    while(cont==True):
        choice= input("Enter \n1. Enqueue\n2. Dequeue\n 3.Display  : ")
        if choice== '1' :
            element= ['10', '22', '3', '40', '55', '7','10', '76','87','56','34','23','9','66'];
			for i in element:
            	Queue.enqueue(element)
        elif choice== '2':
            remove= Queue.dequeue()
        elif choice== '3' :
            print(f"queue: {queue}");
            cont = False
        else:
            print("Wrong choice... Try again ")
