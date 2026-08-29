#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::info("SampleApp started");

    nlohmann::json j = {
        {"product", "Black Duck"},
        {"version", "11.4.2"}
    };

    std::cout << j.dump(2) << std::endl;
    return 0;
}
