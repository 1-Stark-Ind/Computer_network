class Node: 
  
    # Function to initialise the node object 
    def __init__(self, data=None, next= None): 
        self.data = data  
        self.next = next 
  
  
# Linked List class contains a Node object 
class LinkedList: 
  
    # Function to initialize head 
    def __init__(self,head= None): 
        self.head = head

    def insert(self,value):
        new_node= Node(value)
        new_node.next= self.head
        self.head= new_node
    def size(self):
        curr= self.head
        count =0
        while curr:
            count +=1
            curr= curr.next
        return count
    def display(self): 
        temp = self.head 
        while (temp): 
            print (temp.data) 
            temp = temp.next
    def delete(self,value):
        curr= self.head
        prev=None  
        found = False
        while curr and found is False:
            if curr.data == value:
                found= True
            else:
                prev= curr
                curr= curr.next
        if curr is None:
            raise ValueError("Data is not in the list")
        if prev is None :
            self.head= curr.next
        else:
            prev.next= curr.next
  
# Code execution starts here 
if __name__=='__main__': 
  
    # Start with the empty list 
    llist = LinkedList() 
    cont=True
    while(cont==True):
        choice= input("Enter \n1. Insert\n2. Delete\n 3.Display  : ")
        if choice== '1' :
            element= ['10', '22', '3', '40', '55', '7','10', '76','87','56','34','23','9','66'];
            for i in element :
                llist.insert(i)
        elif choice== '2':
            x=  input("Enter the value you want to delete :")
            llist.delete(x)
        elif choice== '3' :
            llist.display();
            cont = False
        else:
            print("Wrong choice... Try again ")

