////library header
//#include<iostream>          //for cin, cout
//#include<iomanip>           //for setw, setprecision
//#include<cmath>             //for sin function
//#include<string>            //for string
//#include<climits>           // for INT_MAX
//using namespace std;
//
//
////subfuntion for easier read
//double getinput(string msg)
//{
//	double input;
//	cout << msg;          //display msg
//	cin >> input;         //get input
//
//
//	//to make sure no error input crashing the program
//	while (cin.fail())
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << msg;
//		cin >> input;
//	}
//	return input;
//}
////main program
//int main()
//{
//
//	//variable, flag and array declaration
//	double R, freq, step, duration, Imax, Amax, Vmax[2], Tmax[2], I = 0, T = 0;
//	bool flag = 0, period = 0;
//
//	/*
//	Dear Liana,
//
//		You try run it 1st time without changing anything, and
//	2nd time you try ("comment" float) && ("uncomment" double)
//												and you'll see the magic~~
//
//
//	PS* the magic is at the end of the result
//												Yours sincerely,
//													JIΛИ
//
//	*/
//
//	/*↓↓↓↓↓↓↓uncomment double below*/
//	//double Time_mili[429], V[429]; 
//
//	float Time_mili[429], V[429];   //没错就是特地放[429]哒~ :p
//	const double pi = 3.14159265;
//	Time_mili[0] = V[0] = 0;
//	Vmax[0] = Vmax[1] = 0;
//
//
//	//capturing data from user and stored to specific variable
//	R = getinput("Enter the resistance, R (in Resistance):");
//	Imax = getinput("Enter your Imax value, Im (in Ampere):");
//	freq = getinput("Enter your frequency, f (in frequency):");
//	cout << endl;
//
//
//	/*all data display with desired decimal point in fixed position
//	display starting of table*/
//	cout << showpoint << fixed << right <<
//		setw(9) << "Time(ms)" << setw(11) << "Current(A)" << setw(11) << "Voltage(V)" << endl;
//
//
//	/*to get the step of time so the
//	"Time" section in table can be accumulated up to 10 step*/
//	step = (1 / freq) / 10;
//
//
//	/*calculation in loop with displaying data line after line
//	loop for eleven times from 0 to 10, exit loop when i exceed 10*/
//	for (int i = 0; i < 11; i++)
//	{
//		//displaying variable, initially all variable is 0
//		cout << setprecision(2) << setw(9) << Time_mili[i] <<
//			setprecision(4) << setw(11) << I <<
//			setw(11) << V[i] << endl;
//
//
//		/*	
//		once V[i]> the Vmax[1],
//		all variable here update itself by equipping itself accordingly
//		to the current value displayed just now,
//		will stop updating when V[i] didn't larger than Vmax[1]
//		*/
//		if (V[i] >= Vmax[1])                //Seow Yong Jian! Check correction of error: if (V[i] > Vmax[1])
//		{
//			Tmax[1] = Time_mili[i];         //correction of error: Tmax[0] = Time_mili[i]
//			if (V[i] != Vmax[1])
//				Tmax[0] = Time_mili[i];
//			Vmax[1] = V[i];
//			Amax = I;
//		}                                   //NOW BOTH FLOAT AND DOUBLE WILL WORK.
//
//
//		/*
//		only the loop after first i++,
//		Vmax[0] will have the previous value of V[i]
//		*/
//		if (i > 0)
//			Vmax[0] = V[i - 1];
//
//
//		/*
//		if Vmax[1] == Vmax[0] and flag is equal to 0
//		flag should become 1 to indicate max is happening now
//		*/
//		if (Vmax[0] == Vmax[1] && flag == 0)
//			flag = 1;
//
//
//		/*
//		once flag == 1 and once V[i] dropped
//		the time before drop will be stored in Tmax[1]
//		flag return to 0 because there might be second contact with max
//		period = 1 means Vmax already happened for a period of time
//		*/
//		if (V[i] < Vmax[1] && flag == 1)
//		{
//			Tmax[1] = Time_mili[i - 1];
//			flag = 0;
//			period = 1;
//		}
//
//
//		/*
//		T in second is incremented by a step
//		"I" will be calculated by specified formula
//		the next value of V, V[i+1] shall be calculated
//		time is converted to milisecond for display and storing
//		*/
//		T += step;
//		I = Imax * sin(2 * pi*freq*T);
//		V[i + 1] = I * R;
//		Time_mili[i + 1] = T * 1000;
//	}
//
//
//	//To display the max data get inside the loop
//	cout << "\nVmax is " << Vmax[1] << " V during " << Amax << " A at time ";
//
//
//	//if Vmax happen in a period of time
//	if (period == 1)
//	{
//		duration = Tmax[1] - Tmax[0];   //calculate duration and display result
//		cout << "from " << setprecision(2) << Tmax[0] << " ms until " << Tmax[1] << " ms." << endl;
//		cout << "Vmax happens for " << duration << " ms.\n";
//	}
//
//
//	//if Vmax didn't happen in a period of time
//	else
//		cout << setprecision(2) << Tmax[0] << " ms." << endl;   //display result
//
//	system("pause"); //excuse Seow Yong Jian where is your system pause and return 0 for int main?
//	return 0;
//}