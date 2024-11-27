#include "req.hpp"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

int requests::getRequest(std::string from, std::string to, std::string date) {

    std::string PathToFile = "C:/Users/gecay/OneDrive/Desktop/Projects/Bots/schedulegram/parser/params.json";
    std::ifstream inputFile(PathToFile);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    nlohmann::json j;
    inputFile >> j;

    inputFile.close();

    std::string url = j["URL"];
    std::string api_key = j["API_KEY"];

    j.clear();

    std::string transport_type = "suburban";

    auto request = cpr::Get(cpr::Url{ url },
                    cpr::Parameters{{"apikey", api_key},
                                    {"from", from},
                                    {"to", to},
                                    {"date", date},
                                    {"transport_types", transport_type}});
    if (request.error) {
    std::cerr << "Request failed: " << request.error.message << std::endl;
    }
    // j = nlohmann::json::parse(request.text);

    // for (nlohmann::json el : j["segments"]) {
    //     std::string departure_time = el["departure"];
    //     int duration = el["duration"];
    //     std::string price = "????";
    //     if (el.contains("tickets_info")) {
    //         if (!el["tickets_info"].is_null()){
    //             nlohmann::json tickets_info = el["tickets_info"];
    //             nlohmann::json ticket = tickets_info["places"][0];
    //             nlohmann::json prices = ticket["price"];
    //             price = std::to_string(int(prices["whole"]));
    //         }
    //     }
    //     nlohmann::json transport_subtype = el["thread"];
    //     nlohmann::json subtype = transport_subtype["transport_subtype"];
    //     std::string type = subtype["title"];

    //     std::cout << additional::parseTime(departure_time) << " "
    //             << additional::calculateArrivalTime(additional::parseTime(departure_time), duration) << " "
    //             << type << " "
    //             << price << std::endl << std::endl;
    // }

    return 0;
}

std::string additional::parseTime(std::string time) {
    return time.substr(time.find('T') + 1, 5);
}

std::string additional::calculateArrivalTime(std::string dep_time, int duration){
    int hours = std::stoi(dep_time.substr(0, 2));
    int minutes = std::stoi(dep_time.substr(3, 2));

    int summary_time = hours * 3600 + minutes * 60 + duration;

    int res_hours = (summary_time / 3600) % 24;
    int res_minutes = (summary_time / 60) % 60;

    std::ostringstream ArrivalTime;
    ArrivalTime << std::setw(2) << std::setfill('0') << res_hours << ":"
                    << std::setw(2) << std::setfill('0') << res_minutes;
    return ArrivalTime.str();
}
