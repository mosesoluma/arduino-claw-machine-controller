# Arduino Claw Machine Controller

A compact embedded robotics project developed during a summer laboratory internship. The system controls a claw-machine teaching platform using an Arduino-compatible controller, two-axis joystick input, four DC motors, a servo-actuated gripper, and a push button.

The project combines **manual Cartesian positioning** of the claw with a **single-button automated pick sequence**.

## Project Highlights

- Arduino C/C++ implementation with modular control functions
- Two-axis joystick control for gantry positioning
- Synchronized dual-motor drive for forward/backward motion
- Independent lateral carriage motion
- Servo-based claw opening and closing
- Push-button-triggered automatic pick sequence
- Hardware-calibrated motion timing and servo angles
- Edge-triggered button handling to prevent repeated cycles while held
- Code structured for readability, testing, and easy modification

## System Behavior

The operator first positions the claw using the joystick. A single push-button press then executes one complete pick cycle:

1. Open the claw
2. Lower the claw
3. Stop and settle
4. Close the claw to grip the object
5. Raise the claw
6. Keep the claw closed while holding the object

## Hardware / Pin Mapping

| Component | Function | Arduino Pin(s) |
|---|---|---|
| Joystick axis 1 | Forward / backward | A2 |
| Joystick axis 2 | Left / right | A3 |
| DC motors 2 & 3 | Synchronized gantry forward / backward | D2-D5 |
| DC motor 1 | Lateral carriage left / right | D12-D13 |
| DC motor 4 | Claw vertical motion | D6-D7 |
| Servo motor | Claw open / close | D9 |
| Push button | Automatic claw sequence | D10 |

## Final Hardware Calibration

| Parameter | Final value |
|---|---:|
| Joystick low threshold | 300 |
| Joystick high threshold | 700 |
| Servo open angle | 110° |
| Servo closed angle | 70° |
| Vertical travel down | 200 ms |
| Vertical travel up | 400 ms |
| Pre-descent open delay | 400 ms |
| Settling delay after descent | 300 ms |
| Grip delay | 700 ms |

These values were tuned on the physical teaching kit and may require recalibration for a different mechanical assembly.

## Software Structure

The controller is intentionally organized into hardware-level functions rather than placing all logic directly in `loop()`.

Core functions include:

- `moveForward()` / `moveBackward()`
- `moveLeft()` / `moveRight()`
- `moveClawDown()` / `moveClawUp()`
- `openClaw()` / `closeClaw()`
- `controlMovement()`
- `isButtonPressed()`
- `executeClawSequence()`

This makes the code easier to inspect, debug, recalibrate, and extend.

## Skills Demonstrated

**Embedded C/C++ · Arduino · Actuator Control · Servo Control · Joystick Input · Hardware Debugging · Sequential Control Logic · Modular Software Design · Physical-System Calibration**

