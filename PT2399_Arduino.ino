//Arduino control VCO of a PT2399
//Step sequencer (1 to 6)
//Control speed of step sequencer
//Choose number of step
//Choose direction of step sequencer (forward/backward)
    //Need to add a return mode when last arrived at last step
//Choose random step
//Balance mode between a min and a max value

//copyleft DMA Evil Corps

//Define SPI for the digital potentiometer
#include <SPI.h>
const int SlaveSelectPin = 10; //CS = 10 | SDI = 11 | CLK = 13
byte SPI_pot_address = 0x11;

//Define potentiometers pins
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;
int pot5 = A4;
int pot6 = A5;
int pot7 = A6;
int pot8 = A7;

//Define leds pins
int led_pot1 = 32; //D2
int led_pot2 = 1; //D3
int led_pot3 = 2; //D4
int led_pot4 = 9; //D5
int led_pot5 = 10; //D6
int led_pot6 = 11; //D7

//Define buttons pins
int Random_button = 31;
int Direction_button = 30;
int Balance_button = 12;
int Return_button = 13;

//Define system variables
int pot1_value = 0;
int pot2_value = 0;
int pot3_value = 0;
int pot4_value = 0;
int pot5_value = 0;
int pot6_value = 0;
int pot7_value = 0;
int pot8_value = 0;

int Random_button_value = 0;
int Direction_button_value = 0;
int Balance_button_value = 0;
int Return_button_value = 0;

int number_of_step = 1;
int speed_of_sequencer = 1;
int SPI_pot_value = 0;
int random_value = 0;
int random_step_value = 1;

int Balance_min_value = 0;
int Balance_max_value = 0;
int Balance_min_loop_value = 1;
int Balance_max_loop_value = 0;


void setup() {

  //Set the SPI slave select Pin as an output
  pinMode(SlaveSelectPin, OUTPUT);
  SPI.begin();

  //Declare the leds pins as outputs
  pinMode(led_pot1, OUTPUT);
  pinMode(led_pot2, OUTPUT);
  pinMode(led_pot3, OUTPUT);
  pinMode(led_pot4, OUTPUT);
  pinMode(led_pot5, OUTPUT);
  pinMode(led_pot6, OUTPUT);

  //Declare the switch pins as inputs
  pinMode(Random_button, INPUT);
  pinMode(Direction_button, INPUT);
  pinMode(Balance_button, INPUT);
  pinMode(Return_button, INPUT);

  //First run, activate led1 (mean no step sequencer)
  digitalWrite(led_pot1, HIGH);

}

void loop() {

  //Est-ce que l'on reste dans la boucle for tant que la valeur du i n'est pas atteinte ?
  //Si oui, il faut appeler à chaque tour les deux sous fonction ReadPot et ReadSwitch

  //Read potentiometers values
  ReadPot;

  //Read the state of the switchs
  ReadSwitch;

  //Balance mode OFF, we use the step sequencer
  if (Balance_button_value = LOW) {
    //Sequencer loop
    if (Random_button_value = LOW) {
      //Choose the direction of the loop
      if (Direction_button_value = LOW) {
        for (int i = 1; i <= number_of_step; i++) {
          //ReadPot;
          //ReadSwitch;
          //For each i the value of the corresponding step pot is write the digital potentiometer
          switch (i) {
            case 1:
              SPI_pot_value = pot1_value;
              digitalWrite(led_pot1, HIGH);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 2:
              SPI_pot_value = pot2_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, HIGH);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 3:
              SPI_pot_value = pot3_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, HIGH);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 4:
              SPI_pot_value = pot4_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, HIGH);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 5:
              SPI_pot_value = pot5_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, HIGH);
              digitalWrite(led_pot6, LOW);
              break;
            case 6:
              SPI_pot_value = pot6_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, HIGH);
              break;
          }
          //Activate the corresponding led of the current step

          //Write the SPI digital potentiometer
          digitalPotWrite(SPI_pot_value);

          //Time delay before next i
          delay(speed_of_sequencer);
        }
      }
      if (Direction_button_value = HIGH) {
        for (int j = 1; j <= number_of_step; j++) {
          //ReadPot;
          //ReadSwitch;
          //For each j the value of the corresponding step pot is write the digital potentiometer
          switch (j) {
            case 6:
              SPI_pot_value = pot1_value;
              digitalWrite(led_pot1, HIGH);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 5:
              SPI_pot_value = pot2_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, HIGH);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 4:
              SPI_pot_value = pot3_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, HIGH);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 3:
              SPI_pot_value = pot4_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, HIGH);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, LOW);
              break;
            case 2:
              SPI_pot_value = pot5_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, HIGH);
              digitalWrite(led_pot6, LOW);
              break;
            case 1:
              SPI_pot_value = pot6_value;
              digitalWrite(led_pot1, LOW);
              digitalWrite(led_pot2, LOW);
              digitalWrite(led_pot3, LOW);
              digitalWrite(led_pot4, LOW);
              digitalWrite(led_pot5, LOW);
              digitalWrite(led_pot6, HIGH);
              break;
          }
          //Activate the corresponding led of the current step

          //Write the SPI digital potentiometer
          digitalPotWrite(SPI_pot_value);

          //Time delay before next i
          delay(speed_of_sequencer);
        }
      }
    }
    if (Random_button_value = HIGH) {
      //Get a random value between 1 to max step
      random_step_value = random(1, number_of_step);
      switch (random_step_value) {
        case 1:
          SPI_pot_value = pot1_value;
          digitalWrite(led_pot1, HIGH);
          digitalWrite(led_pot2, LOW);
          digitalWrite(led_pot3, LOW);
          digitalWrite(led_pot4, LOW);
          digitalWrite(led_pot5, LOW);
          digitalWrite(led_pot6, LOW);
          break;
        case 2:
          SPI_pot_value = pot2_value;
          digitalWrite(led_pot1, LOW);
          digitalWrite(led_pot2, HIGH);
          digitalWrite(led_pot3, LOW);
          digitalWrite(led_pot4, LOW);
          digitalWrite(led_pot5, LOW);
          digitalWrite(led_pot6, LOW);
          break;
        case 3:
          SPI_pot_value = pot3_value;
          digitalWrite(led_pot1, LOW);
          digitalWrite(led_pot2, LOW);
          digitalWrite(led_pot3, HIGH);
          digitalWrite(led_pot4, LOW);
          digitalWrite(led_pot5, LOW);
          digitalWrite(led_pot6, LOW);
          break;
        case 4:
          SPI_pot_value = pot4_value;
          digitalWrite(led_pot1, LOW);
          digitalWrite(led_pot2, LOW);
          digitalWrite(led_pot3, LOW);
          digitalWrite(led_pot4, HIGH);
          digitalWrite(led_pot5, LOW);
          digitalWrite(led_pot6, LOW);
          break;
        case 5:
          SPI_pot_value = pot5_value;
          digitalWrite(led_pot1, LOW);
          digitalWrite(led_pot2, LOW);
          digitalWrite(led_pot3, LOW);
          digitalWrite(led_pot4, LOW);
          digitalWrite(led_pot5, HIGH);
          digitalWrite(led_pot6, LOW);
          break;
        case 6:
          SPI_pot_value = pot6_value;
          digitalWrite(led_pot1, LOW);
          digitalWrite(led_pot2, LOW);
          digitalWrite(led_pot3, LOW);
          digitalWrite(led_pot4, LOW);
          digitalWrite(led_pot5, LOW);
          digitalWrite(led_pot6, HIGH);
          break;
      }

      //Write the SPI digital potentiometer
      digitalPotWrite(SPI_pot_value);

      //Time delay before next change
      delay(speed_of_sequencer);
    }
  }

  //Balance mode ON, we make a sweep of the digital potentiometer value between a min and a max value
  if (Balance_button_value = HIGH) {
    //ReadPot;
    //ReadSwitch;
    Balance_min_value = pot1_value;
    Balance_max_value = pot2_value;

    //Visual indication of the mode
    digitalWrite(led_pot1, HIGH);
    digitalWrite(led_pot2, HIGH);
    digitalWrite(led_pot3, LOW);
    digitalWrite(led_pot4, LOW);
    digitalWrite(led_pot5, LOW);
    digitalWrite(led_pot6, LOW);

    if (Random_button_value = LOW) {

      //Actually this loop only goes in one direction and do not reverse at the end...
      if (Balance_min_loop_value = HIGH) {
        for (int k = Balance_min_value; k <= Balance_max_value; k++) {

          //The digital potentiometer value will varie at each turn of the loop
          SPI_pot_value = k;

          //Write the SPI digital potentiometer
          digitalPotWrite(SPI_pot_value);

          //Time delay before next i
          delay(speed_of_sequencer);
          if (k >= Balance_max_value) {
            Balance_min_loop_value = LOW;
            Balance_max_loop_value = HIGH;
          }
        }
      }

      if (Balance_max_loop_value = HIGH) {
        for (int h = Balance_max_value; h <= Balance_min_value; h--) {

          //The digital potentiometer value will varie at each turn of the loop
          SPI_pot_value = h;

          //Write the SPI digital potentiometer
          digitalPotWrite(SPI_pot_value);

          //Time delay before next i
          delay(speed_of_sequencer);
          if (h <= Balance_min_value) {
            Balance_min_loop_value = HIGH;
            Balance_max_loop_value = LOW;
          }
        }
      }
    }
    //The random button bypass the sweep between min and max
    //It just change the value of the digital potentiometer randomly
    if (Random_button_value = HIGH) {
      //Generate random number
      random_value = random(0, 255);
      SPI_pot_value = random_value;

      //Write the SPI digital potentiometer
      digitalPotWrite(SPI_pot_value);

      //Time delay before next change
      delay(speed_of_sequencer);
    }

  }

}

void digitalPotWrite(int value) {
  digitalWrite(SlaveSelectPin, LOW);
  SPI.transfer(SPI_pot_address);
  SPI.transfer(value);
  digitalWrite(SlaveSelectPin, HIGH);
}

void ReadPot() {
  //Read potentiometers values
  pot1_value = analogRead(pot1);
  pot2_value = analogRead(pot2);
  pot3_value = analogRead(pot3);
  pot4_value = analogRead(pot4);
  pot5_value = analogRead(pot5);
  pot6_value = analogRead(pot6);
  pot7_value = analogRead(pot7);
  pot8_value = analogRead(pot8);

  //Convert pot8 value to a number of step (1 to 6)
  number_of_step = map(pot8_value, 1, 6, 0, 255);

  //convert_pot7 value to a speed/time value (1s to 10s)
  //min and max time can be replace with variables or external control...
  speed_of_sequencer = map(pot7_value, 100, 10000, 0, 255); //delay in ms
}

void ReadSwitch() {
  Random_button_value = digitalRead(Random_button);
  Direction_button_value = digitalRead(Direction_button);
  Balance_button_value = digitalRead(Balance_button);
  Return_button_value = digitalRead(Return_button);
}
