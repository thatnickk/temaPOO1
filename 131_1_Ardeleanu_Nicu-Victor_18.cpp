#include <iostream>

using namespace std;

class Film{
    string denumire;
    string gen;
    string regizor;
    double rating;
    public:
        Film(){
        }
        Film(string a, string b, string c, double r){
            denumire = a;
            gen = b;
            regizor = c;
            rating = r;
        }
        ~Film(){
        }
        string getDenumire(){
            return denumire;
        }
        string getGen(){
            return gen;
        }
        string getRegizor(){
            return regizor;
        }
        double getRating(){
            return rating;
        }
        string setDenumire(string denumire){
            this->denumire = denumire;
        }
        string setGen(string gen){
            this->gen = gen;
        }
        string setRegizor(string regizor){
            this->regizor = regizor;
        }
        double setRating(double rating){
            this->rating = rating;
        }

        void citireNFilme(int n){
            Film *f = new Film[n];
            for(int i=0; i<n; i++){
                cin>>f[i];
            }
        }

        void scriereNFilme(Film f[], int n){
            for(int i=0; i<n; i++){
                cout<<f[i]<<'\n';
            }
        }

        friend istream& operator>>(istream&, Film&);
        friend ostream& operator<<(ostream&, Film&);
        void operator=(const Film& f){
            denumire = f.denumire;
            gen = f.gen;
            regizor = f.regizor;
            rating = f.rating;
        }
        bool operator>(const Film& f){
            if(rating>f.rating)
                return true;
            return false;
        }
        bool operator<(const Film& f){
            if(rating<f.rating)
                return true;
            return false;
        }
        bool operator>=(const Film& f){
            if(rating>=f.rating)
                return true;
            return false;
        }
        bool operator<=(const Film& f){
            if(rating<=f.rating)
                return true;
            return false;
        }
        bool operator==(const Film& f){
            if(rating==f.rating)
                return true;
            return false;
        }
};

istream& operator>>(istream& in, Film& f)
{
    in>>f.denumire;
    in>>f.gen;
    in>>f.regizor;
    in>>f.rating;
    return in;
}

ostream& operator<<(ostream& out, Film& f)
{
    out<<f.denumire<<" "<<f.gen<<" "<<f.regizor<<" "<<f.rating;
    return out;
}

int main(){
    int n,option=-1,i1,i2,opt2;
    string den, g, reg;
    double rate;
    cout<<"Bun venit! Scrieti numarul de filme de inregistrat:";
    cin>>n;
    cout<<"Acum descrieti cele "<<n<<" filme(numele, genul, regizorul, ratingul):\n";
    Film *filme = new Film[n];
    for(int i=0; i<n; i++){
        cout<<"Introduceti datele despre filmul "<<i+1<<'\n';
        cin>>filme[i];
    }
    while(option!=0){
        cout<<"Alegeti actiunea urmatoare:\n 1-comparati doua filme\n 2-modificati informatiile unui film\n 3-afisati toate filmele\n 0-iesire\n";
        cin>>option;
        switch(option){
            case 1:
                cout<<"Dati indexul celor doua filme de comparat:\n";
                cin>>i1>>i2;
                if(filme[i1-1]==filme[i2-1])
                    cout<<"Filmele sunt la fel de bune\n";
                else if(filme[i1-1]>filme[i2-1])
                    cout<<"Filmul "<<filme[i1-1].getDenumire()<<" este mai bun\n";
                else
                    cout<<"Filmul "<<filme[i2-1].getDenumire()<<" este mai bun\n";
                break;
            case 2:
                cout<<"Dati indexul filmului de modificat:\n";
                cin>>i1;
                cout<<"Ce doriti sa modificati la "<<filme[i1-1].getDenumire()<<"?\n 1-denumirea\n 2-genul\n 3-regizorul\n 4-ratingul\n";
                cin>>opt2;
                switch(opt2){
                    case 1:
                        cout<<"Dati noua denumire:\n";
                        cin>>den;
                        filme[i1-1].setDenumire(den);
                        break;
                    case 2:
                        cout<<"Dati noul gen:\n";
                        cin>>g;
                        filme[i1-1].setGen(g);
                        break;
                    case 3:
                        cout<<"Dati noul regizor:\n";
                        cin>>reg;
                        filme[i1-1].setRegizor(reg);
                        break;
                    case 4:
                        cout<<"Dati noul rating:\n";
                        cin>>rate;
                        filme[i1-1].setRating(rate);
                        break;
                }
                break;
            case 3:
                cout<<"Filmele inregistrate sunt:\n";
                for(int i=0; i<n; i++){
                    cout<<filme[i].getDenumire()<<", gen "<<filme[i].getGen()<<", regizat de "<<filme[i].getRegizor()<<". Rated "<<filme[i].getRating()<<" by imdb.\n";
                }
                break;
        }
    }

    delete[] filme;
    return 0;
}
