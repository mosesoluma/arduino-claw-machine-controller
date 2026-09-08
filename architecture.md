# Control Architecture

## Overview

The controller separates **manual positioning** from the **automatic gripping sequence**.

```text
Joystick A2/A3 --> Manual Movement Controller --> DC Motors
                                      |
                                      v
                              Position the claw

Button D10 --> Automatic Pick Sequence --> Servo + Vertical Motor
```

## Manual Motion

### Forward / Backward
Two DC motors are driven together using D2/D3 and D4/D5 so the gantry remains aligned.

### Left / Right
The lateral carriage is driven through D12/D13.

### Joystick Dead Zone
- `0-299`: one direction
- `300-700`: stop / dead zone
- `701-1023`: opposite direction

The dead zone reduces unintended motion from joystick offset or analog noise.

## Automatic Pick Sequence

```text
OPEN -> LOWER -> STOP/SETTLE -> CLOSE/GRIP -> RAISE -> STOP
```

The claw remains closed after the sequence so the object is retained.

## Software Design

The controller uses small, descriptive hardware-control functions rather than placing every `digitalWrite()` directly inside `loop()`.

This supports actuator-level testing, easier direction reversal, timing recalibration, and later migration to a finite-state-machine controller.
