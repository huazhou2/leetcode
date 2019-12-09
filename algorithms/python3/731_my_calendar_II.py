class MyCalendarTwo(object):

    def __init__(self):
        self.events=[]
        self.overlaps=[]



    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if not self.events:
            self.events.append([start,end])
            return True
        for s1,e1 in self.overlaps:
            if s1 < end and start < e1:
                return False
        for s1,e1 in self.events:
            if s1<end and start<e1:
                self.overlaps.append([max(s1,start),min(e1,end)])
        self.events.append([start,end])
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)

mycal=MyCalendarTwo()
mycal.book(10, 20)
mycal.book(50, 60)
mycal.book(10, 40)
mycal.book(5, 15)
mycal.book(5, 10)
mycal.book(25, 55)