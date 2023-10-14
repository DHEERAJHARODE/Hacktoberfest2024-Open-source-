class MyStack {

    //implement stack using 1 queue..
    Queue<Integer> q;


    public MyStack(){
        q = new LinkedList<>();
    }
    
    public void push(int x) {
        q.add(x);

        for(int i=0;i<q.size()-1;i++){
            q.add(q.poll());
        }


        
    }
    
    public int pop() {
        return q.poll();
    }
    
    public int top() {
        return q.peek();
    }
    
    public boolean empty() {
        return q.size()==0 ;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
