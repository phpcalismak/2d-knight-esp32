#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

// Gerekli kütüphaneleri ve diğer header dosyalarını dahil ediyoruz.
#include <Arduino.h>   // Arduino çekirdek fonksiyonları için
#include <TFT_eSPI.h>  // TFT ekran kütüphanesi için

// Oyun mantığı ve yapılandırma dosyaları
#include "game_logic.h"    // Player yapısı ve slashEffect için
#include "game_config.h"   // SCREEN_WIDTH, SCREEN_HEIGHT gibi tanımlamalar için


#define TRANSPARENT_COLOR TFT_BLACK



// SPRITE VERİLERİ İÇİN BİLDİRİMLER
// knight_panda ve knight_attack verilerinin bulunduğu dosyayı buraya dahil edin.
// Genellikle "sprites.h" gibi bir dosya kullanılır.
// Bu dosyada extern const uint16_t knight_panda[]; gibi bildirimler olmalı.
#include "knight.h" // Bu satırı eklediğinizden veya sprites.h dosyanızın var olduğundan emin olun!

// TFT_eSPI nesneleri global olarak tanımlanır ve diğer dosyalardan erişilebilmesi için 'extern' ile bildirilir.
extern TFT_eSPI tft;
extern TFT_eSprite player1Sprite;
extern TFT_eSprite player2Sprite;
extern TFT_eSprite bgSprite;
extern TFT_eSprite uiSprite;

// Karakter sprite'larının boyutlarını tanımlıyoruz. LÜTFEN BU DEĞERLERİ KENDİ SPRITE'LARINIZA GÖRE AYARLAYIN!
// Eğer iki sprite'ın boyutu da aynıysa, tek bir tanım kullanabilirsiniz.
// Eğer farklıysa, her biri için ayrı ayrı tanımlayın.
#define KNIGHT_PANDA_WIDTH   50  // Knight Panda sprite'ının genişliği
#define KNIGHT_PANDA_HEIGHT  48  // Knight Panda sprite'ının yüksekliği

#define KNIGHT_ATTACK_WIDTH  100  // Knight Attack sprite'ının genişliği (Örnek değer, kendi değerinizle değiştirin!)
#define KNIGHT_ATTACK_HEIGHT 65  // Knight Attack sprite'ının yüksekliği (Örnek değer, kendi değerinizle değiştirin!)

// --- Fonksiyon Bildirimleri (Prototipler) ---
// Bu fonksiyonların detaylı tanımları (implementasyonları) display_manager.cpp dosyasında yer almalıdır.

/**
 * @brief TFT_eSPI sprite'larını başlatır ve yapılandırır.
 */
void initSprites();

/**
 * @brief Oyuncu karakter sprite'ını ekrana çizer.
 * @param p Çizilecek oyuncunun Player yapısı.
 * @param spriteData Karakterin RGB565 piksel verisi (uint16_t dizisi).
 * @param spriteWidth Çizilecek sprite'ın genişliği.
 * @param spriteHeight Çizilecek sprite'ın yüksekliği.
 */
void drawCharacterSprite(Player& p, const uint16_t* spriteData, int spriteWidth, int spriteHeight);

/**
 * @brief Ninja karakter sprite'ını ilkel şekillerle çizer.
 * Eğer karakterler tamamen RGB565 sprite'larla çizilecekse bu fonksiyon gereksiz hale gelebilir.
 * @param sprite Çizimin yapılacağı TFT_eSprite objesi.
 * @param p Çizilecek oyuncunun Player yapısı.
 * @param color Ana renk.
 * @param detailColor Detay rengi.
 */


/**
 * @brief Oyunun başlangıç ekranını çizer.
 */
void drawTitleScreen();

/**
 * @brief Oyun sonu ekranını (kazananı belirterek) çizer.
 * @param winner Kazanan oyuncunun numarası (1 veya 2).
 */
void drawGameOverScreen(int winner);

/**
 * @brief Oyuncuların sağlık çubuklarını günceller ve ekrana basar.
 */
void updateHealthBars();

/**
 * @brief Kılıç darbesi efektini çizer.
 * @param x Efektin X koordinatı.
 * @param y Efektin Y koordinatı.
 * @param facingRight Oyuncunun sağa mı baktığı (efekt yönü için).
 * @param power Atak gücü (efektin boyutu ve rengi için).
 */
void drawSlashEffect(int x, int y, bool facingRight, int power);

/**
 * @brief Oyun sahnesini (arka plan, karakterler, efektler) her karede çizer.
 */
void drawGame();

#endif // DISPLAY_MANAGER_H