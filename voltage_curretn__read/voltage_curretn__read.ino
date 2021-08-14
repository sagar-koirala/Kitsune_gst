
#define batt_volt_pin A5
#define sp_volt_pin A4
#define batt_current_pin A1
#define sp_current_pin  A0

float sp_volt = 0;
float sp_current = 0;
float batt_volt = 0;
int batt_current = 0;

void setup() {
  pinMode(sp_volt_pin, INPUT);
  pinMode(sp_current_pin, INPUT);
  pinMode(batt_volt_pin, INPUT);
  pinMode(batt_current_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  batt_volt = map(analogRead(batt_volt_pin), 0, 654, 0, 420)/100.0;
  Serial.print("Battery_Volt: ");
  Serial.print(batt_volt);
  Serial.println("V");
  sp_volt = map(analogRead(sp_volt_pin), 0, 930, 0, 600)/100.0;
  Serial.print("SolarPanel_Volt: ");
  Serial.print(sp_volt);
  Serial.println("V");
  batt_current = map(analogRead(batt_current_pin), 0, 954, 0, 5000);
  Serial.print("Current_consumed: ");
  Serial.print(batt_current);
  Serial.println("mA");
  Serial.println();
  delay(100);
  
}
