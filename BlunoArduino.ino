int code[11];
int value[11];
int len = 11;
char array[11];
int score = 0;
int uvTimeInt = -1;
String uvTimeStr = "";
String scoreStr = "";
String skinType = "";
String out = "";
String skin = "";
String eye = "";
String hair = "";
String frec = "";
String burn = "";
String brownFreq = "";
String brownInt = "";
String face = "";
String tanFreq = "";
String tanHist = "";
String uvTime = "";
String psiStr = "";

int UVOUT = A0; //Output from the sensor
int REF_3V3 = A4; //3.3V power on the Arduino board
int uvIndex;
String uvIndexStr = "";
float outputVoltage;

int fanSwitch = 4;
int fanPin = 11;

int ldrResistor = A2;
float ldrMeasured = 0;
float ldrVoltage = 0;

float calibrateLdrMeasured = 0;
float calibrateLdrVoltage = 0;

float ldrVoltDiff = 0;
float psi = 0;

void setup() {
  Serial.begin(115200);               //initial the Serial
  
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
  pinMode(fanSwitch, INPUT);
  pinMode(fanPin, OUTPUT);
  
  for(int i=0; i<len; i++) {
    code[i] = 0;
  }  
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
  int fanOnOff = digitalRead(fanSwitch);
  if(fanOnOff == HIGH) {
    digitalWrite(fanPin, HIGH);
//    Serial.println("on");
  }
  else {
    digitalWrite(fanPin,LOW);
  }
  uvIndex = -1;
  score = 0;
  outputVoltage = 0;
  if(Serial.available())
  {
    int uvLevel = averageAnalogRead(UVOUT);
    int refLevel = averageAnalogRead(REF_3V3);
    outputVoltage = 3.3 / refLevel * uvLevel;
    Serial.readBytes(array,len);
    for(int j=0; j<len; j++) {
      code[j] = charToInt(array[j]);
    }
    switch(code[0]) {
      case 1:
        eye = "0";
        value[0]=0;
        break;
      case 2:
        eye = "1";
        value[0]=1;
        break;
      case 3:
        eye = "2";
        value[0]=2;
        break;
      case 4:
        eye = "3";
        value[0]=3;
        break;
      case 5:
        eye = "4";
        value[0]=4;
        break;
      default:
        eye = "-1";
        value[0]=-99;
        break;
    }
    switch(code[1]) {
      case 1:
        hair = "0";
        value[1]=0;
        break;
      case 2:
        hair = "1";
        value[1]=1;
        break;
      case 3:
        hair = "2";
        value[1]=2;
        break;
      case 4:
        hair = "2";
        value[1]=2;
        break;
      case 5:
        hair = "3";
        value[1]=3;
        break;
      case 6:
        hair = "4";
        value[1]=4;
        break;
      default:
        hair = "-1";
        value[1]=-99;
        break;
    }
    switch(code[2]) {
      case 1:
        skin = "0";
        value[2]=0;
        uvTime = "10";
        break;
      case 2:
        skin = "1";
        value[2]=1;
        uvTime = "10";
        break;
      case 3:
        skin = "2";
        value[2]=2;
        uvTime = "10";
        break;
      case 4:
        skin = "2";
        value[2]=2;
        uvTime = "10";
        break;
      case 5:
        skin = "3";
        value[2]=3;
        uvTime = "10";
        break;
      case 6:
        skin = "4";
        value[2]=4;
        uvTime = "10";
        break;
      default:
        skin = "-99";
        value[2]=-99;
        break;
    }
    switch(code[3]) {
      case 1:
        frec = "0";
        value[3]=0;
        break;
      case 2:
        frec = "1";
        value[3]=1;
        break;
      case 3:
        frec = "2";
        value[3]=2;
        break;
      case 4:
        frec = "3";
        value[3]=3;
        break;
      case 5:
        frec = "4";
        value[3]=4;
        break;
      default:
        frec = "99";
        value[3]=-99;
        break;
    }
    switch(code[4]) {
      case 1:
        burn = "0";
        value[4]=0;
        break;
      case 2:
        burn = "1";
        value[4]=1;
        break;
      case 3:
        burn = "2";
        value[4]=2;
        break;
      case 4:
        burn = "3";
        value[4]=3;
        break;
      case 5:
        burn = "4";
        value[4]=4;
        break;
      default:
        burn = "99";
        value[4]=-99;
        break;
    }
    switch(code[5]) {
      case 1:
        brownFreq = "0";
        value[5]=0;
        break;
      case 2:
        brownFreq = "1";
        value[5]=1;
        break;
      case 3:
        brownFreq = "2";
        value[5]=2;
        break;
      case 4:
        brownFreq = "3";
        value[5]=3;
        break;
      case 5:
        brownFreq = "4";
        value[5]=4;
        break;
      default:
        brownFreq = "99";
        value[5]=-99;
        break;
    }
    switch(code[6]) {
      case 1:
        brownInt = "0";
        value[6]=0;
        break;
      case 2:
        brownInt = "1";
        value[6]=1;
        break;
      case 3:
        brownInt = "2";
        value[6]=2;
        break;
      case 4:
        brownInt = "3";
        value[6]=3;
        break;
      case 5:
        brownInt = "4";
        value[6]=4;
        break;
      default:
        brownInt = "99";
        value[6]=-99;
        break;
    }
    switch(code[7]) {
      case 1:
        face = "0";
        value[7]=0;
        break;
      case 2:
        face = "1";
        value[7]=1;
        break;
      case 3:
        face = "2";
        value[7]=2;
        break;
      case 4:
        face = "3";
        value[7]=3;
        break;
      case 5:
        face = "4";
        value[7]=4;
        break;
      default:
        face = "99";
        value[7]=-99;
        break;
    }
    switch(code[8]) {
      case 1:
        tanFreq = "0";
        value[8]=0;
        break;
      case 2:
        tanFreq = "1";
        value[8]=1;
        break;
      case 3:
        tanFreq = "2";
        value[8]=2;
        break;
      case 4:
        tanFreq = "3";
        value[8]=3;
        break;
      case 5:
        tanFreq = "4";
        value[8]=4;
        break;
      default:
        tanFreq = "99";
        value[8]=-99;
        break;
    }
    switch(code[9]) {
      case 1:
        tanHist = "0";
        value[9]=0;
        break;
      case 2:
        tanHist = "1";
        value[9]=1;
        break;
      case 3:
        tanHist = "2";
        value[9]=2;
        break;
      case 4:
        tanHist = "3";
        value[9]=3;
        break;
      case 5:
        tanHist = "4";
        value[9]=4;
        break;
      default:
        tanHist = "99";
        value[9]=-99;
        break;
    }
    switch(code[10]) {
      case 0:
        calibrateLdrMeasured = analogRead(ldrResistor);
        calibrateLdrVoltage = calibrateLdrMeasured * (5.0 / 1024);
        break;
      case 1:
        ldrMeasured = analogRead(ldrResistor);
        ldrVoltage = ldrMeasured * (5.0 / 1024); 
        ldrVoltDiff = calibrateLdrVoltage - ldrVoltage;
        break;
    }
    psi = ldrVoltDiff/0.0002;
    if(psi > 300) {
      psiStr = "3";
    }
    else if(psi > 100) {
      psiStr = "2";
    }
    else if(psi > -1) {
      psiStr = "1";
    }
    else {
      psiStr = "9";
    }
    
    uvIndex = (outputVoltage - 1)*12.5+0.5;
    if(uvIndex<10) {
      uvIndexStr="0"+String(uvIndex);
    }
    else {
      uvIndexStr=String(uvIndex);
    }
    
    for(int k=0; k<len; k++) {
      score+=value[k];
    }

    if(score>-1) {
      skinType = "I";
      if(uvIndex>0) {
        uvTimeInt = 1.0*67/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 67;
      }
    }
    if(score>6) {
      skinType = "II";
      if(uvIndex>0) {
        uvTimeInt = 1.0*100/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 100;
      }
    }
    if(score>13) {
      skinType = "III";
      if(uvIndex>0) {
        uvTimeInt = 1.0*200/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 200;
      }
    }
    if(score>20) {
      skinType = "IV";
      if(uvIndex>0) {
        uvTimeInt = 1.0*300/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 300;
      }
    }
    if(score>27) {
      skinType = "V";
      if(uvIndex>0) {
        uvTimeInt = 1.0*400/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 400;
      }
    }
    if(score>34) {
      skinType = "VI";
      if(uvIndex>0) {
        uvTimeInt = 1.0*500/uvIndex + 0.5;
      }
      else {
        uvTimeInt = 500;
      }
    }
    
    if(uvTimeInt<1000) {
        uvTimeStr = String(uvTimeInt);
    }
    if(uvTimeInt<100) {
        uvTimeStr = "0"+String(uvTimeInt);
    }
    if(uvTimeInt<10) {
        uvTimeStr = "00"+String(uvTimeInt);
    }
    if(score <10){
       scoreStr = "0"+String(score);
    }
     else {
       scoreStr = String(score);
     }
    Serial.print(scoreStr+uvIndexStr+uvTimeStr+psiStr);
  }
}

int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0; 

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return(runningValue);  
}
