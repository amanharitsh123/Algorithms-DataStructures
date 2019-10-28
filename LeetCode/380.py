from random import *
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr=[]
        self.dic={}
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.dic:
            self.arr.append(val)
            self.dic[val]=len(self.arr)-1
            return True
        return False
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.dic:
            return False
        if len(self.arr)==1:
            self.arr.pop()
            del self.dic[val]
            return True
        index=self.dic[val]
        last=len(self.arr)-1
        self.dic[self.arr[last]]=index
        self.arr[index],self.arr[last]=self.arr[last],self.arr[index]
        self.arr.pop()
        del self.dic[val]
        return True
        
        

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        num=randrange(0,len(self.arr),1)
        return self.arr[num]
        
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()