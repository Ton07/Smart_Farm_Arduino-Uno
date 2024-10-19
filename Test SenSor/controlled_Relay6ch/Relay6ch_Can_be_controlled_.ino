const int PinRelay1 = 3;
const int PinRelay2 = 4;
const int PinRelay3 = 5;
const int PinRelay4 = 6;
const int PinRelay5 = 7;
const int PinRelay6 = 8;

bool relayStates[6] = {false, false, false, false, false, false}; // เก็บสถานะของรีเลย์
bool allRelaysState = false; // สำหรับควบคุมรีเลย์ทั้งหมด

void setup() {
  pinMode(PinRelay1, OUTPUT);
  pinMode(PinRelay2, OUTPUT);
  pinMode(PinRelay3, OUTPUT);
  pinMode(PinRelay4, OUTPUT);
  pinMode(PinRelay5, OUTPUT);
  pinMode(PinRelay6, OUTPUT);

  // เริ่มต้นด้วยปิดรีเลย์ทั้งหมด
  digitalWrite(PinRelay1, LOW);
  digitalWrite(PinRelay2, LOW);
  digitalWrite(PinRelay3, LOW);
  digitalWrite(PinRelay4, LOW);
  digitalWrite(PinRelay5, LOW);
  digitalWrite(PinRelay6, LOW);

  Serial.begin(9600); // ใช้สำหรับรับข้อมูลตัวเลขที่กด
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read(); // รับข้อมูลจาก Serial
    int relayNumber = input - '0'; // แปลงตัวเลขที่รับมาเป็น int

    if (relayNumber >= 1 && relayNumber <= 6) {
      int index = relayNumber - 1; // แปลงเป็น index สำหรับ relayStates
      relayStates[index] = !relayStates[index]; // สลับสถานะของรีเลย์

      switch (relayNumber) {
        case 1: digitalWrite(PinRelay1, relayStates[0] ? HIGH : LOW); break;
        case 2: digitalWrite(PinRelay2, relayStates[1] ? HIGH : LOW); break;
        case 3: digitalWrite(PinRelay3, relayStates[2] ? HIGH : LOW); break;
        case 4: digitalWrite(PinRelay4, relayStates[3] ? HIGH : LOW); break;
        case 5: digitalWrite(PinRelay5, relayStates[4] ? HIGH : LOW); break;
        case 6: digitalWrite(PinRelay6, relayStates[5] ? HIGH : LOW); break;
      }
    } else if (relayNumber == 7) {
      // สลับสถานะรีเลย์ทั้งหมดพร้อมกันเมื่อกดเลข 7
      allRelaysState = !allRelaysState;

      digitalWrite(PinRelay1, allRelaysState ? HIGH : LOW);
      digitalWrite(PinRelay2, allRelaysState ? HIGH : LOW);
      digitalWrite(PinRelay3, allRelaysState ? HIGH : LOW);
      digitalWrite(PinRelay4, allRelaysState ? HIGH : LOW);
      digitalWrite(PinRelay5, allRelaysState ? HIGH : LOW);
      digitalWrite(PinRelay6, allRelaysState ? HIGH : LOW);
    }
  }
}
