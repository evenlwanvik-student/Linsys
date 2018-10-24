# Helicopter lab assignment

A report was written and an oral presentation + demonstration of the finished product was given. The report contains all the solutions to the problems introduced in the assignment, which is presented in a brief and to the point manner. We had four whole days (8 hours each) reserved in the lab, while the report and relevant mathematical analysis, deductions and calculations were dealt with apart from the given given lab hours.

## Purpose of lab
The purpose of this assignment was to:
* Derive a model for a given system (the helicopter) that can be used for control purposes
* Derive and apply PD and multivariable controllers in a real-time environment.
* Demonstrate how states can be estimated that are not directly measured.
* Give an introduction to optimal control by developing a linear quadratic regulator (LQR) for the helicopter.

## Description of the system

The helicopter consits of a base on which a long arm is attached. The helicopter head, with two motors and propellers, is attached to one side of the arm, which is supported by a counterweight placed on the opposite side. The helicopter has three rotational joints; travel, elivation, and pitch. The travel refers to the rotation about the vertical axis (about the base), elivation is the movement of the head up and down in the vertical plane, and pitch is the tilt of the head about the arm.

![alt text](https://github.com/evenlwanvik-student/Linsys/edit/master/helicopter_lab/helicopter_forces.pdf)