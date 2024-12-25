#include <stdio.h>  //Standart giriþ/çýkýþ iþlemleri için kullanýlýr
#include <string.h> //String deðerler ile iþlem yapmak için kullanýlýr.
#include <windows.h>//Windows API
#include <conio.h>  //Klavyeden girdi almak ve konsol ayarlarý
#include <unistd.h> //sleep fonksiyonu için kullanýldý
#include <stdlib.h> //Dinamik bellek yönetimi, rasgele sayý üretimi, çevre ile iletiþim,
					// tamsayý aritmetiði, arama, sýralama ve dönüþtürme gibi çeþitli genel amaçlý fonksiyonlar tanýmlanmýþtýr

#define MAX_SISTEM_SAYISI 200		//Dizilerin maksimum boyutlarýný belirlemek için kullanýlýyor
#define MAX_SISTEM_UZUNLUGU 200
#define MAX_SATIR_UZUNLUGU 200


void main()
{
    char secim[20];
    char ad[20], sifre[20];
    char kayit_ad[20], kayit_sifre[20];
    int kayit_uyari = 0;
    
    FILE *fp; 
    fp = fopen("kullanicilar.txt", "a+");
 
    
    do
    {
    	system("CLS");
    	printf("\tGiris ekranina hosgeldiniz!\n\n");
    	sleep(1);
        printf("Lutfen yapmak istediginiz islemi seciniz:\n");
        printf("[1] Musteri kayit\n");
        printf("[2] Musteri giris\n");
        printf("[3] Admin giris\n");
        printf("[0] Cikis\n");
        printf("\n->  ");
        scanf("%s", secim);
        
        if(strcmp(secim, "1") == 0)
        {
            printf("Lutfen kullanici adinizi giriniz: ");
            scanf("%s", kayit_ad);
            
            // Kontrol etmek için kaydedilmiþ kullanýcý adlarýný okuyun
            rewind(fp);
            while(fscanf(fp, "%s %s", ad, sifre) == 2)
            {
                if(strcmp(ad, kayit_ad) == 0)
                {
                    kayit_uyari = 1;
                    break;
                }
            }
            //Kullanýcý adýnýn sadece bir kez kullanýldýðýný kontrol eder.
            if(kayit_uyari == 1)
            {
                printf("Bu kullanici adi zaten alinmis!\n");
                sleep(3);
                system("cls");
            }
            else
            {
                printf("Lutfen sifrenizi giriniz: ");
                scanf("%s", kayit_sifre);
                
                fprintf(fp, "%s %s\n", kayit_ad, kayit_sifre);
                
                printf("Kayit islemi tamamlandi!\n");
                
                
            }
        }
        else if(strcmp(secim, "2") == 0)
        {
            printf("Lutfen kullanici adinizi giriniz: ");
            scanf("%s", ad);
            printf("Lutfen sifrenizi giriniz: ");
            scanf("%s", sifre);
            
            
            // Kontrol etmek için kaydedilmiþ kullanýcý adlarýný okuyun
            rewind(fp);
            while(fscanf(fp, "%s %s", kayit_ad, kayit_sifre) == 2)
            {
                if(strcmp(ad, kayit_ad) == 0 && strcmp(sifre, kayit_sifre) == 0)
                {
                	system("CLS");
                    printf("Hosgeldin, %s!\n", ad);
                    sleep(1);
                    ///////////////////////////////////////////ANA MENÜ
                    menu();
    				
                    
                    
                    break;
                }
            }
            
            if(strcmp(ad, kayit_ad) != 0 || strcmp(sifre, kayit_sifre) != 0)
            {
            	system("CLS");
                printf("Hatali kullanici adi veya sifre!\n");
                sleep(1);
            }
        }
        else if(strcmp(secim, "3") == 0) //Admin giriþ bölümü
        {
            printf("Lutfen admin kullanici adinizi giriniz: ");
            scanf("%s", ad);
            printf("Lutfen admin sifrenizi giriniz: ");
            scanf("%s", sifre);
            
            if(strcmp(ad, "admin") == 0 && strcmp(sifre, "1903") == 0)
			{
				system("CLS");
				printf("Admin girisi basarili!\n");
				sleep(1);
				admin();
				
			}
			else
			{
			
			printf("Hatali kullanici adi veya sifre! Lutfen Tekrar deneyiniz.\n");
			sleep(2);
			}
		}
		else if(strcmp(secim, "0") == 0) //menüden çýkýþ
		{
			system("CLS");
			printf("Programdan cikiliyor...\n");
			sleep(1);
			break;
		}
		else
		{
			printf("\n Gecersiz secim! Lutfen tekrar deneyin.\n");
			sleep(1);
			system("cls");
		}
		kayit_uyari = 0;
	} while(1);

		fclose(fp);
		
		

		
}




struct Urun {
    char marka[50];
    char model[50];
    char hafiza[50];
    char frekans[50];
    char gigahertz[50];
    float fiyat;
    int stok;
};

void yeni_urun_ekle() {
    FILE *fp;
    struct Urun u;
    int tercih;
    printf("\nEklemek istediginiz urunu seciniz\n");
    printf("[1]Islemci\n");
    printf("[2]Ekran Karti\n");
    printf("[3]Anakart\n");
    printf("[4]Ram\n");
    printf("[5]Harddisk\n");
    printf("[6]SSD\n");
    printf("[7]Guc Kaynagi(PSU)\n");
    printf("[9]Geri\n");
    printf("[0]Menuye don\n");
    printf("\n->  ");
    scanf("%d",&tercih);
    sleep(1);
    system("cls");
    switch(tercih)
    {
    	case 1:
    		fp = fopen("islemci.txt", "a");
    		printf("\t-Islemci-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Gigahertz(GHz): ");
    		scanf("%s", &u.gigahertz);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		system("cls");
    		fprintf(fp, "%s %s %sGhz %.2fTL stok%d\n", u.marka, u.model, u.gigahertz, u.fiyat, u.stok); // DOSYAYA YAZMA
    		printf("%s %s %sGhz %.2fTL stok %d\n", u.marka, u.model, u.gigahertz, u.fiyat, u.stok); // EKRANA YAZMA
    		sleep(2);
    		printf("Urun kaydedildi.\n");
    		sleep(1);
    		system("cls");
    		fclose(fp);
    		break;
    	case 2:
    		fp = fopen("ekran_karti.txt", "a");
    		printf("\t-Ekran Karti-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Bellek Kapasitesi: ");
    		scanf("%s", &u.hafiza);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		fprintf(fp, "%s %s %sGB %.2fTL stok%d\n", u.marka, u.model, u.hafiza, u.fiyat, u.stok);
    		printf("%s %s %sGB %.2fTL stok %d\n", u.marka, u.model, u.hafiza, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 3:
    		fp = fopen("anakart.txt", "a");
    		printf("\t-Anakart-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		system("cls");
    		fprintf(fp, "%s %s %.2fTL stok%d\n", u.marka, u.model, u.fiyat, u.stok);
    		printf("%s %s %.2fTL stok %d\n", u.marka, u.model, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 4:
    		fp = fopen("ram.txt", "a");
    		printf("\t-Ram-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Bellek Kapasitesi: ");
    		scanf("%s", &u.hafiza);
    		printf("Megahertz(MHz): ");
    		scanf("%s", &u.frekans);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		fprintf(fp, "%s %s %sGB %sMHz %.2fTL stok%d\n", u.marka, u.model, u.hafiza, u.frekans, u.fiyat, u.stok);
    		printf("%s %s %sGB %sMHz %.2fTL stok %d\n", u.marka, u.model, u.hafiza, u.frekans, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 5:
    		fp = fopen("harddisk.txt", "a");
    		printf("\t-Harddisk-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Kapasite: ");
    		scanf("%s", &u.hafiza);
    		printf("RPM: ");
    		scanf("%s", &u.frekans);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		fprintf(fp, "%s %s %sTB %srpm %.2fTL stok%d\n", u.marka, u.model, u.hafiza, u.frekans, u.fiyat, u.stok);
    		printf("%s %s %sTB %srpm %.2fTL stok %d\n", u.marka, u.model, u.hafiza, u.frekans, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 6:
    		fp = fopen("ssd.txt", "a");
    		printf("\t-SSD-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Kapasite: ");
    		scanf("%s", &u.hafiza);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		fprintf(fp, "%s %s %sGB %.2fTL stok%d\n", u.marka, u.model, u.hafiza, u.fiyat, u.stok);
    		printf("%s %s %sGB %.2fTL stok %d\n", u.marka, u.model, u.hafiza, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 7:
    		fp = fopen("guc_kaynagi.txt", "a");
    		printf("\t-Guc Kaynagi(PSU)-\n\n");
    		printf("Marka: ");
   			scanf("%s", u.marka);
   			printf("Model: ");
   			scanf("%s", u.model);
    		printf("Guc(W): ");
    		scanf("%s", &u.frekans);
    		printf("Fiyat: ");
    		scanf("%f", &u.fiyat);
    		printf("Stok: ");
    		scanf("%d", &u.stok);
    		fprintf(fp, "%s %s %sW %.2fTL stok%d\n", u.marka, u.model, u.frekans, u.fiyat, u.stok);
    		printf("%s %s %sW %.2fTL stok %d\n", u.marka, u.model, u.frekans, u.fiyat, u.stok); // EKRANA YAZMA
    		printf("Urun kaydedildi.\n");
    		sleep(2);
    		system("cls");
    		fclose(fp);
    		break;
    	case 9:
    		sleep(1);
    		system("cls");
    		admin();
    		break;
    	case 0:
    		sleep(1);
    		system("cls");
    		main();
    		break;
	}
    
}

void urun_ara() {
    FILE *fp;
    struct Urun u;
    char aranan[1000];
    int tercih;
    sleep(1);
    system("CLS");
    printf("Aramak istediginiz urunu seciniz\n");			
    printf("[1]Islemci\n");
    printf("[2]Ekran Karti\n");
    printf("[3]Anakart\n");
    printf("[4]Ram\n");
    printf("[5]Harddisk\n");
    printf("[6]SSD\n");
    printf("[7]Guc Kaynagi(PSU)\n");
    printf("[9]Geri\n");
    printf("[0]Menuye don\n");
    printf("\n->  ");
    scanf("%d",&tercih);
    sleep(1);
    switch(tercih)
    {
    	
    	int tercih2;
    	case 1:
		{ //ÝÞLEMCÝ
		system("CLS");
    		printf("Goruntulemek istediginiz islemci markasini seciniz\n");
    		printf("[1]Intel\n");
   			printf("[2]Amd\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("islemci.txt", "r");
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
        		break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Intel") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Intel") == EOF && strstr(aranan, "Intel") == NULL) 
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
				
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			break;
   			
    		case 2:
    		fp = fopen("islemci.txt", "r");
    		
            if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Amd") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if (strstr(aranan, "Amd") == EOF && strstr(aranan, "Amd") == NULL) 
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			case 9:
   			urun_ara();
   			break;
   			default:
			   
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
   			}
   		}
   		fclose(fp);
   		break;
    	case 2: { // EKRAN KARTI
    	system("CLS");
    		printf("Goruntulemek istediginiz Ekran Karti markasini seciniz\n");
    		printf("[1]Intel\n");
   			printf("[2]Amd\n");
   			printf("[3]Nvidia\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("ekran_karti.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Intel") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Intel") == EOF && strstr(aranan, "Intel") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("ekran_karti.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Amd") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Amd") == EOF && strstr(aranan, "Amd") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3: 
    		fp = fopen("ekran_karti.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Nvidia") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Nvidia") == EOF && strstr(aranan, "Nvidia") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	break;
    	case 3: {// ANAKART
    	system("CLS");
    		printf("Goruntulemek istediginiz Ram markasini seciniz\n");
    		printf("[1]MSI\n");
   			printf("[2]GIGABYTE\n");
   			printf("[3]ASUS\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("anakart.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "MSI") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "MSI") == EOF && strstr(aranan, "MSI") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("anakart.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "GIGABYTE") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "GIGABYTE") == EOF && strstr(aranan, "GIGABYTE") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3:
    		fp = fopen("anakart.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "ASUS") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "ASUS") == EOF && strstr(aranan, "ASUS") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	fclose(fp);
    	break;
    	case 4: {// RAM
    	system("CLS");
    		printf("Goruntulemek istediginiz Ram markasini seciniz\n");
    		printf("[1]Corsair\n");
   			printf("[2]Kingston\n");
   			printf("[3]GSkill\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("ram.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Corsair") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Corsair") == EOF && strstr(aranan, "Corsair") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("ram.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Kingston") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Kingston") == EOF && strstr(aranan, "Kingston") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3:
    		fp = fopen("ram.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "GSkill") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "GSkill") == EOF && strstr(aranan, "GSkill") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
    		printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	break;
    	case 5:{ //HARDDÝSK
    	system("CLS");
    		printf("Goruntulemek istediginiz Harddisk markasini seciniz\n");
    		printf("[1]Hp\n");
   			printf("[2]Kingston\n");
   			printf("[3]Seagate\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("harddisk.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Hp") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Hp") == EOF && strstr(aranan, "Hp") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("harddisk.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Kingston") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Kingston") == EOF && strstr(aranan, "Kingston") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3:
    		fp = fopen("harddisk.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Seagate") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Seagate") == EOF && strstr(aranan, "Seagate") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	break;
    	case 6:{ //SSD
    	system("CLS");
    		printf("Goruntulemek istediginiz Harddisk markasini seciniz\n");
    		printf("[1]Samsung\n");
   			printf("[2]Kingston\n");
   			printf("[3]Corsair\n");
   			printf("[9]Geri\n");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("ssd.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Samsung") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Samsung") == EOF && strstr(aranan, "Samsung") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("ssd.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Kingston") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Kingston") == EOF && strstr(aranan, "Kingston") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3:
    		fp = fopen("ssd.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Corsair") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Corsair") == EOF && strstr(aranan, "Corsair") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	break;
    	case 7:{ // GÜÇ KAYNAÐI
    	system("CLS");
    		printf("Goruntulemek istediginiz Guc Kaynagi(PSU) markasini seciniz\n");
    		printf("[1]FSP\n");
   			printf("[2]EVGA\n");
   			printf("[3]Thermaltake\n");
   			printf("[9]Geri");
   			printf("\n->  ");
    		scanf("%d",&tercih2);
    		switch(tercih2)
    		{
    		case 1:
    		fp = fopen("guc_kaynagi.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "FSP") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "FSP") == EOF && strstr(aranan, "FSP") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 2:
    		fp = fopen("guc_kaynagi.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "EVGA") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "EVGA") == EOF && strstr(aranan, "EVGA") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
    		fclose(fp);
    		break;
    		case 3:
    		fp = fopen("guc_kaynagi.txt", "r");
    		
    		if (fp == NULL) //DOSYA BOÞ VEYA OLUÞTURULMAMIÞ ÝSE UYARI VERÝYOR
			{
        		printf("Dosya acilamadi!\n");
        		sleep(1);
       			break;
    		}
    		while (fgets(aranan, 1000, fp) != NULL) 
			{
        		if (strstr(aranan, "Thermaltake") != NULL) 
				{ 
            		printf(" - %s", aranan);
        		}
        		else if(strstr(aranan, "Thermaltake") == EOF && strstr(aranan, "Thermaltake") == NULL)
        		{
        			printf("Stokta urun bulunamadi!\n");
        			sleep(1);
        			break;
				}
   			}
   			printf("\nCikis yapmak icin tiklayiniz.");
   			getch();
   			fclose(fp);
   			case 9:
   			urun_ara();
   			break;
   			default:
   				printf("Gecersiz secim.\n");
   				sleep(1);
   				urun_ara();
				break;
    		fclose(fp);
    		break;
    		}
    	}
    	break;
    	case 9:
    		admin();
    		break;
    	case 0:
    		printf("Menuye yonlendiriliyorsunuz...");
    		sleep(1);
    		main();
    		break;
	}
}

int admin() {
int secim;
do {
	system("CLS");
	printf("\t-Admin Paneli-\n\n");
    printf("[1] Yeni urun ekle\n");
    printf("[2] Urun ara\n");
    printf("[0] Cikis\n");
    printf("\n->  ");
    scanf("%d", &secim);
    
    switch (secim) {
        case 1:
            yeni_urun_ekle();
            break;
        case 2:
            urun_ara();
            break;
        case 0:
            printf("Programdan cikiliyor.\n");
            sleep(1);
            break;
        default:
            printf("Gecersiz secim!\n");
            sleep(1);
            break;
    }
} while (secim != 0);
return 0;
}







int menu()
{
    int secimenu;
    
     // Sonsuz döngü, sadece kullanýcýnýn programý sonlandýrmasýný saðlar
    	system("CLS");
        printf("\t-MENU-\n\n");
        printf("[1]Hazir sistemler\n");
        printf("[2]Cuzdan\n");
        printf("[0]Cikis\n");
        printf("\n->  ");
        
        scanf("%d", &secimenu);
        
        switch (secimenu)
        {
            case 1:
                HazirSis();
                break;
            case 2:
        		cuzdan();
                break;
            case 0:
                printf("Program sonlandirildi.\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
                break;
        }
}
///////////////                   CUZDAN                          ////////////////////////

void cuzdan()
{
	int para, scm;

	system("CLS");
            printf("\t-CUZDAN-\n\n");
            printf("[1]Bakiye Sorgula\n");
            printf("[2]Bakiye Ekle\n");
            printf("[9]Geri\n");
            printf("\n->  ");
            scanf("%d", &para);
            system("CLS");

            switch (para) {
	
                case 1:
                
                    bakiyeSorgula();
                    printf("[3] Geri\n->: ");
                    scanf("%d", &scm);
                    if (scm == 3) {
                        system("CLS");
                        printf("Menuye donuluyor...");
                        sleep(1);
                        menu();
                    }
                    break;

                case 2:
                    bakiyeEkle();
                    break;
 
                case 9:
				system("CLS");
				printf("Menuye donuluyor...");
				sleep(1);
				menu();
				break;   
            }
           // break;
}

int bakiye;						    //Mevcut bakiyeyi tutar 
int eklenecek_para;


void bakiyeSorgula() { 				//Kullanýcýnýn mevcut bakiyesini ekrana yazdýrýr ve bakiye.txt'den okur
    system("CLS");
    FILE *dosya;
    dosya = fopen("bakiye.txt", "r");
	fscanf(dosya,"%d", &bakiye);
    printf("Bakiyeniz: %d TL\n\n", bakiye);
    fclose(dosya);
}

void bakiyeEkle() {					//Kullanýcýdan eklenecek para miktarýný alýr, bakiyeyi günceller
    system("CLS");
    printf("Eklemek istediginiz tutari girin: ");
    scanf("%d", &eklenecek_para);
    bakiye += eklenecek_para;
    printf("Guncel Bakiyeniz: %d TL\n\nDikkat! Cuzdan guvenligi icin tekrar giris yapmaniz gerekmektedir.", bakiye);

    // Dosyaya yeni bakiyeyi kaydetme
    FILE* bakiyeDosyasi = fopen("bakiye.txt", "w");
    if (bakiyeDosyasi == NULL) {
        printf("Bakiye dosyasi bulunamadi.\n");
        return;
    }
    fprintf(bakiyeDosyasi,"%d", bakiye);
    fclose(bakiyeDosyasi);

    sleep(4);
}



///////////////////////////////////////////////////////////////////////////////////
void HazirSis()
{
    printf("Hazir sistemler secildi.\n");
    // Hazir sistemlerle ilgili kodlar buraya eklenebilir
    
    hazirsistemmenu();
}


void HazirSistemler(const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }

    char sistemler[MAX_SISTEM_SAYISI][MAX_SISTEM_UZUNLUGU];
    char satir[MAX_SATIR_UZUNLUGU];
    
    int sistemSayisi = 0;
    char sistem[MAX_SISTEM_UZUNLUGU];

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
         printf("%s", satir);
    }

    fclose(dosya);

    if (sistemSayisi > 0) {
        
        int i;
        for (i = 0; i < sistemSayisi; i++) {
            printf("%s", sistemler[i]);
        }
    } 
}

void hazirsistemmenu() {
    int secim;
	
	FILE* dosya;
    dosya = fopen("bakiye.txt", "r");
    if (dosya == NULL) {
        printf("Dosya bulunamadi!");
        return 1;
    }
    fscanf(dosya, "%d", &bakiye);
    fclose(dosya);
	system("CLS");
    printf("----------------HAZIR SISTEMLER----------------\n\n");
    printf("[1]INTEL - NVIDIA SISTEM\n");
    printf("[2]INTEL - AMD SISTEM\n");
    printf("[3]AMD - NVIDIA SISTEM\n");
    printf("[4]AMD - AMD SISTEM\n");
    printf("[9]Geri\n");
    printf("\n->  ");
    scanf("%d", &secim);
	
    switch (secim) {
    	//INTEL - NVIDIA SISTEM
        case 1:
			system("CLS");
            printf("--------------------------\nINTEL - NVIDIA SISTEM\n--------------------------\n\n");
            printf("[1]FURKAN DEMIR - 1905 HAZIR SISTEM\n");

            printf("\n->  ");
            scanf("%d", &secim);
            system("CLS");

            switch (secim) {
                case 1:
                    printf("Yukleniyor...");
                    sleep(1);
                    system("CLS");
                    HazirSistemler("intel-nvidia-furkan.txt");
                    printf("[1]Satin Al\n");
                    printf("[9]Geri\n");
                    printf("\n->  ");
                    scanf("%d", &secim);
                    if (secim == 1) {
                        
                        float fiyat;
                        FILE* fiyatDosyasi = fopen("furkan-fiyat.txt", "r"); // Fiyatý dosyadan okuma
                        if (fiyatDosyasi == NULL) {
                            printf("Fiyat dosyasi bulunamadi.\n");
                            return 0;
                        }
                        fscanf(fiyatDosyasi, "%f", &fiyat);
                        fclose(fiyatDosyasi);


                        if (bakiye >= fiyat) { // Bakiye kontrolü ve satýn alma iþlemi
                               bakiye -= fiyat;
                                printf("Urun satin aliniyor...\n"); sleep(1);
                                printf("Satin alma islemi basarili.\n");
                                printf("Kalan Bakiyeniz: %d TL\n", bakiye);

                            FILE* bakiyeDosyasi = fopen("bakiye.txt", "w"); // Dosyaya yeni bakiyeyi kaydetme
                            if (bakiyeDosyasi == NULL) {
                            printf("Bakiye dosyasi bulunamadi.\n");
                            return 0;
                            }
                           fprintf(bakiyeDosyasi, "%d", bakiye);
                            fclose(bakiyeDosyasi);
                        } else {
                        			printf("Urun satin aliniyor...\n"); sleep(1);
                                    printf("Yetersiz bakiye. Satin alma islemi gerceklestirilemedi.\n");
                        }
                        
                
                        sleep(3);
                        system("CLS");
                        hazirsistemmenu();
                    } else if (secim == 9) {
                    	system("CLS");
                        printf("Hazir sistemler sayfasina donuluyor...");
                        sleep(2);
                        system("CLS");
                        hazirsistemmenu();
                    }
                    break;
            }
            break;


		//INTEL - AMD SISTEM
		
        case 2:
        	system("CLS");
            printf("--------------------------\nINTEL - AMD SISTEM\n--------------------------\n\n");
            printf("[1] YIGIT EREN ATAGOZLI 1903 HAZIR SISTEM\n");

            printf("\n->  ");
            scanf("%d", &secim);
            system("CLS");

            switch (secim) {
                    case 1:
                    printf("Yukleniyor...");
                    sleep(1);
                    system("CLS");
                    HazirSistemler("intel-amd-yigit.txt");
                    printf("[1] Satin Al\n");
                    printf("[9] Geri\n");
                    printf("\n->  ");
                    scanf("%d", &secim);
                    if (secim == 1) {
                        
                        float fiyat;
                        FILE* fiyatDosyasi = fopen("yigit-fiyat.txt", "r"); // Fiyatý dosyadan okuma
                        if (fiyatDosyasi == NULL) {
                            printf("Fiyat dosyasi bulunamadi.\n");
                            return 0;
                        }
                        fscanf(fiyatDosyasi, "%f", &fiyat);
                        fclose(fiyatDosyasi);


                        if (bakiye >= fiyat) { // Bakiye kontrolü ve satýn alma iþlemi
                               bakiye -= fiyat;
                               printf("Urun satin aliniyor...\n"); sleep(1);
                               printf("Satin alma islemi basarili.\n");
                               printf("Kalan Bakiyeniz: %d TL\n", bakiye);

                            FILE* bakiyeDosyasi = fopen("bakiye.txt", "w"); // Dosyaya yeni bakiyeyi kaydetme
                            if (bakiyeDosyasi == NULL) {
                            printf("Bakiye dosyasi bulunamadi.\n");
                            return 0;
                            }
                           fprintf(bakiyeDosyasi, "%d", bakiye);
                            fclose(bakiyeDosyasi);
                        } else {
                        			printf("Urun satin aliniyor...\n"); sleep(1);
                                    printf("Yetersiz bakiye. Satin alma islemi gerceklestirilemedi.\n");
                        }
                        
                        sleep(3);
                        system("CLS");
                        hazirsistemmenu();
                    } else if (secim == 9) {
                    	system("CLS");
                        printf("Hazir sistemler sayfasina donuluyor...");
                        sleep(2);
                        system("CLS");
                        hazirsistemmenu();
                    }
                    break;
            }
            break;

	
		//AMD - NVIDIA SISTEM
		
        case 3:
        	system("CLS");
            printf("--------------------------\nAMD - NVIDIA SISTEM\n--------------------------\n\n");
            printf("[1] MEHMET ILHAN 1903 HAZIR SISTEM\n");
            printf("\n->  ");
            scanf("%d", &secim);
            system("CLS");

            switch (secim) {
                case 1:
                    printf("Yukleniyor...");
                    sleep(1);
                    system("CLS");
                    HazirSistemler("amd-nvidia-mehmet.txt");
                    printf("[1] Satin Al\n");
                    printf("[9] Geri\n");
                    printf("\n->  ");
                    scanf("%d", &secim);
                    if (secim == 1) {
                        
                        float fiyat;
                        FILE* fiyatDosyasi = fopen("mehmet-fiyat.txt", "r"); // Fiyatý dosyadan okuma
                        if (fiyatDosyasi == NULL) {
                            printf("Fiyat dosyasi bulunamadi.\n");
                            return 0;
                        }
                        fscanf(fiyatDosyasi, "%f", &fiyat);
                        fclose(fiyatDosyasi);


                        if (bakiye >= fiyat) { // Bakiye kontrolü ve satýn alma iþlemi
                               bakiye -= fiyat;
                               printf("Urun satin aliniyor...\n"); sleep(1);
                               printf("Satin alma islemi basarili.\n");
                               printf("Kalan Bakiyeniz: %d TL\n", bakiye);

                            FILE* bakiyeDosyasi = fopen("bakiye.txt", "w"); // Dosyaya yeni bakiyeyi kaydetme
                            if (bakiyeDosyasi == NULL) {
                            printf("Bakiye dosyasi bulunamadi.\n");
                            return 0;
                            }
                           fprintf(bakiyeDosyasi, "%d", bakiye);
                            fclose(bakiyeDosyasi);
                        } else {
                        			printf("Urun satin aliniyor...\n"); sleep(1);
                                    printf("Yetersiz bakiye. Satin alma islemi gerceklestirilemedi.\n");
                        }
                        
                        sleep(3);
                        system("CLS");
                        hazirsistemmenu();
                    } else if (secim == 9) {
                    	system("CLS");
                        printf("Hazir sistemler sayfasina donuluyor...");
                        sleep(2);
                        system("CLS");
                        hazirsistemmenu();
                    }
                    break;
        }
				break;
		
            
            //AMD - AMD SISTEM
            
        case 4:
        	system("CLS");
            printf("--------------------------\nAMD - AMD SISTEM\n--------------------------\n\n");
            printf("[1] MYF IGU HAZIR SISTEM\n");
            printf("\n->  ");
            scanf("%d", &secim);
            system("CLS");

            switch (secim) {
                case 1:
                    printf("Yukleniyor...");
                    sleep(1);
                    system("CLS");
                    HazirSistemler("amd-amd-myf.txt");
                    printf("[1] Satin Al\n");
                    printf("[9] Geri\n");
                    printf("\n->  ");
                    scanf("%d", &secim);
                    if (secim == 1) {
                        
                        float fiyat;
                        FILE* fiyatDosyasi = fopen("myf-fiyat.txt", "r"); // Fiyatý dosyadan okuma
                        if (fiyatDosyasi == NULL) {
                            printf("Fiyat dosyasi bulunamadi.\n");
                            return 0;
                        }
                        fscanf(fiyatDosyasi, "%f", &fiyat);
                        fclose(fiyatDosyasi);


                        if (bakiye >= fiyat) { // Bakiye kontrolü ve satýn alma iþlemi
                               bakiye -= fiyat;
                               printf("Urun satin aliniyor...\n"); sleep(1);
                               printf("Satin alma islemi basarili.\n");
                               printf("Kalan Bakiyeniz: %d TL\n", bakiye);

                            FILE* bakiyeDosyasi = fopen("bakiye.txt", "w"); // Dosyaya yeni bakiyeyi kaydetme
                            if (bakiyeDosyasi == NULL) {
                            printf("Bakiye dosyasi bulunamadi.\n");
                            return 0;
                            }
                           fprintf(bakiyeDosyasi, "%d", bakiye);
                            fclose(bakiyeDosyasi);
                        } else {
                        			printf("Urun satin aliniyor...\n"); sleep(1);
                                    printf("Yetersiz bakiye. Satin alma islemi gerceklestirilemedi.\n");
                        }
                        
                        sleep(3);
                        system("CLS");
                        hazirsistemmenu();
                    } else if (secim == 9) {
                    	system("CLS");
                        printf("Hazir sistemler sayfasina donuluyor...");
                        sleep(2);
                        system("CLS");
                        hazirsistemmenu();
                    }
                    break;
            }
            break;
        case 9:
			system("CLS");
			printf("Menuye donuluyor...");
			sleep(1);
			menu();
			break;   
}

    return 0;
}




