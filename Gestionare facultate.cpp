#include <iostream>
#include <string>


using namespace std;

class Facultate {
private:
	const int idFacultate;
	static int nrSpecializari;
	static int nrFacultati;
	char *denumire;
	int nrSInmatriculati;
	float suprafata;
	int nrSali;
	bool programId;
public:

	void afisareFacultate() {
		cout << "Facultate: " << endl;
		cout << "Id: " << idFacultate << endl;
		cout << "Denumire facultate: " << denumire << endl;
		cout << "Nr de studenti inmatriculati: " << nrSInmatriculati << endl;
		cout << "Suprafata: " << suprafata << endl;
		cout << "Nr sali: " << nrSali << endl;
		if (programId == false)
			cout << "Facultatea are program de invatamant la distanta";
		else cout << "Facultatea nu are program de invatamant la distanta";
		cout << endl;
	}

	void citireFacultate() {
		cout << "Facultate: " << endl;
		cout << "Denumire facultate: ";
		char den[40];
		cin >> den;
		denumire = new char[strlen(den) + 1];
		strcpy(denumire, den);
		cout << "Numar de studenti inmatriculati: ";
		cin >> nrSInmatriculati;
		cout << "Suprafata: ";
		cin >> suprafata;
		cout << "Numar sali: ";
		cin >> nrSali;
		cout << "0- Are program de invatamant la distanta/1-Nu are program de invatamant la distanta";
		cin >> programId;
	}

	void initializareFacultate(char *_denumire, int nrs, float _suprafata, int nrsali, bool p) {

		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = nrsali;
		this->programId = p;

	}

	void setDenumire(char * den) {
		if (den != NULL)
		{
			if (denumire != NULL)
				delete[] denumire;
			denumire = new char[strlen(den) + 1];
			strcpy(denumire, den);
		}
		else throw - 1;
	}

	char* getDenumire() {
		return denumire;
	}

	void setNrSInmatriculati(int nr) {
		if (nr > 0) {
			nrSInmatriculati = nr;
		}
		else throw - 1;
	}

	int getNrSInmatriculati() {
		return nrSInmatriculati;
	}

	void setSuprafata(float nr) {
		if (nr > 0)
		{
			suprafata = nr;
		}
	}

	float getSuprafata() {
		return suprafata;
	}

	void setNrSali(int nr) {
		if (nr > 0)
			nrSali = nr;
	}

	int getNrSali() {
		return nrSali;
	}

	void setProgram(bool p) {
		programId = p;
	}
	bool getProgram() {
		return programId;
	}
	Facultate() :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(denumire, "Anonim");
		this->nrSInmatriculati = -1;
		this->suprafata = -1;
		this->nrSali = 0;
		this->programId = true;
	}
	Facultate(const char *_denumire, int nrs, float _suprafata, int nrsali, bool p) :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = nrsali;
		this->programId = p;
	}
	Facultate(char *_denumire, int nrs, float _suprafata) :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = 0;
		this->programId = true;
	}

	Facultate operator=(const Facultate &f) {
		this->denumire = new char[strlen(f.denumire) + 1];
		strcpy(denumire, f.denumire);
		this->nrSInmatriculati = f.nrSInmatriculati;
		this->suprafata = f.suprafata;
		this->nrSali = f.nrSali;
		this->programId = f.programId;
		return *this;
	}
	Facultate(const Facultate &f) :idFacultate(++nrFacultati) {
		this->denumire = new char[strlen(f.denumire) + 1];
		strcpy(denumire, f.denumire);
		this->nrSInmatriculati = f.nrSInmatriculati;
		this->suprafata = f.suprafata;
		this->nrSali = f.nrSali;
		this->programId = f.programId;

	}

	~Facultate() {
		if (denumire != NULL) {
			delete[] this->denumire;
		}
	}

	Facultate operator+=(Facultate f) {
		this->suprafata += f.suprafata;
		return *this;
	}

	bool operator==(Facultate f) {
		if (this->idFacultate == f.idFacultate) return 1;
		else return 0;
	}
	operator int() {
		return this->idFacultate;
	}
	bool  operator>(Facultate f) {
		if (this->suprafata > f.suprafata) return 1;
		else return 0;
	}

	bool  operator<(Facultate f) {
		if (this->suprafata < f.suprafata) return 1;
		else return 0;
	}
	friend ostream& operator<<(ostream& out, Facultate f) {
		out << "Facultate: " << endl;
		out << "Id: " << f.idFacultate << endl;
		out << "Denumire: " << f.denumire << endl;
		out << "Nr de studenti inmatriculati: " << f.nrSInmatriculati << endl;
		out << "Suprafata: " << f.suprafata << endl;
		out << "Nr sali: " << f.nrSali << endl;
		if (f.programId == false)
			out << "Facultatea are program de invatamant la distanta";
		else out << "Facultatea nu are program de invatamant la distanta";
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Facultate& f) {
		cout << "Denumire facultate ";
		in >> f.denumire;
		cout << "Nr studenti inmatriculati ";
		in >> f.nrSInmatriculati;
		cout << "Suprafata ";
		in >> f.suprafata;
		cout << "Nr sali ";
		in >> f.nrSali;
		cout << "Program id ";
		in >> f.programId;
		return in;
	}
};

int Facultate::nrSpecializari = 3;
int Facultate::nrFacultati = 0;

Facultate operator+(Facultate f, int nr) {
	Facultate rezultat = f;
	rezultat.setNrSInmatriculati(rezultat.getNrSInmatriculati() + nr);
	return rezultat;
}
Facultate operator+(int nr, Facultate f) {
	Facultate rezultat = f;
	rezultat.setNrSInmatriculati(rezultat.getNrSInmatriculati() + nr);
	return rezultat;
}




class Specializare :public Facultate {
private:
	string denumire;
	int nrMaterii;
	int aniStudiu;
	int* nrStudenti;
public:
	Specializare() :Facultate() {
		this->denumire = "Anonim ";
		this->nrMaterii = -1;
		this->aniStudiu = -1;
		this->nrStudenti = NULL;
	}
	Specializare( string _denumire, int _nrM, int _an, int * nrS) :Facultate("CSIE",1000,450,100,1) {
		this->denumire = _denumire;
		this->nrMaterii = _nrM;
		this->aniStudiu = _an;
		this->nrStudenti = new int[this->aniStudiu];
		for (int i = 0; i < this->aniStudiu; i++) {
			this->nrStudenti[i] = nrS[i];
		}
	}
	Specializare(const char *denumire, int nrs, float _suprafata, int nrsali, bool p, string _denumire, int _nrM, int _an, int * nrS) :Facultate(denumire, nrs, _suprafata, nrsali, p) {
		this->denumire = _denumire;
		this->nrMaterii =_nrM;
		this->aniStudiu = _an;
		this->nrStudenti = new int[this->aniStudiu];
		for (int i = 0; i < this->aniStudiu; i++) {
			this->nrStudenti[i] = nrS[i];
		}
	}

	friend ostream& operator<<(ostream& out, Specializare s) {
		out <<( Facultate&)s;
		out << "Specializare: " << endl;
		out << "Denumire facultate " << s.denumire << endl;
		out << "Numar materii " << s.nrMaterii << endl;
		out << "Ani de studiu  " << s.aniStudiu << endl;
		for (int i = 0; i < s.aniStudiu; i++)
			out << "Nr studenti in anul " << i + 1 << " inmatriculati " << s.nrStudenti[i] << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Specializare& s)
	{
		in>>(Facultate&)s;
		cout << "Denumire specializare ";
		in >> s.denumire;
		cout << "Numar materii ";
		in >> s.nrMaterii;
		cout << "Ani de studiu ";
		in >> s.aniStudiu;
		s.nrStudenti = new int[s.aniStudiu + 1];
		for (int i = 0; i < s.aniStudiu; i++)
		{
			cout << "Nr studenti inmatriculati in anul " << i + 1 << " ";
			in >> s.nrStudenti[i];
		}

		return in;
	}

	Specializare(const Specializare& s) :Facultate(s) {
		this->denumire = s.denumire;
		this->nrMaterii = s.nrMaterii;
		this->aniStudiu = s.aniStudiu;
		this->nrStudenti = new int[s.aniStudiu];
		for (int i = 0; i < s.aniStudiu; i++) {
			this->nrStudenti[i] = s.nrStudenti[i];
		}
	}

	Specializare operator=(const Specializare& s)  {
		Facultate::operator=(s);
		this->denumire = s.denumire;
		this->nrMaterii = s.nrMaterii;
		this->aniStudiu = s.aniStudiu;
		this->nrStudenti = new int[s.aniStudiu];
		for (int i = 0; i < s.aniStudiu; i++) {
			this->nrStudenti[i] = s.nrStudenti[i];
		}
		return *this;
	}
	~Specializare() {
		if (this->nrStudenti != NULL)
			delete[] this->nrStudenti;
	}

};

class Departament :public Facultate {
private:
	char* denumire;
	int nrProiecte;
	int* nrPersoane;
public:
	Departament() :Facultate() {
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->nrProiecte = 0;
		this->nrPersoane = NULL;
	}
	Departament(const char* den,int nrP, int* nr) :Facultate("CSIE", 1000, 450, 100, 1) {
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->nrProiecte = nrP;
		this->nrPersoane = new int[nrP+1];
		for (int i = 0; i < nrP; i++)
			this->nrPersoane[i] = nr[i];
	}
	Departament(const char *denumire, int nrs, float _suprafata, int nrsali, bool p, const char* den, int nrP, int* nr) :Facultate(denumire, nrs, _suprafata, nrsali, p)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->nrProiecte = nrP;
		this->nrPersoane = new int[nrP + 1];
		for (int i = 0; i < nrP; i++)
			this->nrPersoane[i] = nr[i];
	}
	friend ostream&operator<<(ostream& out, Departament d) {
		out << (Facultate)d;
		out << "Denumire departament " << d.denumire << endl;
		out << "Numar proiecte " << d.nrProiecte << endl;
		for (int i = 0; i < d.nrProiecte; i++)
		{
			out << "La proiectul " << i + 1 << " lucreaza " << d.nrPersoane[i] << " persoane"<<endl;
		}
		return out;

	}

	friend istream&operator>>(istream& in, Departament& d) {
		in >> (Facultate&)d;
		cout << "Denumirea deparatmentului ";
		in >> d.denumire;
		cout << "Numar proiecte ";
		in >> d.nrProiecte;
		d.nrPersoane = new int[d.nrProiecte + 1];
		for (int i = 0; i < d.nrProiecte; i++) {
			cout << "La proiectul " << i + 1 << " lucreaza ";
			in >> d.nrPersoane[i];
		}
		return in;
	}

	Departament(const Departament& d) :Facultate(d) {
		this->denumire = new char[strlen(d.denumire) + 1];
		strcpy(this->denumire, d.denumire);
		this->nrProiecte = d.nrProiecte;
		this->nrPersoane = new int[d.nrProiecte + 1];
		for (int i = 0; i < d.nrProiecte; i++)
		{
			this->nrPersoane[i] = d.nrPersoane[i];
		}
	}

	Departament operator=(const Departament& d) {
		Facultate::operator=(d);
		this->denumire = new char[strlen(d.denumire) + 1];
		strcpy(this->denumire, d.denumire);
		this->nrProiecte = d.nrProiecte;
		this->nrPersoane = new int[d.nrProiecte + 1];
		for (int i = 0; i < d.nrProiecte; i++)
		{
			this->nrPersoane[i] = d.nrPersoane[i];
		}
		return *this;
	}
	~Departament() {
		if (this->denumire != NULL)
			delete[] this->denumire;
		if (this->nrPersoane != NULL)
			delete[] this->nrPersoane;
	}
};

class Secretariat :public Facultate {
private:
	int oraDeschidere;
	int oraInchidere;
	int nrTelefon;
public:
	Secretariat() :Facultate() {
		this->oraDeschidere = 0;
		this->oraInchidere = 0;
		this->nrTelefon = 123;
	}
	Secretariat(int od, int oi, int nt) :Facultate("CSIE", 2000, 456.8, 40, 0) {
		this->oraDeschidere = od;
		this->oraInchidere = oi;
		this->nrTelefon = nt;
	}
	Secretariat(const char *_denumire, int nrs, float _suprafata, int nrsali, bool p,int od, int oi, int nt) :Facultate(_denumire, nrs, _suprafata, nrsali, p) {
		this->oraDeschidere = od;
		this->oraInchidere = oi;
		this->nrTelefon = nt;
	}

	friend ostream&operator<<(ostream& out, Secretariat sr) {
		out << (Facultate)sr;
		out << "Ora deschidere " << sr.oraDeschidere << endl;
		out << "Ora inchidere " << sr.oraInchidere << endl;
		out << "Numar de telefon " << sr.nrTelefon << endl;
		return out;
	}
	friend istream&operator>>(istream& in, Secretariat& sr) {
		in >> (Facultate&)sr;
		cout << "Ora deschidere ";
		in >> sr.oraDeschidere;
		cout << "Ora inchidere ";
		in >> sr.oraInchidere;
		cout << "Numar de  telefon ";
		in >> sr.nrTelefon;
		return in;
	}
	
	Secretariat(const Secretariat& sr) :Facultate(sr){
		this->oraDeschidere = sr.oraDeschidere;
		this->oraInchidere = sr.oraInchidere;
		this->nrTelefon = sr.nrTelefon;
	}

	Secretariat operator=(const Secretariat& sr) {
		Facultate::operator=(sr);
		this->oraDeschidere = sr.oraDeschidere;
		this->oraInchidere = sr.oraInchidere;
		this->nrTelefon = sr.nrTelefon;

		return *this;
	}
};
void main() {
	
	
	Specializare s1("Informatica Economica", 56, 3, new int[3]{ 700,600,500 });
	cout << s1;
	Specializare s2 = s1;
	cout << s2;
	Specializare s3("CSIE",2000,456.8,40,0,"Informatica Economica", 56, 3, new int[3]{ 700,600,500 });
	cout << s3;
	Specializare s4;
	/*cin >> s4;
	cout << s4;*/
	cout << endl;

	Departament d1("Marketing online", 3, new int[3]{ 3,5,2 });
	cout << d1;
	Departament d2("Marketing ", 1000, 756.8, 40, 0, "Marketing online", 3, new int[3]{ 3,5,2 });
	cout << d2;
	Departament d3;
	/*cin >> d3;
	cout << d3;*/
	Departament d4 = d1;
	cout << d4;


	Secretariat sr1(9, 16, 23457);
	cout << sr1;
	Secretariat sr2("Contabilitate ", 1000, 756.8, 40, 0, 9, 16, 23457);
	cout << sr2;
	Secretariat sr3;
	/*cin >> sr3;
	cout << sr3;*/
	Secretariat sr4 = sr2;
	cout << sr4;
}