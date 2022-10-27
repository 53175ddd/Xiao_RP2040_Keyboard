#include <Keyboard.h>

#define DEBUG

#define Scan0 D3
#define Scan1 D4
#define Scan2 D5
#define Read0 D7
#define Read1 D8
#define Read2 D9
#define Read3 D10

const uint8_t Scan[] = {Scan0, Scan1, Scan2};
const uint8_t Read[] = {Read0, Read1, Read2, Read3};

uint8_t Matrix[sizeof(Scan)][sizeof(Read)];

void setup() {
#ifdef DEBUG
  Serial.begin(115200);  // デバッグ用シリアル通信を115200bpsで開始:
#endif
  Keyboard.begin();      // キーボードエミュレート開始:

  for(uint8_t i = 0; i < sizeof(Read); i++) {  // 読み取り線を入力にしてプルアップ:
    pinMode(Read[i],  INPUT_PULLUP);
  }

  for(uint8_t i = 0; i < sizeof(Scan); i++) {  // スキャン線を出力にしてすべてHIGH:
    pinMode(Scan[i], OUTPUT);
    digitalWrite(Scan[i], HIGH);
  }
}

void loop() {
  readKeyPad();

  delay(125);
}

void readKeyPad() {
  for(uint8_t i = 0; i < sizeof(Scan); i++) {    // スキャン線を切り替えつつ読み取り:
    digitalWrite(Scan[i],  LOW);

    for(uint8_t o = 0; o < sizeof(Read); o++) {  // 読み取り:
      Matrix[i][o] = (Matrix[i][o] << 1) + (digitalRead(Read[o]) ? 0 : 1);
    }

    digitalWrite(Scan[i], HIGH);
  }

#ifdef DEBUG
  for(uint8_t i = 0; i < sizeof(Scan); i++) {  // デバッグ表示:
    for(uint8_t o = 0; o < sizeof(Read); o++) {
      char buff[16];
      sprintf(buff, "Matrix[%d][%d] = ", i, o);
      Serial.print(buff);
      Serial.println(Matrix[i][o], BIN);
    }
  }
  Serial.println();
#endif
}