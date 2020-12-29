'''
Sort ALGOs implemented in python
'''

class Sorting:
    def __init__(self, data):
        self.data = data
        self.length = len(data)
        self.Quick(0, self.length-1)
        # print(self.data, end='\n')


    def Bubble(self):
        for i in range(self.length):
            for j in range(self.length-1):
                if self.data[j] < self.data[j+1]: 
                    self.data[j], self.data[j+1] = self.data[j+1], self.data[j]
        
    def Select(self):
        '''Bubble update version
        '''
        for i in range(self.length):
            minIndex = i
            for j in range(i, self.length-1):
                if self.data[i] > self.data[j]: minIndex = j # update minIndex
            if minIndex != i: 
                self.data[i], self.data[minIndex] = self.data[minIndex], self.data[i]  
    
    def Partition(self, begin, end):
        left, right = begin, end
        pivot = self.data[left]
        while left < right:
            while left < right and self.data[right] < pivot:
                right -= 1
            self.data[left], self.data[right] = self.data[right], self.data[left]
            while left < right and pivot < self.data[left]:
                left += 1
            self.data[left], self.data[right] = self.data[right], self.data[left]
        # while end when left = right, where pivot at
        return left

    def Quick(self, begin, end):
        
        if begin >= end: return

        mid = self.Partition(begin, end)
        self.Quick(begin, mid)
        self.Quick(mid+1, end)


if __name__ == "__main__":
    data = [1,4,3,6,2,5,7,8]
    Sim = Sorting(data)
    
