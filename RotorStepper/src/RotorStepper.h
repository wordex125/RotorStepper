#ifndef RotorStepper
#define RotorStepper

//#include "RotorStepper.h"
#include "AccelStepper.h"

class RotorStepper
{
public:

    //the constructor. Sets the maxSpeed and acceleration
    //inside the stepper object
    //enables the steppers upon initialization
    RotorStepper(uint8_t stepPin, uint8_t dirPin, uint8_t microsteppingRate=8, uint8_t enablePin=1, float maxSpeed=3200, float acceleration=400);

    //sets the enable pin for the enable function if
    //AccelStepper library fails to do so
    void setEnablePin();

    //enables the stepper
    void enableStepper();

    //disables the stepper
    void disableStepper();

    //calculates the amount of steps needed in order to
    //rotate by the given angle
    int angleToSteps(float angle);

    //calculates the angle turned after making the given
    //amount of steps
    float stepsToAngle(int steps);

    //sets the target position to the given angle
    //positive is clockwise, negative counterclockwise from
    //the 0 position
    void moveToAngle(float absoluteAangle);

    //sets the target position to current position
    //+/- relative angle
    //positive is clockwise, negative counterclockwise from
    //the current position
    void moveAngle(float relativeAngle);

    //implements the AccelStepper run() function
    //return true if the motor is still running to the target position
    //needs to be called as often as possible
    //makes at most one single step per call
    boolean run();

    //sets maxSpeed in steps per second
    void setMaxSpeed(float speed);

    //sets acceleration in steps per second^2
    void setAcceleration(float acceletarion);

protected:
    uint8_t _enablePin;
    uint8_t _microsteppingRate;
    uint8_t _stepPin;
    uint8_t _dirPin;
    int _maxSpeed;
    int _acceleration;
};

#endif
