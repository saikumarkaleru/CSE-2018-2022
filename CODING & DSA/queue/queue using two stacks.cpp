/*
Method 1 (By making enQueue operation costly) 
This method makes sure that oldest entered element is always at the top of stack 1, 
so that deQueue operation just pops from stack1.
To put the element at top of stack1, stack2 is used.



enQueue(q, x): 

    While stack1 is not empty, push everything from stack1 to stack2.
    Push x to stack1 (assuming size of stacks is unlimited).
    Push everything back to stack1.
    Here time complexity will be O(n)



deQueue(q): 

    If stack1 is empty then error
    Pop an item from stack1 and return it
    Here time complexity will be O(1)

*/


struct Queue {
    stack<int> s1, s2;
 
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};
 





/*

Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned. 

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
     Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)

*/