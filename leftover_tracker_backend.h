#ifndef LEFTOVER_TRACKER_BACKEND_H_
#define LEFTOVER_TRACKER_BACKEND_H_

#include <string>

#include "leftover_tracker.h"
#include "server_utils/crow_all.h"

// A class to represent the leftover tracker backend. This class receives
// and returns CROW framework compatible objects. So when implementing
// classes to represent concepts like leftover record and leftover
//  report etc, convert those objects to/from CROW
// objects. 
class LeftoverTrackerBackend {
 public:
  LeftoverTrackerBackend(const std::string &leftover_records_filepath)
      : leftover_records_filepath_{leftover_records_filepath} {}

  // Reads the leftover records from the file at
  // leftover_records_filepath_, and loads those in memory. If the file is
  // empty, it is a no-op. Returns true if the file was read successfully, else
  // returns false.
  //
  
  bool LoadRecordsFromJSONFile();

  // Writes the leftover records from the memory to a JSON file at path
  // leftover_records_filepath_. Returns true if the file was written
  // successfully, else returns false.
  bool WriteRecordsToJSONFile() const;

  // Add the given leftovere record (in the query_string) to the memory.
  crow::json::wvalue AddRecord(const crow::query_string &query_string);

  // Delete the given leftover record (in the query_string) from the memory.
  crow::json::wvalue DeleteRecord(const crow::query_string &query_string);

  // Returns all the leftover records that are stored in the memory.
  crow::json::wvalue GetRecords() const;

  // Generate a report based on all the leftover records in the memory.
  crow::json::wvalue GetLeftoverReport() const;

 private:
  // File path of the file that stores all the leftover records in JSON
  // format.
  const std::string &leftover_records_filepath_;
  // A top level class object to leftovers.
  LeftoverTracker leftover_tracker_object_{};
};
#endif
