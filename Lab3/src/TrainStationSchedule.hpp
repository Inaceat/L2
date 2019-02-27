#pragma once

#include <vector>

#include "ScheduleEntry.hpp"
#include <functional>


class TrainStationSchedule
{
	TrainStationSchedule(std::string fileName)
	{
		
	}


	friend std::ostream& operator<<(std::ostream& ostream, const TrainStationSchedule& item);
	
	friend std::ifstream& operator>>(std::ifstream& ifstream, TrainStationSchedule& item);
	

	void Save(const std::string& fileName) const;

	TrainStationSchedule SelectWhere(const std::function<bool(const ScheduleEntry&)>& selector) const;

	void Sort(const std::function<int(const ScheduleEntry&, const ScheduleEntry&)>& comparer);

private:
	std::vector<ScheduleEntry> _scheduleEntries;
};
