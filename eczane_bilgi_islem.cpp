#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

class Ilac;
class Eczane; //iç içe friend fonksiyon kullanýmýnda tanýmlanma hatasý vermemesi için programa baþlarken tanýmlayacaðým classlarý declare ediyorum

class Eczane{
	
	
	private: // Eczane classýnda private deðiþken olarak eczanenin id, isim ve adres bilgileri bulunuyor. Bu bilgilere public kýsmýnda tanýmlanan fonksiyonlar aracýlýðýyla ulaþýlýyor.
		
	int eczane_id; 
	string eczane_isim;	
	string eczane_adres;
	
	
	
	public:
		string kaydet;
	
	Eczane(){ //default ctr 
	
	eczane_id    = 0;
	eczane_isim  = "default";
	eczane_adres = "default";
	
    }	
    
    Eczane(int e_id, string e_isim, string adres){ //ctr with arg
    	
    eczane_id    = e_id;
    eczane_isim  = e_isim;
    eczane_adres = adres;

	}
	
	Eczane(const Eczane& other){ //copy ctr
		
	eczane_id    = other.eczane_id;	
	eczane_isim  = other.eczane_isim;
	eczane_adres = other.eczane_adres;
		
	}
	
	Eczane& operator=(const Eczane& other){// assignment
	
	eczane_id    = other.eczane_id;	
	eczane_isim  = other.eczane_isim;
	eczane_adres = other.eczane_adres;	
		
	return *this;		
		
	}
	
	//get functions
	
	int EczId(){       return eczane_id;    }
	
	string EczIsim(){  return eczane_isim;  }
	
	string EczAdres(){ return eczane_adres;	}
	
	//set functions
	
	void eSetId(int e_id)       { 
	
	eczane_id   = e_id;     	}
	
	
	void eSetIsim(string e_isim){
	
	eczane_isim  = e_isim;	    }
	
	
	void eSetAdres(string adres){
		
	eczane_adres = adres;       }
			


    void eczane_olustur(){ //kullanýcý tarafýndan girilen bilgiler doðrultusunda eczane objesinin bilgileri atanýyor.
	
	
	char ecz_adres[150], ecz_isim[20];
    string tempisim, tempadres;
    int tempid, ecz_id;
    
    
    cout<<"Lütfen eczane adýný giriniz: \n";
    cin>>ecz_isim;
    
    eczane_isim = string(ecz_isim)+"_eczanesi";
    tempisim    = string(ecz_isim)+".dat";
    
        
    cout<<eczane_isim<<"'nin id bilgisini giriniz: \n";
    cin>>ecz_id;
    
    eczane_id = ecz_id;

    
    
    cout<<eczane_isim<<"'nin adres bilgisini giriniz: \n"; 
    fflush(stdin);
    getline(cin, eczane_adres);
    
}






    void eczane_bilgileri(){ // eczane_listesi.dat dosyasýndaki bütün eczanelerin bilgileri ekrana yazdýrýlýyor.
    
    string okuma;
    fstream dosya1;
    dosya1.open("eczane_listesi.dat", ios::in);
    
    while(dosya1 >> okuma){
    	cout << okuma << endl;
    	kaydet+=okuma; //dosya okumasý yapýlýrken bilgiler ikici bir string içine kaydediliyor
	}
	
	dosya1.close();
  
	}

//class içerisinde tanýmlanan private deðerlere ulaþmasý gereken class dýþý fonksiyonlar friend fonksiyon olarak tanýmlanýyor.
	
friend void eczane_dosya_olustur(Eczane i); 
friend void eczane_ara(string anahtar);
friend void ilac_dosya_olustur(Ilac ilac, Eczane ecz);
friend void ilac_goster(Ilac ilac);
friend void ilac_duzenle(Ilac ilac);
	

};



void eczane_dosya_olustur(Eczane i){ //fonksiyona yollanan eczane objesinin bilgileri eczane_listesi.at dosyasýna yazdýrýlýyor.
	
	
    fstream dosya;
    dosya.open("eczane_listesi.dat", ios::app); // dosya app eklentisi ile açýlýyor
    
    if(!dosya.is_open()) { cout << "Dosya açýlamadý..."; exit(0);	} //dosyanýn açýlýp açýlmadýðýnýn kontrolü yapýlýyor
    

    
    dosya << i.EczIsim()   << endl;
	dosya << i.EczId()     << endl;
	dosya << i.EczAdres()  << endl;
    
    dosya.close();	// bilgiler dosyaya yazdýrýldýktan sonra dosya kapatýlýyor.
	
}


void eczane_ara(string anahtar){ //kullanýcý tarafýndan girilen eczane adýnýn listede olup olmadýðý aramasý yapýlýyor.
	
	fstream file;
	file.open("eczane_listesi.dat", ios::in);

	
	string line;
	
	if(file.is_open()){
	
		while(getline(file,line)){ // bilgiler dosyadan satýr satýr okuma yapýlýyor
			
			if(anahtar==line){ // aradýðýmýz eczane adý okuduðumuz satýrda ise; 
				cout << endl << " Eczane Adý:" << line; //ilk satýr eczanenin adýna,
				getline(file,line);
				cout << "\n ID:" << line; // ikinci satýr eczanenin id bilgisine, 
				getline(file,line);
				cout << "\n Adres:" << line << endl; // üçüncü satýr eczanenin adres bilgisine eþitleniyor.
			}
		}
	}
}


 
class Ilac
{
	private:  // Ilac classýna ait id, ilacýn sayýsý, fiyatý ve isim bilgileriprivate olarak tanýmlanýyor. Public fonksiyonlar aracýlýðýyla bilgilere ulaþýlýyor.
		
	int ilac_id;
	int ilac_sayisi;	
	double ilac_fiyati;	
	string ilac_isim;	
	
	
	public:
		
	Ilac(){ //default ctr
	
	ilac_id     = 0;
	ilac_sayisi = 0;
	ilac_fiyati = 0.0;
	ilac_isim   = "default";
	
    }
	
	
	
	Ilac(int i_id, int sayi, double fiyat, string i_isim){  //ctr with arg
	
	ilac_id     = i_id;
	ilac_sayisi = sayi;
	ilac_fiyati = fiyat;
	ilac_isim   = i_isim;
	
    }
	
	Ilac(const Ilac& other) { //copy ctr
	
    
    ilac_id     = other.ilac_id;
    ilac_sayisi = other.ilac_sayisi;
    ilac_fiyati  = other.ilac_fiyati;
    ilac_isim   = other.ilac_isim;
	
    }

    Ilac& operator=(const Ilac& obj){ //assignment ctr
	
    
    ilac_id     = obj.ilac_id;
    ilac_sayisi = obj.ilac_sayisi;
    ilac_fiyati  = obj.ilac_fiyati;
    ilac_isim   = obj.ilac_isim;
    
    return *this;
	
    }    
    
    //set functions ilaç
    
    void iSetId(int i_id){ 
    
    ilac_id = i_id; }
    
    
    void iSetSayi(int sayi){ 
    
    ilac_sayisi = sayi; }    
	
	
    void iSetFiyat(double fiyat){ 
    
    ilac_fiyati = fiyat;  }   
    
    
    void iSetIsim(string i_isim){ 
    
    ilac_isim = i_isim;  	}     
    
    
    
    // get functions ilaç
    
    int iId(){ return ilac_id;	}
    
    int iSayi(){ return ilac_sayisi;	}
    
    double iFiyat(){ return ilac_fiyati;	}
    
    string iIsim(){ return ilac_isim;	}    
    
    void ilac_olustur(){ //kullanýcý tarafýnda girilecek olan bilgiler doðrultusunda ilac objesinin bilgilerinne atama yapýlýyor.
    
    int id, sayi;
	double fiyat;
	string isim;
		
	cout << "Ilac adýný giriniz: " << endl;
    fflush(stdin);
    getline(cin, ilac_isim);
		
	cout << "Ilaç ID giriniz: " << endl;
	cin  >> ilac_id;
	
    cout << "Ilacýn sayýsýný giriniz: " << endl;
    cin  >> ilac_sayisi;
    
    cout << "Ilacýn fiyatýný giriniz: " << endl;
    cin  >> ilac_fiyati;

    	
	}
	
	
	



// class dýþý kullanýmdaki fonksiyonlar friend olarak classa tanýmlanýyor
friend void ilac_duzenle(string eczisim);
friend void ilac_dosya_olustur(Ilac ilac, string tempEczaneAdi);   
friend void ilac_goster(string eczisim);

};

void ilac_duzenle(string eczisim){ // eksik fonksiyon
	
	Ilac temp;
	int id;
	
	eczisim=eczisim+"_ilac.dat";
	
	fstream file;
	file.open(eczisim.c_str(), ios::in);

	
	if(file){
		
		cout<<"Bilgilerimi degistirmek istediginiz ilacin ID'sini giriniz: ";
        cin>>id;

        fstream file2;
        file2.open("temp.dat",ios::out | ios::in | ios::app);

		while(file>>temp.ilac_id)
        {

        file>>temp.ilac_isim;
        file>>temp.ilac_fiyati;
        file>>temp.ilac_sayisi;



            if(temp.ilac_id!=id)
            {
                file2<<temp.ilac_id
                     <<temp.ilac_isim
                     <<temp.ilac_fiyati
                     <<temp.ilac_sayisi
                     <<endl;
            }
            else if(temp.ilac_id==id){
            cout.setf(ios::left);
              cout<<"\nYeni isim bilgisi: ";
            cin>>temp.ilac_isim;          
			
			cout<<" Ilacýn yeni ID bilgisi: ";
            cin>>temp.ilac_id;
            
            cout<<"\nYeni sayi bilgisi: ";
            cin>>temp.ilac_sayisi;
            
            cout<<"\nYeni fiyat bilgisi: ";
            cin>>temp.ilac_fiyati;

            file2  << temp.ilac_id      << endl;
			file2  << temp.ilac_isim    << endl;
			file2  << temp.ilac_fiyati  << endl;
			file2  << temp.ilac_sayisi  << endl;
            }

        }

        file.close();
        file2.close();
        remove(eczisim.c_str());
        rename("temp.dat",eczisim.c_str());

    }
    else
    {
        cout<<"Bu isimde bir eczane bulunamady!"<<endl;
    }
	}

void ilac_ara(string ilac, string eczisim){ // kullanýcý tarafýndan girilen ilac ve eczane ismi doðrultusunda oluþturulan ilac dosyalarýnda istenilen isimdeki ilac aranmaktadýr.
	
	fstream file;
	eczisim=eczisim+"_ilac.dat";
	file.open(eczisim.c_str(), ios::in );
	string line;
	
	if(file.is_open()==1){
		
		while(getline(file, line)){
			
			if(ilac == line){
				cout << eczisim << "'nde aradýðýnýz ilaç bulunmuþtur." << endl;
				
				cout<<" Ilac Isim: "<<line;
				getline(file,line);
				cout<<"\n";				
				
				cout<<" Ilac ID: "<<line;
				getline(file,line);
				cout<<"\n";
				
				cout<<" Ilac Adet :"<<line;
				getline(file,line);
				cout<<"\n";
				
				cout<<" Ilac Fiyatý: "<<line<<endl;
				cout<<"\n";
			}
		}
	}else{
		cout << "Dosya açýlamadý" << endl;
	}
	
	file.close();
}

void ilac_goster(string eczisim){ // istenilen ilac objesinin bilgileri ekrana yansýtýlmaktadýr.

	
	fstream dosya1;
	string tempdosya;
	int i=0;
	
		
	tempdosya=eczisim+"_ilac.dat";
	dosya1.open(tempdosya.c_str(), ios::in);
	
	string line;
	
	if(dosya1.is_open()){
	
		while(getline(dosya1,line)){
			
				cout << endl << "Ilac Isim: " << line;
				getline(dosya1,line);
							   
				cout << endl << "Ilac ID: "<< line << endl;
				getline(dosya1,line);
								
				cout << "Ilac Adet :" << line << endl;
				getline(dosya1,line);
				
				cout << "Ilac Fiyatý:" << line << endl;
				
			
		}
	}else {
        cout << "Dosyada kayýtlý isim yok" << endl; 
		dosya1.close(); 
 	}

   		
	dosya1.close();	
}

	

void ilac_dosya_olustur(Ilac ilac, string eczisim){ //olusturulan ilac objesinin bilgileri ait olduðu eczanenin ilac osyasýna kaydediliyor.
	
	ofstream dosya_i;
	string eczaneIlacListesi=eczisim+"_ilac.dat";
		
	dosya_i.open(eczaneIlacListesi.c_str(),ios::app); 
	
	if(!dosya_i.is_open()) { 
		cout << "Dosya açýlamadý..."; exit(0);	
	}
    
	
	dosya_i << ilac.iIsim()  << endl;
	dosya_i << ilac.iId()    << endl;
    dosya_i << ilac.iSayi()  << endl; 
    dosya_i << ilac.iFiyat() << endl;
    
	dosya_i.close();
		
}

	

int main(){
	setlocale(LC_ALL, "Turkish");
	
	
	
	Eczane i[3];  // Eczane objelerinin default ctr ile oluþturulmasý
	Ilac ilac[5]; // Ilac objelerinin default ctr ile oluþturulmasý ***** ctr w arg ile 10a kadar ilac tanýmla
	
	// gerekli deðiþkenlerin tanýmlanmasý
	
	string temp, ilack, sifre,eczanesifre; 
	int back1, ilacsayisi,k=0;
	int a, select,deneme1,menu1, menu2,yetki,m=0;
	string arama, eczisim, eczilac;
string aaaa;


main: //yapýlan iþlemler sonucunda programýn bu noktalardan çalýþmasý devam edecek...
		
	cout << "Yetkiliyseniz 1'i, Müþteriyseniz 2'yi tuþlayýnýz..."; //Eczane seçeneði yalnýzca yetkili tarafýndan seçilebilen bir seçenek olduðu için öncesinde kullanýcýya yetki durumu, 
	cin  >> yetki;
	
	
	if(yetki == 1){ 
	cout << "Eczane sistemi kaydedilecek olan sifrenizi giriniz: "; // akabinde sistem boyunca kullanacaðý þifreyi oluþturmasý istenmektedir.
	cin >> sifre;
	system ("CLS");	//þifre kayýt ekranýndan sonra girilen þifrenin kullanýcý harici kiþiler tarafýndan görülememesi için terminal ekraný temizlenmekte.
	
}
	
	else if(yetki == 2)	{ goto anamenu;	}
	else{ cout << "Hatalý tuþlama yaptýnýz. Tekrar deneyiniz." << endl; goto main;	} //belirtilen deðerler dýþý tuþlama yapma hata bilgisi


	
anamenu://yapýlan iþlemler sonucunda programýn bu noktalardan çalýþmasý devam edecek...
	
	
	cout << "Menu secimi yapiniz: \n 1-Eczane Girisi \n 2-Musteri Girisi\n 3-Sistemden Çýkýþ \n"; //Menü seçimlerinin yapýlmasý
	cin >> select;	
	
	
	
switch(select){
	
	case 1:
		
		
		eczanegirisi: //yapýlan iþlemler sonucunda programýn bu noktalardan çalýþmasý devam edecek...
			
			
			cout << "1-Eczane Girisi" << endl;
			cout << "Lütfen eczane þifresini giriniz: ";
			cin>>eczanesifre;
			system ("CLS"); // her þifre giriþi denemesinden sonra ekran güvenlik sebebiyle temizlenmekte
			
			
			if(eczanesifre==sifre){ //kullanýcý tarafýndan girilen þifrelerin ayný olup olmadýðý kontrolü...
				
				
				cout << "Giriþ baþarýyla gerçekleþtirildi. \n";
				
				eczanegirildi: //yapýlan iþlemler sonucunda programýn bu noktalardan çalýþmasý devam edecek...
					
				cout << "Yapilacak islemi seciniz: \n 1.1 Eczane Listesi Oluþtur \n 1.2 Eczane Ekle \n 1.3 Ýlaç Ekle \n 1.4 Ýlaç Düzenle \n\n Üst menüye dönmek için 5'i tuþlayýnýz...\n ";
				cin  >> menu1;
				
				
				switch(menu1){ //menü seçimleri...
					
					case 1: cout << "-- 1.1 Eczane Listesi Oluþtur--\n"; 
					
					
					i[0].eczane_olustur();
					eczane_dosya_olustur(i[0]);
					
					cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyasýna eklenmiþtir.\n" << endl;
					
		
					for(k=0; k<2; k++){
						
						ilac[k].ilac_olustur();
						ilac_dosya_olustur(ilac[k], i[0].EczIsim());
					}
									
					cout<<"Eczane menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n" << endl;
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
						
					case 2:cout << "-- 1.2 Eczane Ekle--\n";
					
					
					a=1;
					if(i[a].EczId()==0){
						i[a].eczane_olustur();
						eczane_dosya_olustur(i[a]);
						cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyasýna eklenmiþtir.\n" << endl;
					}
					else if(i[a+1].EczId()==0){ 
					    i[a+1].eczane_olustur();
					    eczane_dosya_olustur(i[a+1]);
					    cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyasýna eklenmiþtir.\n" << endl;
					    a++;
					}
					else { cout << "Eklenebilecek maksimum eczane sayýsýna ulaþtýnýz!" << endl; }
					
					
					cout<<"Eczane menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
					
					
					case 3:cout << "-- 1.3 Ýlaç Ekle--\n";
					
					
					ilac[0].ilac_olustur(); cout << "ilac bilgileri alindi" << endl;
					cout <<"Ilacý eklemek istediðiniz eczane adýný giriniz (örneðin cicek_eczanesi): ";
					cin  >> eczisim ;
					ilac_dosya_olustur(ilac[0], eczisim);
					
					cout << "ilac " << eczisim <<" dosyasýna eklendi" << endl;
					
					cout<<"Eczane menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
					
					case 4:	cout << "-- 1.4 Ýlaç Düzenle--\n";
					
					cout << "Eczane ismini giriniz (örneðin cicek_eczanesi): ";
					cin  >> aaaa;
					ilac_duzenle(aaaa);
					
					
					cout<<"Eczane menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
				    
				    
					case 5: goto anamenu;
					
					
					default: goto anamenu;
					
					
					
					
					
				}//menu1 için olan switchin sonu
								
				
				
				
			}else{
		
				cout << "Baþarýsýz giriþ denemesi!";
				cout << "Tekrar denemek için 1, ana menüye dönmek için 0'ý tuþlayýnýz..";
				cin  >> deneme1;
				if(deneme1==1){ goto eczanegirisi; }
				else if(deneme1==0){ goto anamenu; }
			}
	
	
	
	case 2: musterigirisi:
		
		
	cout << "Müþteri Giriþi" << endl;
	cout <<"Hoþgeldiniz. Yapmak istediðiniz iþlemi seçiniz: \n 2.1 Ýlaç Ara \n 2.2 Eczane Listele \n 2.3 Herhangi bir Eczaneyi Göster \n 2.4 Herhangi bir Eczaneye ait Ilaç Listesi \n\n Üst menüye dönmek için 5'i tuþlayýnýz...";
	cin  >> menu2;
	
	switch(menu2){
		
		case 1: cout << "-- 2.1 Ýlaç Arama --\n";
		
		
		cout << "Aramak istediðiniz ilacýn adýný giriniz: ";
		cin  >> ilack;
		
		for(int k=0; k<4 ; k++){
			temp=i[k].EczIsim();
			ilac_ara(ilack, temp);
			
		}
		
		cout<<"Müþteri menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}
		
			
		case 2: cout << "-- 2.2 Eczane Listele -- \n";
		
		m=0;
		
			       if(i[m].EczId()!=0){
			       	i[m].eczane_bilgileri();
						
					}
					else if(i[m+1].EczId()!=0){ 
			        i[m+1].eczane_bilgileri();
					}
					else if(i[m+2].EczId()!=0){
					i[m+2].eczane_bilgileri();	
					}
		
		cout<<"Müþteri menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}
		
		case 3: cout << "-- 2.3 Herhangi bir Eczaneyi Göster--\n";
		
		
		cout << "Lütfen aramak istediðiniz eczane adýný giriniz (örneðin cicek_eczanesi): \n";
		cin  >> arama;	
		eczane_ara(arama);
				
		cout<<"Müþteri menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}	
				
		
		case 4:	cout << "-- 2.4 Herhangi bir Eczaneye ait Ilaç Listesi --\n";
		
		
		cout << "Eczane adýný giriniz (örneðin cicek_eczanesi): ";
		cin  >> eczisim;
		
		ilac_goster(eczisim);
		
		cout<<"Müþteri menüsünde baþka bir iþlem yapmak için 1'i, anamenüye dönmek için 0'ý tuþlayýnýz\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}
		
		
		case 5: goto anamenu;
		
		default: goto anamenu;
		
		
	}//menu2 için olan switchin sonu
	
	case 3: break;
	
	default : break;
	
}//büyük switchin sonu
	
	
return 0; }
