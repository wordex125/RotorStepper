
#include "RotorStepper.h"

RotorStepper::RotorStepper(uint8_t stepPin, uint8_t dirPin, uint8_t microsteppingRate=8, uint8_t enablePin=1,  float maxSpeed=3200, float acceleration=400){
    _microsteppingRate = microsteppingRate;
    _enablePin = enablePin;
    _stepPin = stepPin;
    _dirPin = dirPin;
    _maxSpeed = maxSpeed;
    _acceleration = acceleration;
    //creates the AccelStepper class object to access its methods
    AccelStepper stepper(AccelStepper::DRIVER, _stepPin, _dirPin);
    stepper.setAcceleration(acceleration);
    stepper.setMaxSpeed(maxSpeed);
    setEnablePin();
    enableStepper();
}

void RotorStepper::setEnablePin(){
    pinMode(_enablePin, OUTPUT);
}

void RotorStepper::enableStepper(){
    digitalWrite(_enablePin, LOW);
}

void RotorStepper::disableStepper(){
    digitalWrite(_enablePin, HIGH);
}

int RotorStepper::angleToSteps(float angle){
    return (int)(_microsteppingRate*400*127/13*angle/360);
}

float RotorStepper::stepsToAngle(int steps){
    return (float)steps/400*13*360/127/_microsteppingRate;
}

void RotorStepper::moveToAngle(float absoluteAngle){
    stepper.moveTo(angleToSteps(absoluteAngle));
}

void RotorSteppe::moveAngle(float relativeAngle){
    stepper.move(angleToSteps(relativeAngle));
}

boolean run(){
    return stepper.run(); //is supposed to work
}

void RotorSteppe::setMaxSpeed(float speed){
    _maxSpeed = speed;
    stepper.setMaxSpeed(_maxSpeed);
}

void RotorSteppe::setAcceleration(float acceleration){
    _acceleration = acceleration;
    stepper.setAcceleration(_acceleration);
}
