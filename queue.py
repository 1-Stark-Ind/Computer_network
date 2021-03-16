class Queue:
	
# Initializing a queue
# Use a dummy node, which is 
# easier for handling edge cases. 
    def __init__(self):
	    self.head = []
        

# String representation of the queue
    def __str__(self):
	    cur = self.head
	    out = ""
	    i=0
	    while i<len(self.head):
		    out += str(cur[i]) + ":-:"
		    i+=1
	    return out[:-3] 
	
    def isEmpty(self):
	    return self.head == []

    def enqueue(self, value):
	    self.head.append(value)
    def dequeue(self):
        if self.isEmpty():
            raise TypeError("Popping from an empty Queue")
        remove = self.head.pop(0)
        return remove

cont = True
# Driver Code
if __name__ == "__main__":
    Queue = Queue()
    while(cont==True):
        choice= input("Enter \n1. Enqueue\n2. Dequeue\n 3.Display  : ")
        if choice== '1' :
            element= ['10', '22', '3', '40', '55', '7','10', '76','87','56','34','23','9','66'];
            for i in element :
                Queue.enqueue(i)
        elif choice== '2':
            remove= Queue.dequeue()
        elif choice== '3' :
            print(f"queue: {Queue}");
            cont = False
        else:
            print("Wrong choice... Try again ")
