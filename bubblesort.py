class stack:
    def __init__(self):
        self.arr=[]

    def insert(self,value):
        self.arr.append(value)
    def delete(self):
        self.arr.pop()
    def bsubbleSort(self,arr):
        n=len(arr) 
        for i in range(n): 
            for j in range(0, n-i-1): 
                if arr[j] > arr[j+1] : 
                    arr[j], arr[j+1] = arr[j+1], arr[j] 
  
# Driver code to test above 
if __name__=='__main__':
    arr = [10,2,30,4,5,110,11,24,45,76,90,6,8] 
    n=len(arr)
    stack=stack()  
    for i in range(len(arr)): 
        stack.insert(arr[i]) 
    stack.bubbleSort(stack.arr,0,n-1);
    print ("Sorted array is:",stack.arr)
