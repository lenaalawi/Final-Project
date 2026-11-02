# System Design – Sensor Fusion

## Project Overview
A sensor-fusion system that combines readings from three noisy sensors into one
estimate of an object's position, and compares fusion methods using RMSE.

## Project Leader
_TODO: name of this iteration's leader (someone who has not led before)._

## Task Table

| ID | Task Name | Menu | Member | Files / Functions | Expected Deliverable | Status |
|----|-----------|------|--------|-------------------|----------------------|--------|
| T1 | Trajectory generation | 1 | Afraa | trajectory.h/.cpp – generateTrajectory() | Object's true trajectory (time, position) | Stub |
| T2 | Sensors simulation | 2 | Afraa | sensors.h/.cpp – simulateSensors() | Noisy (and possibly dropped) readings from 3 sensors | Stub |
| T3 | Weighted-average fusion | 3 | Lena | fusion.h/.cpp – weightedAverage() | One fused estimate per time step | Stub |
| T4 | Kalman filter | 4 | Lena | kalman.h/.cpp – kalmanFilter() | Kalman-filtered estimate per time step | Stub |
| T5 | Calculate RMSE | 5 | Afraa | analysis.h/.cpp – calculateRMSE() | RMSE for each sensor and each fusion method | Stub |
| T6 | Display results | 6 | Lena | display.h/.cpp – displayResults() | Readable table of readings, estimates, RMSE | Stub |
| T7 | Noise and dropout experiments | 7 | Afraa | experiments.h/.cpp – runExperiments() | Effect of noise/dropouts on RMSE | Stub |
| T8 | Testing and integration | 8 | Team | tests.h/.cpp – runTests() | Verified, working complete program | Stub |

## Design Decision: Shared State
Every task function takes the shared `SystemState` object. A task reads what
earlier tasks produced and writes only its own fields, so each member can
replace their stubs without editing anyone else's files.

## Class Design

**Reading** (struct, state.h)
- Data: `value` (measured position), `valid` (false = sensor dropout)

**SystemState** (state.h)
- Data: `time`, `truth`, `readings[3]` (vector of `Reading`), `noiseStd[3]`,
  `dropoutProb[3]`, `weightedEstimate`, `kalmanEstimate`, `rmseSensor[3]`,
  `rmseWeighted`, `rmseKalman`, `rmseComputed`
- Methods: `hasTrajectory()`, `hasSensorData()`

Note: the fields are public in this iteration so tasks can share them. If the
course requires private data, convert them to private members with
getters/setters later; the task function signatures do not change.

## Menu Design
```
1. Generate Trajectory
2. Simulate Sensors
3. Weighted-Average Sensor Fusion
4. Kalman Filter
5. Calculate RMSE
6. Display Results
7. Run Noise and Dropout Experiments
8. Test and Integrate System
9. Exit
Enter your choice:
```
`main.cpp` uses a `switch`; each case calls exactly one task function.

## File Structure
```
main.cpp                 menu + switch
state.h                  SystemState, Reading
trajectory.h/.cpp        T1
sensors.h/.cpp           T2
fusion.h/.cpp            T3
kalman.h/.cpp            T4
analysis.h/.cpp          T5
display.h/.cpp           T6
experiments.h/.cpp       T7
tests.h/.cpp             T8
Makefile
README.md
docs/                    design.md, PDF report, Excel plan
```

## Class / Data-Flow Diagram
```
                 +-------------------+
                 |      main.cpp     |
                 |   menu + switch   |
                 +---------+---------+
                           | passes SystemState&
   +-------+-------+-------+-------+-------+-------+-------+
   |       |       |       |       |       |       |       |
  T1      T2      T3      T4      T5      T6      T7      T8
generate simulate weighted kalman calculate display experiments runTests
Trajectory Sensors Average Filter  RMSE    Results
   |       |       |       |       |       ^
   v       v       v       v       v       |
 +----------------------------------------------------+
 |                    SystemState                     |
 |  time, truth -> readings[3] -> weightedEstimate,   |
 |  kalmanEstimate -> rmse*                           |
 +----------------------------------------------------+
            contains: vector<Reading> (value, valid)
```

Data flow: T1 writes `truth` -> T2 reads `truth`, writes `readings` ->
T3/T4 read `readings`, write estimates -> T5 reads all, writes RMSE ->
T6 reads everything for display. T7 re-runs T1-T5 with different
noise/dropout settings.

## Revised Timeline (suggested)
| Stage | Goal |
|-------|------|
| This iteration | Skeleton compiles, full menu, stubs for all tasks |
| Next | T1, T2, T3, T4 working |
| Then | T5, T6 working; start T7 |
| Final | T7, T8 testing/integration, report |

## Member Contributions (this iteration)
- Afraa: _TODO_
- Lena: _TODO_
