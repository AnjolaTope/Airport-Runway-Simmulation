
#include "airport.h"
#include <iostream>
#include<cmath>
#include<iomanip>
#include <cassert> 
#include <cstdlib>
//using namespace std;
namespace runwayspace {

	plane_takingoff::plane_takingoff (double time) {
		time_to_takeoof = time;
	    take_off_time_left=0;
	};
	void plane_takingoff::one_second() {
		if (is_busy()) {
		--take_off_time_left;
		}
	};
	void plane_takingoff::start_taking_off() {
		assert(!is_busy()); 
		take_off_time_left = time_to_takeoof  ;
	};
	plane_landing::plane_landing(double time) {
		time_to_land = time;
		landing_time_left = 0;
	};
	void plane_landing::one_second() {
		if (is_busy()) {
			--landing_time_left;
		}
	};
	void plane_landing::start_landing() {
		assert(!is_busy());
		landing_time_left = time_to_land;
	};
	boolsourceT::boolsourceT(double time, double totaltime){
		   double prob;
		   prob = time / totaltime;

		   assert(prob > 0);
		   assert(prob < 1);
			prob1 = prob;
			if (prob > 1) {
				cout << " we will now run the simulation with default parameters" << endl;
			}
	}
	
	bool boolsourceT :: query()const {
		int num = rand();
		return (num < (prob1 * RAND_MAX));
	}
	boolsourceL::boolsourceL(double time, double totaltime) {

		double prob;
		prob = time / totaltime;
		assert(prob > 0);
		assert(prob < 1);
		prob1 = prob;

		if (prob > 1) {
			cout << " we will now run the simulation with default parameters" << endl;
		}
	}
	bool boolsourceL::query()const {
		int num = rand();
		return (num < (prob1 * RAND_MAX));
	}
	averager_takeoff::averager_takeoff() {
		count = 0;
		sum = 0;
	}
	void averager_takeoff::next_number( double value) {
		count++;
		sum += value;
	}
	double averager_takeoff::average()const {
		assert(how_many_numbers()> 0);
		return sum/count;
	}
	averager_landing::averager_landing() {
		count = 0;
		sum = 0;
	}
	void averager_landing::next_number(double value) {
		count++;
		sum += value;
	}
	double averager_landing::average()const {
		assert(how_many_numbers() > 0);
		return sum / count;
	}
	void averager_landing::crash() {
		count1++;
	};
	double  averager_landing::crashed() {
		return count1;
	};
	
}