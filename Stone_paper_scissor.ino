#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
void print(String) ;
void check(String) ;
void win(String) ;
String validation(String) ;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2) ;
}

void loop() {
  lcd.setCursor(0,0) ;
  lcd.print("ENTER YOUR MOVE:");
  delay(1000) ;
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    print(input) ;
    delay(2000) ;
    check(input) ;
  }
}
String validation(String input){
  if(input == "STONE" || input == "Stone" || input == "stone"){
    return "STONE" ;
  }
  else if(input == "PAPER" || input == "Paper" || input == "paper"){
    return "PAPER" ;
  }
  else if(input == "SCISSOR" || input == "Scissor" || input == "scissor"){
    return "SCISSOR" ;
  }
  else{
  return "Invalid input" ;
  }
}
void print( String input1 ){
 	lcd.clear() ;
    lcd.setCursor(0,0) ;
    lcd.print("You typed: ");
    lcd.setCursor(0,1) ;
    lcd.println(input1);
}
void check( String turn ){
  String n = validation(turn) ;
  if( n == "STONE" || n == "PAPER" || n == "SCISSOR" ){
  lcd.clear() ;
  lcd.setCursor(0,0) ;
  lcd.print("Your : ") ;
  lcd.setCursor(8,0) ;
  lcd.print(turn) ;
  win(n) ;
  }
  else{
  lcd.clear() ;
  lcd.print("Invalid input") ;
  delay(2000) ;
  }
}
void win(String move){
  String comp_choice ;
  randomSeed(analogRead(A2)) ;
  int choice = random(1,4) ;
  if(choice == 1 ){
    comp_choice = "STONE" ;
    lcd.setCursor(0,1) ;
    lcd.print("Comp : ") ;
    lcd.setCursor(8,1) ;
    lcd.print(comp_choice) ;
  }
  else if(choice == 2 ){
    comp_choice = "PAPER" ;
    lcd.setCursor(0,1) ;
    lcd.print("Comp : ") ;
    lcd.setCursor(8,1) ;
    lcd.print(comp_choice) ;
  }
  else if(choice == 3 ){
    comp_choice = "SCISSOR" ;
    lcd.setCursor(0,1) ;
    lcd.print("Comp : ") ;
    lcd.setCursor(8,1) ;
    lcd.print(comp_choice) ;
  }
  delay(2000) ;
  lcd.clear() ;
  lcd.setCursor(2,0) ;
  lcd.print("**RESULT**") ;
  if(move == comp_choice ){
    lcd.setCursor(4,1) ;
    lcd.print("Draw!!") ;
  }
  else if(move == "STONE" && comp_choice == "SCISSOR" ){
    lcd.setCursor(3,1) ;
    lcd.print("YOU WIN !!") ;
  }
  else if(move == "SCISSOR" && comp_choice == "PAPER" ){
    lcd.setCursor(3,1) ;
    lcd.print("YOU WIN !!") ;
  }
  else if(move == "PAPER" && comp_choice == "STONE" ){
    lcd.setCursor(3,1) ;
    lcd.print("YOU WIN !!") ;
  }
  else if(move == "SCISSOR" && comp_choice == "STONE" ){
    lcd.setCursor(1,1) ;
    lcd.print("COMPUTER WIN !!") ;
  }
  else if(move == "PAPER" && comp_choice == "SCISSOR" ){
    lcd.setCursor(1,1) ;
    lcd.print("COMPUTER WIN !!") ;
  }
  else if(move == "STONE" && comp_choice == "PAPER" ){
    lcd.setCursor(1,1) ;
    lcd.print("COMPUTER WIN !!") ;
  }
  delay(2000) ;
  lcd.clear() ;
}