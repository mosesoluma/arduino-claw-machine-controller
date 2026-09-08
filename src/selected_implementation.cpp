/*
 * Arduino Claw Machine Controller
 * Selected Implementation Excerpts
 *
 * This file presents representative implementation details from a
 * summer internship embedded-robotics project.
 *
 * The complete project source is not publicly distributed.
 */

#include <Servo.h>

// ============================================================
// Hardware Configuration
// ============================================================

// Joystick inputs
const int JOYSTICK_FB_PIN = A2;
const int JOYSTICK_LR_PIN = A3;

// Synchronized gantry motors
const int GANTRY_MOTOR_1_A = 2;
const int GANTRY_MOTOR_1_B = 3;
const int GANTRY_MOTOR_2_A = 4;
const int GANTRY_MOTOR_2_B = 5;

// Vertical claw actuator
const int CLAW_VERTICAL_A = 6;
const int CLAW_VERTICAL_B = 7;

// Servo-actuated gripper
const int CLAW_SERVO_PIN = 9;

// Push-button input
const int BUTTON_PIN = 10;

// Lateral carriage motor
const int LATERAL_MOTOR_A = 12;
const int LATERAL_MOTOR_B = 13;


// ============================================================
// Experimentally Calibrated Parameters
// ============================================================

const int JOYSTICK_LOW_THRESHOLD  = 300;
const int JOYSTICK_HIGH_THRESHOLD = 700;

const int CLAW_OPEN_ANGLE   = 110;
const int CLAW_CLOSED_ANGLE = 70;

const unsigned long CLAW_DOWN_TIME_MS = 200;
const unsigned long CLAW_UP_TIME_MS   = 400;


// ============================================================
// Controller Interface
// ============================================================

void controlMovement();

void moveForward();
void moveBackward();
void stopForwardBackward();

void moveLeft();
void moveRight();
void stopLeftRight();

void moveClawDown();
void moveClawUp();
void stopClawVertical();

void openClaw();
void closeClaw();

bool isButtonPressed();
void executeClawSequence();


// ============================================================
// Representative Motor-Control Implementation
// ============================================================

void moveForward()
{
    // Two motors are driven together to maintain gantry alignment.

    digitalWrite(GANTRY_MOTOR_1_A, HIGH);
    digitalWrite(GANTRY_MOTOR_1_B, LOW);

    digitalWrite(GANTRY_MOTOR_2_A, HIGH);
    digitalWrite(GANTRY_MOTOR_2_B, LOW);
}


void moveBackward()
{
    digitalWrite(GANTRY_MOTOR_1_A, LOW);
    digitalWrite(GANTRY_MOTOR_1_B, HIGH);

    digitalWrite(GANTRY_MOTOR_2_A, LOW);
    digitalWrite(GANTRY_MOTOR_2_B, HIGH);
}


void stopForwardBackward()
{
    digitalWrite(GANTRY_MOTOR_1_A, LOW);
    digitalWrite(GANTRY_MOTOR_1_B, LOW);

    digitalWrite(GANTRY_MOTOR_2_A, LOW);
    digitalWrite(GANTRY_MOTOR_2_B, LOW);
}


// ============================================================
// Representative Lateral-Motion Implementation
// ============================================================

void moveLeft()
{
    digitalWrite(LATERAL_MOTOR_A, HIGH);
    digitalWrite(LATERAL_MOTOR_B, LOW);
}


void moveRight()
{
    digitalWrite(LATERAL_MOTOR_A, LOW);
    digitalWrite(LATERAL_MOTOR_B, HIGH);
}


// ============================================================
// Representative Gripper Control
// ============================================================

Servo clawServo;

void openClaw()
{
    clawServo.write(CLAW_OPEN_ANGLE);
}


void closeClaw()
{
    clawServo.write(CLAW_CLOSED_ANGLE);
}


/*
 * Automatic Pick Sequence
 *
 * The complete sequence implementation is intentionally omitted.
 *
 * Functional sequence:
 *
 *     Open gripper
 *          |
 *          v
 *     Lower claw
 *          |
 *          v
 *     Stop / settle
 *          |
 *          v
 *     Close gripper
 *          |
 *          v
 *     Raise claw
 *          |
 *          v
 *     Hold object
 *
 * The full controller also implements joystick processing,
 * button edge detection, actuator stopping logic, and calibrated
 * sequence timing.
 */
