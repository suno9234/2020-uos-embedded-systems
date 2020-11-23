String Speed;
char  LorR;
int  i, s;

#define motorR_1 4
#define motorR_2 5
#define motorL_1 6
#define motorL_2 7
#define motorL_SpeedControler 3
#define motorR_SpeedControler 9
byte DataToRead[6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorL_1,OUTPUT);
  pinMode(motorL_2,OUTPUT);
  pinMode(motorR_1,OUTPUT);
  pinMode(motorR_2,OUTPUT);
  pinMode(motorL_SpeedControler,OUTPUT);
  pinMode(motorR_SpeedControler,OUTPUT);
  
}

void loop() {
  // 1-HIGH 2-LOW -> 앞으로가기
  analogWrite(motorL_SpeedControler,255);
  analogWrite(motorR_SpeedControler,255);
  digitalWrite(motorL_1,HIGH);
  digitalWrite(motorL_2,LOW);
  digitalWrite(motorR_1,HIGH);
  digitalWrite(motorR_2,LOW);
  
  DataToRead[5] = '\n';
  Serial.readBytesUntil(char(13), DataToRead, 5);
  
  LorR = DataToRead[0];
  Speed = "";
  for (i = 1; (DataToRead[i] != '\n') && (i < 6); i++) {
    Speed += DataToRead[i];
  }
  s = Speed.toInt();
  if (LorR == 'L') {
    analogWrite(motorL_SpeedControler,s);
  }
  else if (LorR == 'R') {
    // Turn right wheel with speed s
    analogWrite(motorR_SpeedControler,s);  
  } 
}
