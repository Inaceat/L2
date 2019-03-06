#include "stdafx.h"


#include <sstream>
#include <regex>


#include "ScheduleEntry.hpp"



time_t ParseUnixTime(const std::string& str)
{
	std::stringstream stream;
	
	stream << str;


	time_t result;

	stream >> result;

	return result;
}


ScheduleEntry ScheduleEntry::TryParseCsv(std::string csvString)
{
	std::regex pattern(
		"^"							//Correct ScheduleEntry data is
		"([^,]+?),([^,]+?),"		//[one or more non-comma symbols followed by comma] twice - trainID & dest. station
		"(\\d{1,19}?),(\\d{1,19}?)$"  //[one or more digit] twice - departure and arrival time
	);

	if (false == std::regex_match(csvString, pattern))
		throw std::exception("Wrong Schedule Entry format!");


	std::sregex_token_iterator currentMatch(csvString.begin(), csvString.end(), pattern, { 1, 2, 3, 4 });


	ScheduleEntry result {};

	result._trainID = *currentMatch++;
	result._destinationStation = *currentMatch++;
	result._departureTime = ParseUnixTime(*currentMatch++);
	result._destinationArrivalTime = ParseUnixTime(*currentMatch);

	return result;
}

std::ifstream& operator>>(std::ifstream& ifstream, ScheduleEntry& entry)
{
	std::string inputBuffer;

	std::getline(ifstream, inputBuffer, '\n');


	entry = ScheduleEntry::TryParseCsv(inputBuffer);


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



std::string ScheduleEntry::TrainID() const
{
	return _trainID;
}

std::string ScheduleEntry::DestinationStation() const
{
	return _destinationStation;
}

time_t ScheduleEntry::DepartureTime() const
{
	return _departureTime;
}

time_t ScheduleEntry::DestinationArrivalTime() const
{
	return _destinationArrivalTime;
}
