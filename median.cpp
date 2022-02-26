#include <map>
#include <vector>
#include <iostream>

int main() {
    int N, M;
    std::map<std::string, std::vector<int>> values;
    std::cin >> N;
    std::string sensor;
    int value;
    for(auto i = 0; i < N; i++) {
        std::cin >> sensor >> value;
        values[sensor].push_back(value);
    }
    std::cin >> M;
    for(auto i = 0; i < M; i++) {
        std::cin >> sensor;
        auto& values_for_sensor = values[sensor];
        if (values_for_sensor.empty()) {
            std::cout << "no data" << std::endl;
        } else {
//            std::sort(values_for_sensor.begin(), values_for_sensor.end());
            auto median_iterator = std::next(values_for_sensor.begin(), (values_for_sensor.size() - 1) / 2);
            std::nth_element(values_for_sensor.begin(),  median_iterator,
                             values_for_sensor.end());
            std::cout << *median_iterator << std::endl;
        }



    }

}