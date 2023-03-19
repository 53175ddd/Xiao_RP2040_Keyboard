# Xiao RP2040 Keyboard

## 概要

キーマトリクスを使用して 4x4 のキーボードとしています  
リポジトリ名は `Xiao_RP2040_Keyboard` ですが、ProMicro にも対応しています

具体的には `main.ino` の場合 13 行目か 16 行目、`for_YouTube.ino` の場合は 19 行目か 22 行目のどちらをコメントアウトするかによって、ピンの定義の参照先が切り替わります  
デフォルトでは、Xiao RP2040 を使用する設定になっています

https://github.com/Nch-MOSFET/Xiao_RP2040_Keyboard/blob/cac49ef702fcf1dcca2a3a3e28b84382c639709c/Arduino/main/main.ino#L12-L16

https://github.com/Nch-MOSFET/Xiao_RP2040_Keyboard/blob/cac49ef702fcf1dcca2a3a3e28b84382c639709c/Arduino/sample/for_YouTube/for_YouTube.ino#L18-L22

## 機能

各ボタンにお好みの機能を割り当てて使用できます  
ファームウェアの骨格のみを記述したファイルと、サンプルコードとして YouTube 視聴用のショートカットキーボードとして実装したファイルを用意しています

キーボードのキー名称とその列に接続されているピンは以下の表の通りです

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

## CAD イメージ図

<div align="center"><img src="https://user-images.githubusercontent.com/91242561/212581923-65a2985a-8729-4781-8267-924cb060ff8f.png" width=75%></div>
<div align="center"><img src="https://user-images.githubusercontent.com/91242561/212581941-c41294f9-9366-46a3-a39c-c6ce5d9fab70.png" width=75%></div>

## ファイル・フォルダについて

- `/Arduino`
  - ソースファイル保存場所
  - [`/main/main.ino`](./Arduino/main/main.ino)
    - ファームウェアの骨格のみを記述したファイル
  - `/sample`
    - サンプルコード保存場所
    - [`/for_YouTube4/for_YouTube4.ino`](./Arduino/sample/for_YouTube4/for_YouTube4.ino)
      - YouTube 視聴用のショートカットキーボード（4x4）
- `LICENCE`
  - 二次利用に関するライセンスです。必ず利用前にご確認ください
  - なお、義務ではありませんが利用に関して一報いただけますと幸いです
- `README.md`
  - このファイル
  - 必ずお読みください

## サンプルコードについて

- [`for_YouTube.ino`](./Arduino/sample/for_YouTube/for_YouTube.ino)

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
