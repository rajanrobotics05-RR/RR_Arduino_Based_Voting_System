/*
Rajan Robotics 

*/

#define PRINT_VAR(x) Serial.print(#x " = "); Serial.println(x)
int result=7,A=6,B=5,C=4,buzz=8,reset=3;

/*OLED */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
/OLED end/

void setup() {
// put your setup code here, to run once:
pinMode(7,INPUT);//result
pinMode(6,INPUT);//A
pinMode(5,INPUT);//B
pinMode(4,INPUT);//C
pinMode(reset,INPUT);//3
pinMode(8,OUTPUT);//buzz
Serial.begin(9600);

/OLED/
// Initialize with I2C address 0x3C (try 0x3D if it doesn't work)
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println(F("SSD1306 allocation failed"));
while(1);
}

display.clearDisplay();
display.setTextSize(2);             // Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE); // Draw white pixels
display.setCursor(0, 0);            // Start at top-left corner
display.println(F("Rajan Robotics EVM"));
display.display();                  // Show the text on screen
/OLED end/
digitalWrite(buzz,1);
delay(200);
digitalWrite(buzz,0);
}

int a_status=0,b_status=0,c_status=0,res_status=0,reset_status=0;
int a_vote=0,b_vote=0,c_vote=0;

void loop() {
display.clearDisplay();
display.setTextSize(2);             // Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE); // Draw white pixels
display.setCursor(0, 0);            // Start at top-left corner
display.println(F("Rajan Robotics EVM"));
display.println(F("------------------"));

display.setTextSize(1);             // Normal 1:1 pixel scale
display.println(F("Select A or B or C "));
display.display();                  // Show the text on screen
a_status=digitalRead(A);
b_status=digitalRead(B);
c_status=digitalRead(C);
res_status=digitalRead(result);
reset_status=digitalRead(reset);
// PRINT_VAR(b_status);
// PRINT_VAR(c_status);
// Serial.println("*********");

/////RESET
if(reset_status==1){
PRINT_VAR(reset_status);
a_vote=0;
b_vote=0;
c_vote=0;
display.clearDisplay();
display.setTextSize(1);             // Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE); // Draw white pixels
display.setCursor(0, 0);            // Start at top-left corner
display.println(F("Rajan Robotics EVM"));
display.println(F("------------------"));

PRINT_VAR(a_vote);
PRINT_VAR(b_vote);
PRINT_VAR(c_vote);

display.print("A vote = ");
display.print(a_vote);
display.print(" ");
display.print("B vote = ");
display.println(b_vote);
display.print("C vote = ");
display.println(c_vote);
display.println(" ");

display.setTextSize(1);             // Normal 1:1 pixel scale
display.println(F("RESET"));
display.display();                  // Show the text on screen
while(reset_status==1){
//wait for key debounce
reset_status=digitalRead(reset);
digitalWrite(buzz,HIGH);
delay(500);
digitalWrite(buzz,LOW);
delay(500);
}
//delay(1000);
digitalWrite(buzz,LOW);
}///end of basic if
/////Rest end

///vote for A
if(a_status==1){
PRINT_VAR(a_status);
a_vote++;
PRINT_VAR(a_vote);
Serial.println("Vote casted");

while(a_status==1){  
  //wait for key debounce  
a_status=digitalRead(A);  
digitalWrite(buzz,HIGH);  
}  
//delay(1000);

digitalWrite(buzz,LOW);

vote_Casted();

}///end of basic if

///vote for B
if(b_status==1){
PRINT_VAR(b_status);
b_vote++;
PRINT_VAR(b_vote);
Serial.println("Vote casted");

while(b_status==1){  
  //wait for key debounce  
b_status=digitalRead(B);  
digitalWrite(buzz,HIGH);  
}  
//delay(1000);  
digitalWrite(buzz,LOW);  
vote_Casted();

}///end of basic if

///vote for C
if(c_status==1){
PRINT_VAR(c_status);
c_vote++;
PRINT_VAR(c_vote);
Serial.println("Vote casted");

while(c_status==1){  
  //wait for key debounce  
c_status=digitalRead(C);  
digitalWrite(buzz,HIGH);  
}  
//delay(1000);  
digitalWrite(buzz,LOW);  
vote_Casted();

}///end of basic if

////////////////////////////////////////////////////////

/Result/
///vote for C
if(res_status==1){
//PRINT_VAR(res_status);
//c_vote++;
//PRINT_VAR(c_vote);
//Serial.println("Vote casted");

while(res_status==1){  
  //wait for key debounce  
res_status=digitalRead(result);  
digitalWrite(buzz,HIGH);  
delay(100);  
digitalWrite(buzz,LOW);  
delay(100);  
}  
//delay(1000);  
result_anounce();  
digitalWrite(buzz,LOW);

}///end of basic if

}

void result_anounce(){
display.clearDisplay();
display.setTextSize(1);             // Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE); // Draw white pixels
display.setCursor(0, 0);            // Start at top-left corner
display.println(F("Rajan Robotics EVM"));
display.println(F("------------------"));
//display.setCursor(2, 0);            // Start at top-left corner

PRINT_VAR(a_vote);
PRINT_VAR(b_vote);
PRINT_VAR(c_vote);

display.print("A vote = ");
display.print(a_vote);
display.print(" ");
display.print("B vote = ");
display.println(b_vote);
display.print("C vote = ");
display.println(c_vote);
display.println(" ");

display.setTextSize(1);
if(a_vote == b_vote && b_vote == c_vote){
Serial.println("All candidates are tied");
display.println(F("All candidates are tied"));
}

else if(a_vote > b_vote && a_vote > c_vote){
Serial.println("A is winner");
display.println(F("A is winner"));
}

else if(b_vote > a_vote && b_vote > c_vote){
Serial.println("B is winner");
display.println(F("B is winner"));
}

else if(c_vote > a_vote && c_vote > b_vote){
Serial.println("C is winner");
display.println(F("C is winner"));
}

else{
Serial.println("There is a tie between candidates");
display.println(F("There is a tie between candidates"));
}
display.display();                  // Show the text on scree
Serial.println("*********");
delay(3000);
}

void vote_Casted(){
//Serial.println(i);
display.clearDisplay();
display.setTextSize(1);             // Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE); // Draw white pixels
display.setCursor(0, 0);            // Start at top-left corner
display.println(F("Rajan Robotics EVM"));
display.println(F("------------------"));
display.setTextSize(1);             // Normal 1:1 pixel scale
display.println(F("VOTE Casted"));
display.display();                  // Show the text on screen
delay(1000);
}

This code works perfectly with vote, result and reset.
