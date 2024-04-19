#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_

// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel

#include "leftover_record.h"
#include "leftover_report.h"

class LeftoverTracker {
    // ======================= YOUR CODE HERE =======================
      // Write the LeftoverTracker class here. Refer to your class design for the
      // member variables, constructors, and member functions needed.
      //
      // Note: mark functions that do not modify the member variables
      // as const, by writing `const` after the parameter list.
      // Pass objects by const reference when appropriate.
      // Remember that std::string is an object!
      // ===============================================================
  public:

  bool AddRecord(const LeftoverRecord& record);
  const std::vector<LeftoverRecord>& GetRecords() const { return leftover_records_; };
  LeftoverReport GetLeftoverReport() const {
  return LeftoverReport(leftover_records_);
  };

  private:
  std::vector<LeftoverRecord> leftover_records_;
};

#endif
