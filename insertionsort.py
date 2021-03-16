class stack:
    def __init__(self):
        self.arr=[]

    def insert(self,value):
        self.arr.append(value)
    def delete(self):
        self.arr.pop()
    def insertionSort(self,arr): 
  
    # Traverse through 1 to len(arr) 
        for i in range(1, len(arr)): 
  
            key = arr[i] 
  
        # Move elements of arr[0..i-1], that are 
        # greater than key, to one position ahead 
        # of their current position 
            j = i-1
            while j >=0 and key < arr[j] : 
                    arr[j+1] = arr[j] 
                    j -= 1
            arr[j+1] = key 
  
  
# Driver code to test above 
if __name__=='__main__':
    arr = [10,2,30,4,5,110,11,24,45,76,90,6,8] 
    n=len(arr)
    stack=stack()  
    for i in range(len(arr)): 
        stack.insert(arr[i]); 
    stack.insertionSort(stack.arr);
    print ("Sorted array is:",stack.arr)