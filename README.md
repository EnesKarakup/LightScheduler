### Özet
Kullanıcı tarafından girilen başlangıç ve bitiş zamanlarına göre ışığın durumunu (AÇIK/KAPALI) belirleyen bir C programı. Sistem zamanını temel alarak karar verir.

---

### Açıklama
Bu program, ışığın açılacağı ve kapanacağı zamanları kullanıcıdan alır, bunları **epoch zamanına** çevirir ve mevcut sistem zamanıyla karşılaştırarak ışığın durumunu belirler.

#### Özellikler:
- Başlangıç ve bitiş zamanı kullanıcıdan alınır.
- İnsan tarafından okunabilir tarih formatını epoch zamanına dönüştürür.
- Mevcut sistem zamanını hem epoch hem okunabilir formatta gösterir.
- Kullanıcı girdilerine göre ışığın **AÇIK** veya **KAPALI** olduğunu belirler ve ekrana yazdırır.

#### Gereksinimler:
- Bir C derleyicisi (örneğin: GCC).
- Standart C kütüphanesi (`time.h` ve `stdio.h` kullanılmıştır).

#### Kullanım:
Programı derleyip çalıştırmak için şu komutları kullanabilirsiniz:
```bash
gcc -o isik_durumu isik_durumu.c
./isik_durumu

Örnek giriş:
Işığın açılacağı zamanı giriniz (YYYY AA GG SS DD SS): 2025 02 11 18 00 00
Işığın kapanacağı zamanı giriniz (YYYY AA GG SS DD SS): 2025 02 11 23 00 00

Örnek çıktı:
Başlangıç zamanı (epoch): 1749914400
Bitiş zamanı (epoch): 1749932400
Şu anki zaman (epoch): 1749919200

Şu anki zaman: 2025-02-11 19:00:00

Durum: IŞIK AÇIK
Bu proje, C dilinde zaman yönetimiyle çalışmayı öğrenmek, zaman damgalarını işlemek ve zamana bağlı kararlar vermeyi uygulamak isteyenler için basit ve kullanıcı dostu bir örnektir.
