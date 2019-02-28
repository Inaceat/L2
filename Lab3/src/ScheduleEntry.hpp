#pragma once

#include <string>
#include <ctime>


class ScheduleEntry
{
public:
	ScheduleEntry();

	ScheduleEntry(std::string trainID, std::string destinationStation, tm departureTime, tm destinationArrivalTime);


	std::string TrainID() const;

	std::string DestinationStation() const;


	friend std::ostream& operator<<(std::ostream& ostream, const ScheduleEntry& entry);

	friend std::ifstream& operator>>(std::ifstream& ifstream, ScheduleEntry& entry);

	std::string ToCsv() const;



private:
	std::string _trainID;
	std::string _destinationStation;
	time_t _departureTime;
	time_t _destinationArrivalTime;
};