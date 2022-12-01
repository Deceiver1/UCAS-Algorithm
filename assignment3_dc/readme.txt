Count Inversion
Description
Recall the problem of finding the number of inversions. As in the course, we are given a sequence of nn numbers a_1,a_2,⋯,a_n, and we define an inversion to be a pair i<j such that a_i>a_j
We motivated the problem of counting inversions as a good measure of how different two orderings are. However, one might feel that this measure is too sensitive. Let's call a pair a significant inversion if i<j and a_i>3a_j. Give an O(nlog n) algorithm to count the number of significant inversions between two orderings.
The array contains N elements (1≤N≤100,000). All elements are in the range from 1 to 1,000,000,000.

Input
The first line contains one integer N, indicating the size of the array. The second line contains N elements in the array.
·50% test cases guarantee that N<1000.

Output
Output a single integer which is the number of pairs of significant inversions.



River
Description
Two lovely frogs Alice and Bob live by a river. There are several stones in this river. Every morning, they will go to the other side of the river to have fun. They cross the river by jumping from one stone to another. One day, Alice decides to play tricks on Bob. She plans to remove some stones so that there is no “easy jump” for Bob to across the river any more. But she has no idea which stones she should remove. She needs your help.
The width of the river is an integer L(1≤L≤1,000,000,000). We treat the river as a one-dimensional line segment,with two endpoints A (two frog’s home) and B (the other side of the river). Among the river, there are N stones (0≤N≤50,000). The distance from the i-th stone to side A is D_i(0<D_i<L). Alice would like to remove M stones in the river (0≤M≤N) so that with the rest of the stones, the minimum distance among all possible jumps for Bob is the largest.

Input
Each instance contains two lines. The first line contains three integers L, N and M. The second line gives the positions of M stones. No two stones share the same position.
* 30% test cases guarantee that N<20.

Output
For each instance, output a single line with a single integer which is the maximum of the minimum distance among all possible jumps after removing M stones.
