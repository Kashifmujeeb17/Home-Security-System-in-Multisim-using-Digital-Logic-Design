// variables used in the program
int button = LOW; // button state variable, initial value 0 (LOW)
int i; // variable used in for cycles
int j; // variable used in for cycles
/* The following routines are executed only when they are referred to by present instructions
in the section void loop () */
// ************************ routine of displaying the number 1 **************
void one (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, HIGH); // activate all the doors and turn off all the LEDs beforehand
 digitalWrite (4, LOW); // deactivate port 4 and turn on the right upper vertical segment
 digitalWrite (6, LOW); // deactivate port 6 and turn the vertical right bottom segment on
}
// *********************** routine of displaying the number 2 ******************* ***
void two (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the doors and turn on all the LEDs beforehand
 digitalWrite (6, HIGH); // activate port 6 and turn off the vertical right bottom segment
 digitalWrite (2, HIGH); // activate port 2 and turn off the left upper vertical segment
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
}

// ********************** routine of displaying the number 3 ******************** *
void three (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the doors and turn on all the LEDs beforehand
 digitalWrite (2, HIGH); // activate port 2 and turn off the upper left vertical segment
 digitalWrite (8, HIGH); // activate port 8 and turn off the lower left vertical segment
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
}
// ********************* routine of displaying the number 4 ********************* *
void four (void)
{
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
 digitalWrite (7, HIGH); // activate port 7 and turn off the low horizontal segment
 digitalWrite (8, HIGH); // activate port 8 and turn off the low left vertical segment
 digitalWrite (3, HIGH); // activate port 3 and turn off the top horizontal segment
}
// *************************** routine of displaying the number 5 *************** *******
void five (void)
// Arduino: countdown, digital digit
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
 digitalWrite (4, HIGH); // activate port 4 and turn off the right upper vertical segment
 digitalWrite (8, HIGH); // activate port 8 and turn off the left bottom vertical segment
}
// ************************ routine of displaying the number 6 ****************** **********
void six (void) // the term six was used instead of "six" because "six"
{// is the "reserved" word that sends the compiler into a crisis
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
 digitalWrite (4, HIGH); // activate port 4 and turn off the right upper vertical segment
}
// ***************************** routine of viewing the number 7 ************* ***********
void seven (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, HIGH); // deactivate all the ports and then turn off all the LEDs beforehand
digitalWrite (3, LOW); // deactivate port 3 and turn on the upper horizontal segment
digitalWrite (4, LOW); // deactivate port 4 and turn on the right upper vertical segment
digitalWrite (6, LOW); // deactivate port 6 and turn on the lower right vertical segment
}
// ********************************* routine of viewing the number 8 ********* ***********
void eight (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
}
// ************************ routine of displaying the number 9 ****************** *****
void nine (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
 digitalWrite (8, HIGH); // activate port 8 and then turn off the left bottom vertical segment
}
// **************************** routine of displaying the number zero ************** ***********
void zero (void)
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, LOW); // deactivate all the ports and then turn on all the LEDs beforehand
 digitalWrite (5, HIGH); // activate port 5 and turn off the decimal point
 digitalWrite (1, HIGH); // activate port 1 and turn off the central horizontal segment
}

void setup ()
{
 for (i = 1; i <= 8; i ++)
// Arduino: countdown, digital digit
 pinMode (i, OUTPUT); // defines the ports 1 to 8 as output ports
 pinMode (11, INPUT); // define port 11, to which the button is connected,
 // as an input port
 pinMode (12, OUTPUT); // define port 12, to which the buzzer is connected, like
 // an output port
 pinMode (13, OUTPUT); // define port 13, to which the led is connected, like one
 // output port
}
void loop ()
{
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, HIGH); // activate all the ports and then turn off all the LEDs of the digital digit
button = digitalRead (11); // read the state of the button
 while (button) // executes subsequent statements only if the value of the button is 1 (High)
 // ie if the button is pressed
 {
 nine(); // run the number 9 display routine
 delay (1000); // wait 1 second
 eight(); // run the display routine of the number 8 .....
 delay (1000);
 seven();
 delay (1000);
 six ();
 delay (1000);
 five();
 
 delay (1000);
 four();
 delay (1000);
 three();
 delay (1000);
 two();
 delay (1000);
 one();
 delay (1000);
 zero();
 delay (1000);
 for (j = 1; j <= 8; j ++)
 digitalWrite (j, HIGH); // activate all the ports and then turn off all the LEDs
 for (i = 1; i <= 20; i ++) // routine for the sound signal emission and for the flashing of the led
 {
 digitalWrite (13, HIGH); // turn on the led
 digitalWrite (12, LOW); // turn off the buzzer
 digitalWrite (5, LOW); // turn on the decimal point
 delay (70);
 digitalWrite (13, LOW); // turn off the led 
 digitalWrite (12, HIGH); // activate the buzzer
 digitalWrite (5, HIGH); // turn off the decimal point
 delay (70);
 button = LOW; // put the button in the LOW state, so as not to repeat the countdown
 // until the button is pressed again
 digitalWrite (12, LOW); // turn off the buzzer
 }
 }
}
