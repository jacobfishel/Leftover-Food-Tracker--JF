#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// Jacob Fishel
// CPSC 121L-11
// 1/30/2024
// jacobfishel@csu.fullerton.edu
// jacobfishel
#include "leftover_record.h"

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
  LeftoverReport(const LeftoverRecord& records) : records_(records) {}

  private:
  LeftoverRecord records_;

};

#endif
