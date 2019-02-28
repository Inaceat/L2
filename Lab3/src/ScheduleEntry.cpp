#include "stdafx.h"

#include "ScheduleEntry.hpp"


ScheduleEntry::ScheduleEntry() :
	_departureTime(),
	_destinationArrivalTime()
{}

ScheduleEntry::ScheduleEntry(std::string trainID, std::string destinationStation, tm departureTime, tm destinationArrivalTime):
	
	_trainID(std::move(trainID)),

	_destinationStation(std::move(destinationStation)),
	
	_departureTime(mktime(&departureTime)),
	
	_destinationArrivalTime(mktime(&destinationArrivalTime))
{}



std::string ScheduleEntry::TrainID() const
{
	return _trainID;
}

std::string ScheduleEntry::DestinationStation() const
{
	return _destinationStation;
}



std::ostream& operator<<(std::ostream& ostream, const ScheduleEntry& entry)
{
	ostream << "Train ID: " << entry._trainID;
	ostream << "  Dest.: " << entry._destinationStation;
	ostream << "  Dep. time: " << entry._departureTime;
	ostream << "  Dest arrival: " << entry._destinationArrivalTime;

	ostream << std::endl;

	return ostream;
}


std::ifstream& operator>>(std::ifstream& ifstream, ScheduleEntry& entry)
{


	entry._trainID = "TestID";
	entry._destinationStation = "Nowhere";
	entry._departureTime = 15509007800;
	entry._destinationArrivalTime = 15509752800;

	return ifstream;
}


std::string ScheduleEntry::ToCsv() const
{
	std::string entryContent =
		_trainID + "," +
		_destinationStation + "," +
		std::to_string(_departureTime) + "," +
		std::to_string(_destinationArrivalTime);

	return entryContent;
}