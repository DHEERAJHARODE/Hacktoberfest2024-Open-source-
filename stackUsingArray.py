class stackuarr:
    def __init__(self):
        self.stack = []
        self.top = -1


    # def createstack(self):
    # self.stack = []

    def push(self, itemp):
        if self.top == 15:
            print("stack overflow")
        else:
            self.top += 1
            # self.itemp = itemp
            self.stack.append(itemp)
            print("The item pushed is", itemp)

    def pop(self):
        self.top -= 1
        self.stack.pop()
        if self.top == -1:
            print("stack underflow")

    def peek(self):
        print(self.stack[self.top])

    def display(self):
        print("top =", self.top)
        for i in range(self.top, -1, -1):
            if i == -1:
                print(self.stack[i], "<-------Top")
            else:
                print(self.stack[i])
            print("|")


p = stackuarr()
p.push(14)
p.push(11)
p.pop()
p.push(8)
p.display()
p.pop()
p.pop()
