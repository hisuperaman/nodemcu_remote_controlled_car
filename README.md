# 🚗 RemoteXY Wi-Fi Controlled Car  

![RemoteXY](https://img.shields.io/badge/RemoteXY-WiFi--Controlled--Car-blue.svg)
![ESP8266](https://img.shields.io/badge/ESP8266-Supported-green.svg)

## 📌 Overview  
This project is a **Wi-Fi-controlled car** using **NodeMCU** and **RemoteXY**. It allows users to control the car's movement and speed via a mobile app over a local Wi-Fi network.  

## 🎯 Features  
✅ **Wi-Fi-based control** using RemoteXY  
✅ **Four directional movement**: Forward, Backward, Left, Right  
✅ **Speed control** using a slider  
✅ **Simple motor control** with an L298N motor driver  
✅ **Easy-to-use GUI** generated with RemoteXY  

## 🛠️ Hardware Requirements  
- 🛜 **ESP8266** (e.g., NodeMCU)  
- ⚙️ **L298N Motor Driver**  
- 🚗 **2 BO Motors**  
- 🔋 **Power Supply** (e.g., Li-ion cells)  
- 📶 **Wi-Fi-enabled smartphone**  

## 📂 Software Requirements  
- 🖥 **Arduino IDE**  
- 📦 **RemoteXY Library 3.1.13+** *(Download from [here](http://remotexy.com/en/library/))*  
- 📱 **RemoteXY App** *([Android](http://remotexy.com/en/download/), [iOS](http://remotexy.com/en/download/))*  

## 🔧 Setup Instructions  
### 1️⃣ Install RemoteXY Library  
Download and install from [RemoteXY Library](http://remotexy.com/en/library/).  

### 2️⃣ Connect Hardware  
Wire the components as per the pin configuration in the code.  

### 3️⃣ Upload Code  
1. Open **Arduino IDE**  
2. Select **ESP8266 Board** (NodeMCU, if you using that)
3. Upload the provided sketch  

## 📲 How to Use  
1. **Connect to the Wi-Fi network:**  
   - **SSID:** `RemoteXY`  
   - **Password:** `12345678`  
2. **Open the RemoteXY App** *(Download [here](http://remotexy.com/en/download/))*  
3. **Control the Car:**  
   - Use on-screen buttons for movement  
   - Adjust the slider to control speed  


---

👨‍💻 *Developed using RemoteXY & NodeMCU for easy IoT-based motor control!* 🚀  
