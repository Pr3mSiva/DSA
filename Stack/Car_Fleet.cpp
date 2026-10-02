// LeetCode Q.No- 853. Car Fleet

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

/*
--> The question is to find the before reaching the destinanation howmany no.of cars will be like group without any space between them

* Target is 12* 

eg- pos[0] car started at 10 and has a speed 2 so after t second it reaches 12
    pos[1] car started behind car[0] at 8 has speed 4 after t second it reaches 12 behind the car[0] like a group

    car[1] - 8(speed 4)    9      car[0] - 10(speed 2)

    after t second

    car[1] - 12 car[0] - 12
*/

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,double>> cars;

    for(int i=0;i<position.size();i++) {
        double time=(double)(target-position[i])/speed[i];
        cars.push_back({position[i],time});
    }
    /*
    --> we making a pair that has car postion and time that will be taken by car to reach the destination
    formula is simple traget-currentpostion gives remaing distance to be covered and dividing by speed give the required time

    cars={ {10,1}, {8,1}, {0,12}, {5,7}, {3,3} }
    */

    sort(cars.rbegin(),cars.rend());
    /*
    sorting in DESC 
    position    time
    ----------------
    10          1
    8           1
    5           7
    3           3
    0           12

    --> we did DESC because the first car is nearest to the target, so how fast the cars behind may come but will have stack behind this car and move as group
    */

    int fleets=0;
    double lasttime=0;

    for(auto car : cars) {
        double current_time=car.second; //--> this means take the value of second index in the pair <postion - first(), time - second()>

        if(current_time>lasttime) {
            fleets++;
            lasttime=current_time;
        }
    }
    return fleets;
}

int main() {
    int target=12;
    vector<int> position={10,8,0,5,3}, speed={2,4,1,1,3};
    int result=carFleet(target,position,speed);
    cout<<"No.of car fleet that will arrive at the destination="<<result;
    return 0;
}

/*
LeetCode Version

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for(int i=0;i<position.size();i++) {
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }

        sort(cars.rbegin(),cars.rend());

        int fleets=0;
        double last_time=0;

        for(auto car:cars) {
            double current_time=car.second;
            if(current_time>last_time) {
                fleets++;
                last_time=current_time;
            }
        }
        return fleets;
    }
};
*/