/*OOP345 WS02 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: timedtask
File: timedtask.h*/
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_EVENTS = 10;
	class TimedTask {
		int nTask{ 0 };
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct Task {
			std::string msg{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		}events[MAX_EVENTS];
	public:
		void startClock();
		void stopClock();
		void addTask(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedTask& task);
	};

}
#endif