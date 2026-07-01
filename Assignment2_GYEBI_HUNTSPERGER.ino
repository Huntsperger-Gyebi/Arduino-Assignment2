int segment_pins[] = {2, 3, 4, 5, 6, 7, 9}; // a, b, c, d, e, f, g
int num_of_segments = 7;
int buzzer_pin = 8;

// The pattern for each digit. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
 {1, 1, 1, 1, 1, 1, 0}, // 0
 {0, 1, 1, 0, 0, 0, 0}, // 1
 {1, 1, 0, 1, 1, 0, 1}, // 2
 {1, 1, 1, 1, 0, 0, 1}, // 3
 {0, 1, 1, 0, 0, 1, 1}, // 4
 {1, 0, 1, 1, 0, 1, 1}, // 5
 {1, 0, 1, 1, 1, 1, 1}, // 6
 {1, 1, 1, 0, 0, 0, 0}, // 7
 {1, 1, 1, 1, 1, 1, 1}, // 8
 {1, 1, 1, 1, 0, 1, 1}, // 9
};

void showDigit(int n) {
 for (int i = 0; i < num_of_segments; i++) {
  digitalWrite(segment_pins[i], digits[n][i]);
 }
}

void setup() {
 Serial.begin(9600);
 pinMode(buzzer_pin, OUTPUT);

 for (int i = 0; i < num_of_segments; i++) {
  pinMode(segment_pins[i], OUTPUT);
 }

 Serial.println("=== Beeping Countdown Initializing===");
 int count = 9;
 while (count != 0){
  Serial.print("Counting: ");
  Serial.println(count);
  showDigit(count);
  tone(buzzer_pin, 800, 200);
  delay(1000);
  count = count - 1;
 }
 showDigit(0);
 tone(buzzer_pin, 523, 2000); // longer completion tone
 Serial.println("=== Countdown Successful ===");
}


void loop() { 

}