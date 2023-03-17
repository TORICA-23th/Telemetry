# Telemetry

スマホから機体のロールとピッチが確認できる装置です。
## スマホアプリのインストール
[Serial USB Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal)というアプリをインストールします。

Settingで以下の設定を行います。
* Serial > Baud rate を115200に
* Terminal > Font StyleをMonospaceに、Fontsizeを適宜調整
![](/setting.png)
## 練習用送信機
* USBケーブルをモバイルバッテリーにさせば起動します。
![](/transmitter.jpg)

* 水平な状態で赤いボタンを押すことで、ピッチとロールを0度にリセットできます。
![](/offset.png)

## 本番機送信機
開発中
## 受信機との接続
* スマホにUSB C-Cケーブルで接続します
![](/receiver.jpg)
* スマホアプリの右上のConnectアイコンから、受信機と接続します。
![](/connect.png)