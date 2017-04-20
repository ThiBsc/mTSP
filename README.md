# mTSP
Greedy algorithm to the multiple Traveling Salesman Problem
### Compile
Run ```make all```
### Use
- Mono: ```./tsp.out <tsp_file>```, generate file _sol_mono_objective.txt_
- Multi: ```./tsp.out <tsp_file1> <tsp_file2> [<tsp_file3>] 100```, where 100 is the number of wanted solutions. It's generate a sol_[bi/tri]_objective.dat (Higher is the number of wanted solutions, slower is the answer)
### Result
#### Mono
_sol_mono_objective.txt_ contain the solution cost returned by ```2-opt``` and the path order
#### Multi
##### bi-objective
```
./tsp.out test_file/kroA100.tsp test_file/kroB100.tsp 200
gnuplot -e "plot 'sol_bi_objective.dat'" --persist
```
##### tri-objective
```
./tsp.out test_file/kroA100.tsp test_file/kroB100.tsp test_file/kroC100.tsp 1000
gnuplot
splot 'sol_tri_objective.dat' w p lc palette z
```
##### plot render
First is the bi-objective, and the second, the tri-objective render:  
<img src="https://github.com/thibDev/mTSP/blob/master/sol_bi_objective.png" width="320" height="240"/>
<img src="https://github.com/thibDev/mTSP/blob/master/sol_tri_objective.png" width="320" height="240"/>
