#ifndef _MTSP_H
#define _MTSP_H

#include <algorithm>
#include <random>
#include "axisgoal.h"
#include "solution.h"

class mtsp
{
	
public:	
	mtsp();	
	virtual ~mtsp();
	void add_axisgoal(AxisGoal* ag);
	void shuffle_sol();
	vector<double> eval_axisgoals(SolOrder order);
	void two_opt(AxisGoal& ag);
	SolOrder two_swap(int i, int k);
	bool cmp_sol(Solution& sol);	
	void find_solutions(int nsol = -1);	
	void write_outfile(const char* filename);
	double getSolutionCost(int sol_idx);
	
private: 
	int consistency_check;
	vector<AxisGoal*> axis_goals;
	vector<Solution*> solutions;
	SolOrder sol_current;

	void init();
};

#endif //_MTSP_H
