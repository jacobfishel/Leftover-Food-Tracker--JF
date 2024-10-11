// Jacob Fishel
// 1/30/2024
// jacobtfishel@gmail.com
// jacobfishel

#include "leftover_report.h"
#include <map>
#include <vector>

LeftoverReport::LeftoverReport(const std::vector<LeftoverRecord> &leftover_records)
  : leftover_records_(leftover_records), total_cost_of_leftovers_(0.0) {
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
            // Update max if this is the first occurrence
            max = std::max(max, 1);
        } else {
            maps_common_leftover[common_leftover]++;
            // Update max only if there are more than one records
            if (leftover_records_.size() > 1) {
                max = std::max(max, maps_common_leftover[common_leftover]);
            }
        }
    }

    // find most occurence
    std::vector<std::string> max_food;
    for (const auto& it : maps_common_leftover) {
        if (it.second == max) {
            max_food.push_back(it.first);
        }
    }
    
    return max_food;
}

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals() const {
    std::map<std::string, double> meal_and_cost;
    for(const LeftoverRecord& record : leftover_records_) {
        double cost = record.GetCost();
        std::string name = record.GetMeal();
        meal_and_cost[name] += cost;
    }

    double max = 0;
    for (const auto &pair : meal_and_cost) {
        if (pair.second > max) {
            max = pair.second;
        }
    }

    std::vector<std::string> most_costly_meals;
    for(const auto &pair : meal_and_cost) {
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
    std::vector<std::string> vec_strat;
    bool donate = false;
    bool buy_less_food = false;
    bool cook_small = false;
    bool recycle = true;
    std::vector<std::string> reason_vector = MostCommonLeftoverReasons();
    for(std::string reasons : MostCommonLeftoverReasons()) {
        if (reasons == "Expired") {
            donate = true;
            recycle = false;
        }
        if  (reasons == "Tastes bad") {
            buy_less_food = true;
        }
        if (reasons == "Too much left overs") {
            buy_less_food = true;
            cook_small = true;
        }
    }
    if (reason_vector.empty()) {
        recycle = false;
    }
    if (donate) {
        vec_strat.push_back("Donate before expiration");
    }
    if (buy_less_food) {
        vec_strat.push_back("Buy less food");
    }
    if(cook_small) {
        vec_strat.push_back("Cook small servings");
    }
    if (recycle) {
        vec_strat.push_back("Recycle left overs");
    }
    if (vec_strat.empty()) {
        vec_strat.clear();
    }
    return vec_strat;
}