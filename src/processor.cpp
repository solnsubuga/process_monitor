#include "processor.h"

#include "linux_parser.h"

float Processor::Utilization() {
  long total = LinuxParser::Jiffies();
  long active = LinuxParser::ActiveJiffies();

  return (total != 0) ? static_cast<float>(active) / total : 0.0f;
}
/*
float Processor::Utilization() {
    float nonidle = LinuxParser::Jiffies()  + LinuxParser::ActiveJiffies();
    float idle = LinuxParser::IdleJiffies();

    float total = idle + nonidle;
    float totald = total - prevtotal_;
    float idled = idle - previdle_;

    previdle_ = idle;
    prevnonidle_ = nonidle;
    prevtotal_ = total;

    return (totald - idled) / totald;
}*/