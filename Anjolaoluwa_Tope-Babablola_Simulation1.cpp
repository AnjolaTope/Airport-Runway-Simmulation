
#include <iostream>
#include<cmath>
#include<iomanip>
#include <queue>
#include "airport.h"
using namespace runwayspace;
using namespace std;

int main()
{
	double landingtime,takeofftime, maxtime,total,hold1,hold2; 
	double landing_prob=0.6;
	double take_off_prob=0.7;
	queue<double> arrival_times, depature_times;
	double next;
	
	cout << "*******************************************************************************************************************" << endl;
	cout << "* This is a simulation of an Airport                                                                              *" << endl;
	cout << "* This simulation tells us the amount of time a plane stays in the airzone before landing                         *" << endl;
	cout << "* This simulation also tells us the amount of time a plane stays in the takeoff zone before takeoff               *" << endl;
	cout << "* This simulation tells us the amount of time a plane can  stay in  the airzone before crashing                   *" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "* This are some things needed before we can start the simulation                                                  *" << endl;
	cout << "*  All estimates should be in minutes                                                                             *" << endl;
	cout << "* 1)Please can you give an estimate of the amount of time needed for one plane to land                            *" << endl;
	cin >> landingtime;
	cout << "* 2)Pease can you give an estimate of the amount of time needed for one plane to takeoff                          *" << endl;
	cin >> takeofftime;
	cout << "* 1)Please can you give an estimate of the average amount of time between arrival of planes to the landing queue  *" << endl;
	cin >>landing_prob;
	cout << "* 2)Pease can you give an estimate  the average amount of time between arrival of planes to the take0ff queue     *" << endl;
	cin >> take_off_prob;
	cout << "* 4)Please can you give an estimate of the maximum amount of time that a plane can stay                           *" << endl;
	cout << "*   in the landing queue without running out of fueland crashing                                                  *" << endl;
	cin >> maxtime;
	cout << "* 5)Please can you give an estimate of the total length of time to be simulated.                                  *" << endl;
	cin >> total;
	cout << "*******************************************************************************************************************" << endl;

	plane_landing p1(landingtime);
	boolsourceL l_prob(landing_prob,total);
	averager_landing avg1;

	plane_takingoff p2(takeofftime);
	boolsourceT t_prob(take_off_prob,total);
	averager_takeoff avg2;
	 
	for (double current = 1; current <= total; current++) {
		// simulates the passage of one minute of time.
		
		//check whether  a new plane has arrived for landing
		if (l_prob.query()) {
		
			arrival_times.push(current);
		}

		//check whether  a new plane has arrived for takeoff
		if (t_prob.query()) {
			
			depature_times.push(current);
		}

		//checks if the plane can start landing 
		if ((!p1.is_busy()) && (!p2.is_busy()) && (!arrival_times.empty())) {
			hold1 = arrival_times.front();
			arrival_times.pop();
			next = current - hold1;
			if (next < maxtime) {
				avg1.next_number(current - hold1);
				p1.start_landing();
			}
			if (next > maxtime) {
				avg1.crash();
			}
		}
		//checks if the plane can start  taking off
		else if ((!p1.is_busy()) && (!p2.is_busy())&&(!depature_times.empty()) && (arrival_times.empty())) {
			hold2 = depature_times.front();
			depature_times.pop();
			avg2.next_number(current - hold2);
			p2.start_taking_off();
		}

		// TTelss the simulator that one minute has passed
		p1.one_second();
		p2.one_second();

	}

	// wrire the summary imformation about the simulation

	cout << "PLanes that landed: " << avg1.how_many_numbers() << endl;
	if (avg1.how_many_numbers() > 0) {
		cout << "Average wait time for landing: " << avg1.average() << " minutes" << endl;
	}
		cout << "The number of planes that crashed is : " << avg1.crashed()  << endl;


	cout << "PLanes that tookoff: " << avg2.how_many_numbers() << endl;
	if (avg2.how_many_numbers() > 0)
		cout << "Average wait time for landing: " << avg2.average() << " minutes" << endl;
	
}

