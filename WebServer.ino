/*
  Web Server in intel galilio gen 2
 
 
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress ip(192,168,1,38);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);
int a=0;
String response;
String webpage;
void setup() {
  // Open serial communications and wait for port to open:
  pinMode(11,OUTPUT);
   pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
   if(client.available())
  {
    response="";
   long int time = millis();
                while( (time+100) > millis())
                {
                   while(client.available())
                      {
                         char c = client.read(); // read the next character.
                         response+=c;
                      }  
                }
              
                     Serial.print(response);


                     if(response.indexOf("/?pin=")>0)
     {

     String s=response.substring(response.indexOf("/?pin=")+6,response.indexOf("/?pin=")+9);
    int pin=s.toInt();
if(a==0)
{
    digitalWrite(pin,HIGH);
a=1;
}
else
{

    digitalWrite(pin,LOW);
a=0;
}
      
     }
    if(response.indexOf("/control.html")>0  )
    {
     
   String file1=
"<!DOCTYPE html><html lang=en><title>IOT</title><meta charset=utf-8><meta content=\"width=device-width,initial-scale=1\"name=viewport><link href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" rel=stylesheet><script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script><script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script><style>.jumbotron{background-color:#f4511e;color:#fff;padding:100px 25px}.container-fluid{padding:60px 50px}.bg-grey{background-color:#f6f6f6}.logo{font-size:200px}@media screen and (max-width:768px){.col-sm-4{text-align:center;margin:25px 0}}</style><div class=\"text-center jumbotron\"><h1>IOT</h1></div><div class=\"text-center container-fluid\"><h2>DEVICE</h2><br><div class=row><div class=col-sm-4><span class=\"glyphicon glyphicon-off\"></span><h4>POWER</h4><p><button id=\"11\" type=\"button\" class=\"led btn btn-success\">ON/OFF</button></p></div>"
"<div class=col-sm-4><span class=\"glyphicon glyphicon-off\"></span><h4>LIGHT</h4><p><button id=\"12\" type=\"button\" class=\"led btn btn-success\">ON/OFF</button></p></div>"
"<div class=col-sm-4><span class=\"glyphicon glyphicon-off\"></span><h4>FAN</h4><p><button id=\"13\" type=\"button\" class=\"led btn btn-success\">ON/OFF</button></p></div>"
"</div><br><br>\r\n"
"<script type=\"text/javascript\">\r\n"
"    $(document).ready(function(){\r\n"
"     $(\".led\").click(function(){\r\n"
"       var p = $(this).attr('id');\r\n"
"       $.get(\"http://192.168.1.38/\", {pin:p}); \r\n"
"     });\r\n"
"   });\r\n"
" </script></body></html>\r\n";
 String response1 = "HTTP/1.1 200 OK\r\n";
  response1 += "Content-Type: text/html; charset=UTF-8\r\n"; 
  response1 += "Content-Length: ";
  response1 +=file1.length();
  response1 += "\r\n";
  response1 +="Connection: close\r\n\r\n";
  response1 += file1;
  client.print(response1);
     }
     else if(response.indexOf("/test.html")>0)
     {

         client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
         
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
        
          client.println("<h1>this is a test.html</h1>");
          client.println("</html>");
     }
     
     else
     {

 String file1=
"<!DOCTYPE html><html lang=en><title>IOT</title><meta charset=utf-8><meta content=\"width=device-width,initial-scale=1\"name=viewport><link href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" rel=stylesheet><script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script><script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script><style>.jumbotron{background-color:#f4511e;color:#fff;padding:100px 25px}.container-fluid{padding:60px 50px}.bg-grey{background-color:#f6f6f6}.logo{font-size:200px}@media screen and (max-width:768px){.col-sm-4{text-align:center;margin:25px 0}}</style><div class=\"text-center jumbotron\"><h1>IOT</h1></div><div class=\"text-center container-fluid\"><h2>SENSORS</h2><br><div class=row><div class=col-sm-4><span class=\"glyphicon glyphicon-off\"></span><h4>POWER</h4><p><button id=\"11\" type=\"button\" class=\"led btn btn-success\">ON/OFF</button></p></div><div class=col-sm-4><span class=\"glyphicon glyphicon-fire\"></span><h4>TEMPERATURE</h4></div><div class=col-sm-4><span class=\"glyphicon glyphicon-asterisk\"></span><h4>HUMIDITY</h4></div></div><br><br>\r\n"
"<script type=\"text/javascript\">\r\n"
"    $(document).ready(function(){\r\n"
"     $(\".led\").click(function(){\r\n"
"       var p = $(this).attr('id');\r\n"
"       $.get(\"http://192.168.1.38/\", {pin:p}); \r\n"
"     });\r\n"
"   });\r\n"
" </script></body></html>\r\n";
 String response1 = "HTTP/1.1 200 OK\r\n";
  response1 += "Content-Type: text/html; charset=UTF-8\r\n"; 
  response1 += "Content-Length: ";
  response1 +=file1.length();
  response1 += "\r\n";
  response1 +="Connection: close\r\n\r\n";
  response1 += file1;
  client.print(response1);
     }
     }

     client.stop();
     Serial.println("client disonnected");
    }
  }
    // close the connection:
   
    
 

        

