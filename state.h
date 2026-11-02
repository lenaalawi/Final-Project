// state.h - shared data passed between all tasks.
#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>

// One measurement from one sensor at one time step.
struct Reading {
    double value = 0.0;   // measured position
    bool valid = true;    // false when the sensor dropped out
};

// Holds everything produced by the pipeline so tasks can share results.
// Each task reads what earlier tasks wrote and writes only its own fields.
class SystemState {
public:
    static const int NUM_SENSORS = 3;

    // T1 output
    std::vector<double> time;                 // time stamps
    std::vector<double> truth;                // true positions

    // T2 output: readings[s][k] = sensor s at step k
    std::vector<Reading> readings[NUM_SENSORS];
    double noiseStd[NUM_SENSORS] = {0.5, 1.0, 2.0};     // per-sensor noise
    double dropoutProb[NUM_SENSORS] = {0.0, 0.0, 0.0};  // per-sensor dropout chance

    // T3 / T4 output
    std::vector<double> weightedEstimate;
    std::vector<double> kalmanEstimate;

    // T5 output
    double rmseSensor[NUM_SENSORS] = {0, 0, 0};
    double rmseWeighted = 0.0;
    double rmseKalman = 0.0;
    bool rmseComputed = false;

    bool hasTrajectory() const { return !truth.empty(); }
    bool hasSensorData() const { return !readings[0].empty(); }
};

#endif
