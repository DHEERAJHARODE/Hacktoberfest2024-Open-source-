class Solution:
    def fib(self, n: int) -> int:
        a=0
        b=1
        c=0
        if n<=0 or n==1:
            return a
        else:
            Sequence=[]
            while c<n:
                Sequence.append(a)
                x=a+b
                a=b
                b=x
                c+=1
            return Sequence
