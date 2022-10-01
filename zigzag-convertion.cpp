class Solution {
    public:
        string convert(string input, int numrows) {
            string output="";
            
            int len = input.length();
        
            if(numrows >= len || numrows == 1)
                    return input;
    
       
            int seq[len];
            bool rev = false; 
    
            for(int i=0,j=0;i<len;i++) {
                    seq[i] = j;
                    if(j == numrows - 1)  
                            rev  = true;
                    if(j == 0 )
                            rev = false;
                    if(rev)
                     j--;
                    else
                     j++;
            }
               
            for(int j=0,k=0;j<numrows;j++) {
    
                    for(int i=0;i<len;i++){
                            if(seq[i]== j)
                                    output += input[i];
                    }
            }
           
            return output;
            
        }
    };
