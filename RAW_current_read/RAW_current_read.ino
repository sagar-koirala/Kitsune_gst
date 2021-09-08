#define batt_current_pin A5
int batt_current = 0;


void setup() {
  pinMode(batt_current_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  batt_current = analogRead(batt_current_pin);
//  batt_current = map(analogRead(batt_current_pin), 0, 954, 0, 5000);
//  Serial.print("Current_consumed: ");
  Serial.print(batt_current);
//  Serial.println("mA");
  Serial.println();
//  delay(100);
}
