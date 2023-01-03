# Xiao RP2040 Keyboard

## 概要

キーマトリクスを使用して 3x4 や 4x4 のキーボードとしています

## 機能

各ボタンにお好みの機能を割り当てて使用できます  
ファームウェアの骨格のみを記述したファイルと、サンプルコードとして YouTube 視聴用のショートカットキーボードとして実装したファイルを用意しています

3x4 キーボードのキー名称とその列に接続されているピンは以下の表の通りです

<table>
  <tr>
    <td></td> <td>Read0</td> <td>Read1</td> <td>Read2</td> <td>Read3</td>
  </tr>
  <tr>
    <td>Scan0</td> <td>Key_00</td> <td>Key_01</td> <td>Key_02</td> <td>Key_03</td>
  </tr>
  <tr>
    <td>Scan1</td> <td>Key_10</td> <td>Key_11</td> <td>Key_12</td> <td>Key_13</td>
  </tr>
  <tr>
    <td>Scan2</td> <td>Key_20</td> <td>Key_21</td> <td>Key_22</td> <td>Key_23</td>
  </tr>
</table>

4x4 キーボードのキー名称とその列に接続されているピンは以下の表の通りです

<table>
  <tr>
    <td></td> <td>Read0</td> <td>Read1</td> <td>Read2</td> <td>Read3</td>
  </tr>
  <tr>
    <td>Scan0</td> <td>Key_00</td> <td>Key_01</td> <td>Key_02</td> <td>Key_03</td>
  </tr>
  <tr>
    <td>Scan1</td> <td>Key_10</td> <td>Key_11</td> <td>Key_12</td> <td>Key_13</td>
  </tr>
  <tr>
    <td>Scan2</td> <td>Key_20</td> <td>Key_21</td> <td>Key_22</td> <td>Key_23</td>
  </tr>
  <tr>
    <td>Scan3</td> <td>Key_30</td> <td>Key_31</td> <td>Key_32</td> <td>Key_33</td>
  </tr>
</table>

## ファイル・フォルダについて

- `/Arduino`
  - ソースファイル保存場所
  - [`/main/main.ino`](./Arduino/main/main.ino)
    - ファームウェアの骨格のみを記述したファイル
  - `/sample`
    - サンプルコード保存場所
    - [`/for_YouTube3/for_YouTube3.ino`](./Arduino/sample/for_YouTube3/for_YouTube3.ino)
      - YouTube 視聴用のショートカットキーボード（3x4）
    - [`/for_YouTube4/for_YouTube4.ino`](./Arduino/sample/for_YouTube4/for_YouTube4.ino)
      - YouTube 視聴用のショートカットキーボード（4x4）
- `/Python`
  - やる気があったら MicroPython で再実装するつもりですがやるかどうかは分かりません
- `/UF2`
  - コンパイル済ファイル保存場所
  - Seeed Xiao RP2040 での利用を想定していますが、ピンアサインを合わせれば Raspberry Pi Pico でも動きます
  - [`for_YouTube_v1.uf2`](./UF2/for_YouTube_v1.uf2)
    - コンパイルしたサンプルコード
- `LICENCE`
  - 二次利用に関するライセンスです。必ず利用前にご確認ください
  - なお、義務ではありませんが利用に関して一報いただけますと幸いです
- `README.md`
  - このファイル
  - 必ずお読みください

## サンプルコードについて

- [`for_YouTube3.ino`](./Arduino/sample/for_YouTube3/for_YouTube3.ino)

3x4 キーボードの各キーに割り当てられている機能は以下の表の通りです

<table>
  <tr>
    <td>再生速度上昇</td> <td>10秒戻る</td> <td>10秒進む</td> <td>フルスクリーンモード切り替え</td>
  </tr>
  <tr>
    <td>再生速度低下</td> <td>再生・停止</td> <td>音声ミュート・解除</td> <td>シアターモード切り替え</td>
  </tr>
  <tr>
    <td>動画の頭に移動</td> <td>前のチャプターへ</td> <td>後ろのチャプターへ</td> <td>次の動画へ</td>
  </tr>
</table>

- [`for_YouTube4.ino`](./Arduino/sample/for_YouTube4/for_YouTube4.ino)

4x4 キーボードの各キーに割り当てられている機能は以下の表の通りです

<table>
  <tr>
    <td>再生速度上昇</td> <td>10秒戻る</td> <td>10秒進む</td> <td>フルスクリーンモード切り替え</td>
  </tr>
  <tr>
    <td>再生速度低下</td> <td>再生・停止</td> <td>音声ミュート・解除</td> <td>シアターモード切り替え</td>
  </tr>
  <tr>
    <td>動画の頭に移動</td> <td>前のチャプターへ</td> <td>後ろのチャプターへ</td> <td>次の動画へ</td>
  </tr>
  <tr>
    <td>Ctrl キー</td> <td>左のタブへ</td> <td>タブを閉じる</td> <td>右のタブへ</td>
  </tr>
</table>
