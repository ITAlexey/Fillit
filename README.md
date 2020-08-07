# Fillit
The first group project for "21 School"s students. The fillit project is about to find and output the possible smallest square from the supplied assortment tetraminos.
Solution of the project was shared on two parts: **validation of given file** and **search an appropirate algorithm**.

### Algorithm
Using of recursive backtracking algorithm was effective in this task.
First step is counting the minimum possible square from the tetraminos which were processed.
Second step is consider processed tetrmaino as block and place them to the given square in the following way:
- The filling starts with upper right corner.
- if block is out of boundaries of the square or overlap the previous one it shifts to the right or down.
- if block can't be placed the previous one is going to be retrived and the current one places at that place. if it fails just repeat the method again.
- if it impossible to place all tetraminos in the square using the actions above, the area of square should be increased by one and repeat actions for the new square.
- Repeat these steps until the square is filled.

### Execution
How to run:
```
./fillit [file_name]
```
### Valid tetraminos:
```
##..  ####  ##..  ###.  .##.
##..  ....  #...  .#..  ##..
....  ....  #...  ....  ....
....  ....  ....  ....  ....
```

### Invalid tetraminos:
```
##..  #...  ....  ####
..##  .#..  ....  ####
....  ..#.  ....  ####
....  ...#  ....  ####
```
### Example:
```
./fillit test
```

```
.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

### Team
- [dshala](https://github.com/ITAlexey/)
- [tclarita](https://github.com/iles982)
