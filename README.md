# Constrained-Sorting


> **algorithmic problem: <br>** 
> Given Two stacks ```a``` and ```b``` , stack ```a``` contains some random amounts of numbers and stack
> ```b``` is empty. and given exactly ```11``` operations , sort the
> numbers with the lease amount of operations.
> 
> 
> ~ ```sa```: swap the first 2 elements at the top of stack ```a```.<br>
> ~ ```sb```: same as above for ```b```.<br> ~ ```ss```: ```sa``` and
> ```sb``` at the same time.<br> ~ ```pa```: take the first element of
> ```b``` and put it at the top of ```a```.<br> ~ ```pb```: same as
> above for ```b```.<br> ~ ```ra```: shift up all elements of stack
> ```a``` by 1 The first element becomes the last one.<br> ~```rb```:
> same as above for ```b```.<br> ~```rr```: ```ra``` and ```rb``` at the
> same time.<br> ~```rra```: shift down all elements of stack ```a``` by
one The last element becomes the first one. 
 <br> ~ ```rrb```: same as above for ```b```.<br> ~ ```rrr``` : ```rra``` and ```rrb``` at the
> same time.<br>



# How to use
$ make <br>
$ ARG="some random amount of numbers"; ./push_swap $ARG <br>
=> output: instructions required to sort stack. <br>
=> check if they're correct <br>
$ ARG="some random amount of numbers"; ./push_swap $ARG | ./checker $ARG <br>
=> output: should out put Ok if correct Ko if not. <br>
