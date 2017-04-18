# mTSP
Greedy algorithm to the multiple Traveling Salesman Problem
### Compile
Run ```make all```
### Use
- Mono: ```./tsp.out test_file/kroA100.tsp```
- Multi: ```./tsp.out test_file/kroA100.tsp test_file/kroB100.tsp 100``` where 100 is the number of wanted solutions
- It's generate a sol_[bi/mono]_objective.txt
- To visualize the result:
  - ```gnuplot```
  - ```plot 'sol_bi_objective.txt'```
- You should see something like this:
![plot_result](https://github.com/thibDev/mTSP/blob/master/sol_bi_objective.png)
