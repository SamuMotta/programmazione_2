#include <iostream>
#include <fstream>
#include <cstdlib>
#define N 2000

using namespace std;


class User {
    private:
        unsigned int id;
        string surname;
        string name;
        double popularity;
    
    
    public:
        User(unsigned int i, string c, string n, double p) : 
		id(i), surname(c), name(n), popularity(p) {}
		
	User() : User(0, "", "", 0.0) {}
	
	friend istream &operator>>(istream &input, User &user) {
		string id_string, pop_string;
		getline(input, id_string, ';');
		getline(input, user.surname, ';');
		getline(input, user.name, ';');
		getline(input, pop_string);
		user.id = atoi(id_string.c_str());	
		user.popularity = atof(pop_string.c_str());
		
		return input; 
	
	}
};

int main () {

	ifstream ifs("utenti.txt", ifstream::in);
	
	User *users = new User[N];
	unsigned int count = 0;
	while(ifs.good()) {
		User u;
		ifs >> u;
		users[count++] = u;
	}
	
	ifs.close();

}
