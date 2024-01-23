String BT_msg = "*10000";


unsigned long sleep_time;

void setup() { Serial.begin(9600); }

// The loop() function runs repeatedly after the setup() function.
void loop() {
  // Use `substring()` function to extract a substring from "My_S".
  // The parameters (0, 5) specify that we want to extract characters from index
  // 0 to 4 (inclusive).
  String code_for_alarm = BT_msg.substring(0,1);
  String duration_befo_off = BT_msg.substring(1);

  Serial.println(code_for_alarm);
  Serial.println(duration_befo_off);

  angl_rotation_current = duration_befo_off.toInt();
  Serial.println(angl_rotation_current);
  // Add a delay of 1000 milliseconds (1 second) before the next iteration.
  delay(angl_rotation_current);
}