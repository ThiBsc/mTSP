#include "header/axisgoal.h"

/**
 * 
 * Un axis goal représente un objectif à améliorer,
 * dans notre cas, c'est un fichier .tsp complet qui contient toutes les City
 * (ligne id x y) et la matrice des distances
 * 
 */

AxisGoal::AxisGoal(const char* filename)
{
	read_file(filename);
	int nc = num_cities();
	cities_dist = Matrix<double>(nc, nc);
	for (int i=0; i < nc; i++){
		for (int j=0; j < nc; j++){
			if (i == j)
				cities_dist[i][j] = 0;
			else{
				cities_dist[i][j] = cities[i]->distance(*cities[j]);
			}
		}
	}
}

AxisGoal::~AxisGoal()
{
	cities.clear();
}

double AxisGoal::eval_solution(SolOrder order)
{
	double ret = 0.0;
	for (int i = 0; i < num_cities() - 1; ++i){
		ret += cities_dist[order[i]][order[i+1]];
	}
	ret += cities_dist[order[0]][order[num_cities()-1]];
	return ret;
}

int AxisGoal::num_cities()
{
    return cities.size();
}

Matrix<double> & AxisGoal::matrix_dist()
{
    return cities_dist;
}

void AxisGoal::read_file(const char* filename)
{
	int id_read, x_read, y_read;
	id_read = x_read = y_read = 0;

	cities.clear();
	ifstream file(filename);
	if (!file){
		cout << "Unable to read " << filename << endl;
	}
	else{
		string line;
		while(!file.eof()){
			getline(file, line);
			istringstream tokenize(line);
			if (tokenize >> id_read >> x_read >> y_read){				
				cities.push_back(new City(id_read, x_read, y_read));
			}
		}
		file.close();
	}
}
