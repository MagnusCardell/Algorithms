Alg Master Theorem homework
Homework 10   Due Thursday, 3-1-18
A. Reading

    1. Please read chapter two up to the end of section 2.2.

B. Exercises

    1.[C] Exercise 2.1, page 70.

Using the formula I get (1001 * 2^(8/2) + 1011) * (1011 * 2^(8/2) + 1010) which results in 28830

    2.[C] Exercise 2.2.

After trying a couple of test cases:
n = 2, b = 2

2^2 is in range(3, 9)

n=2, b=3
3^x is in range(2,8) for x = [1,2]

After that I boiled it down to a formula using log to find out the power needed to exponentiate b to fit into the desired range. 

So, log(n) (base b) = p (power)

Where p is the power. 

Then, b^p is in range(n, nb)

    3.[C] Exercise 2.3.

a)  I won't put up my equation here because its too much, but what I discover is that the work to do at each node grows faster than the work to do the recursion and recombining, meaning that d<logd(a) so that O(n) = n log n

b)  The time to compute at each node is clearly constant so this is a case where d>logd(a) meaning that O(n) = n^d, exponential time. 

    4.[C] Exercise 2.4.

My interpretation of A gives me the following  Master theorem formula:

A = 5T(n/2) + n
which gives me:
d = 1
a = 5
b = 2
So, log2(5) = 2.3 which is greater than d=1.
A is therefore n^log2(5)

B would call 2^n child nodes, combine them in constant time which means that they become a whole lot. Exponential time at least. Not a choice

C compiles into 9T(n/3) + n^2
where 
d = 2
a = 9
b = 3
log3(9) = 2 = d
So time complexity is O(n^2*logn) giving us a very close choice between A and C
A graph between the two https://www.wolframalpha.com/input/?i=n%5E2.3+vs+n%5E2*logn+from+1000+to+10000 shows that A grow faster than C so C is ultimately the fastest.

My choice is C. 

    5.[C] Exercise 2.5.

a) 
b=3
a=2
d=0
log3(2) = 0.6... which is greater than d.
Time complexity = O(n^0.6)

b)
b=4
a=5
d=1
log4(5) = 1.16... which is greater than d.
Time complexity = O(n^1.16)

c)
b=7
a=7
d=1
log7(7) = 1 which is smaller than d.
Time complexity = O(n^1) = O(n)

d)
b=3
a=9
d=2
log3(9) = 2 which is equal to d.
Time complexity = O(n^2 * logn)

e)
b=2
a=8
d=3
log2(8) = 3 which is equal to d.
Time complexity = O(n^3 * logn)

f)
b=25
a=49
d=3/2
log25(49) = 1.2... which is smaller than d.
Time complexity = O(n^3/2)

g)
b=1
a=1
d=undefined...
masters theorem doesnt really apply here but a rough evaluation get the time complexity to O(n)
(one node called n-1 times with constant cost)

h)
b=1
a=1
d=x
log1(1) is not really valid here but it will be smaller than x.
Time complexity = O(n^x)

i)
b=1
a=1
d=n
log1(1) is not really valid here leaving me with the constant cost, running n times.
Time complexity = O(n+1)

j)
b=1
a=2
d=0
Similar to last question,
Time complexity = O(n+1)

k)
Similar to last question,
Time complexity = O(n^-0,5)

    6.[C] Exercise 2.12.

2T(n/2) + c where c is a constant. Through the masters theorem, it gives me time 
a = 2
b = 2
d = 0
Log2(2) = 1 which is greater than d so Time complexity is 

O(n^1) = O(n)


    7.[C] Exercise 2.17.

My rational for this is that by the masters theorem it should be T(n) = 2T(n/2) + 1 where c is a constant. 
Then
a = 2
b = 2
d = 0
log2(2) = 1 > d so time complexity is O(n^d * logn) where d = 0 so O(log n)

So I am looking for an algorithm that does logn nodes, and constant work each node. 

My pseudocode for this recursive algorithm is as follows:

void find_n(arr, x, n){
    if(x == 0) or x > arr.size()) return;
    x /= 2;
    if(arr[x] == n){
        cout<<"FOUND IT"<<endl;
        return;
    }
    find_n(arr, x += x/2, n);
    find_n(arr, x -= x/2, n);
}

main(){
    find_arr({1,3,5,7,10,44,52,62,72,99}, 10)
    return 0;
}

This will run logn times. x is the index accessor, n is the target of choice, arr is the array that we search.