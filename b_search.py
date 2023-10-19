def b_search(arr,low,high,x):
  if high>=low:
      mid=(high+low)//2
      if arr[mid] == x:
         return mid
      elif arr[mid]<x:
         return b_search(arr,mid+1,high,x)
      else:
         return b_search(arr,low,mid-1,x)
  else:
     return -1

arr=[1, 2, 4, 5, 10, 11]
x=7
result=b_search(arr,0,len(arr)-1,x)
if result!=-1:
    print("element is present at ",str(result))
else:
    print("element is not present" )
    
