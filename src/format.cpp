#include "format.h"

#include <iomanip>
#include <sstream>
#include <string>

using std::string;

std::string ElapsedTime(long seconds) {
  // Calculate hours, minutes, and remaining seconds
  int hours = seconds / 3600;
  int minutes = (seconds % 3600) / 60;
  int remaining_seconds = seconds % 60;

  // Create a stringstream to format the output
  std::stringstream formatted_time;

  // Format the hours, minutes, and seconds with leading zeros
  formatted_time << std::setfill('0') << std::setw(2) << hours << ":";
  formatted_time << std::setfill('0') << std::setw(2) << minutes << ":";
  formatted_time << std::setfill('0') << std::setw(2) << remaining_seconds;

  return formatted_time.str();  // Convert the stringstream to a string
}