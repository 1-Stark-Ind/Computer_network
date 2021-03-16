class stack:
    def __init__(self):
        self.arr=[]

    def insert(self,value):
        self.arr.append(value)
    def delete(self):
        self.arr.pop()
    def selectionsort(self,arr):
        for i in range(len(arr)): 
      
    # Find the minimum element in remaining  
    # unsorted array 
            min_idx = i 
            for j in range(i+1, len(arr)): 
                if arr[min_idx] > arr[j]: 
                    min_idx = j 
              
    # Swap the found minimum element with  
    # the first element         
            arr[i], arr[min_idx] = arr[min_idx], arr[i] 

if __name__=='__main__':
    arr = [10,2,30,4,5,110,11,24,45,76,90,6,8] 
    n=len(arr)
    stack=stack()  
    for i in range(len(arr)): 
        stack.insert(arr[i]); 
    stack.selectionsort(stack.arr);
    print ("Sorted array is:",stack.arr)