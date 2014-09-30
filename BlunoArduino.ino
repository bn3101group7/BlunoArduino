int code1=0; //currently, code1 for skin, code2 for gender
int code2=0;
int code3=0;
int code4=0;
int code5=0;
int code6=0;
int code7=0;
int code8=0;
int len = 8;
char array[8];
String out = "";
String skin = "";
String eye = "";
String hair = "";
String frec = "";
String burn = "";
String brownFreq = "";
String brownInt = "";
String face = "";
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
      case 1:
        eye = "1";
        break;
      case 2:
        eye = "2";
        break;
      case 3:
        eye = "3";
        break;
      case 4:
        eye = "4";
        break;
      case 5:
        eye = "5";
        break;
      default:
        eye = "6";
        break;
    }
    code2 = charToInt(array[1]);
    switch(code2) {
      case 1:
        hair = "1";
        break;
      case 2:
        hair = "2";
        break;
      case 3:
        hair = "3";
        break;
      case 4:
        hair = "4";
        break;
      case 5:
        hair = "5";
        break;
      default:
        hair = "6";
        break;
    }
    code3 = charToInt(array[2]);
    switch(code3) {
      //take in code1, ask more switch statements for hair color, eye color and tanning ability
      //take in age group and gender as well
      //output recommended spf value and duration
      case 1:
        skin = "1";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 2:
        skin = "2";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 3:
        skin = "3";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 4:
        skin = "4";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 5:
        skin = "5";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      case 6:
        skin = "6";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        uvTime = "10";
        break;
      default:
        skin = "99";
        break;
    }
    code4 = charToInt(array[3]);
    switch(code4) {
      case 1:
        frec = "1";
        break;
      case 2:
        frec = "2";
        break;
      case 3:
        frec = "3";
        break;
      case 4:
        frec = "4";
        break;
      case 5:
        frec = "5";
        break;
      default:
        frec = "99";
        break;
    }
    code5 = charToInt(array[4]);
    switch(code5) {
      case 1:
        burn = "1";
        break;
      case 2:
        burn = "2";
        break;
      case 3:
        burn = "3";
        break;
      case 4:
        burn = "4";
        break;
      case 5:
        burn = "5";
        break;
      default:
        burn = "99";
        break;
    }
    code6 = charToInt(array[5]);
    switch(code6) {
      case 1:
        brownFreq = "1";
        break;
      case 2:
        brownFreq = "2";
        break;
      case 3:
        brownFreq = "3";
        break;
      case 4:
        brownFreq = "4";
        break;
      case 5:
        brownFreq = "5";
        break;
      default:
        brownFreq = "99";
        break;
    }
    code7 = charToInt(array[6]);
    switch(code7) {
      case 1:
        brownInt = "1";
        break;
      case 2:
        brownInt = "2";
        break;
      case 3:
        brownInt = "3";
        break;
      case 4:
        brownInt = "4";
        break;
      case 5:
        brownInt = "5";
        break;
      default:
        brownInt = "99";
        break;
    }
    code8 = charToInt(array[7]);
    switch(code8) {
      case 1:
        face = "1";
        break;
      case 2:
        face = "2";
        break;
      case 3:
        face = "3";
        break;
      case 4:
        face = "4";
        break;
      case 5:
        face = "5";
        break;
      default:
        face = "99";
        break;
    }
    Serial.print("Skin "+skin+
    "\nEye "+eye+
    "\nHair "+hair+
    "\nFreckles "+frec+
    "\nBurn "+burn+
    "\nBrown Freq "+brownFreq+
    "\nBrown Int "+brownInt+
    "\nFace "+face+
    "\nUV Index "+String(uvIndex)+
    "\nRecommended UV exposure time is "+uvTime+" minutes."+"\n");
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
