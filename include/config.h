/*
 * config.h - Configurações para TinyML ESP32
 * Arquivo de configuração principal do projeto
 */

#ifndef CONFIG_H
#define CONFIG_H

// ================== CONFIGURAÇÕES DE HARDWARE ==================
// Pinos do ESP32
#define LED_PIN                 2        // LED interno do ESP32
#define BUTTON_PIN              0        // GPIO0 (BOOT button)

// Configuração I2S para microfone (ex: INMP441)
#define I2S_WS_PIN              25       // Word Select (LRCLK)
#define I2S_SCK_PIN             26       // Serial Clock (BCLK)  
#define I2S_SD_PIN              27       // Serial Data (DIN)

// ================== CONFIGURAÇÕES DE ÁUDIO ==================
#define AUDIO_SAMPLE_RATE       16000    // Taxa de amostragem (Hz)
#define AUDIO_BUFFER_SIZE       1024     // Tamanho do buffer de áudio
#define INPUT_FEATURES          1024     // Características de entrada do modelo
#define OUTPUT_CLASSES          4        // Classes de saída (silence, unknown, yes, no)

// Configurações de processamento
#define CONFIDENCE_THRESHOLD    0.7f     // Limiar de confiança
#define VOICE_ACTIVATION_ENERGY 0.01f    // Energia mínima para ativação

// ================== CONFIGURAÇÕES DO MODELO ML ==================
#define TENSOR_ARENA_SIZE       (60 * 1024)  // 60KB para arena de tensores
#define MODEL_INPUT_SIZE        1024          // Tamanho da entrada do modelo
#define MODEL_OUTPUT_SIZE       4             // Número de classes

// Classes de reconhecimento
#define CLASS_SILENCE           0
#define CLASS_UNKNOWN          1
#define CLASS_YES              2
#define CLASS_NO               3

// ================== CONFIGURAÇÕES DE DEBUG ==================
#define SERIAL_BAUD_RATE        115200
#define DEBUG_ENABLED           1

#if DEBUG_ENABLED
    #define DEBUG_PRINT(x)      Serial.print(x)
    #define DEBUG_PRINTLN(x)    Serial.println(x)
    #define DEBUG_PRINTF(...)   Serial.printf(__VA_ARGS__)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
    #define DEBUG_PRINTF(...)
#endif

// ================== CONFIGURAÇÕES DE REDE ==================
// WiFi (desabilitado por padrão para economia de energia)
#define WIFI_ENABLED            0
#define WIFI_SSID               ""
#define WIFI_PASSWORD           ""

// ================== CONFIGURAÇÕES DE ENERGIA ==================
#define POWER_MANAGEMENT        1        // Habilitar gerenciamento de energia
#define AUTO_LIGHT_SLEEP        1        // Light sleep automático
#define DEEP_SLEEP_ENABLED      1        // Deep sleep habilitado

// Timeouts de energia (em milissegundos)
#define ENERGY_IDLE_TIMEOUT     5000     // Timeout para modo eco
#define ENERGY_SLEEP_TIMEOUT    10000    // Timeout para sleep
#define ENERGY_DEEP_TIMEOUT     30000    // Timeout para deep sleep

// ================== CONFIGURAÇÕES DE MEMÓRIA ==================
#define USE_PSRAM               1        // Usar PSRAM se disponível
#define HEAP_CAPS_SPIRAM        1        // Usar SPIRAM para buffers grandes

// ================== MACROS UTILITÁRIAS ==================
#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define MAX(a, b)               ((a) > (b) ? (a) : (b))
#define CLAMP(x, min, max)      (MIN(MAX(x, min), max))

// Conversões
#define MS_TO_US(ms)            ((ms) * 1000)
#define US_TO_MS(us)            ((us) / 1000)
#define SEC_TO_MS(sec)          ((sec) * 1000)

// ================== CONFIGURAÇÕES DE CALIBRAÇÃO ==================
#define CALIBRATION_SAMPLES     100      // Amostras para calibração
#define NOISE_FLOOR_SAMPLES     50       // Amostras para ruído de fundo
#define AUTO_GAIN_CONTROL       1        // Controle automático de ganho

// ================== VALIDAÇÕES ==================
#if AUDIO_BUFFER_SIZE < INPUT_FEATURES
    #warning "AUDIO_BUFFER_SIZE menor que INPUT_FEATURES"
#endif

#if OUTPUT_CLASSES > 10
    #warning "Muitas classes de saída podem impactar performance"
#endif

#if TENSOR_ARENA_SIZE < 30000
    #warning "Arena muito pequena pode causar falhas"
#endif

#endif // CONFIG_H
