// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel

#include "leftover_tracker.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_tracker.h), only
// if you didn't implement them inline within leftover_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverTracker
// class.
// ===================================================================
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