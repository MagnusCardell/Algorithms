Homework 11   Due Saturday, 3-3-18
A. Reading

    1. Please read sections 2.3, 2.4, and 2.5.

    2. Optional If you would like, feel free to read about the Fast Fourier transform (section 2.6), an algorithm that, according to these authors, has "revolutionized-- indeed, defined-- the field of signal processing."

B. Exercises

    1.[C] Exercise 2.14.

Because I want an algorithm running in n logn time, a formula would look like T(n) = 2T(n/2) + n-1. Because of this, I am using the logic from mergesort. 
Using the same function as in mergesort, I would add in one more comparison check, leaving the sortin functionality to properly compare all similar numbers, resulting in this pseudo-code:

function merge_clense(X, Y){
    if X[:-1] == null return Y
    if Y[::-1] == null return X

    if X[0] == Y[0]{
        return X[0] + merge_clense(X[1:], Y[1:])
    }
    else if X[0] <= Y[0]{
        return X[0] + merge(X[1:], Y)
    }
    else {
        return Y[0] + merge(X, Y[1:])
    }
}

Here, because its being sorted, all identical numbers will at some point be compared to each other, meaning that only one of them is left, thereby removing any duplicates. 

    2.[C] Exercise 2.16.

My approach has 2 sections to solve this. First section finds the array length of interest and sends that to a section function, that finds the specific number. 

findX(arr, X){
    int upperbound = 0
    while(arr[upperbound] < X){
        upperbound *=2
    }
    merge_find(arr[::upperbound])
}
This function doubles the index of array arr until X is lesser than the current element. We know then that X is below that index because its already sorted. Each cycle doubles the upperbound until it reaches n, where above that I assume the loop will return an error and so end the search. This function takes log(n) time because it doubles the upperbound every time. 

The second function acts like a merge finder that we have seen before where the function looks at the middle element of the array then goes up or down recursively depending on the result. This will take log(upperbound) time. 

The total search time is therefore log(n) + log(upperbound) which results in O(logn) because log(n) > log(upperbound) by definition. 


    3.[C] Explain the proof of the n log n lower bound for comparison-based sorting algorithms in your own words.

The total number of permutations of an array of size n is n!. To sort every element of the array, each number has to be compared to another until its right place is found. This can be visualized by a decision tree where there are n! nodes and its depth is log(n!). This means that the algorithm has to do log(n!) comparisons for every element in the array. A mathematical property gives log(n!) = n logn. 

    4.[C] Exercise 2.20.

This is not a comparison based algorithm. Instead its a bucket sort. Each number in the original array is counted in a new array. The new array is then transcribed into a sorted array. It takes n comparisons to look at each number in the original array, then max-min checks in the bucket/bridge to see what number each corresponding place has. Therefore the time complexity is O(n + M) where M = max-min. 

The lower bound does not apply here becuase its not a comparison based algorithm. (However, as discovered before it takes a lot of memory if M is big)
