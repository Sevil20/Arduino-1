int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int var5 = 0;
int var6 = 0;
int var7 = 0;


int zone1Pin=2;
int zone2Pin=3;
int zone3Pin=4;
int zone4Pin=5;

int armPin=6;
int darmPin=7;
int rstPin=8;

int buzPin=13;
int sirPin=12;
int pgmPin=11;
int pwrPin=10;

int lcd;

void setup() {
  pinMode(zone1Pin, INPUT_PULLUP);
  pinMode(zone2Pin, INPUT_PULLUP);
  pinMode(zone3Pin, INPUT_PULLUP);
  pinMode(zone4Pin, INPUT_PULLUP);


  pinMode(armPin, INPUT_PULLUP);
  pinMode(darmPin, INPUT_PULLUP);
  pinMode(rstPin, INPUT_PULLUP);

  pinMode(buzPin, OUTPUT);
  pinMode(sirPin, OUTPUT);
  pinMode(pgmPin, OUTPUT);
  pinMode(pwrPin, OUTPUT);

  digitalWrite(buzPin, LOW);
  digitalWrite(sirPin, LOW);
  digitalWrite(pgmPin, LOW);
  digitalWrite(pwrPin, HIGH);

  lcd.begin(20, 4);
  lcd.setCursor(3, 1);
  lcd.print("fire system");
  lcd.setCursor(5, 2);
  lcd.print("setup");

  digitalWrite(buzPin, HIGH);
  delay(250);
  digitalWrite(buzPin, LOW);
  delay(100);
  digitalWrite(buzPin, HIGH);
  delay(250);
  digitalWrite(buzPin, LOW);
  delay(1000);

  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("ARM");
  lcd.setCursor(1, 1);
  lcd.print("D/ARM");


  lcd.setCursor(10, 0);
  lcd.print("zone:1234");
  Serial.begin(9600);
}

void loop() {
  var1 = digitalRead(zone1Pin);
  var2 = digitalRead(zone2Pin);
  var3 = digitalRead(zone3Pin);
  var4 = digitalRead(zone4Pin);

  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);


  Serial.print("var1: ");
  Serial.println(var1);
  Serial.print("var2: ");
  Serial.println(var2);
  Serial.print("var3: ");
  Serial.println(var3);
  Serial.print("var4: ");
  Serial.println(var4);

  zoneScan();
  modeScan();
}
//alt proqram
void zoneScan(){
if(var1==HIGH){
  lcd.setCursor(15,11);
  lcd.print("*");
}
else{
   lcd.setCursor(15,11);
  lcd.print("-");
}

if(var2==HIGH){
  lcd.setCursor(16,11);
  lcd.print("*");
}
else{
   lcd.setCursor(16,11);
  lcd.print("-");
}

if(var3==HIGH){
  lcd.setCursor(17,11);
  lcd.print("*");
}
else{
   lcd.setCursor(17,11);
  lcd.print("-");
}

if(var4==HIGH){
  lcd.setCursor(18,11);
  lcd.print("*");
}
else{
   lcd.setCursor(18,11);
  lcd.print("-");
}
}

void modeScan(){
 if(var5==HIGH){
  lcd.setCursor(0,0);
  lcd.print(">");
}
else{
   lcd.setCursor(0,0);
  lcd.print(" ");
}


}

