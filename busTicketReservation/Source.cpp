#include <iostream>
#include <string>,
using namespace std;

void slogan(string& slogan) {
	cout << slogan << endl;
}


class City {

private:
	string city1;
	string city2;
	string city3;
	string mesage;

public:
	City() {
		city1 = "ISTANBUL-ANKARA";
		city2 = "ANKARA-ANTALYA";
		city3 = "ISTANBUL-ANTALYA ";
		mesage = "WELCOME.";
	}

	City(string city1, string city2, string city3, string mesage) {
		this->city1 = city1;
		this->city2 = city3;
		this->city3 = city3;
		this->mesage = mesage;
	}
	~City() {
		cout << " " << endl;
	}

	friend void mesagee(City msg);
	friend class Print;
};


void mesagee(City msg) {
	cout << msg.mesage << endl;
}


class Print {
public:
	static void showInfos(City cityInformation) {
		cout << "<<< Cities >>>" << endl;
		cout << cityInformation.city1 << endl;
		cout << cityInformation.city2 << endl;
		cout << cityInformation.city3;

	}

};


class PriceDay : public Print {
private:
	int istank;
	int ankant;
	int istant;
	string day;



public:
	PriceDay(int istank, int ankant, int istant, string day) {
		this->istank = istank;
		this->ankant = ankant;
		this->istant = istant;
		this->day = day;
	}

	friend class Print2;

};


class Print2 {
public:
	static void showInf(PriceDay priceInformation) {
		cout << "<<< Travel Fees >>>" << endl;
		cout << "ISTANBUL-ANKARA: " << priceInformation.istank << " $" << endl;
		cout << "ANKARA-ANTALYA: " << priceInformation.ankant << " $" << endl;
		cout << "ISTANBUL-ANTALYA: " << priceInformation.istant << " $" << endl;
	}

};


class Customer {
private:
	int totalTicketNumber;

public:
	int ticketNumber;
	string* ticket;

	Customer(int totalTicketNumber) {
		this->totalTicketNumber = totalTicketNumber;
		ticketNumber = 0;
		ticket = new string[totalTicketNumber];
		for (int i = 0; i < totalTicketNumber; i++) {
			ticket[i] = "";
		}
	}

	void ticketIncrease() {
		ticketNumber++;
	}

	void seatCount() {
		cout << "Total Ticket Number : " << totalTicketNumber << endl;
		int unusedTicket = totalTicketNumber - ticketNumber;
		cout << "Number of tickets used : " << ticketNumber << endl;
		cout << "Number of unused ticket : " << unusedTicket << endl;
	};


	void bookTickets(int seatNo, string nameSurname) {
		if (seatNo <= totalTicketNumber) {
			if (ticket[seatNo - 1] == "") {
				ticket[seatNo - 1] = nameSurname;
				ticketIncrease();
			}
			else {
				cout << "This ticket has already been sold." << endl;
			}
		}
		else {
			cout << "There are " << totalTicketNumber << " seats" << endl;;
		}

	}

	void listTickets() {
		for (int i = 0; i < totalTicketNumber; i++) {
			cout << i + 1 << ". seat : " << ticket[i] << endl;
		}
	}

};


int main() {



	string slgn = "Most used ticketing app!";
	slogan(slgn);
	cout << endl;
	City city("1)Istanbul-Ankara", "2)Ankara-Antalya", "3)Istanbul-Antalya", "You can cancel your ticket 2 days before the trip.");


	PriceDay price(300, 120, 400, " ");
	price.showInfos(city);
	mesagee(city);
	cout << endl << endl;
	Print2::showInf(price);

	cout << endl << endl;


	int travel;
	cout << "Choose a trip: ";
	cin >> travel;

	string day;
	cout << "Enter the day: ";
	cin >> day;


	int totalSeats = 5;
	Customer customer(totalSeats);
	cout << endl;
	cout << "Ticket Statuses" << endl;
	customer.bookTickets(1, "Full");

	customer.listTickets();
	customer.seatCount();

	cout << endl;
	int chooseSeat;
	cout << "Select Seat : ";
	cin >> chooseSeat;
	string enterName;
	cout << "Enter Name : ";
	cin >> enterName;

	customer.bookTickets(chooseSeat, enterName);

	cout << endl << endl;


	if (chooseSeat < 6 && chooseSeat != 1) {

		cout << "<<< Ticket Information >>>" << endl;

		switch (travel)
		{

		case 1:
			cout << "Name : " << enterName << "\nTicket No : " << chooseSeat << "\nTravel : Istanbul-Ankara " << "\nDay : " << day << "\nHour : 09:00" << "\nPrice : 300 $";
			break;
		case 2:
			cout << "Name : " << enterName << "\nTicket No : " << chooseSeat << "\nTravel : Ankara-Antalya " << "\nDay : " << day << "\nHour : 21:00" << "\nPrice : 120 $";
			break;
		case 3:
			cout << "Name : " << enterName << "\nTicket No : " << chooseSeat << "\nTravel : Istanbul-Antalya " << "\nDay : " << day << "\nHour : 10:00" << "\nPrice : 400 $";
			break;
		default:
			break;
		}

	}

	return 0;
}