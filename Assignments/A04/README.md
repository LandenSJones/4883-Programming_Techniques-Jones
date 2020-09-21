
#### A04 
|   #   | Folder Link | Assignment Description |
| :---: | ----------- | ---------------------- |
|   1   |<a href="https://github.com/LandenSJones/4883-Programming_Techniques-Jones/tree/master/Assignments/A04/122.pdf">122</a>|Trees on the Level|
|   2   |<a href="https://github.com/LandenSJones/4883-Programming_Techniques-Jones/blob/master/Assignments/A04/12347.pdf">12347</a>|Binary Search Tree|


##### The above are problems that relate to binary tree problems from UVA judge.

122 - You could use an array implementation. When you insert a node you would follow the children set of the data ie 'LLR' and for each L you would multiply current index by 2 and for each R you would multiply the current index by 2 and add 1. If you ever exceed the bounds of the array, you would dynamically allocate a newn array. Copy over all current data and continue processing. After processing you could traverse the tree to see if all nodes have information or if there is any duplicate values.

12347 - 
