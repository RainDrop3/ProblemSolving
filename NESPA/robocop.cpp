#include <iostream>
#include <vector>
using namespace std;

int main(){
    int K, time[5], pointCnt = 1;
    cin >> K;

    vector<pair<int, int>> point(K), archive;
    pair<int, int> robot;
    for (int i = 0; i < K; ++i) cin >> point[i].first >> point[i].second;
    for (int i = 0; i < 5; ++i) cin >> time[i];

    robot = point[0];
    archive.push_back(point[0]);
    while(1){
        if(robot == point[pointCnt]) {pointCnt++; pointCnt %= K;}       //Ready to move to the next corner when the robot arrives at the corner
        if(robot.first == point[pointCnt].first) {                      //If two corners have the same x-coordinate, move y-coordinate by 1
            if(robot.second < point[pointCnt].second) robot.second++;
            else robot.second--;
        }
        else if(robot.second == point[pointCnt].second) {               //If two corners have the same y-coordinate, move x-coordinate by 1
            if(robot.first < point[pointCnt].first) robot.first++;
            else robot.first--;
        }
        archive.push_back(robot);
        if(robot == point[0]) break;                                    //When you get to the origin, you're done moving the robot
    }

    for (int i = 0; i < 5; ++i) time[i] %= (archive.size()-1);

    for (int i = 0; i < 5; ++i) cout << archive[time[i]].first << " " << archive[time[i]].second << endl;
}