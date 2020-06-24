#include<SoftwareSerial.h>
#include <Servo.h>
#define LED_PIN 7

#define buzzer_0 13
#define relay_left 12//左舵机
#define relay_right 5
Servo servo_0;//舵机
SoftwareSerial softSerial1(10,9);
void setup() {
  pinMode(buzzer_0, OUTPUT);
  pinMode(relay_left, OUTPUT);
  pinMode(relay_right, OUTPUT);
  servo_0.attach(3);//舵机三号角
  pinMode(LED_PIN, OUTPUT);
  // 初始化串口通信:
  Serial.begin(9600);
  //初始化软串口通信；
  softSerial1.begin(115200);
   delay(1000);
    Serial.println("hhhhhhhhhhh");
  softSerial1.println("AT+CWMODE=2");
  delay(300);
  softSerial1.println("AT+CIPAP=\"192.168.0.99\"");
  delay(300);
  softSerial1.println("AT+CIPMUX=1");
  delay(300);
  softSerial1.println("AT+CIPSERVER=1,1024");
  // 初始化时设置为高电平熄灭LED
  digitalWrite(LED_PIN, HIGH);
  //监听软串口通信
  digitalWrite(buzzer_0, HIGH);
  delay(1000);
  digitalWrite(buzzer_0, LOW);
 digitalWrite(LED_PIN, LOW);
}
// 两个字符串分别用于存储A、B两端传来的数据:
String receiveString = "";
String chulireceiveString = "";
void loop() {
   //softSerial1.listen();
  // 读取从计算机传入的数据，并通过serial1发送个设备B:
  //if (softSerial1.available() > 0)
 // {
     while (softSerial1.available() > 0)  
      {    
          chulireceiveString += char(softSerial1.read());
          delay(2);
      }
     if (chulireceiveString.length() > 0)
      {
          receiveString = chulireceiveString.substring(11,15);
          chulireceiveString = "";
   
           if (receiveString == "1000")
          {
              Serial.println("66666666");
                 Serial.println(receiveString);
            digitalWrite(relay_left, HIGH);//LOW前进
            digitalWrite(relay_right, HIGH);
            digitalWrite(buzzer_0, LOW);
          }
          if (receiveString == "0100") //左转
          {
            digitalWrite(relay_left, HIGH);
            digitalWrite(relay_right, LOW);
            digitalWrite(buzzer_0, LOW);
    
          }
          if (receiveString == "0010") //右转
          {
            digitalWrite(relay_left, LOW);
            digitalWrite(relay_right, HIGH);
            digitalWrite(buzzer_0, LOW);
    
          }
          if (receiveString == "0001") //buzz
          {
            digitalWrite(relay_left, LOW);
            digitalWrite(relay_right, LOW);
            digitalWrite(buzzer_0, HIGH);
    
          }
          if (receiveString == "1100") //buzz
          {
            digitalWrite(relay_left, HIGH);
            digitalWrite(relay_right, LOW);
            digitalWrite(buzzer_0, LOW);
          }
          if (receiveString == "1010") //buzz
          {
            digitalWrite(relay_left, LOW);
            digitalWrite(relay_right, HIGH);
            digitalWrite(buzzer_0, LOW);
          }
          if (receiveString == "1001") //buzz
          {
            digitalWrite(relay_left, HIGH);
            digitalWrite(relay_right, HIGH);
            digitalWrite(buzzer_0, HIGH);
          }
          if (receiveString== "0000") //buzz
          {
            digitalWrite(relay_left, LOW);
            digitalWrite(relay_right, LOW);
            digitalWrite(buzzer_0, LOW);
          }
          
 
      }

   




}
