def Input_BS(n,m):
    print("Enter the stream : \n")
    for i in range(0,n):
        row = list(int(num) for num in input().strip().split())[:m]
        bit_stream.append(row)
        row=0
    print("The given bit stream is ")
    for i in range(0,n):
        print(bit_stream[i])
        print("\n")
def Add_parity(n,m):
    choice=input("Enter 1 for even or 2 for odd : ")
    for i in range(n):
        count=0
        for j in range(m):
            if bit_stream[i][j]== 1:
                count+=1;
        if count%2 == 0 and choice == '1':
            bit_stream[i].append(0)
        elif count%2 == 1 and choice == '1':
            bit_stream[i].append(1)
        elif count%2 == 0 and choice == '2':
            bit_stream[i].append(1)
        elif count%2 == 1 and choice == '2':
            bit_stream[i].append(0)
        else:
            print("Wrong choice")
        
    temp=[]
    for i in range(m+1):
        count=0
        for j in range(n):
            if bit_stream[j][i]== 1:
                count+=1;
        if count%2 == 0 and choice == '1':
            temp.append(0)
        elif count%2 == 1 and choice == '1':
            temp.append(1)
        elif count%2 == 0 and choice == '2':
            temp.append(1)
        elif count%2 == 1 and choice == '2':
            temp.append(0)
        else:
            print("Wrong choice")
    bit_stream.append(temp);
    print("The New Bit Stream is ::")
    for i in range(0,n+1):
        print(bit_stream[i])
        print("\n")    
def check_parity(n,m):
    choice=input("Enter 1 for even or 2 for odd : ")
    temp=[]
    for i in range(n-1):
        count=0
        for j in range(m-1):
            if bit_stream[i][j]== 1:
                count+=1;
        if count%2 == 0 and choice == '1':
            temp.append(0)
        elif count%2 == 1 and choice == '1':
            temp.append(1)
        elif count%2 == 0 and choice == '2':
            temp.append(1)
        elif count%2 == 1 and choice == '2':
            temp.append(0)
        else:
            print("Wrong choice")
        
    temp1=[]
    for i in range(m):
        count=0
        for j in range(n):
            if bit_stream[j][i]== 1:
                count+=1;
        if count%2 == 0 and choice == '1':
            temp1.append(0)
        elif count%2 == 1 and choice == '1':
            temp1.append(1)
        elif count%2 == 0 and choice == '2':
            temp1.append(1)
        elif count%2 == 1 and choice == '2':
            temp1.append(0)
        else:
            print("Wrong choice")
    temp.append(temp1)
    for i in range(n):
        if temp[i]!= bit_stream[i][-1]:
            print("The Bit stream you received has changed")
            exit()
        else:
            print("The bit stream is correct")
            
n = int(input("Enter the row size : "))
m = int(input("Enter the column size : "))
bit_stream= []
def main():
    in_choice= int(input("Enter 1. for Adding parity bit \n2. for Checking parity bit\n::"))
    Input_BS(n,m);
    if in_choice == 1:
        Add_parity(n,m);
    elif in_choice == 2:
        check_parity(n,m);


if __name__=='__main__':
    main();