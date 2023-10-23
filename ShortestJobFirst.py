# Python program to implement the Shortest Job First algorithm   
  
# Taking the input of the number of processes  
n = int(input("Enter the number of processes: "))  
  
# Creating a matrix for storing the Process Id, Burst Time of each process, Average Waiting Time, and the Average Turn Around Time according to the provided burst times.  
mat = [[0 for j in range(4)] for i in range(n)]  
t, avg_wttime, avg_tatime = 0, 0, 0  
print("Enter the Burst Time of the processes:")  
  
# Taking the input of the burst times of the processes  
# Alloting process Ids to each process  
for i in range(n):   
  mat[i][1] = int(input(f"P{i + 1}: "))  
  mat[i][0] = i + 1  
  
# Sorting the processes that we stored above according to their burst time  
for i in range(n):   
  ind = i  
  for j in range(i + 1, n):  
    if mat[j][1] < mat[ind][1]:  
      ind = j  
  a = mat[i][1]  
  mat[i][1] = mat[ind][1]  
  mat[ind][1] = a  
  a = mat[i][0]  
  mat[i][0] = mat[ind][0]  
  mat[ind][0] = a  
  
# Calculating the waiting times of the processes  
mat[0][2] = 0   
for i in range(1, n):  
  mat[i][2] = 0  
  for j in range(i):  
    mat[i][2] += mat[j][1]  
  t += mat[i][2]  
avg_wtime = t / n  
t = 0  
# Calculating the Turn Around Time for each process  
  
# Printing the data in the table form  
print("P B_T W_T TA_T")  
for i in range(n):  
  mat[i][3] = mat[i][1] + mat[i][2]  
  t += mat[i][3]  
  print(f"P{mat[i][0]} {mat[i][1]} {mat[i][2]} {mat[i][3]}")  
avg_tatime = t / n  
print(f"The average Waiting Time of the whole sequence of processes is = {avg_wtime}")  
print(f"The average Turn Around Time of the processes is = {avg_tatime}")
