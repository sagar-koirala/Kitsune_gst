#define sp_volt_pin A4
#define sp_current_pin  A1
#define batt_volt_pin A5
#define batt_current_pin A4

float sp_volt = 0;
float sp_current = 0;
float batt_volt = 0;
float batt_current = 0;

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
  Serial.println(batt_volt);
  sp_volt = map(analogRead(sp_volt_pin), 0, 930, 0, 600)/100.0;
  Serial.print("SolarPanel_Volt: ");
  Serial.println(sp_volt);
  Serial.println();
  delay(100);

}
