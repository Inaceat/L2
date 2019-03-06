#include "stdafx.h"


#include "TrainStationSchedule.hpp"


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