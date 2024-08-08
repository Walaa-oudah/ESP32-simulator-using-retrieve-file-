# ESP32-simulator-using-retrieve-file-

This repository is a python and Arduino codes contains all the supporting project files necessary to work through the ESP32 Simulator project from start to finish.

## Note: This Project is related and connected to Robot-Controller Project.


# About the Project

This project is about using an ESP32 chip to connect a retrieve file that is connected to database and used for a robot controller that controls the movement of a robot and stores the movement data inside a database and retrieves the last value that has been entered inside the database. The project has five different parts: 

1-	Building a retrieve page.

2-	Creating a database using phpMyAdmin and SQL.

3-	Connect the file to database. 

4-	Write an Arduino code.

5- connect ESP32 chip to it to display last command shown by the retrieve file.


### Retrieve Page Purpose:

The retrieve page displays the last command stored in the commands table.


### Structure:

#### 1.	HTML File (retrieve.html)
  - Fetches the last command using JavaScript and displays it on the page.
#### 2.	CSS File (styles2.css)
  - Styles the retrieve page similarly to the control page for a consistent look.
#### 3.	PHP File (retrieve.php)
  - Connects to the MySQL database.
  - Retrieves the last command from the commands table.


### Aurduino Code Purpose:

The ESP32 connects to the Wi-Fi network and periodically checks the last command from the server. Based on the command, it controls a LED.

### Expected Results:

The ESP32 Microchip help to:
- Connects to a specified Wi-Fi network.
- Periodically sends a GET request to the retrieve.php page.
- Retrieves the latest command and prints it to the serial monitor.
- Controls the LED based on the retrieved command:
  
1- Turns the LED (ON) for "forward", "backward", "left", and "right".

2- Turns the LED (OFF) for "stop".


### Structure:

#### 1.	Aurduino File (esp32_project.ino):
 - Creates a simple Wi-Fi connection to check last command from the server directly.
   

## Instructions and Navigation

- Install a web server (Apache).

- Install a database (MySQL).

- Use a server-side scripting language (Python).

- Install Arduino IDE.


### [Download and Install XAMPP]: (https://www.apachefriends.org/download.html)

### [Download and Install Visual Studio Code]: (https://code.visualstudio.com/download)

### [Download and Install Arduino IDE]: (https://www.arduino.cc/en/software)


### Step 1: Create the last input retrieveing Page
#### - retrieve.html 
To Develop the Frontend (HTML + JavaScript).
#### -	retrieve.php
To Develop the Backend (PHP).
#### - styles2.css
For Basic Styling of the retrieve link.


### Step 2: Testing the Setup
1.	Open Your Web Browser: Navigate to http://localhost/robot_control/retrieve.html.
2.	Test Button: Click on button and check if data is being inserted into the database.
3.	Check Data in Database
4.	Open phpMyAdmin: Go to http://localhost/phpmyadmin.
5.	Select Database: Choose Robot_controller from the list.
6.	View Table: Click on the commands table and check if the last command showing is the same as what last command on the retrieve button displayed correctly.

 #### The Pages will be as shown in the pictures below:

 <div> 
   
<img src="https://github.com/user-attachments/assets/457e5714-e19a-428f-8280-d8b7649310ce" width="400" height="400">

<img src="https://github.com/user-attachments/assets/db0130bf-317f-4e4e-a2d3-22d9a4977b5f" width="400" height="200">

<img src="https://github.com/user-attachments/assets/c39ad0bf-5f53-4452-a1ba-15e050994db2" width="400" height="400">

<img src="https://github.com/user-attachments/assets/e503f42e-ea1d-47ac-b9f5-ae1a49f7fe10" width="400" height="500">

</div>


### Step 3: Create Arduino code
#### - esp32_project.ino 
The ESP32 code connects the ESP32 microcontroller to a Wi-Fi network and periodically retrieves the last command from the server. Based on the retrieved command, it controls an LED connected to the ESP32.


### Step 4: Change requierd informations
#### - Wi-Fi Name.
#### - Wi-Fi Password.
#### - Your retrieve page link.
#### - Replace localhost with your IP Address (you can find it using the command on your laptop or pc) --> write (ipconfig) 

#### The result will be similer to the code shown below:  


```
#include <HTTPClient.h>

#include <WiFi.h>
// #include <HTTPClient.h>

const char* ssid = "Your Wi-Fi Name";
const char* pass = "Your Wi-Fi Password";
// 172.20.10.2
const char* serverUrl = "http://Your IP Address/robot_control/retrieve.php";
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
}

void loop() {
    // Make an HTTP GET request
    HTTPClient http;
    http.begin(serverUrl);

    int httpResponseCode = http.GET();
    if (httpResponseCode == 200) {
        String response = http.getString();
        Serial.print("Received data: ");
        Serial.println(response);
    } else {
        Serial.print("Error fetching data. HTTP response code: ");
        Serial.println(httpResponseCode);
    }

    http.end();

    delay(5000); // Fetch data every 5 seconds
}

```

### Step 5: Connect ESP32 Chip to laptop or pc
1.	Plug the chip in laptop or pc port.
2.	Change Sittings from Tools --> Board --> ESP32 Aurduino --> WEMOS D1 MINI ESP32.

<div> 

<img src="https://github.com/user-attachments/assets/fc45e9f4-79a1-440f-bf57-b9a9a623d914" width="800" height="400">

</div>


4.	Click Upload (The right arrow above in the bar).
5.	Wait until it's Done Uploading.
6.	Click on Serial Monitor on the top right of the page (Search icon).
7.	The output will be shown in the Monitor box as shown in the picture below.

<div>
  
<img src="https://github.com/user-attachments/assets/1a3bcbef-d63f-42c1-8b4c-90bb76c2ae9f" width="300" height="300">

</div>


as you can see it matches the result in the retrieve page as well.

<div>
  
<img src="https://github.com/user-attachments/assets/d7dd6dc8-9631-4d62-b49c-80b55d366921" width="400" height="200">

</div>

8. The LED on the ESP32 is (ON)
   
Reason: The last command was (left).


# Summary:
The project involves controlling a robot using a web interface and an ESP32 microcontroller. The web interface sends directional commands to a MySQL database. The ESP32 retrieves the latest command from the database and controls a LED based on the command.


### Technologies Used:

•	HTML, CSS, JavaScript

•	PHP

•	MySQL

•	XAMPP (for local server and MySQL database)

•	Arduino IDE

•	ESP32 External chip


## Thank You!

