#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "derek_LED.h"
using namespace std;
#define LED_PATH "/sys/class/leds/beaglebone:green:usr"


int main(int argc, char* argv[]){
   if(argc!=3){ 								//Changed the nummber of arguments the program expects
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };				//Changed the for loop to accept i as an argument
   for(int i = atoi(argv[2]); i<=4; i){						
      if(cmd=="on")leds[i].turnOn();
      else if(cmd=="off")leds[i].turnOff();
      else if(cmd=="flash")leds[i].flash("100"); //default is "50"
      else if(cmd=="status")leds[i].outputState();
      else if(cmd=="blink")leds[i].blink(atoi(argv[3]));			//added blink 
      else{ cout << "Invalid command!" << endl; }	
   return 0;
   }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
