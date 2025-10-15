#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void tampilkanLirikAnimasi(String baris1, String baris2, int jeda);

void setup() {
  Wire.begin(5, 4); // SDA = D5, SCL = D4

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1); // Stop kalau OLED tidak ditemukan
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();
}

void loop() {
  tampilkanLirikAnimasi("BINTANG 5", "- TENXII", 1000);
  tampilkanLirikAnimasi("Jadi jangan komplain", "soal keadaan", 300);
  tampilkanLirikAnimasi("Bintang lime", "tapi ku bukan ancaman", 400);
  tampilkanLirikAnimasi("Aku nukan polisi", "ku buatmu angkat tangan", 500);
  tampilkanLirikAnimasi("Jangan buru-buru", "kita pelan-pelan", 500);
  tampilkanLirikAnimasi("(Ooh-whoa)", "curi-curi pandang", 600);
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("End of lyrics");
  display.setCursor(0, 35);
  display.println("Restarting...");
  display.display();
  delay(3000);
}

void tampilkanLirikAnimasi(String baris1, String baris2, int jeda) {
  display.clearDisplay();

  // Baris pertama ketik per huruf
  display.setCursor(0, 15);
  for (int i = 0; i < baris1.length(); i++) {
    display.print(baris1[i]);
    display.display();
    delay(80);
  }

  // Baris kedua ketik per huruf
  display.setCursor(0, 35);
  for (int i = 0; i < baris2.length(); i++) {
    display.print(baris2[i]);
    display.display();
    delay(80);
  }

  delay(jeda);
}
