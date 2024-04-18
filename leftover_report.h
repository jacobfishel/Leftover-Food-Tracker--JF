#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel
#include "leftover_record.h"
#include <vector>
#include <unordered_map>

class LeftoverReport {
    // ======================= YOUR CODE HERE =======================
     // Write the LeftoverReport class here. Refer to your class design for the
     // member variables, constructors, and member functions needed.
     //
     // Note: mark functions that do not modify the member variables
     // as const, by writing `const` after the parameter list.
     // Pass objects by const reference when appropriate.
     // Remember that std::string is an object!
     // ===============================================================
  public:
   LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);

  std::vector<std::string> MostCommonLeftover(const std::vector<LeftoverRecord>& records) const ;
  std::vector<std::string> MostCostlyLeftoverProducingMeals(const std::vector<LeftoverRecord>& records) const ;
  double TotalCostOfLeftover(const std::vector<LeftoverRecord>& records) const;
  std::vector<std::string> MostCommonLeftoverReasons(const std::vector<LeftoverRecord>& records) const;
  std::vector<std::string> MostCommonDisposalMechanisms(const std::vector<LeftoverRecord>& records) const;
  std::vector<std::string> SuggestLeftoverReductionStrategies(const std::vector<LeftoverRecord>& records) const;

  
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
