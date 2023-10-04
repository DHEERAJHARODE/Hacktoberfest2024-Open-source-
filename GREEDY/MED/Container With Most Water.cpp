class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int area=0;
        int maxarea=0;
        int e=height.size()-1;
        
            
                  while(s<e){
                 area=0;
                 int lenght=min(height[s],height[e]);
                 int width=e-s;
                 area=lenght*width;
                 maxarea=max(maxarea,area);
                 if(height[s]>height[e]){
                     e--;
                 }
                 else{
                     s++;
                 }
                  
             }
           
         
        return maxarea;
    }
};
