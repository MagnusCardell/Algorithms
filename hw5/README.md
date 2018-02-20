
Homework 5   Due Tuesday, 2-20-18
A. Predicting Time Complexity for Pseudo-code
Below are some high level descriptions, in English, of some possible elements of a computation. For each such description, please write down a formula that might reasonably describe the number of cycles required to run an associated piece of code. As usual, say briefly (in about a sentence) why you came to the conclusion you did. If you think it is appropriate, state any assumptions you made to clarify the problem.

    1.[C] A loop where the loop variable is incremented n times, and the body of the loop contains some trig computation that is not related to the loop variable.

    2.[C] A loop where the loop variable is incremented n times, and the body of the loop contains some trig computation that is related to the loop variable.

    3.[C] A double loop where the outer loop variable is incremented n times, the inner loop variable is incremented n/3 times, and the body of the inner loop contains an array lookup and an assignment into another array.

    4.[C] A double loop where the outer loop increments the outer loop variable, and the inner loop increments both the inner and outer loop variables.

    5.[C] A triple loop where each loop variable goes from zero to n.

    6.[C] A recursive function that calls itself once if the incoming integer is greater than some fixed value.

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