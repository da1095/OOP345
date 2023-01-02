/*OOP345 WS02 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: timedtask
File: timedtask.cpp*/

#include <iomanip>
#include "TimedTask.h"

namespace sdds
{

	void TimedTask::startClock()
	{
		ts = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock() {
		te = std::chrono::steady_clock::now();
	}



	void TimedTask::addTask(const char* msg) {
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
		if (nTask < MAX_EVENTS)
		{
			this->events[nTask].msg = msg;
			this->events[nTask].units = "nanoseconds";
			this->events[nTask].duration = ms;
			nTask++;
		}
	}

	std::ostream& operator<<(std::ostream& out, const TimedTask& task)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < task.nTask; i++)

			out << std::setw(21) << std::left
			<< task.events[i].msg << ' ' << std::setw(13) << std::right
			<< task.events[i].duration.count() << ' '
			<< task.events[i].units << '\n';
		out << "--------------------------\n";
		return out;

	}

}