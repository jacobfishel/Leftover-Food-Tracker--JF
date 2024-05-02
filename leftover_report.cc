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
// std::vector<std::string> LeftoverReport::MostCommonLeftover() const {
//     std::map<std::string, int> common_names;
//     for(const LeftoverRecord& record : leftover_records_) {
//         std::string name = record.GetFoodName();
//         common_names[name]++;
//     }
    
//     double max = 0;
//     for (const auto &pair : common_names) {
//         if (pair.second > max) {
//             max = pair.second;
//         }
//     }

//     std::vector<std::string> most_common_item;
//     for(const auto &pair : common_names) {
//         if(pair.second == max) {
//             most_common_item.push_back(pair.first);
//         }
//     }
    
//     return most_common_item;
// }

// std::vector<std::string> LeftoverReport::MostCommonLeftover() const{
// std::map<std::string, int> leftover_count;
// for (auto records : leftover_records_) {
//     std::string food_name = records.GetFoodName();
//     leftover_count[food_name]++;
// }
// int max = 0;
// for (auto loop : leftover_count) {
//     if (loop.second >= max) {
//         max = loop.second;
//     }
// }
// std::vector<std::string> most_common_items;
// for(auto loop : leftover_count) {
//     if (loop.second == max) {
// most_common_items.push_back(loop.first);
//     }
// }
// return most_common_items;


// };

std::vector<std::string> LeftoverReport::MostCommonLeftover() const {
    std::map<std::string, int> maps_common_leftover;
    int max = 0;
    for(const LeftoverRecord records : leftover_records_) {
        std::string common_leftover = records.GetFoodName();
        if(maps_common_leftover.count(common_leftover) == 0){
            maps_common_leftover.insert({common_leftover, 1});
            if(max < 1) {
                max = 1;
            }
        }else {
            maps_common_leftover[common_leftover]++;
            if (maps_common_leftover[common_leftover] > max) {
                max = maps_common_leftover[common_leftover];
            }
        }
    }
    std::vector<std::string> max_food;
    for(auto& it : maps_common_leftover) {
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
    for (const LeftoverRecord &record : leftover_records_) {
        if (record.GetLeftOverReason() == "Expired") {
            suggested_strategies.push_back("Donate before expiration");
            break;
        } else if (record.GetLeftOverReason() == "Tastes bad") {
            suggested_strategies.push_back("Buy less food");
            break;
        } else if (record.GetLeftOverReason() == "Too much left overs") {
            suggested_strategies.push_back("Buy less food");
            suggested_strategies.push_back("Cook small servings");
            break;
        }
    }
    for(int i = 0; i < suggested_strategies.size(); i++) {
        if(suggested_strategies.at(i) == "Expired") {
            break;
        } else {
        suggested_strategies.push_back("Recycle left overs");
        }
    }
    return suggested_strategies;
}