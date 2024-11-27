#pragma once
#include <string>

namespace requests {
    int getRequest(std::string from, std::string to, std::string date);
}
namespace additional {
    std::string parseTime(std::string time);
    std::string calculateArrivalTime(std::string dep_time, int duration);
}
