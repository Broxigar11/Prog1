#include "Graph.h"
#include "Simple_window.h"

int main()
try{
	using namespace Graph_lib;

	Point tl(100, 100);
	//Simple_window win {tl, 600, 400, "My Window"};
	//win.wait_for_button();

	Simple_window win {tl, 600, 400, "Canvas"};
	win.wait_for_button();

	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
	xa.set_color(Color::green); //szin
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();

	Axis ya {Axis::y, Point{20,300}, 420, 15, "y axis"};  //tengelyhossz
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);     
	win.attach(ya); 
	win.set_label("Canvas #3"); 
	win.wait_for_button();  

	Function sine {sin,0,100,Point{40,200},1000,50,50}; //hely       
	win.attach(sine); 
	win.set_label("Canvas #4"); 
	win.wait_for_button();

	sine.set_color(Color::blue); 
	Polygon poly;
	poly.add(Point{350,100}); 
	poly.add(Point{400,100});
	poly.add(Point{380,150});
	poly.add(Point{330,150});
	 //paralelogramma
	
	poly.set_color(Color::dark_red);  // szin
	poly.set_style(Line_style::dash); 
	win.attach(poly); 
	win.set_label("Canvas #5"); 
	win.wait_for_button();

	Rectangle r {Point{200,200}, 100, 100}; //negyzet
	win.attach(r); 
	win.set_label("Canvas #6"); 
	win.wait_for_button();

	Closed_polyline poly_rect; 
	poly_rect.add(Point{100,50}); 
	poly_rect.add(Point{200,50}); 
	poly_rect.add(Point{200,100}); 
	poly_rect.add(Point{100,100}); 
	win.attach(poly_rect);

	r.set_fill_color(Color::magenta); //szin
	poly.set_style(Line_style(Line_style::dash,4)); 
	poly_rect.set_style(Line_style(Line_style::dash,2)); 
	poly_rect.set_fill_color(Color::green); 
	win.set_label("Canvas #7"); 
	win.wait_for_button();

	Text t {Point{150,150}, "Hello, grafikai vilag!"}; //szoveg
	win.attach(t); 
	win.set_label("Canvas #8"); 
	win.wait_for_button();

	t.set_font(Font::times_bold); 
	t.set_font_size(18); 					// betumeret
	win.set_label("Canvas #9"); 
	win.wait_for_button();

	Image ii {Point{100,50},"dog.jpg"};		// kep
	win.attach(ii); 
	win.set_label("Canvas #10"); 
	win.wait_for_button();

	ii.move(0,200); 						//pozicio
	win.set_label("Canvas #11"); 
	win.wait_for_button();

	Circle c {Point{100,200},50}; 
	Ellipse e {Point{100,200}, 75,25}; 
	e.set_color(Color::dark_red); 
	Mark m {Point{100,200},'x'};

	ostringstream oss; 
	oss << "screen size: " << x_max() << "" << y_max() 
		<< "; window size: " << win.x_max() << "" << win.y_max(); 
	Text sizes {Point{100,20},oss.str()};
	
	Image cal {Point{225,225},"cat.jpg"}; //kep
	cal.set_mask(Point{40,40},200,150);                      
	win.attach(c); 
	win.attach(m); 
	win.attach(e);
	
	win.attach(sizes); 
	win.attach(cal); 
	win.set_label("Canvas #12"); 
	win.wait_for_button();

	return 0;
}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}