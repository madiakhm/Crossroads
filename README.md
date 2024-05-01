# Multithreaded Car Intersection Simulation

**Introduction**  
This C++ program simulates cars passing through an intersection using multithreading. Each car is represented as a separate thread, and they are synchronized to avoid collisions using a mutex lock. The program demonstrates basic multithreading concepts and exception handling.

**Files**  
- `car_intersection.cpp`: This file contains the implementation of the car intersection simulation.
- `README.md`: This file provides information about the program.

**Implementation Details**  
**`drive` Function**  
The `drive` function represents the behavior of a single car passing through the intersection. It takes three parameters:
1. `car_number`: The identification number of the car.
2. `direction`: The direction in which the car is traveling (North, South, West, or East).
3. `time`: The time taken by the car to pass through the intersection.

**`main` Function**  
The `main` function initializes vectors of car numbers, directions, and passing times. It then creates threads for each car using the `drive` function. Exception handling is implemented to catch any invalid arguments passed to the `drive` function.

**Usage**  
To compile and run the program, follow these steps:
1. Ensure you have a C++ compiler and a C++11-compliant standard library installed on your system.
2. Open a terminal or command prompt.
3. Navigate to the directory containing the `car_intersection.cpp` file.
4. Compile the program using the following command: g++ -o car_intersection car_intersection.cpp -std=c++11 -pthread

Note: The `-std=c++11` flag is used to enable C++11 features, and the `-pthread` flag is used to link the pthread library for multithreading support.
5. Run the compiled executable:
./car_intersection


**Example Output**  
Car 1 going North

Car 2 going South

Car 3 going West

Car 4 going East

Exception caught: Invalid direction

Car number 1 has passed the intersection

Car number 2 has passed the intersection

Car number 3 has passed the intersection

Car number 4 has passed the intersection


**Notes**  
- The program demonstrates basic multithreading concepts and exception handling.
- Ensure that the compilation flags include `-std=c++11` and `-pthread` for proper compilation and linking.
