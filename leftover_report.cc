// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel

#include "leftover_report.h"
#include <map>
#include <vector>
// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_report.h), only
// if you didn't implement them inline within leftover_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverReport
// class.
// ===================================================================
std::vector<std::string> LeftoverReport::MostCommonLeftover(const std::vector<LeftoverRecord>& records) const{
  std::map<std::string, int> common_names;
  for(const LeftoverRecord& record : records) {
    std::string name = record.GetFoodName();
    common_names[name]++;
  }
  int max = 0;
  std::string most_common;
  for (std::pair<std::string, int> check : common_names) {
    if (check.second > max) {
      max = check.second;
    }
  }
  std::vector<std::string> most_common_item;
  for(const auto pair : common_names) {
    if(pair.second == max) {
      most_common_item.push_back(pair.first);
    }
  }
  return most_common_item;
  }

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals(const std::vector<LeftoverRecord>& records) const {
  std::map<std::string, int> food_and_cost;
  for(const LeftoverRecord& record : records) {
    double cost = record.GetCost();
    std::string name = record.GetFoodName();
    food_and_cost[name] = cost;
  }
  int max = 0;
  std::string most_costly;
  for (std::pair<std::string, int> check : food_and_cost) {
    if (check.second > max) {
      max = check.second;
      most_costly = check.first;
    }
  }
  std::vector<std::string> most_costly_meals;
  for(const auto pair : food_and_cost) {
    if(pair.second == max) {
      most_costly_meals.push_back(pair.first);
    }
  }
  return most_costly_meals;
  }

double LeftoverReport::TotalCostOfLeftover(const std::vector<LeftoverRecord>& records) const{
  double total_cost = 0;
  for(LeftoverRecord record : records) {
    total_cost += record.GetCost();
  }

return total_cost;
}

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons(const std::vector<LeftoverRecord>& records) const {
std::map<std::string, int> common_reason;
  for(const LeftoverRecord& record : records) {
    std::string reason = record.GetLeftOverReason();
    common_reason[reason]++;
  }
  int max = 0;
  std::string most_common;
  for (std::pair<std::string, int> check : common_reason) {
    if (check.second > max) {
      max = check.second;
    }
  }
  std::vector<std::string> most_common_reason;
  for(const auto pair : common_reason) {
    if(pair.second == max) {
      most_common_reason.push_back(pair.first);
    }
  }
  return most_common_reason;
  }

std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms(const std::vector<LeftoverRecord>& records) const {
std::map<std::string, int> disposal_mechanism;
  for(const LeftoverRecord& record : records) {
    std::string reason = record.GetDisposalMechanism();
    disposal_mechanism[reason]++;
  }
  int max = 0;
  std::string most_common;
  for (std::pair<std::string, int> check : disposal_mechanism) {
    if (check.second > max) {
      max = check.second;
    }
  }
  std::vector<std::string> most_common_disposal_mechanisms;
  for(const auto pair : disposal_mechanism) {
    if(pair.second == max) {
      most_common_disposal_mechanisms.push_back(pair.first);
    }
  }
  return most_common_disposal_mechanisms;
  }

  std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies(const std::vector<LeftoverRecord>& records) const {
    std::vector<std::string> suggested_strategies;
    for (LeftoverRecord leftover_reason : records) {
      if (leftover_reason.GetLeftOverReason() == "Expired") {
        suggested_strategies.push_back("Donate before expiration");
      } else if (leftover_reason.GetLeftOverReason() == "Tastes bad") {
        suggested_strategies.push_back("Buy less food");
        suggested_strategies.push_back("Recycle leftovers");
      } else if (leftover_reason.GetLeftOverReason() == "Too much left overs") {
        suggested_strategies.push_back("Buy less food");
        suggested_strategies.push_back("Cook small servings");
        suggested_strategies.push_back("Recycle leftovers");
    }
    }
return suggested_strategies;
  
  }






  