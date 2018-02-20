
Homework 5   Due Tuesday, 2-20-18
A. Predicting Time Complexity for Pseudo-code
Below are some high level descriptions, in English, of some possible elements of a computation. For each such description, please write down a formula that might reasonably describe the number of cycles required to run an associated piece of code. As usual, say briefly (in about a sentence) why you came to the conclusion you did. If you think it is appropriate, state any assumptions you made to clarify the problem.

    1.[C] A loop where the loop variable is incremented n times, and the body of the loop contains some trig computation that is not related to the loop variable.

    Assuming that a trig computation is handled with ~3 cycles (lookup table, move, more than one), that will be repeated n times. So the formula would look like 3n or more generally c*n where c is the number of cycles of the body. 

    2.[C] A loop where the loop variable is incremented n times, and the body of the loop contains some trig computation that is related to the loop variable.

    The loop will still increment n times by definition, and since it is used in the body it may cause the program to take 1/3 or 1 cycles more per loop. The formula still stands as A1: 3n or c*n.

    3.[C] A double loop where the outer loop variable is incremented n times, the inner loop variable is incremented n/3 times, and the body of the inner loop contains an array lookup and an assignment into another array.

    The body is worth about 2 cycles. It will be run n*(n/2) = 0.5(n^2). Since 2*0.5 =1, the formula looks like n^2.

    4.[C] A double loop where the outer loop increments the outer loop variable, and the inner loop increments both the inner and outer loop variables.

    Based on this information, the loop is infinite and computing time is infinite. But assuming the stopping point is n, the outer loop will fire n/2 times. So its formula is 0.25(n^2) 

    5.[C] A triple loop where each loop variable goes from zero to n.
    
    Using the formula for a tetrahydral plane, and assuming the loop checks and increments total in ~1cycle/loop, the total computation cycles will be n(n+1)(n+2)/6. 

    6.[C] A recursive function that calls itself once if the incoming integer is greater than some fixed value.

    Inifinite computation time because every new function will call a new function based on the integer that does not change between the function calls. 

B. Predicting Time Complexity for Branching Recursive Functions
For each of the code snippets below, write down a formula to describe the time complexity of this code, as a function of n. Also, explain how you arrived at your conclusion, for each of the snippets below.

    1.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/2);
      }
    }
    
    2.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/2);
        recursion(n/2);
      }
    }

    3.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/2);
        recursion(n/2);
        recursion(n/2);
      }
    }

    4.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/3);
        recursion(n/3);
        recursion(n/3);
        recursion(n/3);
      }
    }

    5.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/2);
        recursion(n/3);
      }
    }

    6.[C]

    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n-1);
        recursion(n-1);
      }
    }

C. Actual Timing for a Recursive Function

    1.[C] Now choose a snippet from part B, and actually time it (by making an appropriate C++ program). Paste your code, and the result of your timings, into your homework page, along with a comment about whether the result was high or low, and why you think that might be.