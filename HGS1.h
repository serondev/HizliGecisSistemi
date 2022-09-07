#ifndef HGS_H
#define HGS_H

class HGS{
	public:
		int kilometre;
		int sinif;
		int saat;
		int para;
		double bakiye,ucret;
	
	HGS(){
		ucret=0;
		para=0;
		srand(time(NULL));
		bakiye=rand()%500;
	}
	void bilgi_gir();
	void yazdir();
	double ucret_hesapla(int,double);
	double bakiye_sorgula();
	
	protected:
		double birim_fiyat;
	private:
		string plaka;
};
#endif
