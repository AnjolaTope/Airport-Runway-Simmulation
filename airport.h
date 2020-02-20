#include <iostream>
#include<cmath>
#include<iomanip>
#include <cassert> 
#include <cstdlib>
#pragma once;
#ifndef airport
#define airport
using namespace std;
namespace runwayspace {


	class plane_takingoff
	{
	private:
		double time_to_takeoof;  // total time for takeoff
		double take_off_time_left; // time left to takeoff


	public:
		plane_takingoff(double time);
	    void one_second();//simulates the passage of one minute
		void start_taking_off();// calculates the time left to takeoff
		bool is_busy() const { return (take_off_time_left > 0); }	//checks if the runway is busy
	};

	class plane_landing
	{
	private:
		double time_to_land;// total time for landing
		double landing_time_left;// time left to land

	public:
		plane_landing(double time);
		void one_second();//simulates the passage of one minute
		void start_landing(); // calculates the time left to land
		bool is_busy() const { return (landing_time_left > 0); } //checks if the runway is busy
	};

	class boolsourceT {
	private:
		double prob1;// Probability of query( ) returning true
	public:
		boolsourceT(double time, double totaltime);
		bool query()const; // gets the probability
	};

	class boolsourceL {
	private:
		double prob1; //Probability of query() returning true
     public:
	boolsourceL(double time, double totaltime);
	bool query()const; // gets the probability
	};

	class averager_takeoff
	{
	public:
		averager_takeoff();
		void next_number(double value); // calculates the total time all planes took to takeoff and also counte the number of planes that tookoff
		size_t how_many_numbers() const { return count; }  // total number of planes that tookff
		double average() const;  // calculates the avaerage time it takes for a plane to takeoff
		
	private:
		size_t count; // How many numbers have been given to the averager
		double sum;  // Sum of all the numbers given to the averager
		
	};

	class averager_landing
	{
	public:
		averager_landing();
		void next_number(double value); // calculates the total time all planes took to land and also counte the number of planes that landed
		size_t how_many_numbers() const { return count; } // total number of planes landing 
		double average() const; // calculates the avaerage time it takes to land a plane that did not crash
		void crash();// checks if a plane has crashed
		double crashed();// counts the total number of planes that crashed
	private:
		size_t count; // How many numbers have been given to the averager
		double sum;   // Sum of all the numbers given to the averager
		double count1=0;// number of planes that crashed
	};
}


#endif 