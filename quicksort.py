class stack:
    def __init__(self):
        self.arr=[]

    def insert(self,value):
        self.arr.append(value)
    def delete(self):
        self.arr.pop()
    def partition(self,arr, low, high): 
        i = (low-1)         # index of smaller element 
        pivot = arr[high]     # pivot 
  
        for j in range(low, high): 
  
        # If current element is smaller than or 
        # equal to pivot 
            if arr[j] <= pivot: 
  
            # increment index of smaller element 
                i = i+1
                arr[i], arr[j] = arr[j], arr[i] 
  
        arr[i+1], arr[high] = arr[high], arr[i+1] 
        return (i+1) 
  
    def quickSort(self,arr, low, high): 
        if len(arr) == 1: 
            return arr 
        if low < high: 
  
        # pi is partitioning index, arr[p] is now 
        # at right place 
            pi = self.partition(arr, low, high) 
            self.quickSort(arr, low, pi-1) 
            self.quickSort(arr, pi+1, high) 
  
  
# Driver code to test above 
if __name__=='__main__':
    arr = [10,2,30,4,5,110,11,24,45,76,90,6,8] 
    n=len(arr)
    stack=stack()  
    for i in range(len(arr)): 
        stack.insert(arr[i]); 
    stack.quickSort(stack.arr,0,n-1);
    print ("Sorted array is:",stack.arr)