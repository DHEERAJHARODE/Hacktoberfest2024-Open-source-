'''
Question :---
There are M number of boys, N number of girls and P number of pets given. A pet race is held for a fun-filled Sunday in a town. Each pet animal is accompanied by two persons for the race. 
The organisers are planning for the seating arrangements by making groups such that each group has three members, and among these members, there is at least one boy and at least one
girl, the third member being a boy, a girl or a pet. One bench is required for each such group.
The task here is to find the maximum number of benches required for this.
Example 1:
Input:
5 -> Value of M
4 -> Value of N
2 -> Value of P
Output:
3
'''




>>
m,n,p=int(input()),int(input()),int(input())
c=0

while (m>0):
    if (n>0):
        if (p>0):
            m-=1
            n-=1
            p-=1
            c+=1
            
        # Maximum Sets    
        elif (n>m and n>1):
            m-=1
            n-=2
            c+=1
            
        elif (n<m and m>1):
            m-=2
            n-=1
            c+=1
            
        else: break
    else: break
      
      
  '''   
  ~ @TSG405
  '''
