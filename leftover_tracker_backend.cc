#include "leftover_tracker_backend.h"
#include "leftover_tracker.h"

#include <filesystem>

#include "leftover_record.h"
#include "leftover_report.h"
#include "server_utils/rapidjson/document.h"      // rapidjson's DOM-style API
#include "server_utils/rapidjson/prettywriter.h"  // for stringify JSON
#include "server_utils/rapidjson/rapidjson.h"
#include "server_utils/rapidjson/stringbuffer.h"  // wrapper of C stream for prettywriter as output
#include "server_utils/rapidjson/writer.h"

// Util function to convert a LeftoverRecord class object into a serialized
// JSON object.
void SerializeLeftoverRecordToJSON(
    const LeftoverRecord &record,
    rapidjson::Writer<rapidjson::StringBuffer> *writer) {
  writer->StartObject();

  writer->String("date_");
  std::string date;
  
  date = record.GetDate();
  writer->String(date.c_str());

  writer->String("meal_"); // DO NOT MODIFY
  std::string meal;
  
  meal = record.GetMeal();
  writer->String(meal.c_str());
  writer->String("food_name_"); // DO NOT MODIFY
  std::string food_name;
  
  food_name = record.GetFoodName();
  writer->String(food_name.c_str());
  writer->String("qty_in_oz_"); // DO NOT MODIFY
  double quantity;
  
  quantity = record.GetQuantityInOz();
  writer->Double(quantity);

  writer->String("leftover_reason_");// DO NOT MODIFY
  std::string leftover_reason;
  
  leftover_reason = record.GetLeftOverReason();
  writer->String(leftover_reason.c_str());

  writer->String("disposal_mechanism_"); // DO NOT MODIFY
  std::string disposal_mechanism;
  
  disposal_mechanism = record.GetDisposalMechanism();
  writer->String(disposal_mechanism.c_str());

  writer->String("cost_"); // DO NOT MODIFY
  double cost;
  
  cost = record.GetCost();
  writer->Double(cost);


  writer->EndObject();
}

// Util function to convert a serialized JSON object in to a LeftoverRecord
// class object.
LeftoverRecord DeserializeLeftoverRecordFromJSON(const rapidjson::Value &json_obj) {
  LeftoverRecord record;
  
    record.SetDate(json_obj["date_"].GetString());
 
    record.SetMeal(json_obj["meal_"].GetString());
   
    record.SetFoodName(json_obj["food_name_"].GetString());
    
    record.SetQuantityInOz(json_obj["qty_in_oz_"].GetDouble());
    
    record.SetLeftOverReason(json_obj["leftover_reason_"].GetString());
   
    record.SetDisposalMechanism(json_obj["disposal_mechanism_"].GetString());
    
     record.SetCost(json_obj["cost_"].GetDouble());
  return record;
}


crow::json::wvalue LeftoverRecordToCrowJSON(const LeftoverRecord &record) {
  crow::json::wvalue record_json({});
    
  std::string date;
 
  date = record.GetDate();
  record_json["date"] = date;

  std::string meal;
  
  meal = record.GetMeal();
  record_json["meal"] = meal;

  std::string food_name;
 
  food_name = record.GetFoodName();
  record_json["food_name"] = food_name;

  double quantity;
  
  quantity = record.GetQuantityInOz();
  record_json["qty_in_oz"] = quantity;

  std::string leftover_reason;
 
  leftover_reason = record.GetLeftOverReason();
  record_json["leftover_reason"] = leftover_reason;

  std::string disposal_mechanism;
  
  disposal_mechanism = record.GetDisposalMechanism();
  record_json["disposal_mechanism"] = disposal_mechanism;

  double cost;
 
  cost = record.GetCost();
  record_json["cost"] = cost;
    
  return record_json;
}

// Util function to convert a LeftoverReport object into a serialized
// JSON object.
crow::json::wvalue LeftoverReportToCrowJSON(const LeftoverReport &report) {
  crow::json::wvalue report_json({});

  std::vector<std::string> most_common_disposal_mechanisms{report.MostCommonDisposalMechanisms()};
  
  report_json["most_common_disposal_mechanism_"] = most_common_disposal_mechanisms;

  std::vector<std::string> most_common_leftovers{report.MostCommonLeftover()};
  
  report_json["most_common_leftover_"] = most_common_leftovers;

  std::vector<std::string> most_common_leftover_reasons{report.MostCommonLeftoverReasons()};
  
  report_json["most_common_leftover_reason_"] = most_common_leftover_reasons;

  std::vector<std::string> most_costly_leftover_producing_meals{report.MostCostlyLeftoverProducingMeals()};

  report_json["most_leftover_producing_meal_"] = most_costly_leftover_producing_meals;

  std::vector<std::string> suggested_strategies_to_reduce_leftover{report.SuggestLeftoverReductionStrategies()};
  
  report_json["suggested_strategies_to_reduce_leftover_"] = suggested_strategies_to_reduce_leftover;

  double total_cost_of_leftover = report.TotalCostOfLeftover();
  
  report_json["total_cost_of_leftover_"] = total_cost_of_leftover;
  return report_json;
}

// Util function to convert a crow query string into a LeftoverRecord class
// object.
LeftoverRecord QueryStringToLeftoverRecord(
    const crow::query_string &query_string) {
  LeftoverRecord record{};
    
  record.SetDate(query_string.get("date"));
  
  record.SetMeal(query_string.get("meal"));
  
  record.SetFoodName(query_string.get("food_name"));
  
  record.SetQuantityInOz(std::stod(query_string.get("qty_in_oz")));
  
  record.SetLeftOverReason(query_string.get("leftover_reason"));
  
  record.SetDisposalMechanism(query_string.get("disposal_mechanism"));
  
  record.SetCost(std::stod(query_string.get("cost")));
  return record;
}

bool LeftoverTrackerBackend::LoadRecordsFromJSONFile() {
  std::ifstream records_file{leftover_records_filepath_};
  if (!records_file.is_open()) {
    std::filesystem::remove(leftover_records_filepath_);
    return false;
  }

  std::stringstream buffer;
  buffer << records_file.rdbuf();

  std::string s = buffer.str();
  rapidjson::Document doc;

  if (s.empty()) {
    std::filesystem::remove(leftover_records_filepath_);
    return false;
  }

  std::string validJson(s);

  bool doc_parse_error = doc.Parse(validJson.c_str()).HasParseError();
  if (doc_parse_error || !doc.IsArray()) {
    std::filesystem::remove(leftover_records_filepath_);
    return false;
  }

  for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End();
       ++itr) {
      LeftoverRecord record = DeserializeLeftoverRecordFromJSON(*itr);
      leftover_tracker_object_.AddRecord(record);
  }

  records_file.close();
  return true;
}


bool LeftoverTrackerBackend::WriteRecordsToJSONFile() const {
  std::ofstream records_file{leftover_records_filepath_};
  // Get the records from leftover_tracker_, convert to JSON and
  // save to file.
  rapidjson::StringBuffer ss;
  rapidjson::Writer<rapidjson::StringBuffer> writer(ss);
  writer.StartArray();

  const std::vector<LeftoverRecord>& records = leftover_tracker_object_.GetRecords();
  
  for (LeftoverRecord record : records) {
    SerializeLeftoverRecordToJSON(record, &writer);
  }
  writer.EndArray();

  records_file << ss.GetString();

  records_file.flush();
  records_file.close();
  return true;
}

crow::json::wvalue LeftoverTrackerBackend::AddRecord(
    const crow::query_string &query_string) {
  LeftoverRecord record = QueryStringToLeftoverRecord(query_string);
  crow::json::wvalue status;
    
  bool add_result = false;

  add_result = leftover_tracker_object_.AddRecord(record);

  status["success"] = add_result;
    
  return status;
}

crow::json::wvalue LeftoverTrackerBackend::DeleteRecord(
    const crow::query_string &query_string) {
  LeftoverRecord record = QueryStringToLeftoverRecord(query_string);
  crow::json::wvalue status;
    
  bool delete_result = false;

  delete_result = leftover_tracker_object_.DeleteRecord(record);
  status["success"] = delete_result;
    
  return status;
}

crow::json::wvalue LeftoverTrackerBackend::GetRecords() const {

const std::vector<LeftoverRecord>& records = leftover_tracker_object_.GetRecords();

  crow::json::wvalue records_json({});
  records_json["num_records"] = records.size();

  std::vector<crow::json::wvalue> record_json_vector;
  for (const LeftoverRecord &record : records) {
    record_json_vector.push_back(LeftoverRecordToCrowJSON(record));
  }
  records_json["record_array"] = std::move(record_json_vector);
  return records_json;
}

crow::json::wvalue LeftoverTrackerBackend::GetLeftoverReport() const {
  LeftoverReport generated_report = leftover_tracker_object_.GetLeftoverReport();

  return LeftoverReportToCrowJSON(generated_report);
}