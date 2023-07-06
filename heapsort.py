class heapsort:
    def __init__(self):
        self.answer = [0]
        self.output = []
    def length(self):
        return self.answer[0]
    def swap(self, a, b):
        return b, a
    def check(self):
        cursor = self.length()
        while cursor > 1 and self.answer[cursor] < self.answer[int(cursor/2)]:
            self.answer[int(cursor/2)], self.answer[cursor] = self.swap(self.answer[int(cursor/2)], self.answer[cursor])
            cursor = int(cursor / 2)
    
    def length(self):
        return self.answer[0]
    def push(self, val):
        self.answer.append(val)
        self.answer[0] += 1
        self.check()
    def pop(self):
        temp = self.answer[1]
        self.answer[1] = self.answer[self.length()]
        self.answer[0] -= 1
        cursor = 1
        while True:
            if 2 * cursor <= self.length() and (self.answer[2 * cursor] < self.answer[cursor] and self.answer[2 * cursor] <= self.answer[2 * cursor + 1]):
                self.answer[cursor], self.answer[2 * cursor] = self.swap(self.answer[cursor], self.answer[2 * cursor])
                cursor *= 2
            elif 2 * cursor + 1 <= self.length() and (self.answer[2 * cursor + 1] < self.answer[cursor] and self.answer[2 * cursor + 1] < self.answer[2 * cursor]):
                self.answer[cursor], self.answer[2 * cursor + 1] = self.swap(self.answer[cursor], self.answer[2 * cursor + 1])
                cursor = 2 * cursor + 1
            else:
                break
        return temp