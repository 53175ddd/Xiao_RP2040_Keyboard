# Xiao RP2040 Keyboard

## 概要

キーマトリクスを使用して3x4のキーボードとしています

## 機能

各ボタンにお好みの機能を割り当てて使用できます  
ファームウェアの骨格のみを記述したファイルと、サンプルコードとして YouTube 視聴用のショートカットキーボードとして実装したファイルを用意しています

本キーボードのキー名称とその列に接続されているピンは以下の表の通りです

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

## ファイル・フォルダについて

- `/Arduino`
  - ソースファイル保存場所
  - [`/main/main.ino`](./Arduino/main/main.ino)
    - ファームウェアの骨格のみを記述したファイル
  - `/sample`
    - サンプルコード保存場所
    - [`/for_YouTube/for_YouTube.ino`](./Arduino/sample/for_YouTube/for_YouTube.ino)
      - YouTube 視聴用のショートカットキーボード
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

- [`for_YouTube.ino`](./Arduino/sample/for_YouTube/for_YouTube.ino)

それぞれのキーに割り当てられている機能は以下の表の通りです

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
