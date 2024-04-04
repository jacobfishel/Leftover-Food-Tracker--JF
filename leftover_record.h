#ifndef LEFTOVER_RECORD_H_
#define LEFTOVER_RECORD_H_

// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel

#include <iostream>

class LeftoverRecord {
    // ======================= YOUR CODE HERE =======================
    // Write the LeftoverRecord class here. Refer to your class design for the
    // member variables, constructors, and member functions needed.
    //
    // Note: mark functions that do not modify the member variables
    // as const, by writing `const` after the parameter list.
    // Pass objects by const reference when appropriate.
    // Remember that std::string is an object!
    // ===============================================================
  public:
  LeftoverRecord() = default;
  LeftoverRecord(std::string date, std::string meal, std::string food_name,
  double quantity, std::string leftover_reason, std::string disposal_mechanism,
  double cost) : date_(date), meal_(meal), food_name_(food_name), quantity_(quantity),
                 leftover_reason_(leftover_reason), disposal_mechanism_(disposal_mechanism),
                 cost_(cost) {}

  std::string GetDate() { return date_; }
  std::string GetMeal() { return meal_; }
  std::string GetFoodName() { return food_name_; }
  std::string GetLeftOverReason() { return leftover_reason_; }
  std::string GetDisposalMechanism() { return disposal_mechanism_; }
  double GetQuantity() { return quantity_; }
  double GetCost() { return cost_; }
  
  void SetDate(std::string date) { date_ = date; }
  void SetMeal(std::string meal) { meal_ = meal; }
  void SetFoodName(std::string food_name) { food_name_ = food_name; }
  void SetLeftOverReason(std::string leftover_reason) { leftover_reason_ = leftover_reason; }
  void SetDisposalMechanism(std::string disposal_mechanism) { disposal_mechanism_ = disposal_mechanism; }
  void SetQuantity(double quantity) { quantity_ = quantity; }
  void SetCost(double cost) {cost_ = cost; }

  private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double quantity_;
  std::string leftover_reason_;
  std::string disposal_mechanism_;
  double cost_;

};

#endif
