#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : _pid(pid){} //constructor

// Return this process's ID
int Process::Pid() const 
{
  return _pid;
}

// done
string Process::Command() { 
    return LinuxParser::Command(Pid()); 
}

// done
string Process::Ram() { 
    return LinuxParser::Ram(Pid());
}

// done
string Process::User() { 
    return LinuxParser::User(Pid()); 
}

// done
long int Process::UpTime() { 
    return LinuxParser::UpTime(Pid()); 
}

// done
bool Process::operator<(Process& a)  { 
    return CpuUtilization() > a.CpuUtilization();
}

// Return this process's CPU utilization
float Process::CpuUtilization() { 
    long total = LinuxParser::ActiveJiffies(Pid());
  	long seconds = LinuxParser::UpTime() - Process::UpTime();
    return (float)total / seconds;
}
