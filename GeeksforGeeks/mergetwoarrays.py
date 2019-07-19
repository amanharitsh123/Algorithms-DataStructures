# Merge two arrays without using extra space
class Arr:
    def __init__(self,a1,a2):
        self.a1=a1
        self.a2=a2
        self.s1=len(a1)
        self.s2=len(a2)
    
    def val(self,ind):
        if ind>=self.s1:
            return self.a2[ind-self.s1]
        return self.a1[ind]
    
    def print(self):
        for x in self.a1:
            print(x,end=" ")
        for x in self.a2:
            print(x,end=" ")
        print()
    
    def swap(self,i,j):
        ai=self.a1
        aj=self.a1
        if i>=self.s1:
            ai=self.a2
            i=i-self.s1
        if j>=self.s1:
            aj=self.a2
            j=j-self.s1
            # print(i,j)
            # print(ai,aj)
        ai[i],aj[j]=aj[j],ai[i]
        # self.print()
    
    def se(self,i,val):
        ai=self.a1
        if i>=self.s1:
            ai=self.a2
            i=i-self.s1
        ai[i]=val



def part(arr,i,j):
    x=i-1
    y=i
    pivot=arr.val((i+j)//2)
    # print("pivot is ",pivot)
    while y<=j:
        if arr.val(y) <pivot:
            x+=1
            # print("swapping ",x,y)
            arr.swap(x,y)
        y+=1
    swap_ind=x+1
    while swap_ind <=j and arr.val(swap_ind)!=pivot:
    	swap_ind+=1
    arr.swap(x+1,swap_ind)
    # print("after part ",end="")
    # arr.print()
    return x+1

def quicksort(arr,i,j):
    # print(i,j)
    # arr.print()
    if i>j:
        return
    # arr.print()
    pos=part(arr,i,j)
    # print("pos is ",pos)
    # arr.print()
    quicksort(arr,i,pos-1)
    quicksort(arr,pos+1,j)

for _ in range(int(input())):
    n1,n2=list(map(int,input().split()))
    a1=list(map(int,input().split()))
    a2=list(map(int,input().split()))
    arr = Arr(a1,a2)
    quicksort(arr,0,n1+n2-1)
    arr.print()



# 2
# 4 5
# 1 3 5 7
# 0 2 6 8 9
# 2 3
# 10 12
# 5 18 20