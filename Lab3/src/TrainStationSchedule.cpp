#include "stdafx.h"


#include "TrainStationSchedule.hpp"



TrainStationSchedule::TrainStationSchedule(std::string fileName) :
	_scheduleEntries()
{
	tm dep{};
	tm arr{};

	_scheduleEntries.emplace_back("N0", "D0", dep, arr);
	_scheduleEntries.emplace_back("N1", "D0", dep, arr);
	_scheduleEntries.emplace_back("N2", "D0", dep, arr);
	_scheduleEntries.emplace_back("N3", "D0", dep, arr);
	_scheduleEntries.emplace_back("N4", "D0", dep, arr);
}



std::ostream& operator<<(std::ostream& ostream, const TrainStationSchedule& schedule)
{
	for (auto entry : schedule._scheduleEntries)
		ostream << entry;

	return ostream;
}

std::ifstream& operator>>(std::ifstream& ifstream, TrainStationSchedule& schedule)
{
	ScheduleEntry readEntry;


	while (ifstream.eof() == false)
	{
		ifstream >> readEntry;

		schedule._scheduleEntries.push_back(readEntry);
	}


	return ifstream;
}
TrainStationSchedule TrainStationSchedule::LoadFromFile(const std::string & fileName)
{
	return TrainStationSchedule();
}

void TrainStationSchedule::SaveAsCSV(const std::string& fileName) const
{

}

TrainStationSchedule TrainStationSchedule::Where(const std::function<bool(const ScheduleEntry&)>& selector) const
{
	return TrainStationSchedule();
}


void TrainStationSchedule::OrderBy(const std::function<int(const ScheduleEntry&, const ScheduleEntry&)>& comparer)
{

}