#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <vector>

using namespace std;

typedef vector<int> SolOrder;

class Solution
{
	
public:
	Solution(SolOrder order, vector<double> axisg_eval);	
	virtual ~Solution();
	SolOrder get_order();
	vector<double> get_axis_eval();
	
private: 
	SolOrder order;
	vector<double> axisg_eval;
};

#endif //_SOLUTION_H
