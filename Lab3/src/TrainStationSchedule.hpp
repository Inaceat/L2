#pragma once

#include <vector>
#include <functional>


#include "ScheduleEntry.hpp"


class TrainStationSchedule
{
public:

	static TrainStationSchedule LoadFromFile(const std::string& fileName);

	void SaveAsCSV(const std::string& fileName) const;
	

	TrainStationSchedule Where(const std::function<bool(const ScheduleEntry&)>& selector) const;

	void OrderBy(const std::function<int(const ScheduleEntry&, const ScheduleEntry&)>& comparer);



private:
	std::vector<ScheduleEntry> _scheduleEntries{};
};
