#define NUM_RELAYS 4
#define DO_PIN_0  4


void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < NUM_RELAYS; i++){
    pinMode(getPin(i), OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    String in = Serial.readString();

    if(in.equalsIgnoreCase("start")){
      allRelaysON();
    }
    else if(in.equalsIgnoreCase("stop")){
      allRelaysOFF();
    }
    else{
      //error? nah we'll just ignore it for now
    }
    delay(300);
}

void allRelaysON(){
  for(int i =0; i < NUM_RELAYS; i++){
    relayOn(getPin(i));
  }
}

void allRelaysOFF(){
  for(int i =0; i < NUM_RELAYS; i++){
    relayOff(getPin(i));
  }
}

void relayOn(int pinIndex){
  digitalWrite(pinIndex, HIGH);
}

void relayOff(int pinIndex){
  digitalWrite(pinIndex, LOW);
}

int getPin(int index){
  return index + DO_PIN_0;
}
