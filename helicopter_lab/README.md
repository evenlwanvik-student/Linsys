# Helicopter lab assignment

A report was written and an oral presentation + demonstration of the finished product was given, which accounted for 30% of the final grade of the course. The report contains all the solutions to the problems introduced in the assignment, which is presented in a brief and to the point manner. We had four whole days (8 hours each) reserved in the lab, while the report and relevant mathematical analysis, deductions and calculations were dealt with apart from the given given lab hours. 

## Purpose of lab
The purpose of this assignment was to:
* Derive a model for a given system (the helicopter) that can be used for control purposes
* Derive and apply PD and multivariable controllers in a real-time environment.
* Demonstrate how states can be estimated that are not directly measured.
* Give an introduction to optimal control by developing a linear quadratic regulator (LQR) for the helicopter.

## Description of the system

<p align="center">
<img src="https://github.com/evenlwanvik-student/Linsys/blob/master/helicopter_lab/helicopter_forces.png" alt="Model that shows the forces and joint angles of the helicopter" height="300">
</p>


The helicopter consits of a base on which a long arm is attached. The helicopter head, with two motors and propellers, is attached to one side of the arm, which is supported by a counterweight placed on the opposite side. The helicopter has three rotational joints; travel, elivation, and pitch (see picture). The travel refers to the rotation about the vertical axis (about the base), elivation is the movement of the head up and down in the vertical plane, and pitch is the tilt of the head about the arm. The helicopter is solely actuated by the two motors on the helicopter head, which are connected to the propellers. The propellers delivers the necessary thrust to lift the helicopter head from the table.

The lab stations use the Quanser [Q8-USB data aquisition (DAQ) cards](https://www.quanser.com/products/q8-usb-data-acquisition-device/) for both inputs and outputs. All the joint angles, i.e. the pitch, elevation and travel, are measured using special counter circuits to read the encoders on the helicopter. The control signals (motor voltages) are set using a digital-to-analog converter (DAC). This signal is amplified by a linear amplifier inside the power suppply and fed to the motors.

A joystick is used for controlling the helicopter. The joystick displacement is measured by potentiometers, which are transmitted to the PC via USB. A *Joystick* Simulink block interprets and translates the joystick displacement into a value from -1 to 1.

## Content of the report (and excecution order of lab excercises)

The report, and assignment in general, was divided into four parts:
* **PART I**: Mathematical modeling
  - *Problem 1*: Compute the equations of motion (differential equations) for the joint angles.
  - *problem 2*: Linearize the system around the equilibrium point of the system.
  - *problem 3*: Use feedforward (directly from joystick) and compare the physical behaviour with the theoretical models.
  - *problem 4*: Convert outputs to the appropriate values and determine motor force constant and voltage to maintain equilibrium.
* **PART II**: Monovariable Control
  - *Problem 1*: Design a PD controller for the pitch angle.
  - *problem 2*: Design a P controller for the travel rate, which will work as a referennce for the pitch controller. 
* **PART III**: Multivariable Control (LQR)
  - *Problem 1*: Find the model for the angles we want to control with state-feedback (pitch and elevation rate).
  - *Problem 2*: Check controllability and find feedback matrix based on the LQR cost function.
  - *Problem 3*: Modify controller to include an integral effect for elevation rate and the pitch angle (PI controller).
* **PART IV**: State Estimation
  - *Problem 1*: Derive a state-space model for the system where the angles of the joints are measured.
  - *Problem 2*: Examine observability of system and create a linear observer for the system.
  - *Problem 3*: Examine observability and try to create a linear observer when only two joint angles are measured (i.e. one is missing).

## Endnotes?
