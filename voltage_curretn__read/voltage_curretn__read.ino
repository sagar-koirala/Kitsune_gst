#define sp_volt A2
#define sp_current  A5
#define batt_volt A3
#define batt_current A4


void setup() {
pinMode(sp_volt, INPUT);
pinMode(sp_current, INPUT);
pinMode(batt_volt, INPUT);
pinMode(batt_current, INPUT);

Serial.begin(9600);
}

void loop() {

Serial.println(analogRead(sp_volt));
Serial.println(analogRead(sp_current));
Serial.println(analogRead(batt_volt));
Serial.println(analogRead(batt_current));


}
