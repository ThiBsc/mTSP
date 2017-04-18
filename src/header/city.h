#ifndef _CITY_H
#define _CITY_H

#include "math.h"

class City
{
	
public: 
	City(int id, int x, int y);	
	virtual ~City();	
	int get_id();	
	int get_x();	
	int get_y();
	double distance(City& c);
	
private: 
	int id;
	int x;
	int y;
};

#endif //_CITY_H
