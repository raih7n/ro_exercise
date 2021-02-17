// Copyright (c) Raih7n
// raihan17.business@gmail.com

#include <iostream>
#include <sstream>

#include "medication.h"

int main()
{
	Medication medic;
	if (!medic.Init()) {
		std::cin.get();
		return 0;
	}

	spdlog::set_pattern("[%^%l%$] %v");
	spdlog::info("Ro Rx parser started!");
	spdlog::info("Enter medications seperated by spaces");
	spdlog::info("Type exit to quit");

	while (true)
	{
		std::string input;
		std::cout << "> ";
		getline(std::cin, input);

		if (!input.compare("exit") || !input.compare("EXIT"))
			return 0;

		std::string buffer;
		std::stringstream sstream(input);
		while (sstream >> buffer)
			medic.addMedication(buffer);

		medic.testMedications();
	}

	std::cin.ignore(INT_MAX);
}

