//Rukiye Ucar
//21100011057

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ana_menu();
int uye_menu();
void yeniKayit();
void kayitListele();
void kayitGuncelle();
void cinsiyet_dagilimi();
void birim_dagilimi();
void cihaz_menu();

struct uye
{
    char ad_soyad[20];
    int okul_no;
    int cinsiyet;
    int birim;
};

struct cihaz
{
    char cihaz_adi[20];
    int seri_no;
    int yapilis_suresi;


};

struct birimm
{
    struct uye yazilimm;
    struct uye elektronikk;
    struct uye mekatronikk;
    struct uye bakim_onarim;
};

int main()
{
    printf("***************************************************************\n");
    printf("*******BOZKIR TECH. TEAM UYELIK SISTEMINE HOS GELDINIZ*********\n");
    printf("***************************************************************\n");
    int secim;
    int ana_menu();
    secim = ana_menu();
    struct uye *uyeptr = NULL;
    struct birimm *birimptr = NULL;
    int sayi = 0;
    int kadinSayisi = 0;
    int erkekSayisi = 0;

    while(ana_menu !=3)
    {
        if(secim==1)
        {
            uye_menu();
            while(secim !=0)
            {
                if(secim==1)
                {
                    yeniKayit(&uyeptr, &sayi, &kadinSayisi, &erkekSayisi,&birimptr);
                }
                else if(secim==2)
                {
                    kayitListele(uyeptr,sayi);
                }
                else if(secim==3)
                {
                    kayitGuncelle(uyeptr,sayi);
                }
                else if(secim == 4)
                {
                    uyeSil(uyeptr,sayi);
                }
                else if(secim == 5)
                {
                    cinsiyet_dagilimi(&kadinSayisi,&erkekSayisi);
                }
                else if(secim==6)
                {
                    birim_dagilimi(birimptr,sayi);
                }
                else if(secim == 0)
                {
                    printf("Ana Menuye Yonlendiriliyorsunuz..\n");
                    secim = ana_menu();
                    break;
                }
                else
                {
                    printf("Hatali Bir Islem Yaptiniz\nLutfen Tekrar Deneyiniz..\n");
                }
                secim = uye_menu();
            }


            }
        else if(secim==2)
        {
            cihaz_menu();
        }
        else if(secim==3)
        {
            printf("\nBasariyla Cikis Yapildi..\n");
            break;
        }
        else
        {
            printf("\nHatali Bir Islem Yaptiniz\nLutfen Tekrar Deneyiniz..\n");
            break;
        }

        secim = ana_menu();

    }

    free(uyeptr);
    free(birimptr);
}

int ana_menu()
{
    int secim;
    printf("\n1)Uye Islemleri\n");
    printf("2)Cihaz Islemleri\n");
    printf("3)Cikis\n");
    printf("Seciminiz: "); scanf("%d",&secim);
    return secim;
}

int uye_menu()
{
    int secim;
    printf("\n1-Yeni Uye Kaydi\n");
    printf("2-Kayit Listeleme\n");
    printf("3-Kayit Guncelleme\n");
    printf("4-Kayit Silme\n");
    printf("5-Cinsiyet Dagilimi\n");
    printf("6-Birim Listesi\n");
    printf("0-Ana Menuye Don\n");
    printf("Seciminiz: "); scanf("%d",&secim);

    return secim;
}

void yeniKayit(struct uye **uyeptr, int *sayi,int *kadinSayisi, int *erkekSayisi, struct birimm **birimptr)
{
    char ad_soyad[20];
    int okul_no;
    int cinsiyet;
    int birim;

    printf("\n\nKac Kisi Kaydetmek Istersiniz: ");
    scanf("%d", sayi);

    *uyeptr = (struct uye *)malloc((*sayi) * sizeof(struct uye));
    *birimptr = (struct birimm *)malloc(sizeof(struct birimm));

    *kadinSayisi = 0;       //kadin ve erkek sayisi basta 0 girilir. cunku takimda erkek olmama durumunda erkek sayisini 0 hesaplamak isteriz
    *erkekSayisi = 0;
    for (int i = 0; i < *sayi; i++)
    {
        printf("%d. Ogrenci Bilgilerini Giriniz: \n", i + 1);
        printf("Ad-Soyad: "); scanf(" %[^\n]", ad_soyad);   //entera basana kadar kullanicidan girdi almak icin [\n] kullanilir
        printf("Okul No: "); scanf("%d", &okul_no);

        printf("Cinsiyet:\n1-Kadin\n2-Erkek\n"); scanf("%d", &cinsiyet);
        if (cinsiyet == 1)
        {
            (*kadinSayisi)++;
        }
        else if (cinsiyet == 2)
        {
            (*erkekSayisi)++;
        }


        printf("Birim:\n1-Yazilim\n2-Elektronik\n3-Mekatronik\n4-Bakim-Onarim\n");
        scanf("%d", &birim);

        (*uyeptr)[i].okul_no = okul_no;
        strcpy((*uyeptr)[i].ad_soyad, ad_soyad);
        (*uyeptr)[i].cinsiyet = cinsiyet;
        (*uyeptr)[i].birim = birim;

        if (birim == 1)
        {
        strcpy((*birimptr)[i].yazilimm.ad_soyad,ad_soyad);

        }
        else if(birim==2)
        {
            strcpy((*birimptr)[i].elektronikk.ad_soyad,ad_soyad);
        }

        else if(birim== 3)
        {
           strcpy((*birimptr)[i].mekatronikk.ad_soyad,ad_soyad);
        }

        else if(birim== 4)
        {
           strcpy((*birimptr)[i].bakim_onarim.ad_soyad,ad_soyad);
        }

        printf("Yeni Uye Basariyla Kaydedildi.\n");

    }


}

void kayitListele(struct uye *uyeptr, int sayi) {
    for (int i = 0; i < sayi; i++) {
        printf("\n\n%d Numarali Uye Bilgileri: \n", uyeptr[i].okul_no);
        printf("Ad-Soyad  : %s\n", uyeptr[i].ad_soyad);

        if (uyeptr[i].cinsiyet == 1) {
            printf("Cinsiyet  : Kadin\n");
        } else if (uyeptr[i].cinsiyet == 2) {
            printf("Cinsiyet  : Erkek\n");
        }

        if (uyeptr[i].birim == 1) {
            printf("Birim     : Yazilim\n");
        } else if (uyeptr[i].birim == 2) {
            printf("Birim     : Elektronik\n");
        } else if (uyeptr[i].birim == 3) {
            printf("Birim     : Mekatronik\n");
        } else if (uyeptr[i].birim == 4) {
            printf("Birim     : Bakim-Onarim\n");
        }
        printf("***************************\n");
    }
    printf("Listeleme Islemi Basariyla Tamamlandi..\n\n");
}

void kayitGuncelle(struct uye *uyeptr, int sayi,struct birimm **birimptr)
{
    int okul_no;
    char ad_soyad[20];
    int cinsiyet;
    int birim;
    int i=0;
    printf("\n\nKaydi Guncellenecek Uye Okul Numarasi: \n");    //okul numarasi ile kayit kontrol yapmak istedik, eger boyle bir kayit varsa kullanicinin kaydini girdigi bilgilere gore gunceller
    scanf("%d",&okul_no);

    while(i<sayi)
    {
        int sonuc =0;

        if (okul_no==uyeptr->okul_no)
        {
            printf("%d. Numarali Uye Bilgilerini Giriniz: \n",okul_no);
            printf("Okul No  : \n");scanf("%d", &okul_no);
            printf("Ad-Soyad : \n");scanf(" %[^\n]",ad_soyad);
            printf("Cinsiyet : \n1-Kadin\n2-Erkek\n");scanf("%d",&cinsiyet);
            printf("Birim    : \n1-Yazilim\n2-Elektronik\n3-Mekatronik\n4-Bakim-Onarim\n\n");scanf("%d",&birim);

            uyeptr ->okul_no =okul_no;
            strcpy(uyeptr->ad_soyad,ad_soyad);
            uyeptr->cinsiyet = cinsiyet;
            uyeptr ->birim = birim;

            if (birim == 1)
            {
            strcpy((*birimptr)[i].yazilimm.ad_soyad,ad_soyad);

            }
            else if(birim==2)
            {
                strcpy((*birimptr)[i].elektronikk.ad_soyad,ad_soyad);
            }

            else if(birim== 3)
            {
               strcpy((*birimptr)[i].mekatronikk.ad_soyad,ad_soyad);
            }

            else if(birim== 4)
            {
               strcpy((*birimptr)[i].bakim_onarim.ad_soyad,ad_soyad);
            }

            sonuc = 1;
            break;
        }

        if(sonuc==0)
        {
            printf("%d Numarali Uye Listede yok",okul_no);
        }
        i++;
        uyeptr++;
    }
    printf("Kayit Guncelleme Islemi Basariyla Gerceklesti..\n");


}

void uyeSil(struct uye *uyeptr ,int sayi)
{
    int silinecek,i,j;
    printf("\n\nSilmek Istediginiz Uyenin Okul Numarasini Giriniz :");
    scanf("%d",&silinecek);

    for(j=0; j<sayi; j++)
    {
        if((uyeptr+j)->okul_no==silinecek)
        {
            break; //uyenin listedeki yerini bulup asagidaki i ve j ye atti
        }
    }

    if(j+1<=0 || j+1>sayi)
    {
        printf("\nBoyle Bir Uye Bulunmamaktadir\n");
    }
    else
    {
        for(i=j+1; i<sayi; i++)
        {
            *(uyeptr+(i-1))=*(uyeptr+i); //silmek istenileni araya aldi bir sonrakini kendi yerine koydu
        }

        printf("\nSiliniyor...\nBasariyla Silindi\n");

        uyeptr=(struct uye*)realloc(uyeptr,sizeof(struct uye)*sayi); //hafizadaki yeri gunceller
    }
    sayi--;
}

void cinsiyet_dagilimi(int *kadinSayisi, int *erkekSayisi)
{
    int toplam = *kadinSayisi + *erkekSayisi;       //kadin sayisi ve erkek sayisi toplanir ve daha sonra bunun yuzdesi alinir.
    float kadin_yuzde = (*kadinSayisi) * 100 /toplam;
    float erkek_yuzde = (*erkekSayisi) * 100 / toplam;
    printf("\n\nTakimdaki Kadin Sayisi : %d\n",*kadinSayisi);
    printf("Takimdaki Erkek Sayisi : %d\n", *erkekSayisi);
    printf("Takimdaki Kadin Yuzdesi: %.2f\n",kadin_yuzde);
    printf("Takimdaki Erkek Yuzdesi: %.2f\n",erkek_yuzde);

}

void birim_dagilimi(struct birimm *birimptr, int sayi)     //yeniKayit fonksiyonunda girilen bilgiler birim adinda struct icinde struct kullanilarak ad soyad listelenir.
{
    for (int i = 0; i < sayi; i++) {
        if (birimptr[i].yazilimm.ad_soyad[0]!= '\0') {  //yazilimm icindeki isim eger varsa yani ilk karakter '\0' degilse bu bloga girer.
            printf("\n***Yazilim Birimi Uyeleri***\n");
            //printf("%s",birimptr[i].yazilimm.ad_soyad[0]);
            printf("%d-%s\n\n", i+1, birimptr[i].yazilimm.ad_soyad);
        }
        else if (birimptr[i].elektronikk.ad_soyad[0]!= '\0') {
            printf("\n***Elektronik Birimi Uyeleri***\n");
            printf("%d-%s\n\n",i+1, birimptr[i].elektronikk.ad_soyad);
        }

        else if (birimptr[i].mekatronikk.ad_soyad[0]!= '\0') {
            printf("\n***Mekatronik Birimi Uyeleri***\n");
            printf("%d-%s\n\n", i+1, birimptr[i].mekatronikk.ad_soyad);
        }
        else if (birimptr[i].bakim_onarim.ad_soyad[0]!= '\0') {
            printf("\n***Bakim-Onarim Birimi Uyeleri***\n");
            printf("%d-%s\n\n",i+1, birimptr[i].bakim_onarim.ad_soyad);
        }
    }
}

void cihaz_menu()
{
    printf("\nUppps!\nSistemimiz Gelistirme Asamasindadir \nAna Menuye Yonlendiriliyorsunuz\n\n");  //bu kisim gelistirme asamasindadir ve ana menuye yonlendirilir.

}
