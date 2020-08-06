//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
///*
//Author: Liana
//Date: 19/11/2019
//Program: A cinema ticketing system for staff to purchase seats.
//*/
//
////Declaration of Constants
//const float PRICE[3][3] = { {20,16,18},
//							{10,6,8},
//							{12,8,10} }; //PRICE[category][class]
//
//const int MAX_SEAT[3][3] = { {15,15,30},
//						{15,15,30},
//						{15,15,30} }; //MAX_SEAT[movie][class]
//
////Declaration of Functions
//bool staff_login();
//int menu();
//void logo(); //To print out logo
//void ending(); //To print out ending message
//int movies(); //To show movies available
//void seats(int seat_rmg[3][3]); //To show seats available and prices of seats
//int ticketing(int seat_rmg[3][3], string seat_num[3][3][30], int &a, int seat_sold[3][3]);
//void report(const int MAX_SEAT[3][3], int seat_sold[3][3]);
//
//int main()
//{
//	//Declaration of Variables
//	int seat_rmg[3][3] = { {15,15,30},
//						{15,15,30},
//						{15,15,30} };//Remaining seats: [movie][class]
//
//	string seat_num[3][3][30] = { {"001","002","003","004","005","006","007", //Class 0
//								"008","009","010","011","012","013","014","015"},
//								{"101","102","103","104","105","106","107", //Class 1
//								"108","109","110","111","112","113","114","115"} ,
//								{"201","202","203","204","205","206","207", //Class 2 (30 seats)
//								"208","209","210","211","212","213","214","215",
//								"216","217","218","219","220","221","222",
//								"223","224","225","226","227","228","229","230"} };
//	/*The above is to display seat number on ticket
//	  seat_num[movie][class][number of seats available] */
//
//	int a = 0; //Prints out number of seats in each category for each movie without repeating
//
//	int seat_sold[3][3] = { {0,0,0},
//							{0,0,0},
//							{0,0,0}, }; //seat_sold[class][category] for sales report
//	int menu_choice = 0, movie_choice = 0, seat_choice = 0;
//	bool access;
//
//	access = staff_login();
//
//	if (access == true)
//	{
//		do
//		{
//			menu_choice = menu();
//
//			switch (menu_choice)
//			{
//			case 1:
//				movie_choice = movies();
//				break;
//			case 2:
//				seats(seat_rmg);
//				menu_choice = menu();
//				break;
//			case 3:
//				a = ticketing(seat_rmg, seat_num, a, seat_sold); //Prevent a from initialising to 0
//				report(MAX_SEAT, seat_sold);
//				menu();
//				break;
//			case 4:
//				report(MAX_SEAT, seat_sold);
//				menu();
//				break;
//			case 5:
//				break;
//			default:
//				cout << "Invalid choice. Please re-enter : ";
//				cin >> menu_choice;
//			}
//		} while (menu_choice != 5 && movie_choice == 4);
//
//		cout << " Ending Program......\n\n";
//		ending();
//	}
//
//	system("pause");
//	return 0;
//
//}
//
//bool staff_login()
//{
//	//Declaration of Variables
//	string default_id = "tarcinemax", default_psw = "ilovetarc"; //Default ID and password
//	string input_id, input_psw; //User ID and password
//	bool access;
//
//	cout << "  Staff ID : ";
//	getline(cin, input_id);
//	cout << "  Password : ";
//	getline(cin, input_psw);
//
//	//Compare ID and password
//	if (default_id == input_id) //If ID is correct
//	{
//		if (default_psw == input_psw)
//		{
//			system("CLS");
//			logo();
//			cout << setw(35) << right << "\n  LOGIN SUCCESSFUL!\n";
//			system("pause");
//			access = true;
//		}
//	}
//	else
//	{
//		cout << setw(35) << right << "  ACCESS DENIED\n";
//		access = false;
//	}
//
//	return access;
//}
//
//int menu()
//{
//	//Declaration of Variables
//	int menu_choice;
//
//	system("CLS");
//	logo();
//	cout <<
//		"============= MENU =============\n"
//		"  1. Movies Available\n"
//		"  2. Seats Available\n"
//		"  3. Ticket Purchase\n"
//		"  4. Sales Report\n"
//		"  5. Quit Program\n"
//		"=================================\n"
//		"  Please enter your choice : ";
//	cin >> menu_choice;
//
//	return menu_choice;
//}
//
//void logo()
//{
//	//Logo
//	cout <<
//
//		"        _____ _   ___    ___ _         \n"
//		"       |_   _/_\\ | _ \\  / __(_)_ _  ___ _ __  __ ___ __ \n"
//		"         | |/ _ \\|   / | (__| | ' \\/ -_) '  \\/ _` \\ \\ / \n"
//		"         |_/_/ \\_\\_|_\\  \\___|_|_||_\\___|_|_|_\\__,_/_\\_\\ \n";
//
//	cout << "\n  WELCOME TO TAR CINEMAX, A CINEMA THAT ONLY OPENS ON FRIDAYS\n";
//	cout << "=================================================================\n";
//}
//
//void ending()
//{
//	cout <<
//		"  888888 88  88    db    88b 88 88  dP     Yb  dP  dP'Yb  88   88 d8b\n"
//		"    88   88  88   dPYb   88Yb88 88odP       YbdP  dP   Yb 88   88 Y8P\n"
//		"    88   888888  dP__Yb  88 Y88 88'Yb        8P   Yb   dP Y8   8P `''\n"
//		"    88   88  88 dP````Yb 88  Y8 88  Yb      dP     YbodP  `YbodP' (8)\n\n";
//
//}
//
//int movies()
//{
//	//Declaration of Variables
//	int movie_choice;
//
//	do
//	{
//		system("CLS");
//		logo();
//
//		cout <<
//			"============= MOVIES (27-12-2019) =============\n"
//			"  1. \"Frozen 2\"         (10.00 a.m.) \n"
//			"  2. \"Joker\"            (12.00 p.m.) \n"
//			"  3. \"Charlie's Angels\" ( 3.00 p.m.)\n"
//			"  4. Return to Main Menu\n"
//			"===============================================\n"
//			"  Select a movie to view details : ";
//		cin >> movie_choice;
//
//		system("CLS");
//		logo();
//		switch (movie_choice)
//		{
//		case 1:
//			cout <<
//				"============================= MOVIE DETAILS ==============================\n"
//				"  Frozen 2 (F2)\n"
//				"  Year             : 2019\n"
//				"  Genre            : Drama/Fantasy\n"
//				"  Length           : 1 hour 43 minutes\n"
//				"  Synopsis         : \n"
//				"    Elsa the Snow Queen and her sister Anna embark on an adventure\n"
//				"    far away from the kingdom of Arendelle. They are joined by\n"
//				"    friends, Kristoff, Olaf, and Sven.\n\n"
//				"===========================================================================\n";
//			system("pause");
//			break;
//
//		case 2:
//			cout <<
//				"============================= MOVIE DETAILS ==============================\n"
//				"  Joker (JK)S\n"
//				"  Year             : 2019\n"
//				"  Genre            : Drama/Thriller\n"
//				"  Length           : 2 hours 2 minutes\n"
//				"  Synopsis         : \n"
//				"    Forever alone in a crowd, failed comedian Arthur Fleck\n"
//				"    seeks connection as he walks the streets of Gotham City.\n"
//				"    Arthur wears two masks -- the one he paints for his day job\n"
//				"    as a clown, and the guise he projects in a futile attempt\n"
//				"    to feel like he's part of the world around him.\n"
//				"    Isolated, bullied and disregarded by society, Fleck begins\n"
//				"    a slow descent into madness as he transforms into\n"
//				"    the criminal mastermind known as the Joker.\n\n"
//				"===========================================================================\n";
//			system("pause");
//			break;
//
//		case 3:
//			cout <<
//				"============================= MOVIE DETAILS ==============================\n"
//				"  Charlie's Angels (CA)\n"
//				"  Year             : 2019\n"
//				"  Genre            : Action/Adventure\n"
//				"  Length           : 1 hour 58 minutes\n"
//				"  Synopsis         : \n"
//				"    A brilliant scientist invents Calisto -- \n"
//				"    a sustainable energy source that will revolutionize the way\n"
//				"    people use power. But when Calisto falls into the wrong hands,\n"
//				"    the Angels must retrieve it before it can be used as a weapon\n"
//				"    of mass destruction.\n"
//				"===========================================================================\n";
//			system("pause");
//			break;
//
//		case 4:
//			break;
//		default:
//			cout << "Invalid choice. Please re-enter: ";
//			cin >> movie_choice;
//		}
//	} while (movie_choice != 4);
//
//	return movie_choice;
//}
//
//void seats(int seat_rmg[3][3])
//{
//	//Declaration of Variables
//	int movie, display[3], seat_choice; //Display movie seats available, [0] = class 0, [1] = class 1, [2] = class 2
//	string movie_name, category[3] = { "  ADULT", "  CHILD", "  STUDENT" }; //To display table
//
//	system("CLS");
//	logo();
//
//	cout <<
//		"============= MOVIES (27-12-2019) =============\n"
//		"  1. \"Frozen 2\"         (10.00 a.m.) \n"
//		"  2. \"Joker\"            (12.00 p.m.) \n"
//		"  3. \"Charlie's Angels\" ( 3.00 p.m.)\n"
//		"===============================================\n";
//	cout << "  Select a movie to view seating : ";
//	cin >> movie;
//	while (movie != 1 && movie != 2 && movie != 3)
//	{
//		cout << "Invalid choice. Please re-enter : ";
//		cin >> movie;
//	}
//	movie -= 1; //To prevent confusion for programmer, sync to become 0,1,2
//
//	//Seats Remaining for Each Movie
//	switch (movie)
//	{
//	case 0:
//		for (int i = 0; i < 3; i++)
//			display[i] = seat_rmg[0][i];
//		movie_name = "FROZEN 2";
//		break;
//	case 1:
//		for (int i = 0; i < 3; i++)
//			display[i] = seat_rmg[1][i];
//		movie_name = "JOKER";
//		break;
//	case 2:
//		for (int i = 0; i < 3; i++)
//			display[i] = seat_rmg[2][i];
//		movie_name = "CHARLIE'S ANGELS";
//		break;
//	}
//
//	cout << setw(20) << right << movie_name << endl;
//	cout <<
//		"============ SEATS REMAINING ============\n"
//		"  Class 0 (VIP)    : " << display[0] << endl <<
//		"  Class 1 (Front)  : " << display[1] << endl <<
//		"  Class 2 (Back)   : " << display[2] << endl <<
//		"==========================================\n";
//
//	//Price
//	cout << "  CATEGORY/CLASS            0            1           2\n";
//	for (int i = 0; i < 3; i++) //For each movie
//	{
//		cout << setw(12) << category[i] << "        ";
//		for (int j = 0; j < 3; j++) //For each class
//			cout << setw(10) << right << noshowpoint << "RM " << PRICE[i][j];
//		cout << endl;
//	}
//
//	system("pause");
//}
//
//int ticketing(int seat_rmg[3][3], string seat_num[3][3][30], int &a, int seat_sold[3][3])
//{
//	//Declaration of Variables
//	int ticket[3]; //ticket[category], [0] = adult, [1] = child, [2] = student
//	int tclass, movie, count[3]; //count[category] to be displayed on tickets
//	string name, time, movie_name; //To display on ticket
//	string category_total[3] =
//	{ "Adult Tickets Total", "Child Tickets Total", "Student Tickets Total" }; //To display on receipt
//	string category[3] = { "ADULT", "CHILD", "STUDENT" }; //To display on tickets
//	float payment = 0, change_due = 0, total = 0, subtotal[3] = { 0,0,0 };
//	enum Operation { OPEN, CLOSE, NEXT_CUSTOMER, NO_MORE }; //Ticket counter open or close?
//	Operation all_counter = OPEN, counter[3][3], movie_counter[3];
//	Operation cont = NEXT_CUSTOMER; //Continue to next customer?
//	char nc; //Next customer
//
//	system("CLS");
//	logo();
//
//	while (all_counter == OPEN && cont == NEXT_CUSTOMER)
//	{
//		//Check if counter is still open
//		for (int i = 0; i < 3; i++) //Check each movie
//		{
//			int c = 0; //Determine if the counter for this movie closes
//			int m = 0; //Determine if the entire counter closes
//
//			for (int j = 0; j < 3; j++) //Check each class in each movie
//			{
//				if (seat_rmg[i][j] == 0) //All seats in this class for this movie are sold out
//				{
//					counter[i][j] = CLOSE; //This counter closes
//					c++; //One class unavailable for this movie
//				}
//				else
//					counter[i][j] = OPEN;
//			}
//			if (c == 3) //All counters for this movie are sold out
//			{
//				movie_counter[i] = CLOSE;
//				m++;
//			}
//			else
//				movie_counter[i] = OPEN;
//
//			if (m == 3) //All movies are sold out
//				all_counter = CLOSE;
//			else
//				all_counter = OPEN;
//		}
//
//		//User Input
//		cin.get();
//		cout << "  Customer Name                           : ";
//		getline(cin, name);
//		name[0] = toupper(name[0]); //To capitalise the name
//		for (int i = 1; i < name.length(); i++)
//			if (name[i] == ' ') //Check for new word
//				name[i + 1] = toupper(name[i + 1]);
//
//		cout << "  Movie (1,2,3)                           : ";
//		cin >> movie;
//		while (movie != 1 && movie != 2 && movie != 3) //Validate data
//		{
//			cout << "Invalid movie choice." << endl;
//			cout << "  Movie (1,2,3)                          : ";
//			cin >> movie;
//		}
//		while (movie_counter[movie - 1] == CLOSE) //If movie counter is closed, re-enter movie
//		{
//			cout << "All seats have been sold out for this movie. Please choose another movie." << endl;
//			cout << "  Movie (1,2,3)                          : ";
//			cin >> movie;
//		}
//		switch (movie) //To print out movie name on ticket
//		{
//		case 1:
//			movie_name = "Frozen 2";
//			time = "27 Dec 2019, 10.00 a.m.";
//			break;
//		case 2:
//			movie_name = "Joker";
//			time = "27 Dec 2019, 12.00 p.m.";
//			break;
//		case 3:
//			movie_name = "Charlie's Angels";
//			time = "27 Dec 2019, 3.00 p.m.";
//		}
//		movie--; //For programmer's use
//
//		cout << "  Ticket Class (0,1,2)                    : ";
//		cin >> tclass;
//		while (tclass != 0 && tclass != 1 && tclass != 2)
//		{
//			cout << "  Invalid ticket class entered." << endl;
//			cout << "  Ticket Class (0,1,2)                    : ";
//			cin >> tclass;
//		}
//		while (counter[movie][tclass] == CLOSE)
//		{
//			cout << "  All tickets for this class have been sold out. Please choose another class." << endl;
//			cout << "  Ticket Class (0,1,2)                    : ";
//			cin >> tclass;
//		}
//
//		cout << "  Number of Adult Tickets                 : ";
//		cin >> ticket[0];
//		while (ticket[0] < 0 || ticket[0] > seat_rmg[movie][tclass]) //Validate data
//		{
//			cout << "  Invalid number of tickets entered." << endl;
//			cout << "  Remaining seats available               : " << seat_rmg[movie][tclass] << endl;
//			cout << "  Number of Adult Tickets                 : ";
//			cin >> ticket[0];
//		}
//		seat_rmg[movie][tclass] -= ticket[0]; //Update seat_rmg after tickets are purchased
//		seat_sold[tclass][0] += ticket[0]; //Update seats sold for each class and each category
//
//		cout << "  Number of Child Tickets                 : ";
//		cin >> ticket[1];
//		while (ticket[1] < 0 || ticket[1] > seat_rmg[movie][tclass]) //Validate data
//		{
//			cout << "  Invalid number of tickets entered." << endl;
//			cout << "  Remaining seats available               : " << seat_rmg[movie][tclass] << endl;
//			cout << "  Number of Child Tickets                 : ";
//			cin >> ticket[1];
//		}
//		seat_rmg[movie][tclass] -= ticket[1]; //Update seat_rmg after tickets are purchased
//		seat_sold[tclass][1] += ticket[1]; //Update seats sold for each class and each category
//
//		cout << "  Number of Student Tickets (ID required) : ";
//		cin >> ticket[2];
//		while (ticket[2] < 0 || ticket[2] > seat_rmg[movie][tclass]) //Validate data
//		{
//			cout << "  Invalid number of tickets entered." << endl;
//			cout << "  Remaining seats available               : " << seat_rmg[movie][tclass] << endl;
//			cout << "  Number of Student Tickets               : ";
//			cin >> ticket[2];
//		}
//		seat_rmg[movie][tclass] -= ticket[2]; //Update seat_rmg after tickets are purchased
//		seat_sold[tclass][2] += ticket[2]; //Update seats sold for each class and each category
//
//		//Calculate total amount due
//		for (int i = 0; i < 3; i++)
//		{
//			subtotal[i] = ticket[i] * PRICE[i][tclass]; //PRICE[category][class]
//			total += subtotal[i];
//		}
//
//		cout << "  Total Amount Due                        : RM " << fixed << setprecision(2) << total << endl;
//		cout << "  Payment Made                            : RM ";
//		cin >> payment;
//		while (payment < total) //Validate data
//		{
//			cout << "  Invalid amount entered." << endl;
//			cout << "  Payment Made                            : RM ";
//			cin >> payment;
//		}
//		change_due = payment - total;
//		cout << "  Total Change Due                        : RM " << fixed << setprecision(2) << change_due << endl;
//
//		//Receipt
//		cout << "\n=================== RECEIPT (CLASS " << tclass << ") ===================\n";
//		cout << "  Name                  : " << name << endl;
//		cout << "  Movie                 : " << movie_name << endl;
//		for (int i = 0; i < 3; i++)
//		{
//			cout << "  " << category_total[i] << " : RM "
//				<< PRICE[i][tclass] << " * " << ticket[i] << " ticket(s) = RM " //PRICE[category][class]
//				<< fixed << setprecision(2) << subtotal[i] << endl;
//		}
//		cout << "  Total                 : RM " << fixed << setprecision(2) << total << endl;
//		cout << "  Payment Made          : RM " << fixed << setprecision(2) << payment << endl;
//		cout << "  Total Change          : RM " << fixed << setprecision(2) << change_due << endl;
//		cout << "=========================================================\n";
//
//		//Ticket
//		cout << "  Printing tickets......" << endl;
//		system("pause");
//
//		for (int i = 0; i < 3; i++) //Calculate how many tickets to be printed for each category
//			count[i] = ticket[i];
//
//		for (int j = 0; j < 3; j++) //Prints out category for adult, then child, then student
//		{
//			for (count[j]; count[j] > 0; count[j]--) //Prints out number of tickets for each category
//			{
//				cout << "===================== TICKET =====================\n"
//					<< "  TAR Cinemax\n"
//					<< "  " << category[j] << endl
//					<< "  Movie       : " << movie_name << endl
//					<< "  Date / Time : " << time << endl
//					<< "  Class       : " << tclass << endl;
//				if (tclass == 0)
//				{
//					cout << "  Seat        : " << seat_num[movie][tclass][a] << endl
//						<< "==================================================\n";
//					a++;
//				}//a has to be returned to main function, distribution of seats
//			}
//		}
//
//		//Do you want to carry on?
//		cout << "  Next Customer (Y = Yes)                  : ";
//		cin >> nc;
//		if (nc == 'y' || nc == 'Y')
//			cont = NEXT_CUSTOMER;
//		else
//			cont = NO_MORE;
//	}
//
//	if (all_counter == CLOSE)
//		cout << "  All tickets have been sold out. Please come again next week!\n";
//
//	else if (cont == NO_MORE)
//		cout << "  No more customers. Counter closed.\n";
//
//	return a;
//}
//
//void report(const int MAX_SEAT[3][3], int seat_sold[3][3])
//{
//	system("pause");
//	logo();
//
//	int class_sold[3] = { 0,0,0 }; //class_sold[class]
//	int max_seat[3] = { 0,0,0 }; //max_seat[class]
//	int cat_sold[3] = { 0,0,0 }; //cat_sold[category]
//	int cat_revenue[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} }; //cat_revenue[category][class]
//	int revenue[3] = { 0,0,0 }; //revenue[category]
//	int all_class = 0, all_seat = 0, all_revenue = 0, all_cat = 0;
//
//	for (int i = 0; i < 3; i++) //Add up
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			class_sold[i] += seat_sold[i][j];
//			max_seat[i] += MAX_SEAT[j][i];
//			cat_sold[i] += seat_sold[j][i];
//			cat_revenue[i][j] += seat_sold[j][i] * PRICE[i][j]; //PRICE[category][class]
//			revenue[i] += cat_revenue[i][j];
//		}
//		all_class += class_sold[i];
//		all_seat += max_seat[i];
//		all_cat += cat_sold[i];
//		all_revenue += revenue[i];
//	}
//
//	cout <<
//		"=========================== SALES REPORT ===========================\n"
//		"  Movies       : \"Frozen 2\", \"Joker\", \"Charlie's Angels\"\n"
//		"  Date         : 27 Dec 2019\n\n"
//		"  Seat Occupancy for Each Class:\n\n"
//		"                 Total Seats    Quantity Sold    Sold %\n"
//		"     Class 0          " << max_seat[0] << setw(15) << right << class_sold[0] << setw(15) << right
//		<< (class_sold[0] * 100 / max_seat[0]) << endl <<
//		"     Class 1          " << max_seat[1] << setw(15) << right << class_sold[1] << setw(15) << right
//		<< (class_sold[1] * 100 / max_seat[1]) << endl <<
//		"     Class 2          " << max_seat[2] << setw(15) << right << class_sold[2] << setw(15) << right
//		<< (class_sold[2] * 100 / max_seat[2]) << endl <<
//		"                    ------          ------       --------\n"
//		"     Overall          " << all_seat << setw(15) << right << all_class << setw(15) << right
//		<< (all_class * 100 / all_seat) << endl << endl <<
//		"  Sales for Each Category Type:\n\n"
//		"                   Category        Seats        Sales (RM) \n"
//		"                    Adult" << setw(14) << right << cat_sold[0] << setw(17) << right << revenue[0] << endl <<
//		"                    Child" << setw(14) << right << cat_sold[1] << setw(17) << right << revenue[1] << endl <<
//		"                   Student" << setw(13) << right << cat_sold[2] << setw(17) << right << revenue[2] << endl <<
//		"                                   ------        --------\n"
//		"                    Total" << setw(13) << right << all_cat << setw(17) << right << all_revenue << endl <<
//		"====================================================================\n";
//
//	system("pause");
//}