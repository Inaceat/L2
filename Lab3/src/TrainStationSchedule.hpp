#pragma once

#include <vector>
#include <functional>


#include "ScheduleEntry.hpp"


class TrainStationSchedule
{
public:

	static TrainStationSchedule LoadFromCSVFile(const std::string& fileName);

	void SaveAsCSV(const std::string& fileName) const;


	void Show() const;


	TrainStationSchedule Where(const std::function<bool(const ScheduleEntry&)>& selector) const;

	TrainStationSchedule OrderBy(const std::function<bool(const ScheduleEntry&, const ScheduleEntry&)>& isRightOrderComparer) const;



private:
	std::vector<ScheduleEntry> _scheduleEntries{};
};
