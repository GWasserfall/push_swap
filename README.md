# push_swap
Sorting algorithm usng 2 stacks

## Sorting algorithm

In each iterative movement of stack A or B the first best possible move is determined by indexing each number in stack A starting at 0, the index would invert when passing the middle of stack A. The corresponding position would then be found by checking the move count in stack B in order to get the corresponding value in A to the correct position. These numbers are added / subtracted together to find the total move count.

yada yada need a better way to explain this

## Visualiser
I created a visualiser using the C ncurses library to draw both stacks to the screen. The stack positions can be moved forward and backward using the arrow keys on the keyboard, or solved from the current position using the enter key

{{ giff_here }}
