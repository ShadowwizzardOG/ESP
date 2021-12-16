void setup() {
  // put your setup code here, to run once:
#include <WiFi.h>
#include "secret.h"
#include "time.h"
// data below is set as a define in the file secret.h
//const char* ssid       = "HANZE-XX";
//const char* password   = "AXAXAXA";

void WiFi_connect(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      printf(".");
  }
  printf(" CONNECTED\r\n");
}


void setup(){
  WiFi_connect();
  // init time protocol sync
  sntp_setoperatingmode(SNTP_OPMODE_POLL);
  sntp_setservername(0, "pool.ntp.org");
  sntp_init();
  setenv("TZ", "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", 1);
  tzset();
}

void loop(){
}
}

void loop() {
  // put your main code here, to run repeatedly:
}
