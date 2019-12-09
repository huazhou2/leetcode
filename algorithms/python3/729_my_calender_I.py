class MyCalendar(object):
    def __init__(self):
        self.curlist = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if not self.curlist:
            self.curlist.append([start, end])
            return True
        for s1, e1 in self.curlist:
            if s1 < end and start < e1:
                return False

        self.curlist.append([start, end])
        return True




# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)