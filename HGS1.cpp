#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

#include "HGS1.h"

void HGS::bilgi_gir(){
	baslangic_noktasi:
		cout<<endl<<"Plaka giriniz: "<<endl;
		cin>>plaka;
		cout<<endl<<"Sinif bilgisi giriniz : "<<endl;
		cin>>sinif;
		try
		{
			if(sinif>4 || sinif<=0) throw 1;
		}
		catch(int i)
		{
			if(i==1){
				cout<<endl<<"\nSinif bilgisi bulunamadi";
			}
		}
		cout<<endl<<"Kilometre giriniz : "<<endl;
		cin>>kilometre;
		cout<<endl<<"Saat giriniz: "<<endl;
		cin>>saat;
}
double HGS::ucret_hesapla(int a,double b){
	birim_fiyat = b;
	kilometre=a;
	ucret=a*b;
	return ucret;
}


double HGS::bakiye_sorgula(){
	bakiye+=para;
	cout<<endl<<endl<<"Bakiyeniz : "<<bakiye<<"TL"<<endl;
	return 0;
}


void HGS::yazdir(){
    
    cout<<endl<<endl<<"~~~~~";
    cout<<endl<<endl<<"Arac plakasi: "<<plaka<<".\n\n"<<"Gidilen yol: "<<kilometre<<"km ve "<<saat<<"saat."<<endl;
}

class Sinif1:public HGS{
	public:
		double birim_fiyat;
		Sinif1():HGS(){
			birim_fiyat=3.00;
			cout<<"1.Sinif Arac : Otomobil"<<endl;
			
		}
};
class Sinif2:public HGS{
	public:
		double birim_fiyat;
		Sinif2():HGS(){
			birim_fiyat=5.00;
			cout<<"2.Sinif Arac : Minibus"<<endl;
			
		}
};
class Sinif3:public HGS{
	public:
		double birim_fiyat;
		Sinif3():HGS(){
			birim_fiyat=7.00;
			cout<<"3.Sinif Arac: Otobus"<<endl;
		}
};



int main()
{
	HGS arac;
	
	int secim;
	string cevap="evet";
	string plaka;
	
	while(cevap=="evet"){
		
    cout<<"********** Hizli Gecis Sistemi **********\n";
    
	cout<<"ISLEMLER:"<<endl;
	cout<<endl<<"1 --> Ucret Hesaplama"<<endl;
	cout<<endl<<"2 --> Bakiye Sorgulama"<<endl;
	cout<<endl<<"************************************\n\n";
	
	cout<<"\n\nLutfen bir islem seciniz: ";
	cin>>secim;
	
    switch(secim){
    	
    	case 1:
    		
	    arac.bilgi_gir();
	    arac.yazdir();
	    
	    if(arac.sinif==1){
	        Sinif1 arac1;
	        arac1.kilometre=arac.kilometre;
	        cout<<endl<<"UCRET : "<<arac1.ucret_hesapla(arac1.kilometre,arac1.birim_fiyat)<<endl;
			arac1.saat=arac.saat;
		
	    }
	    
	    else if(arac.sinif==2){
	        Sinif2 arac2;
	        arac2.kilometre=arac.kilometre;
	        cout<<endl<<"UCRET : "<<arac2.ucret_hesapla(arac2.kilometre,arac2.birim_fiyat)<<endl;
	        
			arac2.saat=arac.saat;
	    }
	    else if(arac.sinif==3){
	        Sinif3 arac3;
	        arac3.kilometre=arac.kilometre;
	        cout<<endl<<"UCRET :"<<arac3.ucret_hesapla(arac3.kilometre,arac3.birim_fiyat)<<endl;
	        
			arac3.saat=arac.saat;
	    }
	    break;
	    case 2:
    	 
		 cout<<endl<<"Lutfen Plaka Bilgisi Giriniz: "<<endl;
		 cin>>plaka;
		 arac.bakiye_sorgula();
		break;
		
    
    	
		default:
    	cout<<"Gecersiz islem.";
	}
	
	cout<<endl<<"Devam etmek ister misin? evet || hayir : ";
	cin>>cevap;

}
return 0;
}
	

