#pragma once

#include <string>
#include <ctime>


class ScheduleEntry
{
public:
	ScheduleEntry(std::string trainID,std::string destinationStation, tm departureTime,	tm destinationArrivalTime):
		_trainID(std::move(trainID)),
		_destinationStation(std::move(destinationStation))
	{
		_departureTime = mktime(&departureTime);
		_destinationArrivalTime = mktime(&destinationArrivalTime);
	}


	std::string TrainID() const
	{
		return _trainID;
	}

	std::string DestinationStation() const
	{
		return _destinationStation;
	}






private:
	std::string _trainID;
	std::string _destinationStation;
	time_t _departureTime;
	time_t _destinationArrivalTime;
};
