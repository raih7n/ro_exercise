// Copyright (c) Raih7n
// raihan17.business@gmail.com

#pragma once

#include <fstream>
#include <vector>
#include <set>

#include <spdlog/spdlog.h>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>


struct conflict_t
{
	std::string drug1;
	std::string drug2;
	std::string severity;
	std::string description;

	inline bool operator<(const conflict_t& conf) const { return description < conf.description; }
};

class Medication
{
public:

	/// <summary>
	/// Parses the interactions json
	/// </summary>
	/// <returns>True if parsing is sucessful</returns>
	bool Init();

	/// <summary>
	/// Adds a medication to the list
	/// </summary>
	/// <param name="medication">medication to add</param>
	void addMedication(std::string medication);

	/// <summary>
	/// Tests a list of medications for conflicts and prints them
	/// </summary>
	/// <param name="medications">vector of medicines</param>
	void testMedications();

	/// <summary>
	/// Reads the interactions json and checks for conflicts 
	/// </summary>
	/// <param name="medication">Medication that being checked</param>
	/// <param name="conflict">resulting conflict data</param>
	/// <returns>True if a conflict is detected</returns>
	bool checkConflict(std::string medication, std::set<conflict_t>& conflict);

private:
	std::vector<std::string> m_medications;
	rapidjson::Document m_rxJson;
};