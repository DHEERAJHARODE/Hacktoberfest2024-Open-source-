#!/usr/bin/env python
# coding: utf-8

# In[35]:

#krishna6431




# In[1]:


#all required libraries that are needed
# priority queue
from queue import PriorityQueue
# deepcopy
import copy
# time module
import time
#math module
import math
#importing random module
import random


# In[2]:


#Search with uniform cost i.e. h(n)=0
def zeroCost(currState):
    heuristicVal = 0
    return heuristicVal


# In[3]:


#Search with displaced tile count i.e. h(n)= no of displaced tiles 
def numDisplacedTiles(currState):
    heuristicVal = 0
    for i in range(0,N):
        for j in range(0,N):
            if currState[i][j]!=final[i][j]:
                heuristicVal=heuristicVal+1        
    return heuristicVal


# In[4]:


#Search with mannhaten distance i.e. h(n)= manhattenDistance
def manhattenDistance(currState):
    #position of the tiles of final puzzle
    posTiles = {1:[0,0],2:[0,1],3:[0,2],4:[1,0],5:[1,1],6:[1,2],7:[2,0],8:[2,1],0:[2,2]}
    heuristicVal = 0
    for i in range(0,3):
        for j in range(0,3):
            #calculating manhatten distance
            manhatten_Distance = abs(i-posTiles[currState[i][j]][0]) + abs(j-posTiles[currState[i][j]][1])     
            heuristicVal = heuristicVal +  manhatten_Distance      
    return heuristicVal


# In[5]:


#Search with euclidien distance i.e. h(n)= custom_heuristic
def customHeuristic(currState):
    #position of the tiles of final puzzle
    posTiles = {1:[1],2:[2],3:[3],4:[4],5:[5],6:[6],7:[7],8:[8],0:[9]}
    
    heuristicVal = 0
    currPos = 1
    for i in range(0,3):
        for j in range(0,3):
            heuristicVal = heuristicVal + abs(posTiles[currState[i][j]][0]-currPos)
            currPos = currPos+1
    return heuristicVal


# In[6]:


#function that calculates the heuristic value of the puzzle 
def heuristicValue(currState,selectedMethod):
    #h(n) = 0
    if selectedMethod == 1:
        return zeroCost(currState)
    #h(n) = displacedTiles
    if selectedMethod == 2:
        return numDisplacedTiles(currState)
    #h(n) = manhattenDistance
    if selectedMethod == 3:
        return manhattenDistance(currState)
    #h(n) = Custom (Euclidian Distance)
    if selectedMethod == 4:
        return customHeuristic(currState)


# In[7]:


#Function that finds the position of 0 in the puzzle
def findBlankPosition(currPuzzleState):
    for i in range(0,N):
        for j in range(0,N):
            if(currPuzzleState[i][j]==0):
                return i,j


# In[8]:


# function that swaps upward element 
def moveUpward(currState,x,y):
    currState[x][y],currState[x-1][y] = currState[x-1][y],0
    return currState
# function that swaps left element 
def moveLeft(currState,x,y):
    currState[x][y],currState[x][y-1] = currState[x][y-1],0
    return currState
# function that swaps right element 
def moveRight(currState,x,y):
    currState[x][y],currState[x][y+1] = currState[x][y+1],0
    return currState
# function that swaps downward element 
def moveDownward(currState,x,y):
    currState[x][y],currState[x+1][y] = currState[x+1][y],0
    return currState


# In[25]:


def exploreChildNode(currPuzzleNode,visited,pq,method):
    #current puzzle state
    currPuzzleState = currPuzzleNode[0]
    #current puzzle moves list
    currPuzzleMoves = currPuzzleNode[3]
    #location of 0 in Puzzle
    x,y=findBlankPosition(currPuzzleState)
    
    #swapping 0 in upward direction if possible
    if(x!=0):
        #creating copy of the currentpuzzle state for swapping both the tiles
        newPuzzleState = copy.deepcopy(currPuzzleState)
        #moving the tile in upward direction
        newPuzzleState = moveUpward(newPuzzleState,x,y)
        key=tuple(map(tuple,newPuzzleState))
        #checking that if we already visited the current state or not
        if(key not in visited.keys()):
                #make visited of current puzzle as True
                visited[key] = True
                #calculating heuristic value
                heuristicVal = heuristicValue(newPuzzleState,method)
                #adding the moves direction in moves list of the puzzle
                newMovesTaken = copy.deepcopy(currPuzzleMoves)
                newMovesTaken.append("↑")
                #children of the current puzzle after swapping
                childPuzzleNode = [newPuzzleState,1+currPuzzleNode[1],heuristicVal,newMovesTaken]
                #adding the child node into the priority queue
                pq.put([currPuzzleNode[1]+1+heuristicVal,childPuzzleNode])

    #swapping 0 in left direction if possible
    if(y!=0):
        #creating copy of the currentpuzzle state for swapping both the tiles
        newPuzzleState = copy.deepcopy(currPuzzleState)
        newPuzzleState = moveLeft(newPuzzleState,x,y)
        key=tuple(map(tuple,newPuzzleState))
        if(key not in visited.keys()):
                #make visited of current puzzle as True
                visited[key] = True
                #calculating heuristic value
                heuristicVal = heuristicValue(newPuzzleState,method)
                #adding the moves direction in moves list of the puzzle
                newMovesTaken = copy.deepcopy(currPuzzleMoves)
                newMovesTaken.append("←")
                #children of the current puzzle after swapping
                childPuzzleNode = [newPuzzleState,1+currPuzzleNode[1],heuristicVal,newMovesTaken]
                #adding the child node into the priority queue
                pq.put([currPuzzleNode[1]+1+heuristicVal,childPuzzleNode])

                
    #swapping 0 in downward direction if possible
    if(x < N-1):
        #creating copy of the currentpuzzle state for swapping both the tiles
        newPuzzleState = copy.deepcopy(currPuzzleState)
        newPuzzleState = moveDownward(newPuzzleState,x,y)
        key=tuple(map(tuple,newPuzzleState))
        if(key not in visited.keys()):
                #make visited of current puzzle as True
                visited[key] = True
                #calculating heuristic value
                heuristicVal = heuristicValue(newPuzzleState,method)
                #adding the moves direction in moves list of the puzzle
                newMovesTaken = copy.deepcopy(currPuzzleMoves)
                newMovesTaken.append("↓")
                #children of the current puzzle after swapping
                childPuzzleNode = [newPuzzleState,1+currPuzzleNode[1],heuristicVal,newMovesTaken]
                #adding the child node into the priority queue
                pq.put([currPuzzleNode[1]+1+heuristicVal,childPuzzleNode])

    #swapping 0 in right direction if possible
    if(y < N-1):
        #creating copy of the currentpuzzle state for swapping both the tiles
        newPuzzleState = copy.deepcopy(currPuzzleState)
        newPuzzleState = moveRight(newPuzzleState,x,y)
        key=tuple(map(tuple,newPuzzleState))
        if(key not in visited.keys()):
               #make visited of current puzzle as True
                visited[key] = True
                #calculating heuristic value
                heuristicVal = heuristicValue(newPuzzleState,method)
                #adding the moves direction in moves list of the puzzle
                newMovesTaken = copy.deepcopy(currPuzzleMoves)
                newMovesTaken.append("→")
                #children of the current puzzle after swapping
                childPuzzleNode = [newPuzzleState,1+currPuzzleNode[1],heuristicVal,newMovesTaken]
                #adding the child node into the priority queue
                pq.put([currPuzzleNode[1]+1+heuristicVal,childPuzzleNode])


# In[32]:


#function that solves the Puzzle
def solveSearch(initial,final,selectedMethod):
    #visited Dictionary for keeping track of explored states
    visited = {}
    #time limit for showing TLE
    ttl = 15
    #start time
    sTime = time.time()
    #initializing Priority Queue
    pq = PriorityQueue()
    #calculating heuristic value of initial state
    heuristicVal = heuristicValue(initial,selectedMethod)
    #initializing the rootPuzzleNode object contains all information
    rootPuzzleNode = [initial,0,heuristicVal,[]]
    key=tuple(map(tuple,rootPuzzleNode[0]))
    #marking the initial puzzle true in the dictionary
    visited[key] = True
    #adding the puzzle with its heuristic value in priority queue
    pq.put([0+heuristicVal,rootPuzzleNode])
    solved = False
    #running loop till minHeap will become empty
    while pq:
        #popping the  [h(n)+g(n),rootPuzzleNode] from priority queue with minimum h(n)+g(n)
        temp_rootPuzzleNode = pq.get()
        #getting rootPuzzleNode from temp_rootPuzzleNode
        rootPuzzleNode = list(temp_rootPuzzleNode)[1]
        #return if Goal acheived
        if(rootPuzzleNode[0]==final):
            totalTime = time.time() - sTime
            print("👏Hurray!Puzzle Solved.")
            print("Number of states explored = ",end="")
            print(len(visited))
            print("Number of states to optimal path = ",end=" ")
            print(len(rootPuzzleNode[3]))
            print("Optimal Path = ",end="")
            print(rootPuzzleNode[3])
            print("Optimal Path Cost = ",end=" ")
            print(len(rootPuzzleNode[3]))
            print("Time taken for execution = ",end="")
            print(round(totalTime,6),"sec")
            solved = True
        #if time limit exceeded break from the loop  
        if solved or (time.time()-sTime)>=ttl:
            break
        #exploring the children of the node
        exploreChildNode(rootPuzzleNode,visited,pq,selectedMethod)
    #if Puzzle remains unsolved
    if not solved:
        print("Ooops!Time Limit Exceeded for Solving the Puzzle.\nBetter Luck Next Time 👍")
        print("Total number of states explored = ",end="")
        print(len(visited))


# In[34]:


#main functions starts from here
if __name__=='__main__':
    print("Welcome to N-Puzzle Solver\n")
    # Taking Board Size Input
    print("Enter the value of N to create NxN Puzzle")
    N=int(input())
    userResponse = True
    print("Press U for UserInput or D for Demo Input or R for Random Input")
    pressedButton = input()
    
    if(pressedButton == 'D'):
        initial = [[3,2,1],[4,5,6],[8,7,0]]
        print("Demo Initial Puzzle")
        print("[3,2,1]")
        print("[4,5,6]")
        print("[8,7,0]")
    #if user gives input
    elif(pressedButton == 'U'):
        print("Enter Initital State of the Puzzle(Space Seperated Value (N*N)\n:  ",sep="")
        initial=[]
        for i in range (1,N+1):
            print("Enter values to row ",i,sep="")
            initial.append(list(map(int,input().split(" "))))
        #printing initial state of puzzle   
        print("Initial state of Puzzle:")
        for i in range(0,N):
            print(initial[i])
    #if want to test for random input
    elif(pressedButton == 'R'):
        t=[]
        initial=[]
        for i in range (0,N):
            temp=[]
            for j in range (0,N):
                temp.append(i)
            initial.append(temp)
        for i in range (0,N*N):
            t.append(i)
        random.shuffle(t) 
        k = 0
        for i in range (0,N):
            for j in range (0,N):
                initial[i][j]=t[k]
                k=k+1
        #printing initial state of puzzle   
        print("Initial state of Puzzle:")
        for i in range(0,N):
            print(initial[i])
    #if user pressed wrong button
    else:
        print("You Pressed Wrong Key!Restart Again")
        userResponse = False
    #if key pressed by user is right
    if userResponse:
        #generating final state for given input
        final=[]
        l=[]
        for i in range (1,N*N+1):
            if i!=N*N:
                l.append(i)
            else:
                l.append(0)
            if i%N==0:
                final.append(l)
                l=[]

        print("\nFinal state of Puzzle:")
        for i in range(0,N):
            print(final[i])

        #list of all available method
        methodList = {1:"Heuristic = 0",2:"Heuristic = No of Displaced Tiles",3:"Heuristic = Manhatten Distance",4:"Heuristic = Custom Heuristic"}
        #if N > 3 (manhatten and euclidien is not implemented right Now)
        if(N>3):
            print("\nHey There! Select The Method to Solve the Puzzle.")
            print("1: Heuristic = 0")
            print("2: Heuristic = No of DisplacedTiles")
        #for N==3
        else:
            print("\nHey There! Select The Method to Solve the Puzzle.")
            print("1: Heuristic = 0")
            print("2: Heuristic = No of DisplacedTiles")
            print("3: Heuristic = Manhatten Distance")
            print("4: Heuristic = Custom Heuristic")
        #select option from given list (selecting method)
        selectedMethod = int(input())
        print(f"You have selected {methodList[selectedMethod]}")
        print("Solving the Puzzle.....")
        solveSearch(initial,final,selectedMethod)
        print("Thank You For Using this service")
        #thank you so much


# In[12]:


#1 : 143577  24
#2 : 19746 24
#3 : 5739 24
#4 : 6922 24

# ©krishna_2211cs19@iitp.ac.in

