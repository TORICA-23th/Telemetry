# Telemetry

## 使い方
スマホから機体のロールとピッチが確認できる装置です。
### スマホアプリのインストール
[Serial USB Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal)というアプリをインストールします。

Settingで以下の設定を行います。
* Serial > Baud rate を115200に
* Terminal > Font Style をMonospaceに、Fontsizeを適宜調整
![](/setting.png)
### 練習用送信機
* USBケーブルをモバイルバッテリーにさせば起動します。
![](/transmitter.jpg)

* 水平な状態で赤いボタンを押すことで、ピッチとロールを0度にリセットできます。
![](/offset.png)

### 本番機送信機
開発中
### 受信機との接続
* スマホにUSB C-Cケーブルで接続します
![](/receiver.jpg)
* スマホアプリの右上のConnectアイコンから、受信機と接続します。
![](/connect.png)

## 作り方
<!--
### マイコンとTWELITEの接続
### TWELITEの設定
[TWELITE R2](https://akizukidenshi.com/catalog/g/gM-15095/)

[TWELITE](https://akizukidenshi.com/catalog/g/gM-12505/)
https://mono-wireless.com/jp/products/TWE-APPS/App_Uart/index.html
https://twelite.gitbook.io/mw-pug-uart/interactive-mode
https://twelite.gitbook.io/mw-psd-uart/
-->