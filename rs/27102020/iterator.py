class Fibonachi:
    def __init__(self):
        self.a1 = 1
        self.a2 = 1
        self.res = 0
        self.counter = 0
    def __iter__(self):
        return self

    def __next__(self):
        while self.counter < 2:
            self.counter += 1
            return 1    
        self.res = self.a1 + self.a2
        self.a1, self.a2 = self.a2, self.res
        return self.res
fib = Fibonachi()

for i in fib:
    print(i)
    if i > 20:
        break
