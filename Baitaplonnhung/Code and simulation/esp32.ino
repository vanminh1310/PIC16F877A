
#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP32.h>
// thu vien firebase
#define FIREBASE_HOST "iot59tdh-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ngRiubKaRp2TUnoEz2LOMO2nqWa9RQC24UiWSwLF"

//Define FirebaseESP32 data object
FirebaseData firebaseData;
#define WIFI_SSID "joy" //cái này nữa
#define WIFI_PASSWORD "12345678"// đây nữa

#define RX2 16
#define TX2 17
 char state;
 long last =0;

 
void setup() {
 

  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);

   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");

  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  last = millis();
}

void read_uart(){
  if(Serial2.available()&& WiFi.status() == WL_CONNECTED) {
    Firebase.setInt(firebaseData, "/btl/check",1);
    }
    else{
         Firebase.setInt(firebaseData, "/btl/check",0);
      }         
  char data1;
    data1 = Serial2.read();
    Serial.println(data1);
    String a = String(data1);
   // tests if myChar is a digit
  Firebase.setString(firebaseData, "/btl/traffic",a);

      switch (data1)
      {
        // on 
      case 'a':
        Firebase.setInt(firebaseData, "/btl/ttb1", 1);
        Firebase.setInt(firebaseData, "/btl/ttb2", 2);
         Firebase.setInt(firebaseData, "/btl/ttb3", 3);
           Firebase.setInt(firebaseData, "/btl/ttb4", 4);
        break;
      case 'o':
        Firebase.setInt(firebaseData, "/btl/ttb1", 0);
        Firebase.setInt(firebaseData, "/btl/ttb2", 7);
         Firebase.setInt(firebaseData, "/btl/ttb3", 8);
          Firebase.setInt(firebaseData, "/btl/ttb4", 9);
        break;
     }
    
        
  }

void send_uart(){


if (Firebase.getString(firebaseData, "/btl/auman"))
  {
    if (firebaseData.dataType() == "string")
    {
      String auman = firebaseData.stringData();
      Serial.println(auman);
      Serial2.println(auman);
    }
  }

//  if (Firebase.getString(firebaseData, "/btl/auto_man"))
//  {
//    if (firebaseData.dataType() == "string")
//    {
//      String auto_man = firebaseData.stringData();
//      Serial.println(auto_man);
//      Serial2.println(auto_man);
//    }
//  }
//
//    if (Firebase.getString(firebaseData, "/btl/ledtr"))
//  {
//    if (firebaseData.dataType() == "string")
//    {
//      String ledtr = firebaseData.stringData();
//      Serial.println(ledtr);
//      Serial2.println(ledtr);
//    }
//  }

if (Firebase.getInt(firebaseData, "/btl/ttb1"))
  {
    if (firebaseData.dataType() == "int")
    {
      int tbb1 = firebaseData.intData();
      //Serial.println(tbb1);
      Serial2.println(tbb1);
    }
  }

if (Firebase.getInt(firebaseData, "/btl/ttb2"))
  {
    if (firebaseData.dataType() == "int")
    {
      int tbb2 = firebaseData.intData();
      //Serial.println(tbb2);
      Serial2.println(tbb2);
    }
  }

      
if (Firebase.getInt(firebaseData, "/btl/ttb3"))
  {
    if (firebaseData.dataType() == "int")
    {
      int tbb3 = firebaseData.intData();
      //Serial.println(tbb3);
      Serial2.println(tbb3);
    }
  }

if (Firebase.getInt(firebaseData, "/btl/ttb4"))
  {
    if (firebaseData.dataType() == "int")
    {
      int ttb4 = firebaseData.intData();
     // Serial.println(ttb4);
      Serial2.println(ttb4);
    }
  }
}
void loop() {
   
  
  if (millis() - last >= 100)
     {
      //Serial2.println("l");
      send_uart();
      last = millis();
      }
      
 read_uart();
 
}
