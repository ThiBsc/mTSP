#include "header/axisgoal.h"
#include "header/mtsp.h"
#include <iostream>

#define MONO_RESULT "sol_mono_objective.txt"
#define BI_RESULT "sol_bi_objective.dat"
#define TRI_RESULT "sol_tri_objective.dat"

using namespace std;

int main(int argc, char const *argv[])
{
	mtsp m_tsp;
	if (argc >= 2 && argc <= 3){
		cout << "TSP mono-objective" << endl;
		AxisGoal ag1(argv[1]);
		m_tsp.add_axisgoal(&ag1);
		if (argc == 3){
			int limit = std::atoi(argv[2]);
			do {
				m_tsp.two_opt(ag1);
				//cout << m_tsp.getSolutionCost(0) << endl;
			} while (m_tsp.getSolutionCost(0) >= limit);
		} else {
			m_tsp.two_opt(ag1);
		}
		m_tsp.write_outfile(MONO_RESULT);
	}
	else if (argc == 4){
		cout << "TSP bi-objective" << endl;
		m_tsp.add_axisgoal(new AxisGoal(argv[1]));
		m_tsp.add_axisgoal(new AxisGoal(argv[2]));
		m_tsp.find_solutions(atoi(argv[3]));
		m_tsp.write_outfile(BI_RESULT);
	}
	else if (argc == 5){
		cout << "TSP tri-objective" << endl;
		m_tsp.add_axisgoal(new AxisGoal(argv[1]));
		m_tsp.add_axisgoal(new AxisGoal(argv[2]));
		m_tsp.add_axisgoal(new AxisGoal(argv[3]));
		m_tsp.find_solutions(atoi(argv[4]));
		m_tsp.write_outfile(TRI_RESULT);
	}
	else{
		cout << "Usage: tsp.out file1.txt [file2.txt [file3.txt] nb_sol]" << endl;
		cout << "Ex: " << endl;
		cout << "mono: ./tsp.out kroA100.tsp [UNDER_LIMIT]" << endl;
		cout << "multi: ./tsp.out kroA100.tsp kroB100.tst 200" << endl;
	}

	return 0;
}
