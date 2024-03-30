#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex m;

void drive(int car_number, std::string direction, int time) {
    std::unique_lock<std::mutex> lock(m);
    
    if (direction != "North" && direction != "South" && direction != "West" && direction != "East") {
        throw std::invalid_argument("Invalid direction");
    }
    
    if (time < 0) {
        throw std::invalid_argument("Invalid time");
    }
    
    std::cout << "Car " << car_number <<  " going "  << direction << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Car number " << car_number << " has passed the intersection\n";
}

int main() {
    std::vector<int> car_numbers = {1, 2, 3, 4, 5};
    std::vector<std::string> directions = {"North", "South", "West", "East", "North"};
    std::vector<int> times = {1, 2, 3, 4, 5};

    std::vector<std::thread> threads;
    for (int i = 0; i < car_numbers.size(); i++) {
        try {
            threads.push_back(std::thread(drive, car_numbers[i], directions[i], times[i]));
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
