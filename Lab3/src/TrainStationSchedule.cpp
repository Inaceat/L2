#include "stdafx.h"

#include <algorithm>
#include <ctime>

#include "TrainStationSchedule.hpp"


TrainStationSchedule TrainStationSchedule::LoadFromCSVFile(const std::string& fileName)
{
	TrainStationSchedule readSchedule {};


	std::ifstream fileStream(fileName);

	

	ScheduleEntry readEntry {};
	
	while (EOF != fileStream.peek())
	{
		fileStream >> readEntry;

		readSchedule._scheduleEntries.push_back(readEntry);
	}


	return readSchedule;
}

void TrainStationSchedule::SaveAsCSV(const std::string& fileName) const
{
	std::ofstream writeStream(fileName, std::fstream::out);


	for (auto entry : _scheduleEntries)
		writeStream << entry.ToCsv() << '\n';


	writeStream.close();
}


std::string UnixTimeToString(time_t unixTime, std::string format)
{
	tm time {};
	gmtime_s(&time, &unixTime);


	const auto timeBuffer = new char[50];

	strftime(timeBuffer, 50, format.c_str(), &time);


	std::string result(timeBuffer);


	delete[] timeBuffer;

	return result;
}

void TrainStationSchedule::Show() const
{
	std::cout << std::setw(5) << "No";
	std::cout << std::setw(15) << "Destination";
	std::cout << std::setw(25) << "Departure";
	std::cout << std::setw(25) << "Dest. arrival";
	std::cout << std::endl;

	for (auto entry : _scheduleEntries)
	{
		std::cout << std::setw(5) << entry.TrainID();
		std::cout << std::setw(15) << entry.DestinationStation();
		std::cout << std::setw(25) << UnixTimeToString(entry.DepartureTime(), "%d/%m/%y %R");
		std::cout << std::setw(25) << UnixTimeToString(entry.DestinationArrivalTime(), "%d/%m/%y %R");
		std::cout << std::endl;
	}
}


TrainStationSchedule TrainStationSchedule::Where(const std::function<bool(const ScheduleEntry&)>& selector) const
{
	TrainStationSchedule result {};

	for (auto entry : _scheduleEntries)
		if (true == selector(entry))
			result._scheduleEntries.push_back(entry);

	return result;
}

TrainStationSchedule TrainStationSchedule::OrderBy(const std::function<bool(const ScheduleEntry&, const ScheduleEntry&)>& isRightOrderComparer) const
{
	TrainStationSchedule result(*this);

	std::sort(result._scheduleEntries.begin(), result._scheduleEntries.end(), isRightOrderComparer);

	return result;
}
