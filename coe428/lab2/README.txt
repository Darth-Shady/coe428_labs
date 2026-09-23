Q1/ Suppose that towers(5, 2, 3) is invoked.

1. How will the first recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the
three parameters.

towers(n-1, from, spare) --> towers(4, 2, 1)


2. How many recursive calls to towers() will be made before this first recursive call actually returns to the initial invocation?

2^(n+1) - 1 total recursive calls
In our case, 31 recursive calls.

3. Once towers(5, 2, 3) has invoked its first recursive call to towers() and this
invocation has returned, what will be printed to stdout? (i.e. What actual
move will be made by towers(5, 2, 3) ?)

2 3

4. How will the second recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters.

towers(4,1,3)

Q2 / Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?
one stdout line / move
2^(n) - 1   moves required to solve towers of hanoi
2^8 - 1 = 255 moves / lines that will be printed to stdout




//notes for next demo:

make sure to read your code over again, and equations and what not, after 2 weeks everything is forgotten pretty much
e.g. for Q2)II) the equation and thereby explanation was wrong, it was actually 2^n - 1 


