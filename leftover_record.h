#ifndef LEFTOVER_RECORD_H_
#define LEFTOVER_RECORD_H_

// Jacob Fishel
// 1/30/2024
// jacobtfishel@gmail.com
// jacobfishel

#include <iostream>

class LeftoverRecord {
   
  public:
  LeftoverRecord() = default;
  LeftoverRecord(std::string date, std::string meal, std::string food_name,
  double qty_in_oz, std::string leftover_reason, std::string disposal_mechanism,
  double cost) : date_(date), meal_(meal), food_name_(food_name), qty_in_oz_(qty_in_oz),
                 leftover_reason_(leftover_reason), disposal_mechanism_(disposal_mechanism),
                 cost_(cost) {}

  const std::string& GetDate()const { return date_; }
  const std::string& GetMeal()const { return meal_; }
  const std::string& GetFoodName()const { return food_name_; }
  const std::string& GetLeftOverReason()const { return leftover_reason_; }
  const std::string& GetDisposalMechanism()const { return disposal_mechanism_; }
  double GetQuantityInOz()const { return qty_in_oz_; }
  double GetCost()const { return cost_; }
  
  void SetDate(const std::string& date) { date_ = date; }
  void SetMeal(const std::string& meal) { meal_ = meal; }
  void SetFoodName(const std::string& food_name) { food_name_ = food_name; }
  void SetLeftOverReason(const std::string& leftover_reason) { leftover_reason_ = leftover_reason; }
  void SetDisposalMechanism(const std::string& disposal_mechanism) { disposal_mechanism_ = disposal_mechanism; }
  void SetQuantityInOz(double qty_in_oz) { qty_in_oz_ = qty_in_oz; }
  void SetCost(double cost) {cost_ = cost; }

  private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double qty_in_oz_;
  std::string leftover_reason_;
  std::string disposal_mechanism_;
  double cost_;
};

#endif
