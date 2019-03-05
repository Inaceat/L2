#include "stdafx.h"

#include "ScheduleEntry.hpp"
#include <regex>


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

ScheduleEntry ScheduleEntry::TryParseCsv(std::string csvString)
{
	std::regex pattern(
		"^"							//Correct ScheduleEntry data is
		"([^,]+?),([^,]+?),"		//[one or more non-comma symbols followed by comma] twice - trainID & dest. station
		"(\d{1,19}?),(\d{1,19}?)$"  //[one or more digit] twice - departure and arrival time
	);

	if (false == std::regex_match(csvString, pattern))
		throw std::exception("Wrong Schedule Entry format!");


	std::sregex_token_iterator currentMatch(csvString.begin(), csvString.end(), pattern, { 1, 2, 3, 4 });


	ScheduleEntry result;
	result._trainID = *currentMatch;
	result._destinationStation = ;
	result._departureTime = 0;
	result._destinationArrivalTime = 0;

	return result;
}