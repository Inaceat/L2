#include "stdafx.h"


#include "TrainStationSchedule.hpp"



int main()
{
	const std::string inputFile = "data/schedule.txt";


	auto schedule = TrainStationSchedule::LoadFromCSVFile(inputFile);


	std::cout << "Initial schedule:" << std::endl;
	schedule.Show();
	std::cout << std::endl;


	std::cout << "Departure time ascending sorted:" << std::endl;

	schedule.OrderBy(
		[]
		(const ScheduleEntry& left, const ScheduleEntry& right) -> bool
		{
			return left.DepartureTime() < right.DepartureTime();
		}
	).Show();

	std::cout << std::endl;



	std::string destinationName = "Nowhere";

	auto nowhereTrains = schedule.Where(
		[destinationName]
		(const ScheduleEntry& entry)
		{
			return destinationName == entry.DestinationStation();
		}
	);

	std::cout << "Trains to \""<< destinationName <<"\" station:" << std::endl;
	nowhereTrains.Show();
	std::cout << std::endl;

	const std::string nowhereTrainFileName = "data/nowhere.txt";
	nowhereTrains.SaveAsCSV(nowhereTrainFileName);

    return 0;
}