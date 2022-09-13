#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <unistd.h> // Sleep fonksiyonu için bu kütüphaneyi tanýmladýk.

struct banka /* tüm fonksiyonlarda verilere eriþebilmek için Struct yapýsý oluþturduk. */
{
	char ad[30];
	char soyad[30];
	char CepTel[30];
	char Iban[30];
	char Dogum_tarihi[30];
	char kizlik_soyadi[30];
	char e_posta[30];
	float bakiye1;	
}banka={"Yusuf","XXX","5313313131","TR77777777777777","07.03.2000","AAAAAA","yusufxxx@gmail.com",27300}; /* Struct yapýsýna veriler girdik*/
void menu();
void bakiye_sorgula(float bakiye);
int para_cekme(float bakiye);
int para_yatirma(float bakiye);
int para_gonderme(float bakiye);
int yatirim_getirisi(float bakiye);
void hesap_bilgisi(char ad[20], char soyad[20],char CepTel[10],char Iban[26],char Dogum_tarihi[10],char kizlik_soyadi[20],char e_posta[BUFSIZ],float bakiye);


main()
{
	
	system("color 3e"); 
	system("cls"); 
	menu();	
	
	}	
			
	void menu(){
		printf("\n Yusuf XXX");
	char islem; 
	int secim;		
	printf("\n\t\t\t   VEFA BANKASINA HOSGELDINIZ.\t\n");
	
	printf("\t\t\t|\t     MENU");
	printf("\t\t|\n"),
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\t|1-Hesap Bilgilerini Goster");
	printf("\t|\n");
	printf("\t\t\t|2-Bakiye Sorgulama"); 
	printf("\t\t|\n");
	printf("\t\t\t|3-Para Cekme");
	printf("\t\t\t|\n");
	printf("\t\t\t|4-Para Yatirma");
	printf("\t\t\t|\n");
	printf("\t\t\t|5-Para Gonderme");
	printf("\t\t|\n");
	printf("\t\t\t|6-Yatirim Getirisi Hesaplama");
	printf("\t|\n");
	printf("\t\t\t|7-Cikis");
	printf("\t\t\t|\n"),
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\tYapmak istediginiz islemi seciniz:");
	
	scanf("%d",&secim);

	if(secim==1)
	{
		hesap_bilgisi(banka.ad,banka.soyad,banka.CepTel,banka.Iban,banka.Dogum_tarihi,banka.kizlik_soyadi,banka.e_posta,banka.bakiye1); /*Struct yapýlarýndaki verileri okumak için
		dizilerin baþýna " banka. " eklendi. */
	}
	else if(secim==3)
	{
		
		 banka.bakiye1=para_cekme(banka.bakiye1);
		
		main();
	}
	else if(secim==2)
	{
		bakiye_sorgula(banka.bakiye1);
		
	}
	else if(secim==4)
	{
		banka.bakiye1=para_yatirma(banka.bakiye1);
		main();
	}
	else if(secim==5)
	{
		banka.bakiye1=para_gonderme(banka.bakiye1);
		main();
	}
	else if(secim==6)
	{
		banka.bakiye1=yatirim_getirisi(banka.bakiye1);
		main();
	}
	else if(secim==7)
	{
		exit(1);
	}
	else
	{
		
	}
}


void bakiye_sorgula(float bakiye)
{
	char devam;
	printf("Musterinin Toplam Bakiyesi: %5.2f \n",bakiye);
	while(1){
	
	printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
		devam=getche();
		if((tolower(devam)=='d' )) 
		{
		
		main();
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5); /*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}
		}
	
}

int para_cekme(float bakiye)
{
	char devam;
	float miktar;
while(1){
	printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);
	printf("Cekmek istediginiz bakiye miktarini giriniz:\n");
	scanf("%f",&miktar);
	float hesaplama=bakiye-miktar;
	printf("Paraniz basariyla cekilmistir.\n");
	printf("Su an ki Bakiyeniz:%5.2f\n",hesaplama);
	

	printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
		devam=getche();
		if((tolower(devam)=='d' ))
		{	
		return hesaplama;		
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}
		}
}
	

int para_yatirma(float bakiye)
{
		
	char devam;
	float miktar, hesaplama;
	while(1)
	{
	printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);
	printf("Yatirmak istediginiz bakiye miktarini giriniz:\n");
	scanf("%f",&miktar);
	hesaplama=bakiye+miktar;
	printf("Paraniz basariyla yatirilmistir.\n");
	printf("Su an ki Bakiyeniz:%5.2f\n",hesaplama);
	

	printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
		devam=getche();
		if((tolower(devam)=='d' )) 
		{	
		return hesaplama;		
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
	}
	}
	}

int para_gonderme(float bakiye)

{
	char Iban2[30];
	char CepTel2[30];
	char devam;
	char devam2;
	float miktar, hesaplama;
	while(1)
	{
	printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);

	printf("Gondermek istediginiz hesabin IBAN numarasini giriniz:\n");
	fflush(stdin); /* Gets komutunu kullandýðýmýzda kaynaklanan , veriyi almadan direk atlatýðýndan dolayý 
	 Internetten araþtýrdýðýmda gets(); komutundan once fflush(); yazdýðýmýzda sorun olmadýðýndan kullandým.*/
	gets(Iban2);
	geri: 
	printf("\nGondermek istediginiz bakiye miktarini giriniz:\n");
	scanf("%f",&miktar);
	bakiye=bakiye-miktar;
	hesaplama=bakiye-((bakiye*5)/100); /*komisyon alýyoruz*/
	
	printf("Gondermek Istediginiz\n---> IBAN:%s\n--->Telefon Numaraniz:%s\n",Iban2,banka.CepTel);
	
	printf("---->Islemi onaylamak icin E/e tusuna basiniz.\n");	
	printf("---->Para miktarini duzeltmek icin G/g tusuna basiniz\n");
	printf("---->Islemden vazgecmek icin V/v tusuna basiniz\n");
	devam=getche();
	if((tolower(devam)=='e' ))
	{
	printf("Paraniz basariyla gonderilmistir.\n");
	printf("Su an ki Bakiyeniz:%5.2f\n",hesaplama);
	

	printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
		devam2=getche();
		if((tolower(devam2)=='d' ))
		{	
		return hesaplama;		
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}	
	}
	
	if((tolower(devam)=='g' ))
	{
		goto geri; 
	}
	if((tolower(devam)=='v' ))
	{
		main();
	}
	
	
}
}



void hesap_bilgisi(char ad[20], char soyad[20],char CepTel[10],char Iban[26],char Dogum_tarihi[10],char kizlik_soyadi[20],char e_posta[BUFSIZ],float bakiye)
{
	char devam;
	while(1){	
	printf("Musteri Bilgileri: Ad:%s \tSoyad:%s\tCep:%s\tIBAN:%s\tDogum Tarihi:%s\tAnne Kizlik Soyadi:%s\tE-Postasi:%s\tBakiyesi:%5.2f\t\n ",ad,soyad,CepTel,Iban,Dogum_tarihi,kizlik_soyadi,e_posta,bakiye);
	
	
	printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
	
		
		devam=getche();
		if((tolower(devam)=='d' )) 
		{
		
		main();	
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}
		}
}




int yatirim_getirisi(float bakiye)

{
	int secim;
	char devam;
	int yil;
	float faiz=0.02;
	float faiz2=0.04;
	float faiz3=0.05;
	float i;
	while(1)
	{
	
	

	printf("\n\n\n\t\t\t|\t     MENU");
	printf("\t\t|\n");
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\t|1-Altin Hesabina para yatir");
	printf("\t|\n");
	printf("\t\t\t|2-Dolar Hesabina para yatir"); 
	printf("\t|\n");
	printf("\t\t\t|3-Vadeli Hesabina para yatir");
	printf("\t|\n");
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\tYapmak istediginiz islemi seciniz:");
	
	scanf("%d",&secim);
	
	if (secim==1)
	{
		printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);
		printf("Lutfen yatirim yilini giriniz \n");
		scanf("%d",&yil);
		for(i=0;i<yil;i++)
		{
		
		 bakiye=bakiye+(bakiye*faiz);
	}
	

		printf(" Altin Hesabi Yatirim Getirisi :%5.2f\n",bakiye);
		
		
	
		printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
	
		
		devam=getche();
		if((tolower(devam)=='d' )) 
		{
		return bakiye;
		main();	
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}
		
	}
		
		
		else if (secim==2)
	{
		printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);
		printf("Lutfen yatirim yilini giriniz \n");
		scanf("%d",&yil);
		for(i=0;i<yil;i++)
		{
		
		 bakiye=bakiye+(bakiye*faiz2);
	}
	

		printf(" Dolar Hesabi Yatirim Getirisi :%5.2f\n",bakiye);
		
		
	
		printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
	
		
		devam=getche();
		if((tolower(devam)=='d' )) 
		{
		return bakiye;
		main();	
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}
	}
	 else if (secim==3)
	{
	
		printf("Su an ki Bakiyeniz:%5.2f\n",bakiye);
		printf("Lutfen yatirim yilini giriniz \n");
		scanf("%d",&yil);
		for(i=0;i<yil;i++)
		{
		
		 bakiye=bakiye+(bakiye*faiz3);
	}
}

		printf(" Vadeli Hesabi Yatirim Getirisi :%5.2f\n",bakiye);
		
		
	
		printf("\n Menuye donmek icin D/d tusuna basiniz.\n");
	
		
		devam=getche();
		if((tolower(devam)=='d' )) 
		{
		return bakiye;
		main();	
		}
		else
		{
			printf("Hatali Islem Yaptiniz.Menuye Yonlendiriliyorsunuz.");
			sleep(5);/*Programý 5 saniye durduruyor. Üstteki Hatalý iþlem yaptýnýz yazýsýný göstermek için bu kodu kullandýk.Kullanmasaydýk maine hemen dönecekti
			 ve system(cls) kodundan dolayý Hatalý iþlem yaptýnýz yazýsý görünmeyecekti.*/
			main();
		}

}
	}

