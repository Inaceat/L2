#pragma once

#include <string>
#include <ctime>


class ScheduleEntry
{
public:

	friend std::ifstream& operator>>(std::ifstream& ifstream, ScheduleEntry& entry);


	
	std::string ToCsv() const;


	std::string TrainID() const;
	std::string DestinationStation() const;
	time_t DepartureTime() const;
	time_t DestinationArrivalTime() const;


private:
	static ScheduleEntry TryParseCsv(std::string csvString);


private:
	std::string _trainID;
	std::string _destinationStation;
	time_t _departureTime;
	time_t _destinationArrivalTime;
};