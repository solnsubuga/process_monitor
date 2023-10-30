#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(size_t pid) { _pid = pid; }

int Process::Pid() const { return _pid; }

float Process::CpuUtilization() const {
  // Get the active jiffies (CPU time) used by the process
  long activeJiffies = LinuxParser::ActiveJiffies(_pid);
  long totalJiffies = LinuxParser::ActiveJiffies();

  // // Get the process's uptime
  // long processUptime = LinuxParser::UpTime(_pid);

  // // Calculate the total jiffies (CPU time) during the process's lifetime
  // long totalJiffies = sysconf(_SC_CLK_TCK) * processUptime;

  // Calculate the CPU utilization percentage as a float
  float cpuUtilization =
      (static_cast<float>(activeJiffies) / totalJiffies) * 100.0f;

  return cpuUtilization;
}

string Process::Command() { return LinuxParser::Command(_pid); }

string Process::Ram() const { return LinuxParser::Ram(_pid); }

string Process::User() { return LinuxParser::User(_pid); }

long int Process::UpTime() { return LinuxParser::UpTime(_pid); }

bool Process::operator<(Process const& a) const {
  return CpuUtilization() > a.CpuUtilization();
}