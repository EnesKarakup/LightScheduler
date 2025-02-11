#include <stdio.h>
#include <time.h>

// Tarih ve saat yapisi
struct TarihSaat {
    int yil, ay, gun, saat, dakika, saniye;
};

// Tarihi epoch zamanina donusturen fonksiyon
time_t tariheDonustur(struct TarihSaat ts) {
    struct tm t;
    t.tm_year = ts.yil - 1900; // Yýl 1900'dan baþlýyor
    t.tm_mon = ts.ay - 1;      // Ay 0'dan baþlýyor
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1; // Yaz saati otomatik ayar
    return mktime(&t);
}

// Epoch zamanini okunabilir formata cevirme fonksiyonu
void tarihSaatYazdir(time_t epoch) {
    struct tm *t = localtime(&epoch);
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
           t->tm_hour, t->tm_min, t->tm_sec);
}

int main() {
    struct TarihSaat acilmaZamani, kapanmaZamani;
    time_t mevcutEpoch;

    // Kullanicidan isigin acilacagi zaman aliniyor
    printf("isigin acilacagi zamani giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d",
          &acilmaZamani.yil, &acilmaZamani.ay, &acilmaZamani.gun,
          &acilmaZamani.saat, &acilmaZamani.dakika, &acilmaZamani.saniye);

    // Kullanicidan isigin kapanacagi zaman aliniyor
    printf("isigin kapanacagi zamani giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d",
          &kapanmaZamani.yil, &kapanmaZamani.ay, &kapanmaZamani.gun,
          &kapanmaZamani.saat, &kapanmaZamani.dakika, &kapanmaZamani.saniye);

    // Tarihleri epoch'a cevir
    time_t acilmaEpoch = tariheDonustur(acilmaZamani);
    time_t kapanmaEpoch = tariheDonustur(kapanmaZamani);

    // su anki epoch zamani al
    mevcutEpoch = time(NULL);

    // Epoch zamanlarini ekrana yazdir
    printf("\nBaslangic zamani (epoch): %ld\n", acilmaEpoch);
    printf("Bitis zamani (epoch): %ld\n", kapanmaEpoch);
    printf("su anki zaman (epoch): %ld\n", mevcutEpoch);

    // Su anki zamani okunabilir formatta yazdir
    printf("\nsu anki zaman: ");
    tarihSaatYazdir(mevcutEpoch);

    // isik durumu kontrolu
    if (mevcutEpoch >= acilmaEpoch && mevcutEpoch <= kapanmaEpoch) {
        printf("\nDurum: ISIK ACIK\n");
    } else {
        printf("\nDurum: ISIK KAPALI\n");
    }

    return 0;
}

