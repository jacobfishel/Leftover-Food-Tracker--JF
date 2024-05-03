// // Jacob Fishel
// // CPSC 121L-11
// // 1/30/2024
// // jacobfishel@csu.fullerton.edu
// // jacobfishel

#include "leftover_report.h"
#include <map>
#include <vector>
// // ========================= YOUR CODE HERE =========================
// // This implementation file is where you should implement
// // the member functions declared in the header (leftover_report.h), only
// if you didn't implement them inline within leftover_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverReport
// class.
// ===================================================================
LeftoverReport::LeftoverReport(const std::vector<LeftoverRecord> &leftover_records)
  : leftover_records_(leftover_records), total_cost_of_leftovers_(0.0){
    if (leftover_records.empty()) {
        return;
    }
     }

std::vector<std::string> LeftoverReport::MostCommonLeftover() const {
    std::map<std::string, int> maps_common_leftover;
    int max = 0;
    
    // Count frequencies and find maximum frequency
    for (const LeftoverRecord& record : leftover_records_) {
        const std::string& common_leftover = record.GetFoodName();
        if (maps_common_leftover.count(common_leftover) == 0) {
            maps_common_leftover[common_leftover] = 1;
        } else {
            maps_common_leftover[common_leftover]++;
            max = std::max(max, maps_common_leftover[common_leftover]);
        }
    }

    // Find food items with maximum frequency
    std::vector<std::string> max_food;
    for (const auto& it : maps_common_leftover) {
        if (it.second == max) {
            max_food.push_back(it.first);
        }
    }
    
    return max_food;
}

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals() const {
    std::map<std::string, double> food_and_cost;
    for(const LeftoverRecord& record : leftover_records_) {
        double cost = record.GetCost();
        std::string name = record.GetFoodName();
        food_and_cost[name] += cost;
    }

    double max = 0;
    for (const auto &pair : food_and_cost) {
        if (pair.second > max) {
            max = pair.second;
        }
    }

    std::vector<std::string> most_costly_meals;
    for(const auto &pair : food_and_cost) {
        if(pair.second == max) {
            most_costly_meals.push_back(pair.first);
        }
    }

    return most_costly_meals;
}

double LeftoverReport::TotalCostOfLeftover() const{
    double total_cost = 0.0;
    for(const LeftoverRecord& record : leftover_records_) {
        total_cost += record.GetCost();
    }

    return total_cost;
}

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons() const {
    std::map<std::string, int> common_reason;
    for(const LeftoverRecord& record : leftover_records_) {
        std::string reason = record.GetLeftOverReason();
        common_reason[reason]++;
    }

    double max = 0;
    for (const auto &pair : common_reason) {
        if (pair.second > max) {
            max = pair.second;
        }
    }

    std::vector<std::string> most_common_reason;
    for(const auto &pair : common_reason) {
        if(pair.second == max) {
            most_common_reason.push_back(pair.first);
        }
    }

    return most_common_reason;
}

std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms() const {
    std::map<std::string, int> disposal_mechanism;
    for(const LeftoverRecord& record : leftover_records_) {
        std::string reason = record.GetDisposalMechanism();
        disposal_mechanism[reason]++;
    }

    double max = 0;
    for (const auto &pair : disposal_mechanism) {
        if (pair.second > max) {
            max = pair.second;
        }
    }

    std::vector<std::string> most_common_disposal_mechanisms;
    for(const auto &pair : disposal_mechanism) {
        if(pair.second == max) {
            most_common_disposal_mechanisms.push_back(pair.first);
        }
    }

    return most_common_disposal_mechanisms;
}

std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies() const {
    std::vector<std::string> suggested_strategies;
    bool has_expired = false;

    for (const LeftoverRecord &record : leftover_records_) {
        if (record.GetLeftOverReason() == "Expired") {
            has_expired = true;
            suggested_strategies.push_back("Donate before expiration");
        } else if (record.GetLeftOverReason() == "Tastes bad") {
            suggested_strategies.push_back("Buy less food");
        } else if (record.GetLeftOverReason() == "Too much leftovers") {
            suggested_strategies.push_back("Buy less food");
            suggested_strategies.push_back("Cook smaller servings");
        }
    }

    if (!has_expired) {
        suggested_strategies.push_back("Recycle leftovers");
    }

    return suggested_strategies;
}