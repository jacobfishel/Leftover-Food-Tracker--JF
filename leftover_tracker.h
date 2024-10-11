#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_

// Jacob Fishel
// 1/30/2024
// jacobtfishel@gmail.com
// jacobfishel

#include "leftover_record.h"
#include "leftover_report.h"

class LeftoverTracker {
  public:

  bool AddRecord(const LeftoverRecord& record);
  const std::vector<LeftoverRecord>& GetRecords() const { return leftover_records_; };
  LeftoverReport GetLeftoverReport() const {
    return LeftoverReport(leftover_records_);
  };
  bool DeleteRecord(const LeftoverRecord &record);

  private:
  std::vector<LeftoverRecord> leftover_records_;
};

#endif
