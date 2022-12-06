#include <Keyboard.h>

// デバッグ関連の処理の有効無効を指定:
//#define DEBUG

// 読み取り間隔 (microsec):
#define delayTime 5000

// キー出力モードの指定用:
#define MODE_Press   true
#define MODE_Release false

// 使用するGPIOを定義:
#define Scan0 D3
#define Scan1 D4
#define Scan2 D5
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

// GPIO初期化用配列:
const uint8_t Scan[] = {Scan0, Scan1, Scan2};
const uint8_t Read[] = {Read0, Read1, Read2, Read3};

// キーマトリクス操作用配列:
const uint8_t keyMap[sizeof(Scan)][sizeof(Read)] = {{Key_00, Key_01, Key_02, Key_03},
                                                    {Key_10, Key_11, Key_12, Key_13},
                                                    {Key_20, Key_21, Key_22, Key_23}};

// キーマトリクスの状態保存用配列:
volatile uint8_t Matrix[sizeof(Scan)][sizeof(Read)];

void setup(void) {
#ifdef DEBUG
  // デバッグ用シリアル通信を115200bpsで開始:
  Serial.begin(115200);
#endif
  // キーボードエミュレート開始:
  Keyboard.begin();

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
  readKeyPad();      // キーボードの状態を読み取り、配列を更新する:
  checkMatrix();     // 配列を参照し押されたかどうかを判断:

  delayMicroseconds(delayTime);  // 読み取り間隔を設定:
}

void readKeyPad(void) {
  for(uint8_t i = 0; i < sizeof(Scan); i++) {    // スキャン線を順に切り替え:
    digitalWrite(Scan[i],  LOW);                 // 読み取るところだけ落とす:

    for(uint8_t o = 0; o < sizeof(Read); o++) {  // 読み取って配列を更新:
      Matrix[i][o] = (Matrix[i][o] << 1) + (digitalRead(Read[o]) ? 0 : 1);
    }
    digitalWrite(Scan[i], HIGH);                 // 定常状態に戻す:
  }

#ifdef DEBUG
  // デバッグ表示:
  for(uint8_t i = 0; i < sizeof(Scan); i++) {
    for(uint8_t o = 0; o < sizeof(Read); o++) {
      char buff[16];
      sprintf(buff, "Matrix[%d][%d] = %8b\n", i, o, Matrix[i][o]);
      Serial.print(buff);
    }
  }
  Serial.print("\n");
#endif
}

void checkMatrix(void) {
  // キーボード出力:
  for(uint8_t i = 0; i < sizeof(Scan); i++) {
    for(uint8_t o = 0; o < sizeof(Read); o++) {
            if((Matrix[i][o] & 0b00001111) == 0b0011) {
        keyOut(keyMap[i][o], MODE_Press);
      }else if((Matrix[i][o] & 0b00001111) == 0b1100) {
        keyOut(keyMap[i][o], MODE_Release);
      }
    }
  }
}

void keyOut(const uint8_t keys, const bool mode) {

/********************************************
  この関数内にスイッチが操作された際の処理を記述します
  以下概要:
  
  ```
    case Key_00:  // キー00:
      if(mode) {
        // 押されたときの処理:
      }else {
        // 放されたときの処理:
      }
      break;
  ```
  
  具体的な記述方法はサンプルコードをご覧ください
********************************************/

  switch(keys) {
/*******************************************/
    case Key_00:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_01:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_02:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_03:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_10:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_11:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_12:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_13:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_20:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_21:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/
    case Key_22:
      if(mode) {
       
      }else {
        
      }
      break;
/*******************************************/
    case Key_23:
      if(mode) {
        
      }else {
        
      }
      break;
/*******************************************/ 
    default:
#ifdef DEBUG
      Serial.print("Incorrect value was used.");
#endif
      break;
  }
}
