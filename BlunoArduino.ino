int code1=0; //currently, code1 for skin, code2 for gender
int code2=0;
int code3=0;
int code4=0;
int len = 4;
char array[4];
String out = "";
String skin = "";
String eye = "";
String hair = "";
String frec = "";
String uvTime = "";

int UVOUT = A0; //Output from the sensor
int REF_3V3 = A1; //3.3V power on the Arduino board
int uvIndex;

void setup() {
  Serial.begin(115200);               //initial the Serial
  
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
}

int charToInt(char c) {
  int o = -1;
  if(c=='1')
    o = 1;
  if(c=='2')
    o = 2;
  if(c=='3')
    o = 3;
  if(c=='4')
    o = 4;
  if(c=='5')
    o = 5;
  if(c=='6')
    o = 6;
  if(c=='7')
    o = 7;
  if(c=='8')
    o = 8;
  if(c=='9')
    o = 9;
  if(c=='0')
    o = 0;
  return o;
}

void loop()
{
  uvIndex = -1;
  if(Serial.available())
  {
    int uvLevel = averageAnalogRead(UVOUT);
    int refLevel = averageAnalogRead(REF_3V3);
    float outputVoltage = 3.3 / refLevel * uvLevel;
    Serial.readBytes(array,len);
    code1 = charToInt(array[0]);
    switch(code1) {
      //take in code1, ask more switch statements for hair color, eye color and tanning ability
      //take in age group and gender as well
      //output recommended spf value and duration
      case 1:
        skin = "Very Fair";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 2:
        skin = "Fair";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 3:
        skin = "Normal";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 4:
        skin = "Tanned";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 5:
        skin = "Very Tanned";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 6:
        skin = "Very Very Tanned";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      default:
        skin = "Nothing";
        break;
    }
    code2 = charToInt(array[1]);
    switch(code2) {
      case 1:
        eye = "Light blue, gray or green";
        break;
      case 2:
        eye = "Blue, gray or green";
        break;
      case 3:
        eye = "Dark blue, gray or green";
        break;
      case 4:
        eye = "Brown";
        break;
      case 5:
        eye = "Black";
        break;
      default:
        eye = "Nothing";
        break;
    }
    code3 = charToInt(array[2]);
    switch(code3) {
      case 1:
        hair = "Sandy red";
        break;
      case 2:
        hair = "Blond";
        break;
      case 3:
        hair = "Chestnut or dark blond";
        break;
      case 4:
        hair = "Brown";
        break;
      case 5:
        hair = "Black";
        break;
      default:
        hair = "Nothing";
        break;
    }
    code4 = charToInt(array[3]);
    switch(code4) {
      case 1:
        frec = "Many";
        break;
      case 2:
        frec = "Several";
        break;
      case 3:
        frec = "Few";
        break;
      case 4:
        frec = "Rare";
        break;
      case 5:
        frec = "None";
        break;
      default:
        frec = "Nothing";
        break;
    }
    Serial.print("Skin is "+skin+"\nEye is "+
    eye+"\nHair is "+hair+"\nNumber of freckles is "+
    frec+"\nUV Index is "+String(uvIndex)+
    "\nRecommended UV exposure time is "+uvTime+
    " minutes."+"\n");
    //Serial.print(out);
    //out="";
    //Serial.write(code);    //send what has been received
  }
}

int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 16;
  unsigned int runningValue = 0; 

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return(runningValue);  
}
