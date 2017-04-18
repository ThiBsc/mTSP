#include "header/axisgoal.h"
#include "header/mtsp.h"
#include <iostream>

#define MONO_RESULT "sol_mono_objective.txt"
#define MULTI_RESULT "sol_bi_objective.txt"

using namespace std;

int main(int argc, char const *argv[])
{
	mtsp m_tsp;
	if (argc == 2){
		cout << "TSP mono-objective" << endl;
		AxisGoal ag1(argv[1]);
		m_tsp.add_axisgoal(&ag1);
		m_tsp.two_opt(ag1);
		m_tsp.write_outfile(MONO_RESULT);
	}
	else if (argc == 4){
		cout << "TSP bi-objective" << endl;
		AxisGoal ag1(argv[1]);
		AxisGoal ag2(argv[2]);
		m_tsp.add_axisgoal(&ag1);
		m_tsp.add_axisgoal(&ag2);
		m_tsp.find_solutions(atoi(argv[3]));
		m_tsp.write_outfile(MULTI_RESULT);
	}
	else{
		cout << "Usage: tsp.out file1.txt [file2.txt nb_sol]" << endl;
		cout << "Ex: " << endl;
		cout << "mono: ./tsp.out kroA100.tsp" << endl;
		cout << "multi: ./tsp.out kroA100.tsp kroB100.tst 200" << endl;
	}

	return 0;
}
