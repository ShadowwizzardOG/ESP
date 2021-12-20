void setup() {
  // put your setup code here, to run once:
#include <WiFi.h>
#include "secret.h"
#include "time.h"
// add header file for SNTP client
#include "esp_sntp.h"
//

// data below is set as a define in the file secret.h
//const char* ssid       = "HANZE-XX";
//const char* password   = "AXAXAXA";
// contants for SNTP client
const char* ntpServer = "nl.pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;
//

void WiFi_connect(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      printf(".");
  }
  printf(" CONNECTED\r\n");
}

char* printLocalTime()
{
 //https://docs.espressif.com/projects/esp-idf/en/latest/esp32/apireference/system/system_time.html
 time_t now;
 char *time_buf = (char*)malloc(64 * sizeof(char));
 struct tm timeinfo;
 time(&now);
 localtime_r(&now, &timeinfo);
 strftime(time_buf, (64 * sizeof(char)), "%c", &timeinfo);
 //ESP_LOGI(TAG, "\r\nThe current date/time is: %s\r\n", time_buf);
 return time_buf;
}

void setup(){
  WiFi_connect();
  // init time protocol sync
  sntp_setoperatingmode(SNTP_OPMODE_POLL);
  sntp_setservername(0, "pool.ntp.org");
  sntp_init();
  setenv("TZ", "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", 1);
  tzset();
  init time protocol sync
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
