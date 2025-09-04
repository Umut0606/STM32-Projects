STM32F407G-DISC1 Engelden Kaçan Robot - Kurulum Kılavuzu
🛠️ Gerekli Malzemeler
STM32F407G-DISC1 geliştirme kartı

L298N Motor Sürücü modülü

2x DC motor + tekerlek seti

1x SG90/MG90S Servo motor

1x HC-SR04 Ultrasonik mesafe sensörü

7-12V pil veya powerbank

Jumper kablolar

Araba şasisi




🔌 Bağlantı Şeması
Güç Bağlantıları:


Pil (+) → L298N VM (12V giriş)
Pil (-) → L298N GND → STM32 GND → HC-SR04 GND



Motor Bağlantıları:


Motor A → L298N OUT1 + OUT2
Motor B → L298N OUT3 + OUT4



L298N - STM32 Bağlantıları:



L298N IN1 → PB0
L298N IN2 → PB1  
L298N IN3 → PB10
L298N IN4 → PB11
L298N ENA → PA6 (TIM3_CH1)
L298N ENB → PA7 (TIM3_CH2)



HC-SR04 Bağlantıları:


VCC → 5V
TRIG → PC0
ECHO → PC1
GND → Ortak GND



Servo Bağlantıları:



Sinyal → PA0 (TIM2_CH1)
VCC → 5V
GND → Ortak GND








⚙️ STM32CubeIDE Ayarları
1. Timer Konfigürasyonu:
TIM2: Servo PWM (50Hz)

Channel 1: PWM Generation

Prescaler: 83

Counter Period: 19999

TIM3: Motor PWM (1kHz)

Channel 1: PWM Generation

Channel 2: PWM Generation

Prescaler: 83

Counter Period: 999

2. GPIO Ayarları:
PB0, PB1, PB10, PB11: Output

PC0: Output (TRIG)

PC1: Input (ECHO)

3. Clock Ayarları:
HSE: 8MHz

PLL: 336MHz

System Clock: 168MHz




💻 Kod Yapısı


// Ana fonksiyonlar
void HC_SR04_Trigger(void);
uint32_t HC_SR04_Read(void);
void MotorA_Forward(void);
void MotorA_Backward(void);
void MotorB_Forward(void); 
void MotorB_Backward(void);
void Servo_SetPosition(uint16_t pulse);
void Motor_SetSpeed(uint16_t dutyA, uint16_t dutyB);

// Ana döngü
while (1) {
  distance = HC_SR04_Read();
  if (distance < 20) {
    // Engelden kaçma manevrası
    GeriGit();
    Dur();
    SagaDon();
  } else {
    // Düz ileri git
    IleriGit();
  }
}















📦 Kurulum Adımları
Donanım bağlantılarını yapın

STM32CubeIDE'de yeni proje oluşturun

Yukarıdaki ayarları yapılandırın

Main.c dosyasına kodu yazın

Projeyi derleyin ve kartı programlayın

Pil bağlantısını yapın

Test edin ve ayarları optimize edin

🔧 Debug Önerileri
LED'leri debug için kullanın

Mesafe değerlerini serial portta görüntüleyin

Motor hızlarını kademeli artırın

Engel algılama mesafesini ayarlayın (20cm)



































