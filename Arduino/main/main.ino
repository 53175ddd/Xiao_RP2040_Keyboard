#include <Keyboard.h>

// キーマトリクスの処理の有効無効を指定:
// #define DEBUG_Matrix

// 実行速度モニタリングの有効無効を指定:
// #define DEBUG_Times

// テスト用にキー出力を無効にする:
// #define DISABLE_KeyOUT

// ProMicro を使用する場合は下の行をコメント解除：
// #define ProMicro

// Xiao RP2040 を使用する場合は下の行をコメント解除
#define XiaoRP

#ifdef DEBUG_Times
 #ifndef DEBUG
  #define DEBUG
 #endif
#endif

#ifdef DEBUG_Matrix
 #ifndef DEBUG
  #define DEBUG
 #endif
#endif

// 読み取り間隔 (microsec):
#ifdef DEBUG
 #define delayTime 250000
#else
 #define delayTime 5000
#endif

// キー出力モードの指定用:
#define MODE_Press   true
#define MODE_Release false

#ifdef ProMicro
 // 使用するGPIOを定義:
 #define Scan0 6
 #define Scan1 7
 #define Scan2 8
 #define Scan3 9
 #define Read0 5
 #define Read1 4
 #define Read2 3
 #define Read3 2
#endif

#ifdef XiaoRP
 // 使用するGPIOを定義:
 #define Scan0 D3
 #define Scan1 D4
 #define Scan2 D5
 #define Scan3 D6
 #define Read0 D7
 #define Read1 D8
 #define Read2 D9
 #define Read3 D10
#endif

// キー名称と識別番号の対応を定義:
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
#define Key_30 13
#define Key_31 14
#define Key_32 15
#define Key_33 16

// 読み取り間隔 (microsec):
#ifdef DEBUG
 #define delayTime 250000
#else
 #define delayTime 5000
#endif

// キー出力モードの指定用:
#define MODE_Press   true
#define MODE_Release false

// 使用するGPIOを定義:
#define Scan0 D3
#define Scan1 D4
#define Scan2 D5
#define Scan3 D6
#define Read0 D7
#define Read1 D8
#define Read2 D9
#define Read3 D10

// キー名称と識別番号の対応を定義:
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
#define Key_30 13
#define Key_31 14
#define Key_32 15
#define Key_33 16

// GPIO初期化用配列:
const uint8_t Scan[] = {Scan0, Scan1, Scan2, Scan3};
const uint8_t Read[] = {Read0, Read1, Read2, Read3};

// キーマトリクス操作用配列:
const uint8_t keyMap[sizeof(Scan)][sizeof(Read)] = {{Key_00, Key_01, Key_02, Key_03},
                                                    {Key_10, Key_11, Key_12, Key_13},
                                                    {Key_20, Key_21, Key_22, Key_23},
                                                    {Key_30, Key_31, Key_32, Key_33}};

// キーマトリクスの状態保存用配列:
volatile uint8_t Matrix[sizeof(Scan)][sizeof(Read)];

void setup(void) {
#ifdef DEBUG
  // デバッグ用シリアル通信を115200bpsで開始:
  Serial.begin(115200);
#endif

#ifndef DISABLE_KeyOUT
  // キーボードエミュレート開始:
  Keyboard.begin();
#endif

  // 読み取り線を入力にしてプルアップ:
  for(uint8_t i = 0; i < sizeof(Read); i++) {
    pinMode(Read[i],  INPUT_PULLUP);
  }

  // スキャン線を出力にしてすべてHIGH:
  for(uint8_t i = 0; i < sizeof(Scan); i++) {
    pinMode(Scan[i], OUTPUT);
    digitalWrite(Scan[i], HIGH);
  }
}

void loop(void) {
#ifdef DEBUG_Times
  uint16_t startTime = micros();
#endif

  readKeyPad();      // キーボードの状態を読み取り、配列を更新する:
  checkMatrix();     // 配列を参照し押されたかどうかを判断:

#ifdef DEBUG_Times
  uint16_t endTime = micros();
  uint8_t diff = endTime - startTime;
  char buf[30];
  sprintf(buf, " - Running Time : %2d micro sec.\n\n", diff);
  Serial.print(buf);
#endif

  delayMicroseconds(delayTime);  // 読み取り間隔を設定:
}

void readKeyPad(void) {
  for(uint8_t i = 0; i < sizeof(Scan); i++) {    // スキャン線を順に切り替え:
    digitalWrite(Scan[i],  LOW);                 // 読み取るところだけ落とす:
    delayMicroseconds(1);
    for(uint8_t o = 0; o < sizeof(Read); o++) {  // 読み取って配列を更新:
      Matrix[i][o] = (Matrix[i][o] << 1) + (digitalRead(Read[o]) ? 0 : 1);
    }
    delayMicroseconds(1);
    digitalWrite(Scan[i], HIGH);                 // 定常状態に戻す:
  }

#ifdef DEBUG_Matrix
  // デバッグ表示:
  for(uint8_t i = 0; i < sizeof(Scan); i++) {
    Serial.print(" | ");
    for(uint8_t o = 0; o < sizeof(Read); o++) {
      for(uint8_t b = 7; b > 0; b--) {
        if((Matrix[i][o] & 1 << b) == 0) {
          Serial.print("0");
        }else {
          Serial.print("1");
        }
      }
      Serial.print(" | ");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
#endif
}

void checkMatrix(void) {
  // キーボード出力:
  for(uint8_t i = 0; i < sizeof(Scan); i++) {
    for(uint8_t o = 0; o < sizeof(Read); o++) {
            if((Matrix[i][o] & 0b00000111) == 0b011) {
        keyOut(keyMap[i][o], MODE_Press);
      }else if((Matrix[i][o] & 0b00000111) == 0b100) {
        keyOut(keyMap[i][o], MODE_Release);
      }
    }
  }
}

void keyOut(const uint8_t keys, const bool mode) {
#ifndef DISABLE_KeyOUT
  switch(keys) {
/********************************/
    case Key_00:            // キー00 に関する処理:
      if(mode) {
        // 押された際の処理:
      }else {
        // 離された際の処理:
      }
      break;
/********************************/
    default:
#ifdef DEBUG_Matrix
      Serial.print("Incorrect value was used.");
#endif
      break;
  }
#endif
}
