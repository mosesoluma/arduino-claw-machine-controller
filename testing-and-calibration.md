# Testing and Calibration Notes

## Final Pin / Axis Mapping

| Physical function | Final pins |
|---|---|
| Joystick forward/backward | A2 |
| Joystick left/right | A3 |
| Gantry forward/backward | D2/D3 and D4/D5 |
| Lateral carriage left/right | D12/D13 |
| Claw vertical motion | D6/D7 |
| Servo gripper | D9 |
| Push button | D10 |

## Final Direction Logic

### Gantry forward
D2=HIGH, D3=LOW, D4=HIGH, D5=LOW

### Gantry backward
D2=LOW, D3=HIGH, D4=LOW, D5=HIGH

### Lateral left
D12=HIGH, D13=LOW

### Lateral right
D12=LOW, D13=HIGH

### Claw down
D6=HIGH, D7=LOW

### Claw up
D6=LOW, D7=HIGH

All stop commands drive both pins for the associated DC motor(s) LOW.

## Joystick Calibration

- A2 up: approximately 1023
- A2 down: approximately 0
- A3 left: approximately 0
- A3 right: approximately 1023
- Low threshold: 300
- High threshold: 700

## Servo Calibration

- Open: 110°
- Closed: 70°

## Automatic Sequence Timing

```text
Open       400 ms
Down       200 ms
Settle     300 ms
Close      700 ms
Up         400 ms
```

The claw remains closed at the end of the cycle.

## Button Handling

The button uses Arduino's internal pull-up resistor:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

Released = HIGH; pressed = LOW. Edge detection prevents repeated execution while the button remains held.

## Known Limitation

The current automatic sequence uses blocking `delay()` calls. This is acceptable for the teaching-kit behavior because manual movement should stop during the pick cycle. A production controller would normally use a non-blocking state machine, hardware limit feedback, and explicit fault handling.
