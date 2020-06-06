//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////// Sound event (Gunshot) detection system v0.1 written by Brad Hutson Jr @ 3/17/2020 ///
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


/// Pin assignments
int Mic1PinAnalog = A1;
int LEDPin = 13;



/// Floating value for Mic sound level used during comparison with NoiseFloor.
int MicValue1 = 0;


/// This is our NoiseFloor Value. It is used to determine what the current noise level is and is used later for comparison with our MicValues for any spikes to the volume level for detection of sudden loud sound events.
int NoiseFloorValue = 0;


/// This is our delay between NoiseFloor sampling and our sound event, use it for fine tuning event detection sensitivity.
int SampleDelay = 1;


/// This is the noise threshold above the NoiseFloorValue. It sets our threshhold above our NoiseFloor. Fine tune this for sound event detection sensitivity.
int SoundEventThreshhold  = 350;


/// Other Variables
;int  Mic1Digitalval; // Define a digital variable val.


void setup() {

/// Pin I/O Setup
  pinMode(LEDPin, OUTPUT);
  pinMode(Mic1PinAnalog, INPUT);


/// Serial Monitor Setup
  Serial.begin(9600);
  
 }




void loop() {

/// Assign our clock to dt
  //dt = clock.getDateTime();

 

/// Sound Detection begin.
  
  
  /// Listen for our current NoiseFloor
  NoiseFloorValue = analogRead(Mic1PinAnalog);
  //Serial.println(NoiseFloorValue); // Prints Noise floor to serial monitor for debug.


  /// Wait a bit, specified via SampleDelay
  delay(SampleDelay);


  /// Sample again after our Delay for any sudden spikes.
  MicValue1 = analogRead(Mic1PinAnalog); 
  //Serial.println(MicValue1); // Prints Mic1 sample value to serial monitor for debug.





//// Begin our check for a sound event!



/// Listening for a sound event using pure analog.

if(NoiseFloorValue-MicValue1>SoundEventThreshhold)
{

  /// Pull an LED on specified pin high for visual indication on hardware to indicate an event has occurred.
  digitalWrite(LEDPin, HIGH);


  /// Serial output about current task.
  Serial.print("Event Occurred at: ");
 // Serial.println(clock.dateFormat("d-m-Y H:i:s", dt));
  Serial.print("Sound level above background noise: ");
  Serial.println(NoiseFloorValue-MicValue1);


  /// Wait and turn LED off by pulling the pin LOW, ending visual hardware event notification.
  delay(2000);
  digitalWrite(LEDPin, LOW);

  }

/// End sound event check using pure analog.



  
}
