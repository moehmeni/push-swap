# push-swap
Sorting a set of numbers with two stacks with a low set of instructions done

# How it works
If you run:
```
./push_swap 1 3 2 4
```
You will see:
```
pb
sa
pa
```
These are the abbreviations for the instrcutions that we apply for each of those two stack (stack a and b).

- `sa` (swap a)
- `sb` (swap b)
- `ss` (sa and sb)
- `pa` (pop from b and push to a)
- `pb` (pop from a and push to b)
- `ra` (rotate a)
- `rb` (rotate b)
- `rr` (ra and rb)
- `rra` (reverse rotate a)
- `rrb` (reverse rotate b)
- `rrr` (rra and rrb)

<sub>rotate means shift left and reverse rotate means shift right</sub>

# Performance
```
bash test.sh
```
```
Testing with 3 numbers
Instructtions: 1
Checker: OK


Testing with 5 numbers
Instructtions: 7
Checker: OK


Testing with 100 numbers
Instructtions: 598
Checker: OK


Testing with 500 numbers
Instructtions: 4984
Checker: OK
```

# Disclaimer
If you're a 42 network student, please write everything yourself from scratch after you got the idea. Good luck!

# Notes
I tried to keep the code as short and clean as possible so if you are looking for a short and not scary project then it's worth investing the time to
figure out the algorithm and the implementaions. Feel free to sugggest any improvement regarding the algorithm performance :)
