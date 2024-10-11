// Jacob Fishel
// 1/30/2024
// jacobtfishel@gmail.com
// jacobfishel

#include "leftover_tracker.h"

//Leftover_tracker class inplementation

bool LeftoverTracker::AddRecord(const LeftoverRecord& record) { 
    for(LeftoverRecord x : leftover_records_) {
      if (x.GetCost() == record.GetCost() &&
          x.GetDate() == record.GetDate() &&
          x.GetDisposalMechanism() == record.GetDisposalMechanism() &&
          x.GetFoodName() == record.GetFoodName() &&
          x.GetLeftOverReason() == record.GetLeftOverReason() &&
          x.GetQuantityInOz() == record.GetQuantityInOz() &&
          x.GetMeal() == record.GetMeal()) {
            return false;
          } 
    }
    leftover_records_.push_back(record); 
    return true;
}
  
bool LeftoverTracker::DeleteRecord(const LeftoverRecord &record) {
    // Iterate through the vector to find the record
    for (size_t i = 0; i < leftover_records_.size(); ++i) {
        const LeftoverRecord &x = leftover_records_[i]; // Get the current record

        // Check if the current record matches the provided record
        if (x.GetCost() == record.GetCost() &&
            x.GetDate() == record.GetDate() &&
            x.GetDisposalMechanism() == record.GetDisposalMechanism() &&
            x.GetFoodName() == record.GetFoodName() &&
            x.GetLeftOverReason() == record.GetLeftOverReason() &&
            x.GetQuantityInOz() == record.GetQuantityInOz() &&
            x.GetMeal() == record.GetMeal()) {
            
            leftover_records_.erase(leftover_records_.begin() + i); // Erase the record
            return true; // Record deleted successfully
        } 
    }
    return false; // Record not found
}