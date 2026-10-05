CS 210 Programing assignment 1 

1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

concat works between lists of the same type because ArrayList and LinkedList store their elements differently. A LinkedList connects nodes, while an ArrayList stores pointers inside an array. To combine different types, I would need another way to go through the other list and transfer each value safely.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

My linked-list reverse() uses three pointers named previous, current, and next. previous remembers the node behind the current node, while next saves the remaining part of the list before I change the link. If I do not save next, I will lose access to the rest of the list after changing.

3. addAnywhere and deleteAnywhere both need a bounds check. What is the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

For addAnywhere, the valid range is from 0 through size, including size because an item can be added at the end. For deleteAnywhere, the valid range is from 0 through size - 1 because the position must already contain an item. My code prints an invalid-position message and returns without changing the list when the position is outside the correct range.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

concat must find the final node so it can connect that node to the beginning of the other list. addFront and deleteFront only work with head_, so they do not need to search through the list. A tail pointer would make concat faster, but I would need to update it during additions, deletions, reversing, concatenation, and whenever the list becomes empty.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

In my ArrayList::addAnywhere, the existing elements must shift one position to the right to create an empty space. I start shifting from the back of the array and move toward the requested position. If I started from the front, I could overwrite an element before copying it to its new position.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

The line that changes the direction is tableOne->reverse();. Before that line, the order is Carl, Lip, Fiona, and Liam, and afterward it becomes Liam, Fiona, Lip, and Carl. Without that line, the printed order would not reverse, and deleteAnywhere(1) would remove Lip instead of Fiona.

