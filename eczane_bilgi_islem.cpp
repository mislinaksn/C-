#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

class Ilac;
class Eczane; //i� i�e friend fonksiyon kullan�m�nda tan�mlanma hatas� vermemesi i�in programa ba�larken tan�mlayaca��m classlar� declare ediyorum

class Eczane{
	
	
	private: // Eczane class�nda private de�i�ken olarak eczanenin id, isim ve adres bilgileri bulunuyor. Bu bilgilere public k�sm�nda tan�mlanan fonksiyonlar arac�l���yla ula��l�yor.
		
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
			


    void eczane_olustur(){ //kullan�c� taraf�ndan girilen bilgiler do�rultusunda eczane objesinin bilgileri atan�yor.
	
	
	char ecz_adres[150], ecz_isim[20];
    string tempisim, tempadres;
    int tempid, ecz_id;
    
    
    cout<<"L�tfen eczane ad�n� giriniz: \n";
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






    void eczane_bilgileri(){ // eczane_listesi.dat dosyas�ndaki b�t�n eczanelerin bilgileri ekrana yazd�r�l�yor.
    
    string okuma;
    fstream dosya1;
    dosya1.open("eczane_listesi.dat", ios::in);
    
    while(dosya1 >> okuma){
    	cout << okuma << endl;
    	kaydet+=okuma; //dosya okumas� yap�l�rken bilgiler ikici bir string i�ine kaydediliyor
	}
	
	dosya1.close();
  
	}

//class i�erisinde tan�mlanan private de�erlere ula�mas� gereken class d��� fonksiyonlar friend fonksiyon olarak tan�mlan�yor.
	
friend void eczane_dosya_olustur(Eczane i); 
friend void eczane_ara(string anahtar);
friend void ilac_dosya_olustur(Ilac ilac, Eczane ecz);
friend void ilac_goster(Ilac ilac);
friend void ilac_duzenle(Ilac ilac);
	

};



void eczane_dosya_olustur(Eczane i){ //fonksiyona yollanan eczane objesinin bilgileri eczane_listesi.at dosyas�na yazd�r�l�yor.
	
	
    fstream dosya;
    dosya.open("eczane_listesi.dat", ios::app); // dosya app eklentisi ile a��l�yor
    
    if(!dosya.is_open()) { cout << "Dosya a��lamad�..."; exit(0);	} //dosyan�n a��l�p a��lmad���n�n kontrol� yap�l�yor
    

    
    dosya << i.EczIsim()   << endl;
	dosya << i.EczId()     << endl;
	dosya << i.EczAdres()  << endl;
    
    dosya.close();	// bilgiler dosyaya yazd�r�ld�ktan sonra dosya kapat�l�yor.
	
}


void eczane_ara(string anahtar){ //kullan�c� taraf�ndan girilen eczane ad�n�n listede olup olmad��� aramas� yap�l�yor.
	
	fstream file;
	file.open("eczane_listesi.dat", ios::in);

	
	string line;
	
	if(file.is_open()){
	
		while(getline(file,line)){ // bilgiler dosyadan sat�r sat�r okuma yap�l�yor
			
			if(anahtar==line){ // arad���m�z eczane ad� okudu�umuz sat�rda ise; 
				cout << endl << " Eczane Ad�:" << line; //ilk sat�r eczanenin ad�na,
				getline(file,line);
				cout << "\n ID:" << line; // ikinci sat�r eczanenin id bilgisine, 
				getline(file,line);
				cout << "\n Adres:" << line << endl; // ���nc� sat�r eczanenin adres bilgisine e�itleniyor.
			}
		}
	}
}


 
class Ilac
{
	private:  // Ilac class�na ait id, ilac�n say�s�, fiyat� ve isim bilgileriprivate olarak tan�mlan�yor. Public fonksiyonlar arac�l���yla bilgilere ula��l�yor.
		
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
    
    //set functions ila�
    
    void iSetId(int i_id){ 
    
    ilac_id = i_id; }
    
    
    void iSetSayi(int sayi){ 
    
    ilac_sayisi = sayi; }    
	
	
    void iSetFiyat(double fiyat){ 
    
    ilac_fiyati = fiyat;  }   
    
    
    void iSetIsim(string i_isim){ 
    
    ilac_isim = i_isim;  	}     
    
    
    
    // get functions ila�
    
    int iId(){ return ilac_id;	}
    
    int iSayi(){ return ilac_sayisi;	}
    
    double iFiyat(){ return ilac_fiyati;	}
    
    string iIsim(){ return ilac_isim;	}    
    
    void ilac_olustur(){ //kullan�c� taraf�nda girilecek olan bilgiler do�rultusunda ilac objesinin bilgilerinne atama yap�l�yor.
    
    int id, sayi;
	double fiyat;
	string isim;
		
	cout << "Ilac ad�n� giriniz: " << endl;
    fflush(stdin);
    getline(cin, ilac_isim);
		
	cout << "Ila� ID giriniz: " << endl;
	cin  >> ilac_id;
	
    cout << "Ilac�n say�s�n� giriniz: " << endl;
    cin  >> ilac_sayisi;
    
    cout << "Ilac�n fiyat�n� giriniz: " << endl;
    cin  >> ilac_fiyati;

    	
	}
	
	
	



// class d��� kullan�mdaki fonksiyonlar friend olarak classa tan�mlan�yor
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
			
			cout<<" Ilac�n yeni ID bilgisi: ";
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

void ilac_ara(string ilac, string eczisim){ // kullan�c� taraf�ndan girilen ilac ve eczane ismi do�rultusunda olu�turulan ilac dosyalar�nda istenilen isimdeki ilac aranmaktad�r.
	
	fstream file;
	eczisim=eczisim+"_ilac.dat";
	file.open(eczisim.c_str(), ios::in );
	string line;
	
	if(file.is_open()==1){
		
		while(getline(file, line)){
			
			if(ilac == line){
				cout << eczisim << "'nde arad���n�z ila� bulunmu�tur." << endl;
				
				cout<<" Ilac Isim: "<<line;
				getline(file,line);
				cout<<"\n";				
				
				cout<<" Ilac ID: "<<line;
				getline(file,line);
				cout<<"\n";
				
				cout<<" Ilac Adet :"<<line;
				getline(file,line);
				cout<<"\n";
				
				cout<<" Ilac Fiyat�: "<<line<<endl;
				cout<<"\n";
			}
		}
	}else{
		cout << "Dosya a��lamad�" << endl;
	}
	
	file.close();
}

void ilac_goster(string eczisim){ // istenilen ilac objesinin bilgileri ekrana yans�t�lmaktad�r.

	
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
				
				cout << "Ilac Fiyat�:" << line << endl;
				
			
		}
	}else {
        cout << "Dosyada kay�tl� isim yok" << endl; 
		dosya1.close(); 
 	}

   		
	dosya1.close();	
}

	

void ilac_dosya_olustur(Ilac ilac, string eczisim){ //olusturulan ilac objesinin bilgileri ait oldu�u eczanenin ilac osyas�na kaydediliyor.
	
	ofstream dosya_i;
	string eczaneIlacListesi=eczisim+"_ilac.dat";
		
	dosya_i.open(eczaneIlacListesi.c_str(),ios::app); 
	
	if(!dosya_i.is_open()) { 
		cout << "Dosya a��lamad�..."; exit(0);	
	}
    
	
	dosya_i << ilac.iIsim()  << endl;
	dosya_i << ilac.iId()    << endl;
    dosya_i << ilac.iSayi()  << endl; 
    dosya_i << ilac.iFiyat() << endl;
    
	dosya_i.close();
		
}

	

int main(){
	setlocale(LC_ALL, "Turkish");
	
	
	
	Eczane i[3];  // Eczane objelerinin default ctr ile olu�turulmas�
	Ilac ilac[5]; // Ilac objelerinin default ctr ile olu�turulmas� ***** ctr w arg ile 10a kadar ilac tan�mla
	
	// gerekli de�i�kenlerin tan�mlanmas�
	
	string temp, ilack, sifre,eczanesifre; 
	int back1, ilacsayisi,k=0;
	int a, select,deneme1,menu1, menu2,yetki,m=0;
	string arama, eczisim, eczilac;
string aaaa;


main: //yap�lan i�lemler sonucunda program�n bu noktalardan �al��mas� devam edecek...
		
	cout << "Yetkiliyseniz 1'i, M��teriyseniz 2'yi tu�lay�n�z..."; //Eczane se�ene�i yaln�zca yetkili taraf�ndan se�ilebilen bir se�enek oldu�u i�in �ncesinde kullan�c�ya yetki durumu, 
	cin  >> yetki;
	
	
	if(yetki == 1){ 
	cout << "Eczane sistemi kaydedilecek olan sifrenizi giriniz: "; // akabinde sistem boyunca kullanaca�� �ifreyi olu�turmas� istenmektedir.
	cin >> sifre;
	system ("CLS");	//�ifre kay�t ekran�ndan sonra girilen �ifrenin kullan�c� harici ki�iler taraf�ndan g�r�lememesi i�in terminal ekran� temizlenmekte.
	
}
	
	else if(yetki == 2)	{ goto anamenu;	}
	else{ cout << "Hatal� tu�lama yapt�n�z. Tekrar deneyiniz." << endl; goto main;	} //belirtilen de�erler d��� tu�lama yapma hata bilgisi


	
anamenu://yap�lan i�lemler sonucunda program�n bu noktalardan �al��mas� devam edecek...
	
	
	cout << "Menu secimi yapiniz: \n 1-Eczane Girisi \n 2-Musteri Girisi\n 3-Sistemden ��k�� \n"; //Men� se�imlerinin yap�lmas�
	cin >> select;	
	
	
	
switch(select){
	
	case 1:
		
		
		eczanegirisi: //yap�lan i�lemler sonucunda program�n bu noktalardan �al��mas� devam edecek...
			
			
			cout << "1-Eczane Girisi" << endl;
			cout << "L�tfen eczane �ifresini giriniz: ";
			cin>>eczanesifre;
			system ("CLS"); // her �ifre giri�i denemesinden sonra ekran g�venlik sebebiyle temizlenmekte
			
			
			if(eczanesifre==sifre){ //kullan�c� taraf�ndan girilen �ifrelerin ayn� olup olmad��� kontrol�...
				
				
				cout << "Giri� ba�ar�yla ger�ekle�tirildi. \n";
				
				eczanegirildi: //yap�lan i�lemler sonucunda program�n bu noktalardan �al��mas� devam edecek...
					
				cout << "Yapilacak islemi seciniz: \n 1.1 Eczane Listesi Olu�tur \n 1.2 Eczane Ekle \n 1.3 �la� Ekle \n 1.4 �la� D�zenle \n\n �st men�ye d�nmek i�in 5'i tu�lay�n�z...\n ";
				cin  >> menu1;
				
				
				switch(menu1){ //men� se�imleri...
					
					case 1: cout << "-- 1.1 Eczane Listesi Olu�tur--\n"; 
					
					
					i[0].eczane_olustur();
					eczane_dosya_olustur(i[0]);
					
					cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyas�na eklenmi�tir.\n" << endl;
					
		
					for(k=0; k<2; k++){
						
						ilac[k].ilac_olustur();
						ilac_dosya_olustur(ilac[k], i[0].EczIsim());
					}
									
					cout<<"Eczane men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n" << endl;
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
						
					case 2:cout << "-- 1.2 Eczane Ekle--\n";
					
					
					a=1;
					if(i[a].EczId()==0){
						i[a].eczane_olustur();
						eczane_dosya_olustur(i[a]);
						cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyas�na eklenmi�tir.\n" << endl;
					}
					else if(i[a+1].EczId()==0){ 
					    i[a+1].eczane_olustur();
					    eczane_dosya_olustur(i[a+1]);
					    cout<<i[0].EczIsim()<<"'nin bilgileri eczane_listesi.dat dosyas�na eklenmi�tir.\n" << endl;
					    a++;
					}
					else { cout << "Eklenebilecek maksimum eczane say�s�na ula�t�n�z!" << endl; }
					
					
					cout<<"Eczane men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
					
					
					case 3:cout << "-- 1.3 �la� Ekle--\n";
					
					
					ilac[0].ilac_olustur(); cout << "ilac bilgileri alindi" << endl;
					cout <<"Ilac� eklemek istedi�iniz eczane ad�n� giriniz (�rne�in cicek_eczanesi): ";
					cin  >> eczisim ;
					ilac_dosya_olustur(ilac[0], eczisim);
					
					cout << "ilac " << eczisim <<" dosyas�na eklendi" << endl;
					
					cout<<"Eczane men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
					
					
					case 4:	cout << "-- 1.4 �la� D�zenle--\n";
					
					cout << "Eczane ismini giriniz (�rne�in cicek_eczanesi): ";
					cin  >> aaaa;
					ilac_duzenle(aaaa);
					
					
					cout<<"Eczane men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto eczanegirildi;	}
				    else if (back1==0) { goto anamenu;  	}
				    
				    
					case 5: goto anamenu;
					
					
					default: goto anamenu;
					
					
					
					
					
				}//menu1 i�in olan switchin sonu
								
				
				
				
			}else{
		
				cout << "Ba�ar�s�z giri� denemesi!";
				cout << "Tekrar denemek i�in 1, ana men�ye d�nmek i�in 0'� tu�lay�n�z..";
				cin  >> deneme1;
				if(deneme1==1){ goto eczanegirisi; }
				else if(deneme1==0){ goto anamenu; }
			}
	
	
	
	case 2: musterigirisi:
		
		
	cout << "M��teri Giri�i" << endl;
	cout <<"Ho�geldiniz. Yapmak istedi�iniz i�lemi se�iniz: \n 2.1 �la� Ara \n 2.2 Eczane Listele \n 2.3 Herhangi bir Eczaneyi G�ster \n 2.4 Herhangi bir Eczaneye ait Ila� Listesi \n\n �st men�ye d�nmek i�in 5'i tu�lay�n�z...";
	cin  >> menu2;
	
	switch(menu2){
		
		case 1: cout << "-- 2.1 �la� Arama --\n";
		
		
		cout << "Aramak istedi�iniz ilac�n ad�n� giriniz: ";
		cin  >> ilack;
		
		for(int k=0; k<4 ; k++){
			temp=i[k].EczIsim();
			ilac_ara(ilack, temp);
			
		}
		
		cout<<"M��teri men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
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
		
		cout<<"M��teri men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}
		
		case 3: cout << "-- 2.3 Herhangi bir Eczaneyi G�ster--\n";
		
		
		cout << "L�tfen aramak istedi�iniz eczane ad�n� giriniz (�rne�in cicek_eczanesi): \n";
		cin  >> arama;	
		eczane_ara(arama);
				
		cout<<"M��teri men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}	
				
		
		case 4:	cout << "-- 2.4 Herhangi bir Eczaneye ait Ila� Listesi --\n";
		
		
		cout << "Eczane ad�n� giriniz (�rne�in cicek_eczanesi): ";
		cin  >> eczisim;
		
		ilac_goster(eczisim);
		
		cout<<"M��teri men�s�nde ba�ka bir i�lem yapmak i�in 1'i, anamen�ye d�nmek i�in 0'� tu�lay�n�z\n";
				    cin>>back1;
				    
				    if (back1==1){ goto musterigirisi;	}
				    else if (back1==0) { goto anamenu;  	}
		
		
		case 5: goto anamenu;
		
		default: goto anamenu;
		
		
	}//menu2 i�in olan switchin sonu
	
	case 3: break;
	
	default : break;
	
}//b�y�k switchin sonu
	
	
return 0; }
