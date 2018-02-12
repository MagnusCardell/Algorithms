A. Per-Instruction Latency and Throughput
Please check out the following examples for estimating individual instruction cycle counts:

    a simple loop --> simple_loop.png
    a simple recursive function --> recursive_loop.png

The cycle counts in these examples are taken from this source(http://www.agner.org/optimize/), with some estimates more specifically from this(http://www.agner.org/optimize/optimizing_assembly.pdf) pdf on page 64. Please use these sources to figure out what is meant by latency and throughput, and also briefly answer the following questions:

    1.[C] If we're working with integers on a typical processor (Hint: information for a "typical processor", rather than a specific model like the ones we use in the lab, can be found in the document "Optimizing Subroutines in Assembly Language"), which of the following operations has the highest latency: Moving, adding, subtracting, multiplying, dividing, shifting, or boolean comparison?

    2.[C] Looking specifically at our processor (Intel Core 2 Merom; you might find the "Instruction Tables" helpful), do we see higher latency and reciprocal throughput when we move (MOV) between two registers, or between a register and memory?

    3.[C] In general, based on the instruction tables, do most instructions have higher latency or reciprocal throughput? Why?

B. Estimating Total Cycles
Given the above examples, can you figure out the corresponding C++ code and estimate the number of cycles for the following Assembly snippets?

    1.[C] Exercise 1

    2.[C] Exercise 2

C. Relative Costs

    1.[C] Compile the following C++ code as Assembly and determine which portion is the most time-consuming. State your reasoning.

        int i, x;

        for (i=0; i<500; i++)
          x = i;

        cout << i << endl;

D. Essential Numeric Sums

    1.[C] What is the sum of the whole numbers from 1 to n?

    2.[C] Justify your answer mathematically, in a way that makes sense to you.

    3.[C] What is the sum of the powers of 5 from 1 to 5^n?

    4.[C] Justify your answer mathematically, in a way that makes sense to you.