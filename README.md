# Project introduction
This is a project in the Udacity Advanced Embedded System nanodegree. 

In this project you will control an LED blinking through variable PWM signal created by a timer, and defined by the LED driver user.

# Project Requirements
- Blinking LED control
- Control blinking of an LED for a user-defined ON and OFF periods
- Create a function in the App layer that takes as an input from the user a specific ON time and OFF time in seconds, lights a LED for the given ON time, and dim it for the given OFF time. It’s prohibited to use predefined delay functions, only timer driver functions can be used. This function implements implicitly the PWM module using Timer Overflow.

## Prepare project folders
- Create a COTS folder for the whole course including a folder for each layer in the layered architectureto include MCAL, HAL, SERVICE, APPLICATION, and LIBRARIES

## Implement the GPIO driver
- Create the GPIO driver from scratch using the sufficient interface,configure,private and program files
- Create functions in GPIO driver that are needed to perform the required project functionality

## Implement Timer driver
- Create the Timer driver from scratch using the sufficient interface,configure,private and program files
- Create functions in Timer driver that are needed to perform the required project functionality
- Creating a Timer Overflow ISR that performs the required functionality
- Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer

## Implement interrupt driver
- Creating the Interrupt driver from scratch using the sufficient interface,configure,private and program files
- Create functions in Interrupt driver that are needed to perform the required project functionality

You should deliver a schematic/block diagram according to your understanding of the requirements.
