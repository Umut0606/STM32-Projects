# STM32F407 LCD 16x2 Projesi

Bu proje, STM32F407 mikrodenetleyicisi ile 16x2 karakter LCD ekranın paralel bağlantı kullanılarak kontrol edilmesini sağlar. LCD ekran, kullanıcıya metin görüntüleme imkanı sunar ve mikrodenetleyici ile etkileşimli projelerde yaygın olarak kullanılır.

## 📌 Özellikler

- **Mikrodenetleyici**: STM32F407
- **Ekran**: 16x2 LCD (HD44780 uyumlu)
- **Bağlantı Türü**: Paralel (4-bit veri yolu)
- **Kullanılan Pinler**:
  - RS (Register Select): PA1
  - RW (Read/Write): PA2
  - EN (Enable): PA3
  - D4-D7 (Data Pins): PA4 - PA7
- **Geliştirme Ortamı**: STM32CubeIDE
- **Kütüphane**: STM32 HAL (Hardware Abstraction Layer)

## 🔌 Donanım Bağlantıları

| LCD Pin  | STM32F407 Pin            |
| -------- | ------------------------ |
| VSS      | GND                      |
| VDD      | 5V                       |
| V0       | Potansiyometre (0-5V)    |
| RS       | PA1                      |
| RW       | PA2                      |
| E        | PA3                      |
| D4       | PA4                      |
| D5       | PA5                      |
| D6       | PA6                      |
| D7       | PA7                      |
| A (LED+) | 5V                       |
| K (LED-) | GND                      |

> **Not**: LCD ekranın kontrastını ayarlamak için V0 pinine bağlı bir potansiyometre kullanılması önerilir.

## ⚙️ Yazılım Kurulumu

1. **STM32CubeIDE**'yi indirin ve kurun: [https://www.st.com/en/development-tools/stm32cubeide.html](https://www.st.com/en/development-tools/stm32cubeide.html)

2. STM32CubeIDE'yi açın ve yeni bir proje oluşturun:
   - **Mikrodenetleyici Seçimi**: STM32F407VG
   - **Proje Adı**: LCD_16x2
   - **Proje Konumu**: İstediğiniz bir dizin

3. **Pin Yapılandırması**:
   - PA1 (RS), PA2 (RW), PA3 (EN), PA4 (D4), PA5 (D5), PA6 (D6), PA7 (D7) pinlerini çıkış olarak ayarlayın.

4. **Periferik Yapılandırma**:
   - **GPIO**: İlgili pinleri çıkış olarak ayarlayın.
   - **SysTick**: 1 ms zamanlayıcıyı etkinleştirin.

5. **Kod Yazımı**:
   - LCD kontrol fonksiyonlarını içeren `lcd.c` ve `lcd.h` dosyalarını projeye dahil edin.
   - `main.c` dosyasına aşağıdaki kodu ekleyin:

     ```c
     #include "lcd.h"

     int main(void)
     {
         HAL_Init();
         LCD_Init();
         LCD_Clear();
         LCD_SetCursor(0, 0);
         LCD_Print("Merhaba STM32!");
         while (1)
         {
         }
     }
     ```

6. **Proje Derleme ve Yükleme**:
   - Projeyi derleyin ve mikrodenetleyiciye yükleyin.

## 📄 Lisans

Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için [LICENSE](./LICENSE) dosyasına bakınız.
