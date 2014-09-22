int code1=0;
int code2=0;
int len = 2;
char array[2];
String out = "";
String skin = "";
String gender = "";

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
        skin = "Fair";
        uvIndex = (outputVoltage - 1)*12.5+0.5;
        break;
      case 2:
        skin = "Tanned";
        break;
      case 3:
        skin = "Very Tanned";
        break;
      default:
        Serial.write("nothing");
        break;
    }
    code2 = charToInt(array[1]);
    switch(code2) {
      case 1:
        gender = "Male";
        break;
      case 2:
        gender = "Female";
        break;
      default:
        break;
    }
    Serial.print("Skin is "+skin+" Gender is "+gender+" UV Index is "+String(uvIndex)+"\n");
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
