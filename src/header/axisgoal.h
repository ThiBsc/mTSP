#ifndef _AXISGOAL_H
#define _AXISGOAL_H

#include "city.h"
#include "matrix.h"
#include "solution.h"
#include <vector>
#include <fstream>

class AxisGoal
{
	
public:	
	AxisGoal(const char* filename);	
	virtual ~AxisGoal();
	double eval_solution(SolOrder order);	
	int num_cities();
	Matrix<double>& matrix_dist();
	
private: 
	Matrix<double> cities_dist;
	vector<City*> cities;
	
	void read_file(const char* filename);
};

#endif //_AXISGOAL_H
