#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// Jacob Fishel
// 1/30/2024
// jacobtfishel@gmail.com
// jacobfishel

#include "leftover_record.h"
#include <vector>
#include <unordered_map>

class LeftoverReport {

  public:
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);

  std::vector<std::string> MostCommonLeftover()const;
  std::vector<std::string> MostCostlyLeftoverProducingMeals()const;
  double TotalCostOfLeftover()const;
  std::vector<std::string> MostCommonLeftoverReasons()const;
  std::vector<std::string> MostCommonDisposalMechanisms()const;
  std::vector<std::string> SuggestLeftoverReductionStrategies()const;


  private:
  const std::vector<LeftoverRecord> &leftover_records_;
  std::vector<std::string> most_common_leftover_;
  std::vector<std::string> most_costly_leftover_producing_meals_;
  double total_cost_of_leftovers_;
  std::vector<std::string> most_common_leftover_reasons_;
  std::vector<std::string> most_common_disposal_mechanisms_;
  std::vector<std::string> suggested_strategies_to_reduce_leftovers_;
};
#endif
