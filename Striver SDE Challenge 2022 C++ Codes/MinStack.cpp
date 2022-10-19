class MinStack {
  stack < int > st;
  int mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      // while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int val) {
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 * val - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    int el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    int el = ;
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};