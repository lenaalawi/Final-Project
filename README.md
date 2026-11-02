# Sensor Fusion System

A C++ program that combines readings from three simulated sensors into a single
position estimate, using a weighted average and a Kalman filter, and evaluates
the results with RMSE.

**Team:** Afraa, Lena
**Project Leader (this iteration):** Afraa Boukataya

## Build

Requires a C++17 compiler (g++ or clang++) and `make`.

```
make
```

Without make:

```
g++ -std=c++17 -Wall -Wextra -o sensor_fusion main.cpp trajectory.cpp sensors.cpp fusion.cpp kalman.cpp analysis.cpp display.cpp experiments.cpp tests.cpp
```

## Run

```
./sensor_fusion
```

## Menu

| Option | Task | Owner | Status |
|---|---|---|---|
| 1 | Generate Trajectory | Afraa | stub |
| 2 | Simulate Sensors | Afraa | stub |
| 3 | Weighted-Average Sensor Fusion | Lena | stub |
| 4 | Kalman Filter | Lena | stub |
| 5 | Calculate RMSE | Afraa | stub |
| 6 | Display Results | Lena | stub |
| 7 | Run Noise and Dropout Experiments | Afraa | stub |
| 8 | Test and Integrate System | Team | stub |
| 9 | Exit | - | done |

Run the options in order 1 → 2 → 3/4 → 5 → 6; later tasks use the data
produced by earlier ones (stored in `SystemState`).

## Files

See `docs/design.md` for the class design, file structure and diagram.

## Team rules

- Only edit your own task files (see table above).
- Commit often with clear messages, e.g. `T3: implement weighted average`.
- `state.h` is shared: tell the team before changing it.
