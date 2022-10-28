#include <Keyboard.h>

#define DEBUG

#define Scan0 D3
#define Scan1 D4
#define Scan2 D5
#define Read0 D7
#define Read1 D8
#define Read2 D9
#define Read3 D10

#define Key_00 1
#define Key_01 2
#define Key_02 3
#define Key_03 4
#define Key_10 5
#define Key_11 6
#define Key_12 7
#define Key_13 8
#define Key_20 9
#define Key_21 10
#define Key_22 11
#define Key_23 12

const uint8_t Scan[] = {Scan0, Scan1, Scan2};
const uint8_t Read[] = {Read0, Read1, Read2, Read3};
const uint8_t keyMap[sizeof(Scan)][sizeof(Read)] = {{Key_00, Key_01, Key_02, Key_03},
                                                    {Key_10, Key_11, Key_12, Key_13},
                                                    {Key_20, Key_21, Key_22, Key_23}};

uint8_t Matrix[sizeof(Scan)][sizeof(Read)];

void setup(void) {
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

void loop(void) {
  readKeyPad();
  checkMatrix();

  delay(125);
}

void readKeyPad(void) {
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

void checkMatrix(void) {
  for(uint8_t i = 0; i < sizeof(Scan); i++) {  // キーボード出力:
    for(uint8_t o = 0; o < sizeof(Read); o++) {
      if((Matrix[i][o] & 0b00000011) == 0b01) {
        KeyOut(keyMap[i][o]);
      }
    }
  }
}

void KeyOut(uint8_t keys) {
  switch(keys) {
    case Key_00:            // 再生速度↑:
      Keyboard.print(">");
      break;

    case Key_01:            // 10秒戻る:
      Keyboard.print("j");
      break;

    case Key_02:            // 10秒進む:
      Keyboard.print("l");
      break;

    case Key_03:            // フルスクリーン:
      Keyboard.print("f");
      break;

    case Key_10:            // 再生速度↓:
      Keyboard.print("<");
      break;

    case Key_11:            // 再生・停止:
      Keyboard.print("k");
      break;

    case Key_12:            // ミュート:
      Keyboard.print("m");
      break;

    case Key_13:            // シアターモード:
      Keyboard.print("t");
      break;

    case Key_20:            // チャプター戻る:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      break;

    case Key_21:            // チャプター進む:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      break;

    case Key_22:            // フレーム戻る:
      Keyboard.print(",");
      break;

    case Key_23:            // フレーム進む:
      Keyboard.print(".");
      break;
  }
}
