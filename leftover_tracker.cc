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
// bool LeftoverTracker::AddRecord(const LeftoverRecord& record) { 
//     for(LeftoverRecord x : leftover_records_) {
//       if (x.GetCost() == record.GetCost() &&
//           x.GetDate() == record.GetDate() &&
//           x.GetDisposalMechanism() == record.GetDisposalMechanism() &&
//           x.GetFoodName() == record.GetFoodName() &&
//           x.GetLeftOverReason() == record.GetLeftOverReason() &&
//           x.GetQuantityInOz() == record.GetQuantityInOz() &&
//           x.GetMeal() == record.GetMeal()) {
//             return false;
//           } 
//     }
//     leftover_records_.push_back(record); 
//     return true;
// }

bool LeftoverTracker::AddRecord(const LeftoverRecord& record) { 
    for(LeftoverRecord x : leftover_records_) {
      if (x.GetCost() != record.GetCost() ||
          x.GetDate() != record.GetDate() ||
          x.GetDisposalMechanism() != record.GetDisposalMechanism() ||
          x.GetFoodName() != record.GetFoodName() ||
          x.GetLeftOverReason() != record.GetLeftOverReason() ||
          x.GetQuantityInOz() != record.GetQuantityInOz() ||
          x.GetMeal() != record.GetMeal()) {
                leftover_records_.push_back(record); 
            return true;
          } 
          }
          return false;
    }

