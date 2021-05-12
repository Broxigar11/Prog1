#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"

double one(double x){
	return 1;
}

double slope(double x){
	return x/2;
}

double square(double x){
	return x*x;
}

double sloping_cos(double x){
	return slope(x)+cos(x);
}

int main()
try{
	using namespace Graph_lib;

	Simple_window win{Point{100,100},600,600,"Function graphs"};

	Axis x{Axis::x, Point{100,300}, 400, 20, "1==20 pixels"};
	x.set_color(Color::red);
	
	Axis y{Axis::y, Point{300,500}, 400, 20, "1==20 pixels"};
	y.set_color(Color::red);

	Function f1{one,-10,11,Point{300,300},400,20,20};
	
	Function f2{slope,-10,11,Point{300,300},400,20,20};
	Text t{Point{100,380}, "x/2"};

	Function f3{square,-10,11,Point{300,300},400,20,20};

	Function f4([](double x){return cos(x);},-10,11,Point{300,300},400,20,20);
	f4.set_color(Color::blue);

	Function f5{sloping_cos,-10,11,Point{300,300},400,20,20};

	win.attach(x);
	win.attach(y);

	win.attach(f1);
	win.attach(t);

	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.wait_for_button();
}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}
