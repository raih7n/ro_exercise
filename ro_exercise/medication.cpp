// Copyright (c) Raih7n
// raihan17.business@gmail.com

#include "medication.h"
#include <iostream>

bool Medication::Init()
{
    std::fstream ifs("interactions.json");
    if (!ifs.good()) {
        spdlog::error("Couldn't parse interactions file, is it in the right place?");
        return false;
    }

    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::ParseResult result = m_rxJson.ParseStream(isw);
    if (!result) {
        spdlog::error("Error while parsing interactions file, is this the right file?");
        return false;
    }

    return true;
}

void Medication::addMedication(std::string medication)
{
    m_medications.push_back(medication);
}

void Medication::testMedications()
{
    // check for duplicates
    std::sort(m_medications.begin(), m_medications.end());
    m_medications.erase(std::unique(m_medications.begin(), m_medications.end()), m_medications.end());

    // check for conflicts with current medication
    std::vector<conflict_t> conflicts;
    for (auto medication : m_medications)
        checkConflict(medication, conflicts);
    
    // check for duplicates
    conflicts.erase(std::unique(conflicts.begin(), conflicts.end(), [](conflict_t u1, conflict_t u2) {
        return u1.description.compare(u2.description) == 0;
        }), conflicts.end());

    if (conflicts.empty()) {
        spdlog::info("No conflicts detected");
        return;
    }

    spdlog::warn("{} conflict(s) detected!", conflicts.size());
    for (auto conflict : conflicts)
    {
        spdlog::warn("{} will have a {} interaction with {}. {}",
            conflict.drug1.c_str(), conflict.severity.c_str(),
            conflict.drug2.c_str(), conflict.description.c_str());
    }
}

bool Medication::checkConflict(std::string medication, std::vector<conflict_t>& conflicts)
{
	// no medications, no conflicts
    if (m_medications.empty())
        return false;

    // look for a potential conflict in our existing meds
    for (auto curmed : m_medications)
    {
        auto arr = m_rxJson.GetArray();

        for (auto& elm_it : arr)
        {
            auto drug_it = elm_it.FindMember("drugs");
            auto drug_data = drug_it->value.GetArray();
            std::string drug1 = drug_data[0].GetString();
            std::string drug2 = drug_data[1].GetString();

            if ((!drug1.compare(medication) && !drug2.compare(curmed)) ||
                (!drug2.compare(medication) && !drug1.compare(curmed)))
            {
                // we have a conflict
                conflict_t conflict;
                conflict.severity = elm_it.FindMember("severity")->value.GetString();
                conflict.description = elm_it.FindMember("description")->value.GetString();
                conflict.drug1 = drug1;
                conflict.drug2 = drug2;
                conflicts.push_back(conflict);
            }
        }
    }

    return !conflicts.empty();
}
